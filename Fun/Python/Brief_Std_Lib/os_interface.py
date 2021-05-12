# This file contains notes and examples for file systems paths in Python
# Topic: file system
#
# Author: Xuhua Huang
# Created: May 12, 2021
# Last updated: May 12, 2021

import os
import shutil
from pathlib import Path


def __main__():
    print("Current working directory: " + os.getcwd())
    os.chdir('../Automated_Excel')
    print("Working directory changed to: " + os.getcwd())

    print("Printing full list of module functions: ")
    for mod_func in dir(os):
        print(mod_func)

    # Basic Use of Filesystem Paths #
    print("Printing file in \"D:\GitHub\EmbeddedProgramming\Fun\Python\" with wildcard **/*.py")
    python_dir = Path("D:\GitHub\EmbeddedProgramming\Fun\Python")
    if python_dir.exists:
        for file_name in list(python_dir.glob('**/*.py')):
            print(file_name)


if __name__ == '__main__':
    __main__()
