from keras.datasets import mnist
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation
from keras.optimizers import Adam 
from keras.utils import np_utils


# (1) MNIST 데이터 읽어 들이기 ------------------------------------------
(X_train, y_train), (X_test, y_test) = mnist.load_data()

# (2) 데이터 가공 -----------------------------------------------------
# 데이터를 float32 자료형으로 변환하고 정규화
X_train = X_train.reshape(60000, 784).astype('float32')
X_test  = X_test.reshape(10000, 784).astype('float')
X_train /= 255
X_test  /= 255

# 레이블 데이터를 0-9까지의 카테고리를 나타내는 배열로 변환
y_train = np_utils.to_categorical(y_train, 10)
y_test  = np_utils.to_categorical(y_test, 10)

# (2) 모델 구조 정의---------------------------------------------------
model = Sequential()
model.add(Dense(512, input_shape=(784,)))    # 입력층
model.add(Activation('relu'))
model.add(Dropout(0.2))
model.add(Dense(512))                       # 은닉층
model.add(Activation('relu'))
model.add(Dropout(0.2))
model.add(Dense(10))                        # 출력층
model.add(Activation('softmax'))

# (3) 모델 구축 ---------------------------------------------------
model.compile(
    loss='categorical_crossentropy',   # 다중분류 손실 함수
    optimizer=Adam(),                  # 최적화 알고리즘
    metrics=['accuracy'])

# (4) 데이터 훈련하기 ----------------------------------------------
hist = model.fit(X_train, y_train)

# (5) 테스트 데이터로 평가 -----------------------------------------
score = model.evaluate(X_test, y_test, verbose=1)
print('loss=', score[0])
print('accuracy=', score[1])