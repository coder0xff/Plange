import os
import fnmatch
from htmldom import htmldom
import pdb


def strip(text):
	dom = htmldom.HtmlDom().createDom(text)
	elem = dom.find("div[id=sites-canvas-main-content]")
	elem = elem.find("div[dir=ltr]")
	return "<meta charset='utf-8'/>\n<html>\n<body>" + elem.html()[25:][:-6] + "</body>\n</html>\n"

def fixup(text):
	return text.replace("https://sites.google.com/site/plangelanguage", "http://plange.tech")

def migrate(relative_filepath):
	#read in
	text = open("/home/brent/backup_plange_site/" + relative_filepath).read()

	#apply transformations
	text = strip(text)
	text = fixup(text)

	#write out
	dest = "/home/brent/plange_site/" + relative_filepath;
	directory = os.path.dirname(dest)
	if not os.path.exists(directory):
		os.makedirs(directory)
	open(dest, "w").write(text);

# This script overwrites the ~/plange_site directory, so it's disabled for safety

#for root, dirs, files in os.walk("/home/brent/plange_site"):
#	for filename in fnmatch.filter(files, '*.html'):
#		fullPath = root + "/" + filename
#		relativePath = fullPath[len("/home/brent/plange_site/"):]
#		print relativePath
#		migrate(relativePath)