# https://leetcode.com/problems/create-a-dataframe-from-list

from typing import List
import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    column_names: List[str] = ['student_id', 'age']
    # call the pd.DataFrame constructor
    # with columns keywords argument
    result = pd.DataFrame(student_data, columns=column_names)
    return result
