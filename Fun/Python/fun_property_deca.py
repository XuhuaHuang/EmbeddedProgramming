# Topic: property decorator in Python along with setter and getter
#
# Author: Xuhua Huang
# Last updated: Jun 28, 2021
# Created on: Jun 28, 2021

import datetime

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

    ''' Add setter for class variable wage_raise_index '''
    @classmethod
    def set_wage_raise_index(cls, new_amount):
        if new_amount >= 0:
            cls.wage_raise_index = new_amount
        else:
            raise ValueError('New wage raise index is invalid')

    ''' Use @classmethod decorator to write alternative constructor '''
    ''' Use case: 'Xuhua-Huang-60_000' initialization '''
    @classmethod
    def from_string(cls, emp_str):
        first_name, last_name, salary = emp_str.spilt('-')
        return cls.__init__(first_name, last_name, salary)

    @staticmethod
    def is_workday(day):
        if day.weekday() == 5 or day.weekday() == 6:
            return False
        return True


""" Test Cases for Employee class """
def main():
    emp_xuhua = Employee('Xuhua', 'Huang', 60000)
    ''' Test constructor '''
    print(emp_xuhua.first_name)  # Xuhua
    print(emp_xuhua.last_name)  # Huang
    print(emp_xuhua.fullname)  # Xuhua Huang
    print(emp_xuhua.email)  # xuhua.huang@brainboxai.ca

    ''' Apply raise and verify '''
    emp_xuhua.apply_raise()
    print(emp_xuhua.salary)  # 60_000 * 1.05

    ''' Change wage_raise_index with static method and verify '''
    Employee.set_wage_raise_index(1.06)
    emp_xuhua.apply_raise()
    print(emp_xuhua.salary)  # 60_000 * 1.05 * 1.06

    del emp_xuhua.fullname  # Delete name and set to None

    ''' Test case for static method is_workday() '''
    date_1 = datetime.date(2021, 6, 28)  # Monday, is_workday() returns True
    print(Employee.is_workday(date_1))


if __name__ == '__main__':
    main()
