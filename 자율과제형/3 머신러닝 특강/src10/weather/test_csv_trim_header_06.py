# 만들었던 웨더 모듈가져와서 쓰는것
import unittest
import pandas as pd
from src10.weather import csv_trim_header_01 as cth

class TestCsvTrimHeader(unittest.TestCase):

    def test_trim(self):
        df = pd.read_csv(cth.TEMP_CSV, encoding="utf-8")
        v = int(df['연'][0:1][0])
        self.assertEqual(v, 2006)

if __name__ == '__main__':
    unittest.main()