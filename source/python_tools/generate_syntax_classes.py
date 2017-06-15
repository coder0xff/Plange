#!/usr/bin/python

import os
from string import Template
import sys

import yaml

from wirth import *

if __name__ != "__main__":
    os.exit(-1)

with open('../syntax.yml', mode='rb') as f:
    specs = yaml.safe_load(f)

for (name, spec) in specs.items():
    header_name = name.lower() + ".hpp"
    header_code = "#ifndef " + name ""
    source_name = name.lower() + ".cpp"
    if "cpp_binary_arithmetic_eval" in spec:
        implementation = "class "
        implementation = spec["cpp_binary_arithmetic_eval"]

