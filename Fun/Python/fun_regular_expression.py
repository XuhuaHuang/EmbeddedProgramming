# Topic: regular expression in Python
# search for specific pattern in text
#
# Author: Xuhua Huang
# Last updated: Jun 30, 2021
# Created on: Jun 30, 2021

import re

sentence = 'Start a sentence and then bring it to an end'

text_to_search = '''
abcdefghijklmnopqurtuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
1234567890

Ha HaHa

MetaCharacters (Need to be escaped):
. ^ $ * + ? { } [ ] \ | ( )
e.g. re.compile.finditer(r'\.')

xhuang@brainboxai.com

321-555-4321
123.555.1234
123*555*1234
800-555-1234
900-555-1234

Mr. Schafer
Mr Smith
Ms Davis
Mrs. Robinson
Mr. T
'''

def main():
    """
    Print a raw string
    Raw strings do not implement escape sequences
    """
    print(r'\tTab with raw string format')
    print('\tTab')

    """ re.compile.finditer() method """
    pattern = re.compile(r'abc')
    matches = pattern.finditer(text_to_search)

    for match in matches:  # case sensitive match
        print(match)  # <re.Match object; span=(1, 4), match='abc'>

    # print equivalent with span output from the previous line
    print(text_to_search[1:4])

    """ Match digit 0 - 9 """
    digits_pattern = re.compile(r'\d')
    matches = digits_pattern.finditer(text_to_search)
    print("\nPrinting all matches for 0 - 9 digits")
    for match in matches:
        print(match)

    """ Match 'not a digit' with 'W' """
    not_digits = re.compile(r'\W')
    matches = not_digits.finditer(text_to_search)
    print("\nPrinting all matches for Non-a-digit")
    for match in matches:
        print(match)

    """ Match pattern with sentence """
    sentence_pattern = re.compile(r'^Start')
    # Use ^ to indicate start of a string
    # In this case, the match has to start with the string "Start"
    # Use $ to indicate end of a string
    # for example:
    # sentence_pattern = re.compile(r'end$')
    # print(sentence_pattern.finditer(sentence))
    # <re.Match object; span=(41, 44), match='end'>
    matches = sentence_pattern.finditer(sentence)
    print("\nPrinting all matches for sentence match")
    for match in matches:
        print(match)  # <re.Match object; span=(0, 5), match='Start'>

    """
    Exercise: look for the following character
    321-555-4321
    123.555.1234
    123*555*1234
    800-555-1234
    900-555-1234
    """
    pattern = re.compile(r'\d\d\d.\d\d\d.\d\d\d\d')
    # 3 digits, 3 digits and 4 digits concatenated together with all separator
    matches = pattern.finditer(text_to_search)
    print("\nPrinting all matches that are likely to be phone numbers")
    for match in matches:
        print(match)

    """ Match phone numbers specifically with dashes and asterisks """
    pattern = re.compile(r'\d\d\d[-*]\d\d\d[-*]\d\d\d\d')
    matches = pattern.finditer(text_to_search)
    print("\nPrinting all phone numbers concatenated with dashes and asterisks")
    for match in matches:
        print(match)

    """ Match phone numbers with Quantifiers """
    pattern = re.compile(r'\d{3}[-*]\d{3}[-*]\d{4}')
    matches_quantifier = pattern.finditer(text_to_search)
    print("\nPrinting all phone numbers concatenated with dashes and asterisks with Quantifiers")
    for match in matches_quantifier:
        print(match)
    print(f"Two match cases yield the same result: {matches_quantifier == matches}")


if __name__ == '__main__':
    main()
