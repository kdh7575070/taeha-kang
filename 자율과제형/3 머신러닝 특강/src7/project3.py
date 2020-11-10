from sklearn import model_selection, svm, metrics

DEBUG = False #True 해버리면 안된다!! 실행 코드 볼려고 True 해놓은거고 실제는 False로 해야한다

#CSV파일을 읽어 들이고 가공하기
def load_csv(fname):
    labels = []
    images = []
    with open(fname, 'r') as f:
        #train.csv 파일에 있는 데이터 읽어서 데이터 셋과 라벨 분리
        for line in f:
            cols = line.split(",")
            if DEBUG:
                print('len(cols) = {}'.format(len(cols)))
                print('cols DATA => {}'.format(cols))

            if len(cols) < 2 : continue #라인 구분문자는 데이터가 아니므로 스킵

            labels.append(int(cols.pop(0))) #데이터 리스트에서 첫번째 요소-라벨 꺼내기
            vals = list(map(lambda n: int(n)/256, cols)) #나머지 784개 픽셀 리스트를 데이터리스트로 변환
                                                         # 256(명암데이터 데이터 범위축소)로 정규화 overfiting(너무큰오류값)방지
            images.append(vals)
            if DEBUG: print('vals DATA=>', vals)

        #딕셔너리 타입으로 반환
    return {"labels" : labels, "images": images}

#학습 및 테스트용 데이터 로딩
data = load_csv("./mnist/train.csv")
test = load_csv("./mnist/t10k.csv")
print("Data =>", data)

# 학습하기
print("Learning..")
clf = svm.SVC(gamma='scale') #디프리케이티드되서 써줘야한다이제
clf.fit(data["images"], data["labels"])  # 이미지의 로데이타와 라벨을 줘서 학습

#예측하기
print("Testing..")
predict = clf.predict(test["images"])

#결과 확인하기
print("Confirming..")
ac_score = metrics.accuracy_score(test["labels"], predict)
cl_report = metrics.classification_report(test["labels"], predict)
print("정답률 =", ac_score)
print("리포트 =",)
print(cl_report)