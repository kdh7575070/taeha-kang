# 모듈 로딩 ------------------------------------
from matplotlib import pyplot as plt        # 그래프용
from matplotlib import font_manager as fm   # 한글 폰트 설정
import numpy as np
import matplotlib as mpl
import pandas as pd

org = pd.read_csv("../DATA/bmi.csv")
print("org.columns =>", org.columns)
print("org.index =>", org.index)

tbl = pd.read_csv("../DATA/bmi.csv", index_col=2)  # 아무것도 안하면 irist 처럼 나중에 첫행에서 라벨을 따로 지정해야하는데
                                                   # 이렇게 하면 칼럼 2를 라벨로 바로 가져올 수 있다
print("tbl.columns =>", tbl.columns)
print("tbl.index =>", tbl.index)

# 한글 폰트 설정 ---------------------------------------
font_path = r'C:\Windows\Fonts\batang.ttc'
font_name = fm.FontProperties(fname=font_path).get_name()
print(font_name)
plt.rc('font', family=font_name)     # mpl.rcParams['font.family'] = 'Gullim'
plt.rc('axes', unicode_minus=False)  # mpl.rcParams['axes.unicode_minus'] = False #안그러면 음수부분에 엑박뜬다

#분포도 그래프 그리기
plt.scatter(tbl.loc['fat']["weight"], tbl.loc['fat']["height"], c='red', label='fat')
plt.scatter(tbl.loc['normal']["weight"], tbl.loc['normal']["height"], c='yellow', label='normal')
plt.scatter(tbl.loc['thin']["weight"], tbl.loc['thin']["height"], c='purple', label='thin')

plt.legend(loc='upper right')
plt.xlabel('키')
plt.ylabel('몸무게')
plt.savefig("bmi-test.png")
plt.title("BMI지수")
plt.show()