#!/usr/bin/python

import yaml
import pprint

specsFile = open('../../source/syntax.yml')
specs = yaml.safe_load(specsFile)
specsFile.close()

pprint.pprint(specs)
