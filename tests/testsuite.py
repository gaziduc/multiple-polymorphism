#!/usr/bin/env python3

import subprocess as sp
from os import listdir

if __name__ == "__main__":

    ok = 0
    ko = 0

    tests = [f for f in listdir("../tests/tests/")]

    for f in tests: 
        res = sp.run(["python3", "../tests/tests/" + f], capture_output=True)
        if res.returncode == 0:
            print("[OK] " + f)
            ok += 1
        else:
            print("[KO] " + f + "   ", end='')
            print(res.stdout.decode("utf-8"))
            ko += 1

    print('\nOK -> ' + str(ok) + '   KO -> ' + str(ko))
