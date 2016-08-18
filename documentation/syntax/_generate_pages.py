#!/usr/bin/python

import yaml
import pprint
import os
import pdb
import re
import cgi
import codecs

specsFile = open('../../source/syntax.yml')
specs = yaml.safe_load(specsFile)
specsFile.close()

phpFiles = [ f for f in os.listdir(".") if f.endswith(".php")]
for f in phpFiles:
        os.remove(f)
	
pageTemplate = ""
with open("_syntax_page_template", 'r') as templateFile:
        pageTemplate = templateFile.read()

htmlTest = re.compile("(?i)<\/?\w+((\s+\w+(\s*=\s*(?:\".*?\"|'.*?'|[^'\">\s]+))?)+\s*|\s*)\/?>")
def paragraphy(text):
        if htmlTest.match(text):
                return text
        else:
                return "\t\t<p>" + cgi.escape(text).strip() + "\n\t\t</p>\n"

def loadExample(example):
        if ("annotation" in example):
                result = paragraphy(example["annotation"])
        else:
                result = ""
                
        result = result + "\t\t<div class=\"code\">\n\t\t\t<p>Example</p>\n\t\t\t<pre>"
        
        if type(example) is str or type(example) is unicode:
                result = result + cgi.escape(example).strip()
        elif type(example) is dict:
                if ("example" in example):
                        result += cgi.escape(example["example"]).strip()
                else:
                        raise ValueError("every entry must contain an example element")
        else:
                raise ValueError("unrecognized type for example data")
        
        result = result + "</pre>\n\t\t</div>"
        return result

indexPageContents = "<meta charset='utf-8'/>\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=0.6\">\n<html>\n\t<head>\n\t\t<title>Syntax Listing - Plange</title>\n\t\t<link rel=StyleSheet href='../css/general.css' type='text/css' />\n\t</head>\n\t<body>\n\t\t<?php require('../header.php') ?>\n\n\n\t\t<p>The root production of the grammar is \"statement_scope.\"</p>\n\t\t<h2>Subpage Listing</h2>\n\t\t<ul>\n"
names = specs.keys()
names.sort()
regexs = {name: re.compile("\\b" + name + "\\b") for name in names}
for name in names:
        details = specs[name]
                
        phpFilename = name + ".php"
        if "doc" in details:
                content = "\t\t<p>" + details["doc"].strip() + "</p>\n\n"
        else:
                content = ""

        if "syntax" in details:
                syntaxString = cgi.escape(details["syntax"]).strip()
                for refName in names:
                        if refName == name:
                                continue
                        syntaxString = regexs[refName].sub("<a href=\"/documentation/syntax/" + refName + ".php\">" + refName + "</a>", syntaxString)

                title = "syntax"
                if "assoc" in details:
                        title = title + " (associativity: " + details["assoc"] + ")"
                content = content + "\t\t<div class=\"syntax\">\n\t\t\t<p>" + title + "</p>\n\t\t\t<div>" + syntaxString + "</div>\n\t\t</div>\n"
        else:
                raise ValueError("every entry must contain a syntax element")

        if "example" in details:
                content += loadExample(details["example"])

        if "examples" in details:
                for example in details["examples"]:
                        content += loadExample(example)

        if "notes" in details:
                content = content + "\t\t<h2>Notes</h2>\n\t\t" + paragraphy(details["notes"])

        if "see" in details:
                content = content + "\t\t<p>See:"
                for i in details["see"]:
                        content = content + "<a href=\"" + i + ".php\">" + i + "</a>"
                content = content + "\n\t\t</p>\n"

        page = pageTemplate.replace("%CONTENT%", content)
        page = page.replace("%NAME%", name)

        with codecs.open(phpFilename, "w", "utf-8") as phpFile:
                phpFile.write(page)

        indexPageContents = indexPageContents + "\t\t\t<li><a href=\"/documentation/syntax/" + phpFilename + "\">" + name + "</a></li>\n"

indexPageContents = indexPageContents + "\n\n\t\t<?php require('../footer.php') ?>\n\t</body>\n</html>"
with codecs.open("../syntax.php", "w", "utf-8") as indexFile:
        indexFile.write(indexPageContents)
