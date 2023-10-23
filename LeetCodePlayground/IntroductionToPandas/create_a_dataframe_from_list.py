# https://leetcode.com/problems/create-a-dataframe-from-list

from typing import List
import unittest
import pandas as pd


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    column_names: List[str] = ['student_id', 'age']
    # call the pd.DataFrame constructor
    # with columns keywords argument
    result = pd.DataFrame(student_data, columns=column_names)
    return result

class TestCreateDataFrameSolution(unittest.TestCase):

    def test_solution(self):
        student_data: List[List[int]] = [
            [1, 15],
            [2, 11],
            [3, 11],
            [4, 20]
        ]
        result: pd.DataFrame = createDataframe(student_data=student_data)

        pd.testing.assert_series_equal(pd.Series(result['student_id']),
                                       pd.Series([1, 2, 3, 4]),
                                       check_names=False)
        pd.testing.assert_series_equal(pd.Series(result['age']),
                                       pd.Series([15, 11, 11, 20]),
                                       check_names=False)

if __name__ == '__main__':
    unittest.main()
