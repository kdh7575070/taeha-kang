import matplotlib.pyplot as plt
import pandas as pd
from matplotlib import font_manager as fm   # 한글 폰트 설정

# 데이터 변수 선언 -------------------------------------
TEMP_CSV = "./tem10y.csv"

# ----------------------------------------------------
# 데이터 준비
# ----------------------------------------------------
df = pd.read_csv(TEMP_CSV, encoding="utf-8")

# 월별 평균 구하기
# 일에 대한 것들은 섞여있어 그루핑이 불가능했지만 월은 같은 월끼리 묶여있기 때문에 그루핑이 가능하다
g = df.groupby(['월'])['기온']
gg = g.sum() / g.count() #묶인 [월]그룹끼리의 [기온]합과 수를 구할 수 있다

# ----------------------------------------------------
# 데이터 출력
# ----------------------------------------------------
# 한글 폰트 설정 ---------------------------------------
font_path = r'C:\Windows\Fonts\malgun.ttf' #안그럼 네모로 깨져버린다
font_name = fm.FontProperties(fname=font_path).get_name()
plt.rc('font', family=font_name)
plt.rc('axes', unicode_minus=False) #마이너스 부호 나오면 이거 없으면 네모로 깨진다
print(gg)

gg.plot() #DataFrame에서 제공한 그래프 함수
plt.title("월별기온")
plt.savefig("tem-month-avg.png")
plt.show()

