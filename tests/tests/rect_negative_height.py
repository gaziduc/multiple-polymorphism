#!/usr/bin/env python3

from skimage import data, io
import os
import sys
import inspect

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
work_dir = os.path.dirname(parent_dir)
sys.path.insert(0, work_dir + '/build')

import pylene as pln


if __name__ == '__main__':

    # GIVEN
    width = 5
    height = -3

    # WHEN / THEN
    try:
        se = pln.se.rectangle(width, height)
        sys.exit(1)
    except Exception:
        sys.exit(0) # if exception then [OK]
