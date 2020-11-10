import tensorflow as tf
import numpy as np

#cross_entropy, one_hot, reshape 를 써서 좀 더 fancy한 버전 - 동물분류
xy = np.loadtxt('./DeepLearningZeroToAll-master/data-04-zoo.csv',
                delimiter=',', dtype=np.float32)
x_data = xy[:, 0:-1]
y_data = xy[:, [-1]]

X = tf.placeholder(tf.float32, shape=[None, 16])
Y = tf.placeholder(tf.int32, shape=[None, 1]) #일단 하나로 받는다
#이거때문에 아까 nb_classes 했던거군
nb_classes = 7

W = tf.Variable(tf.random_normal([16, nb_classes], name='weight')) #헷갈림방지였어
b = tf.Variable(tf.random_normal([nb_classes], name='bias'))

Y_one_hot = tf.one_hot(Y, nb_classes) # 0~6 니까 7개짜리 원핫 만들어줘 shape = (None, 1, 7) <- 한차원이 더 더해진다
Y_one_hot = tf.reshape(Y_one_hot, [-1, nb_classes]) #한차원 작게 만들어줘 shape = (None, 7)

logits = tf.matmul(X, W) + b
hypothesis = tf.nn.softmax(logits)
#cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1)) 이렇게하지말고

# cross entropy 함수로 쉽게해보자 - 나중에 조정하기 쉽다
cost_i = tf.nn.softmax_cross_entropy_with_logits(logits=logits,
                                                 labels=Y_one_hot)
cost = tf.reduce_mean(cost_i)

# 트레이닝
train = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)

# 정확도 계산
prediction = tf.argmax(hypothesis, 1) #정확도 계산을 위해 hypothesis를 label화 시키는 것
correct_prediction = tf.equal(prediction, tf.argmax(Y_one_hot, 1)) #실제값과 선택한 onehot에서 선택값(즉 label)을 비교
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) #구한 것들을 float타입으로 저장해서 평균내기

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    # Fit the line
    for step in range(2001):
        sess.run(train, feed_dict={X:x_data, Y:y_data})
        if step % 100 == 0:
            loss, acc = sess.run([cost, accuracy], feed_dict={
                X: x_data, Y: y_data})
            print("Step: {:5}\tLoss:{:.3f}\tAcc:{:.2%}".format(
                step, loss, acc))

    # 정확도 검사
    pred = sess.run(prediction, feed_dict={X:x_data})

    for p, y in zip(pred, y_data.flatten()): #flatten()은 y elements를 평평하게 해주는 것 [[1],[0],... -> [1,0,...
                                             #zip은 각각의 elements를 p,y로 편하게 넘겨주기 위해서 zip으로 묶는 것
        print("[{}] Prediction z: {} True Y: {}".format(p==int(y), p, int(y))) #예측확인