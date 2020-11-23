# IT교육센터 파이썬 기반 인공지능 수업
## 수업을 들으며 한줄 한줄 기록했던 내용에다가 이번 제출을 위해 복습하며 주석을 추가하여 정리했습니다. 클릭하여 꼭 확인해주시기 바랍니다.
Pycharm을 이용하여 정리했습니다.\
python version == 3.8.6\
pycharm edition version == 2019.3.3\
tensorflow version == 1.11 \
keras version == 2.2.2

### src2-5. 1주차에 해당하는 내용입니다.
python와 matplotlib, pandas와 numpy에 관한 내용을 전반적으로 학습했고, 웹에서 데이터를 크롤링, 스크레이핑 하여 데이터를 가져오는 기술에 대해서도 학습했습니다.
아래 예제는 영화 순위 정보를 크롤링해서 보여주는 예제입니다. 

#### 코드리뷰
    from bs4 import BeautifulSoup
    import urllib.request as req

    # urlopen()으로 데이터 수집
    url = "https://movie.naver.com/movie/sdb/rank/rmovie.nhn"
    res = req.urlopen(url)

    # BeautifulSoup으로 분석
    soup = BeautifulSoup(res, "html.parser")

    movie = soup.select_one("#old_content > table > tbody > tr:nth-child(2) > td.title > div > a").string

    movies = soup.select("#old_content > table > tbody > tr > td.title > div > a")
    print ("movies =", movies, len(movies))
    number = 1
    for move in movies : #move는 자동으로 객체형으로 정해진다
        print(number, move.string) #string을 붙이면 앞뒤의 <> <>가 떨어져나간다
        if number >= len(movies)/10: break;
        number+=1

    print()
    for i in range(2,11):
        x = "#old_content > table > tbody > tr:nth-child("+str(i)+") > td.title > div > a"
        moviem = soup.select_one(x).string
        print(moviem)

    //BeautifulSoup이라는 package를 통해 영화정보를 크롤링 하는 함수입니다. 서버에 url 요청을 위해 urllib이라는 패키지도 사용합니다.
[src4/movie.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src4/movie.py)

    from selenium import webdriver

    # 크롬 브라우저 제어 드라이버 생성
    driver=webdriver.Chrome('C:\Program Files/WebDriver/chromedriver.exe')

    # 크롬 브라우저 드라이버를 활용한 원격 웹 페이지 제어
    # URL 열기
    driver.get("https://www.naver.com")

    # WEB 페이지의 특정 요소에 접근
    # //*[@id="query"]
    driver.find_element_by_xpath('//*[@id="query"]').send_keys('안녕하세요.')
    
    //scraping을 위해 selenium의 webdriver package를 이용합니다.
[src4/scraping.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src4/scraping.py)

### src6-10. 2주차에 해당하는 내용입니다.
본격적으로 tensorflow의 다양한 activation function error function, gradient algorithm을 이용해 csv파일을 머신러닝 합니다. 
아래 예제는 SVM을 이용해서 잎 수, 넓이 등의 feature를 통해 붓꽃의 종류를 예측하는 아주 보편적인 예제입니다.

#### 코드리뷰
    if not os.path.exists(CSV_FILE):
    print("Download DATA")
    request.urlretrieve(DATA_URL, CSV_FILE)

    # 붓꽃 CSV 데이터 수집
    csv = pd.read_csv(CSV_FILE)
    if DEBUG :
        print('type(csv) =>', type(csv))
        print(csv.columns)
        print(csv.index)
        print(csv.iloc[0,2])

    # 필요한 데이터(column) 추출
    print(csv.columns)
    print(csv.index)

    csv_data  = csv[["SepalLength","SepalWidth","PetalLength","PetalWidth"]]
    csv_label = csv["Name"]

    # 학습 데이터와 테스트 전용 데이터 분류
    train_data, test_data, train_label, test_label = \
        train_test_split(csv_data, csv_label)

    # 데이터 학습 & 예측
    clf = svm.SVC()
    clf.fit(train_data, train_label)    # 학습
    pre = clf.predict(test_data)        # 테스트
    print('type(clf)=', type(clf))

    # 정확도 검사
    ac_score = metrics.accuracy_score(test_label, pre)
    print("정답률 =", ac_score)
    
    //나머지 예제 파일들도 대부분 위와같은 순서로 구현했습니다. 
[src6/iris-train2.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src6/iris-train2.py)

### src11-15. 3주차에 해당하는 내용입니다.
keras를 이용해서 심층 신경망을 활용해 csv파일을 딥러닝 합니다. 
아래 예제는 컨벌루셔널 뉴럴넷을 통해 이미지를 학습하여 textset을 101개의 클래스중 하나로 예측하는 아주 보편적인 예제입니다.
loss functiond으로는 'binary_crossentropy'를 optimizer로 'rmsprop'를 사용했으며 CNN과 Maxpooling layer에 두번 통과시킨 후 드롭아웃을 거쳐 softmax로 classification합니다. 

#### 코드리뷰
    # 데이터 정규화
    X_train = X_train.astype("float") / 256
    X_test  = X_test.astype("float")  / 256
    print('X_train shape:', X_train.shape)

    # 모델 구축하기
    model = Sequential()
    model.add(Convolution2D(32, 3, 3, 
        border_mode='same',
        input_shape=X_train.shape[1:]))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Convolution2D(64, 3, 3, border_mode='same'))
    model.add(Activation('relu'))
    model.add(Convolution2D(64, 3, 3))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Flatten()) # --- (※3) 
    model.add(Dense(512))
    model.add(Activation('relu'))
    model.add(Dropout(0.5))
    model.add(Dense(nb_classes))
    model.add(Activation('softmax'))

    # 모델 생성
    model.compile(loss='binary_crossentropy',
        optimizer='rmsprop',
        metrics=['accuracy'])

    # 모델 훈련하기
    hdf5_file = "../DATA/5obj-model.hdf5"
    if os.path.exists(hdf5_file):
        model.load_weights(hdf5_file)
    else:
        model.fit(X_train, y_train, batch_size=32, nb_epoch=50)
        model.save_weights(hdf5_file)

    # 모델 평가
    pre = model.predict(X_test)
    for i,v in enumerate(pre):
        pre_ans = v.argmax()
        ans = y_test[i].argmax()
        dat = X_test[i]
        if ans == pre_ans: continue
        print("[NG]", categories[pre_ans], "!=", categories[ans])
        print(v)
        fname = "image/error/" + str(i) + "-" + categories[pre_ans] + \
            "-ne-" + categories[ans] + ".png"
        dat *= 256
        img = Image.fromarray(np.uint8(dat))
        img.save(fname)
    score = model.evaluate(X_test, y_test)
    print('loss=', score[0])
    print('accuracy=', score[1])
    
    //90% 의 정확도를 얻었습니다.
[src13/caltech101_keras2.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/3%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%ED%8A%B9%EA%B0%95/src13/caltech101_keras2.py)

### 수료증입니다.
<img src="https://user-images.githubusercontent.com/67677983/99956337-340ee580-2dc9-11eb-97aa-eb3048168cb5.png" width="400">
