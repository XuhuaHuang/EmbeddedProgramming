# Hands on with pytest framework
# Running multiple tests with CLI
# Author: Xuhua Huang
#
# Last updated: July 10, 2021
# Created on: July 10, 2021
#

import pytest

"""
pytest will run all all files of the form of the following:
"test_*.py" or "*_test.py" in the current directory
following generally test discovery rules
"""


def force_crash():
    raise SystemExit(1)


def test_force_crash():
    with pytest.raises(SystemExit):
        force_crash()


"""
Execute this test with "quiet" flag
Linux: $ pytest -q test_02_multiple_test.py
Windows:
PS %Directory%> python -m pytest -q 'test_02_multiple_tests.py'
.                                                                                                                [100%]
1 passed in 0.03s
"""


# Group multiple tests in a class
# pytest will discover both methods prefixed with "test_*"
class TestClass:
    def test_one(self):
        some_str = "This is a simple string"
        assert 'h' in some_str

    def test_two(self):
        classic = 'Hello, world'
        try:
            assert hasattr(classic, 'check')
        except AssertionError:
            print('An expected assertion error has occurred in method test_two')


"""
====================================================== FAILURES =======================================================
_________________________________________________ TestClass.test_two __________________________________________________

self = <test_02_multiple_tests.TestClass object at 0x000002666472C9A0>

    def test_two(self):
        classic = 'Hello, world'
>       assert hasattr(classic, 'check')
E       AssertionError: assert False
E        +  where False = hasattr('Hello, world', 'check')

test_02_multiple_tests.py:44: AssertionError
=============================================== short test summary info ===============================================
FAILED test_02_multiple_tests.py::TestClass::test_two - AssertionError: assert False
1 failed, 2 passed in 0.14s
"""

"""
To run a specific method within a module, use the :: separator
PS %Directory%> python -m pytest -q test_02_multiple_tests.py::test_force_crash
.                                                                                                                [100%] 
PS %Directory%> python -m pytest -q test_02_multiple_tests.py::TestClass::test_one
.                                                                                                                [100%]
"""


@pytest.mark.custom
def test_mark():
    print('This is a customized pytest mark to run')
    assert True


"""
To run the test above, use the -m flag, which stands for "mark"
PS %Directory%> python -m pytest -m custom
================================================= test session starts =================================================
platform win32 -- Python 3.9.6, pytest-6.2.4, py-1.10.0, pluggy-0.13.1
rootdir: D:\GitHub\EmbeddedProgramming\Fun\Python
collected 20 items / 19 deselected / 1 selected

pytest\test_02_multiple_tests.py .                                                                               [100%]

================================================== warnings summary ===================================================
pytest\test_02_multiple_tests.py:79
  PytestUnknownMarkWarning: Unknown pytest.mark.custom - is this a typo?  You can register custom marks to avoid this 
  warning - for details, see https://docs.pytest.org/en/stable/mark.html
    @pytest.mark.custom

-- Docs: https://docs.pytest.org/en/stable/warnings.html
===================================== 1 passed, 19 deselected, 1 warning in 0.17s =====================================
"""
