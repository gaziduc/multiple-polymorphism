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
    se = pln.se.disc(10)
    image = data.camera()

    # WHEN / THEN
    try:
        out = pln.morpho.opening(image, se)
        sys.exit(0)
    except Exception as err:
        print(err, end='')
        sys.exit(1)
