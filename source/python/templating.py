import codecs

def gen(templateFilePathname, outputFile, dictionary):
	with codecs.open(templateFilePathname, 'r', "utf-8") as templateFile:
		template = templateFile.read()
	
	for name, value in dictionary.iteritems():
		template = template.replace("%" + name + "%", value)
		
	with codecs.open(outputFile, "w", "utf-8") as out:
		out.write(template)
		
