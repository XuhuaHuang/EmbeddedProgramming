# Hands on with pytest framework
# Combining tests with parametrization
# Author: Xuhua Huang
#
# Last updated: July 8, 2021
# Created on: July 8, 2021
#

import pytest

"""
Parametrize a single test definition, and pytest will create variants of the test
with the specified parameters

Run with the following command:
python -m pytest test_01_parametization.py
"""


# Define a function to determine whether a string is a Palindrome
def is_palindrome(word: str):
    return word[:].strip().lower() == word[::-1].strip().lower()


# Test cases may look like the following
def test_is_palindrome_empty_string():
    assert is_palindrome("")


def test_is_palindrome_single_character():
    assert is_palindrome("a")


def test_is_palindrome_mixed_casing():
    assert is_palindrome("Bob")


def test_is_palindrome_with_spaces():
    assert is_palindrome("Never odd or even")


def test_is_palindrome_with_punctuation():
    assert is_palindrome("Do geese see God?")


def test_is_palindrome_not_palindrome():
    assert not is_palindrome("abc")


def test_is_palindrome_not_quite():
    assert not is_palindrome("abab")


"""
Common pattern:
def test_is_palindrome_<in some situation>():
    assert is_palindrome("<some string>")
    
use @pytest.mark.parametrize() to fill in this shape with different values
reducing test code significantly:
"""


@pytest.mark.parametrize("palindrome", [
    "",
    "a",
    "Bob",
    "Never odd or even",
    "Do geese see God?",
])
def test_is_palindrome(palindrome):
    assert is_palindrome(palindrome)


@pytest.mark.parametrize("non_palindrome", [
    "abc",
    "abab",
])
def test_is_palindrome_not_palindrome(non_palindrome):
    assert not is_palindrome(non_palindrome)


@pytest.mark.parametrize("maybe_palindrome, expected_result", [
    ("", True),
    ("a", True),
    ("Bob", True),
    ("Never odd or even", True),
    ("Do geese see God?", True),
    ("abc", False),
    ("abab", False),
])
def test_is_palindrome(maybe_palindrome, expected_result):
    assert is_palindrome(maybe_palindrome) == expected_result
