# Topic: class ManualComment in python
# Author: Xuhua Huang
#
# Last updated: May  25, 2021
# Created on: May 25, 2021
#
# __init__ function
# __eq__, __ne__, and @property
#

class ManualComment:
    def __init__(self, id: int, text: str):
        self.__id: int = id
        self.__text: str = text

    @property
    def id(self):
        return self.__id

    @property
    def text(self):
        return self.__text

    '''
    repr() function returns a printable representational string of the given object
    self.__class.__name__(self.id, self.text)
    ManualComment(id, text)
    '''

    def __repr__(self):
        return "{}(id = {}, text = {})".format(self.__class__.__name__, self.id, self.text)

    def __eq__(self, other):
        if other.__class is self.__class__:
            return (self.id, self.text) == (other.id, other.text)
        else:
            return NotImplemented

    def __ne__(self, other):
        result = self.__eq__(other)
        if result is NotImplemented:
            return NotImplemented
        else:
            return not result

    def __hash__(self):
        return hash((self.__class__, self.id, self.text))

    def __lt__(self, other):
        if other.__class__ is self.__class__:
            return (self.id, self.text) < (other.id, other.text)
        else:
            return NotImplemented

    def __le__(self, other):
        if other.__class__ is self.__class__:
            return (self.id, self.text) <= (other.id, other.text)
        else:
            return NotImplemented

    def __gt__(self, other):
        if other.__class__ is self.__class__:
            return (self.id, self.text) > (other.id, other.text)
        else:
            return NotImplemented

    def __ge__(self, other):
        if other.__class__ is self.__class__:
            return (self.id, self.text) >= (other.id, other.text)
        else:
            return NotImplemented


def main():
    my_comment = ManualComment(1, "Hello world with id 1")
    print(my_comment.__repr__())
    ur_comment = ManualComment(2, "Hello world with id 2")
    print(ur_comment.__repr__())
    print(my_comment.__le__(ur_comment))  # expecting true


if __name__ == '__main__':
    main()
