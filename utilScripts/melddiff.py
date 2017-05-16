#!/usr/bin/python

# This is a script that loads up when git diff is run.
# It has been configured using git config --global diff.external <pathToThisFile>

import sys
import os

os.system('meld "%s" "%s"' % (sys.argv[2], sys.argv[5]))
