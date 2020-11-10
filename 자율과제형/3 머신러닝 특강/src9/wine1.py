# 2-1 저장하기
# 특징은 맨마지막 속성임! 독버섯은 OX형 모델 wine 경우에는 회귀형 그루핑 모델

import urllib.request as req
import os.path

save_path = '../DATA/WINE/'
file_name = save_path+"winequality-whitewine.csv"
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-white.csv"

#폴더생성
if not os.path.exists(save_path):
    os.mkdir(save_path)
    print("make dir ok")

#파일저장
if not os.path.exists(file_name):
    req.urlretrieve(url, file_name)
    print("save data ok")

print("end download ok")