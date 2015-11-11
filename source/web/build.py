#!/usr/bin/python

import os
import fnmatch
import re
from htmldom import htmldom
import pdb

sourceDir = os.path.dirname(os.path.abspath(__file__)) + "/"
buildDir = os.path.abspath(sourceDir + "../../") + "/"

def strip(text):
	dom = htmldom.HtmlDom().createDom(text)
	elem = dom.find("body")
	return elem.html()[6:][:-7]

def decorate(treeDepth, name, text):
	pathBacktrack = "../" * treeDepth
	result = "<meta charset='utf-8'/><html><head><title>" + name
	result = result + "</title><link rel=StyleSheet href='"
	result = result + pathBacktrack + "css/general.css' type='text/css' /></head><body><?php require('"
	result = result + pathBacktrack + "header.php') ?>\n\n\n" + text + "\n\n\n<?php require('"
	result = result + pathBacktrack + "footer.php') ?></body></html>"
	return result

def build(relative_filepath):
	sourcePath = sourceDir + relative_filepath
	destPath = buildDir + relative_filepath[:-5] + ".php"

	#read in
	text = open(sourcePath).read()

	#apply transformations
	text = strip(text)
	text = text.replace(".html", ".php")

	(temp, _) = os.path.split(relative_filepath);
	treeDepth = len(relative_filepath) - len(relative_filepath.replace("/", ""))
	text = decorate(treeDepth, text, os.path.basename(relative_filepath))

	#write out
	directory = os.path.dirname(destPath)
	if not os.path.exists(directory):
		os.makedirs(directory)
	open(destPath, "w").write(text);

for not_nice_root, dirs, files in os.walk(sourceDir):
	root = not_nice_root if not_nice_root.endswith("/") else (not_nice_root + "/")
	for filename in fnmatch.filter(files, '*.html'):		
		fullPath = root + filename
		relativePath = fullPath[len(sourceDir):]
		print relativePath
		build(relativePath)
