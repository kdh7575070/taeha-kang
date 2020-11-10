# 2-4 그래핑

import matplotlib.pyplot as plt
import pandas as pd

# 데이터변수 선언 -----------------------------------------------------
WINE_CSV='../DATA/WINE/winequality-whitewine.csv'    # CSV파일 저장 경로

# --------------------------------------------------------------------
# 데이터 준비
# --------------------------------------------------------------------

# 데이터 읽기
wine = pd.read_csv(WINE_CSV, sep=";", encoding="utf-8")

# --------------------------------------------------------------------
# 데이터 분석
# --------------------------------------------------------------------

# 품질 데이터별로 그룹을 나누고 분포 조사
count_data = wine.groupby('quality')["quality"].count()
print(count_data)

# 수를 그래프로 그리기
count_data.plot()
plt.savefig("wine-count-plt.png")
plt.show()

