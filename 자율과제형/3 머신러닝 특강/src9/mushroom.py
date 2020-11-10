import urllib.request as req
import os.path
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.model_selection import train_test_split

save_path = '../DATA/MUSH/'
file_name = save_path+"mushroom.csv"
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/mushroom/agaricus-lepiota.data"


#폴더생성
if not os.path.exists(save_path):
    os.mkdir(save_path)
    print("make dir ok")

#파일저장
if not os.path.exists(file_name):
    req.urlretrieve(url, file_name)
    print("save data ok")

print("end download ok")