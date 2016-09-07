#!/usr/bin/python

import os
import yaml
import pdb
import re

execfile("../../python/templating.py")

oldHppFiles = [ f for f in os.listdir(".") if f.endswith(".hpp")]
for f in oldHppFiles:
    os.remove(f)

oldCppFiles = [ f for f in os.listdir(".") if f.endswith(".cpp")]
for f in oldCppFiles:
    os.remove(f)

with open('../../syntax.yml') as specsFile:
    specs = yaml.safe_load(specsFile)

names = specs.keys()
names.sort()

regexs = {name: re.compile("\\b" + name + "\\b") for name in names}
dependencies = dict()

def direct_dependencies():
	for name in names:
		details = specs[name]
		dependencies[name] = set()
		syntaxString = details["syntax"].strip()
		for refName in names:
			if refName == "EXPRESSION" or refName == "IC":
				continue
			if regexs[refName].search(syntaxString):
				dependencies[name].add(refName)
direct_dependencies()

#apply transitivity
def transitivity():
	anyChanged = True
	while anyChanged:
		anyChanged = False
		for name in names:
			for child in set(dependencies[name]):
				if child == name:
					continue
				for grandchild in dependencies[child]:
					if not grandchild in dependencies[name]:
						dependencies[name].add(grandchild)
						anyChanged = True

transitivity()

def get_cname(ppname):
    cname = ppname.lower()
    cname = cname[0:1].upper() + cname[1:]
    i = cname.find("_")
    while i >= 0 and i < len(cname) - 1:
        cname = cname[0:i] + cname[i + 1].upper() + (cname[i + 2:] if i < len(cname) - 2 else "")
        i = cname.find("_")
    return cname

def get_op(syntax):
    (s, e) = re.search("\".*\"", syntax).span()
    return syntax[(s+1):(e-1)]
    
for ppname in names:
    print(ppname)
    details = specs[ppname]
    cname = get_cname(ppname)
    cppFilename = cname + ".cpp"
    hppFilename = cname + ".hpp"

    if not ppname.endswith("_OP"):
        props = {"PPNAME": ppname, "NAME": cname, "CPP_INTERPRET": details["cpp_interpret"]}
        if ppname in dependencies["BINARY_OP"]:
            op = get_op(details["syntax"])
            props["OP"] = op
            gen("_binary_op_hpp_template", hppFilename, props)
            gen("_binary_op_cpp_template", cppFilename, props)
            continue
        elif ppname in dependencies["UNARY_OP"]:
            op = get_op(details["syntax"])
            props["OP"] = op
            props["IS_POSTFIX"] = "false" if details["syntax"].strip().startswith("\"" + op + "\"") else "true"
            gen("_unary_op_hpp_template", hppFilename, props)
            gen("_unary_op_cpp_template", cppFilename, props)
            continue

    gen("_hpp_template", hppFilename, props)
    gen("_cpp_template", cppFilename, props)
