import glob
import os.path as path
import sys
import time


class Checker:
    def __init__(self, ts, fnames):
        self._ts = ts
        self._fnames = fnames

    def run(self):
        return any([self._ts < path.getmtime(fname) for fname in self._fnames])


def main():
    ts = int(sys.argv[1]) / 10**9
    files = glob.glob('*')
    checker = Checker(ts, files)
    while True:
        if checker.run():
            return
        time.sleep(0.1)


try:
    main()
except KeyboardInterrupt:
    exit(1)
