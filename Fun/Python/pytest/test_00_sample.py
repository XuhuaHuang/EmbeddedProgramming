# Hands on with pytest framework
# Author: Xuhua Huang
#
# Last updated: July 8, 2021
# Created on: July 8, 2021
#

def increment_by_one(x: int):
    return x + 1


def test_increment():
    assert increment_by_one(3) == 5


"""
To execute this file, open a terminal and navigate to the current directory
Run the following command:
$ pytest

if the above command does not work, try the following:
$ python -m pytest

Example output:

PS D:\GitHub\EmbeddedProgramming\Fun\Python\pytest> python -m pytest
================================================= test session starts =================================================
platform win32 -- Python 3.9.6, pytest-6.2.4, py-1.10.0, pluggy-0.13.1
rootdir: D:\GitHub\EmbeddedProgramming\Fun\Python\pytest
collected 1 item

test_00_sample.py F                                                                                              [100%]

====================================================== FAILURES =======================================================
___________________________________________________ test_increment ____________________________________________________

    def test_increment():
>       assert increment_by_one(3) == 5
E       assert 4 == 5
E        +  where 4 = increment_by_one(3)

test_00_sample.py:13: AssertionError
=============================================== short test summary info ===============================================
FAILED test_00_sample.py::test_increment - assert 4 == 5
================================================== 1 failed in 0.17s ==================================================
"""
