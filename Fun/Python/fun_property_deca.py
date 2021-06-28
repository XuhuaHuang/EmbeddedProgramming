# Topic: property decorator in Python along with setter and getter
#
# Author: Xuhua Huang
# Last updated: Jun 28, 2021
# Created on: Jun 28, 2021

class Employee:
    wage_raise_index = 1.05

    def __init__(self, first_name: str = 'Unknown', last_name: str = 'Unknown', annual_salary: int = None):
        self.first_name = first_name
        self.last_name = last_name
        self.salary = annual_salary

    @property
    def email(self):
        return '{}.{}@brainboxai.ca'.format(self.first_name.lower(), self.last_name.lower())

    @property
    def fullname(self):
        return '{} {}'.format(self.first_name, self.last_name)

    @fullname.setter
    def fullname(self, user_name):
        self.first_name, self.last_name = user_name.spilt(' ')

    @fullname.deleter
    def fullname(self):
        print('Deleting Name...')
        self.first_name = None
        self.last_name = None
        print('Done Deleting.')

    def apply_raise(self, raise_index: int = wage_raise_index):
        self.salary *= raise_index


""" Test Cases for Employee class """
def main():
    emp_xuhua = Employee('Xuhua', 'Huang', 60000)
    ''' Test constructor '''
    print(emp_xuhua.first_name)  # Xuhua
    print(emp_xuhua.last_name)  # Huang
    print(emp_xuhua.fullname)  # Xuhua Huang

    ''' Apply raise and verify '''
    emp_xuhua.apply_raise()
    print(emp_xuhua.salary)

    del emp_xuhua.fullname  # Delete name and set to None


if __name__ == '__main__':
    main()
