#!/usr/bin/python

import yaml
import pprint
import os
import pdb
import re
import cgi
import codecs
import sys

import cgitb
cgitb.enable()

if (sys.stdout.encoding is None):
        print >> sys.stderr, "please set python env PYTHONIOENCODING=UTF-8, example: export PYTHONIOENCODING=UTF-8, when write to stdout."
        exit(1)

specsFile = open('../source/syntax.yml')
specs = yaml.safe_load(specsFile)
specsFile.close()

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
                
        result = result + "\t\t<div class=\"code2\">\n\t\t\t<p>Example</p>\n\t\t\t<pre>\n"
        
        if type(example) is str or type(example) is unicode:
                result = result + cgi.escape(example).strip()
        elif type(example) is dict:
                if ("example" in example):
                        result += cgi.escape(example["example"]).strip()
                else:
                        raise ValueError("every entry must contain an example element")
        else:
                raise ValueError("unrecognized type for example data")
        
        result = result + "\n</pre>\n\t\t</div>"
        return result

indexPageContents = "<meta charset='utf-8'/>\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=0.6\">\n<html>\n\t<head>\n\t\t<title>Syntax Listing - Plange</title>\n\t\t<link rel=StyleSheet href='../css/general.css' type='text/css' />\n\t</head>\n\t<body>\n\t\t<?php require('../header.php') ?>\n\n\n\t\t<p>This page is generated from the <a href='/source/syntax.yml'>syntax specification</a>. Tags, identities, and all {IC} (optional whitespace and comment regions) are filtered from the syntax display to improve readability. See the specification for the full grammar specification. The root production of the grammar is \"STATEMENT_SCOPE\".</p>\n\t\t<h2>Subpage Listing</h2>\n\t\t<table>\n"
names = specs.keys()
names.sort()

regexs = {name: re.compile("\\b" + name + "\\b") for name in names}
stripRegex = re.compile("(\\$)|(%[_\w0-9]+)|(\\{IC\\})")
openParenSpaceRegex = re.compile("\\( ")
openBraceSpaceRegex = re.compile("\\{ ")
openBracketSpaceREgex = re.compile("\\[ ")
spaceCloseParenRegex = re.compile(" \\)")
spaceCloseBraceRegex = re.compile(" \\}")
spaceCloseBracketRegex = re.compile(" \\]")

def simplifySyntaxString(syntax):
        syntax = cgi.escape(syntax).strip()
        syntax = stripRegex.sub("", syntax)
        syntax = openParenSpaceRegex.sub("(", syntax)
        syntax = openBraceSpaceRegex.sub("{", syntax)
        syntax = openBracketSpaceREgex.sub("[", syntax)
        syntax = spaceCloseParenRegex.sub(")", syntax)
        syntax = spaceCloseBraceRegex.sub("}", syntax)
        syntax = spaceCloseBracketRegex.sub("]", syntax)
        syntax = spaceCloseBracketRegex.sub("]", syntax)
        return syntax        

def simplifySyntaxStringAddAnchors(syntax):
        syntax = simplifySyntaxString(syntax)
        for refName in names:
                if refName == name:
                        continue
                syntax = regexs[refName].sub("<a href=\"/documentation/syntax.php#" + refName + "\">" + refName + "</a>", syntax)
        return syntax

def simplifySyntaxStringAddLinks(syntax):
        syntax = simplifySyntaxString(syntax)
        for refName in names:
                if refName == name:
                        continue
                syntax = regexs[refName].sub("<a href=\"/documentation/syntax.php?name=" + refName + "\">" + refName + "</a>", syntax)
        return syntax

if len(sys.argv) == 1: # output the table for the syntax listing page
        print "\n\t\t<table>\n"
        for name in names:
                details = specs[name]

                syntaxString = simplifySyntaxStringAddAnchors(details["syntax"])
                print "\t\t\t<tr>\n"
                print "\t\t\t\t<td><a id=\"" + name + "\" href=\"/documentation/syntax.php?name=" + name + "\">" + name + "</a></td>\n"
                if "doc" in details:
                        print "\t\t\t\t<td>" + details["doc"].strip() + "</td>\n"
                else:
                        print "\t\t\t\t<td>no doc string</td>\n"
                        
                print "\t\t\t\t<td>" + syntaxString + "</td>\n"
                print "\t\t\t</tr>\n"
        print "\t\t</table>\n"
else:
        name = sys.argv[1]
        details = specs[name]
                        
        if "doc" in details:
                print "\t\t<p>" + details["doc"].strip() + "</p>\n\n"

        if "syntax" in details:
                syntaxString = simplifySyntaxStringAddLinks(details["syntax"])
               
                title = "syntax"
                if "assoc" in details:
                        title = title + " (associativity: " + details["assoc"] + ")"
                print "\t\t<div class=\"syntax\">\n\t\t\t<p>" + title + "</p>\n\t\t\t<div>" + syntaxString + "</div>\n\t\t</div>\n"
        else:
                raise ValueError("every entry must contain a syntax element")

        if "example" in details:
                print loadExample(details["example"])

        if "examples" in details:
                for example in details["examples"]:
                        print loadExample(example)

        if "notes" in details:
                print "\t\t<h2>Notes</h2>\n\t\t" + paragraphy(details["notes"])

        if "see" in details:
                print "\t\t<p>See:"
                for i in details["see"]:
                        print " <a href=\"syntax.php?name=" + i + "\">" + i + "</a>"
                print "\n\t\t</p>\n"
