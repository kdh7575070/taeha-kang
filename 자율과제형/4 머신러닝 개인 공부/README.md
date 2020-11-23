# 모두의 딥러닝 유투브강의 학습 정리
## 약 50편의 강의를 통해 이론수업을 병행하면서 더욱 깊이 공부했습니다.
특강 3주차 때는 딥러닝의 이론적인 내용에 대한 설명이 부족했고 Keras를 사용함으로 인해 세부적인 parameter를 조정하면서 그것이 모델학습에 기여하는 영향을 알 수 없었기 때문에 딥러닝 기초이론부터
차근차근 학습했습니다. 또한 특강수업 때 끝내지 못한 MNIST데이터셋 기반 손글씨인식 문제를 스스로 해결해보았습니다. 
Pycharm을 이용하여 정리했습니다.\
python version == 3.8.6\
pycharm edition version == 2019.3.3\
tensorflow version == 1.11 \
keras version == 2.2.2

### src9에 해당하는 내용입니다.
CNN을 통해 손글씨를 예측하는 아주 보편적인 예제입니다. Tensorflow를 활용해서 파라미터값을 세부적으로 조정했습니다.

#### 코드리뷰
    import tensorflow as tf
    from tensorflow.examples.tutorials.mnist import input_data

    tf.set_random_seed(777)

    mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

    nb_classes = 10
    
    #뉴럴넷 생성
    X = tf.placeholder(tf.float32, shape=[None, 784])
    Y = tf.placeholder(tf.float32, shape=[None, nb_classes])

    W1 = tf.Variable(tf.random_normal([784, 256]), name='weight1')
    b1 = tf.Variable(tf.random_normal([256]), name='bias1')
    layer1 = tf.nn.relu(tf.matmul(X, W1) + b1)

    W2 = tf.Variable(tf.random_normal([256, 256]), name='weight2')
    b2 = tf.Variable(tf.random_normal([256]), name='bias2')
    layer2 = tf.nn.relu(tf.matmul(layer1, W2) + b2)

    W3 = tf.Variable(tf.random_normal([256, nb_classes]), name='weight3')
    b3 = tf.Variable(tf.random_normal([nb_classes]), name='bias3')
    hypothesis = tf.nn.softmax(tf.matmul(layer2, W3) + b3)

    #cost 함수 정의
    cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1)) #ReLU의 코스트는 이렇게 안쓴다 -> lab-10-2 파일로가서 확인가능
    train = tf.train.AdamOptimizer(learning_rate=0.001).minimize(cost)

    correct_prediction = tf.equal(tf.argmax(hypothesis, 1), tf.argmax(Y, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

    training_epochs = 15
    batch_size = 100
  
    #traing 시작
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())

        for epoch in range(training_epochs):
            avg_cost = 0
            total_batch = int(mnist.train.num_examples / batch_size)

            for i in range(total_batch):
                batch_xs, batch_ys = mnist.train.next_batch(batch_size)
                c, _ = sess.run([cost, train], feed_dict={X:batch_xs, Y:batch_ys})
                avg_cost += c /total_batch

        print("Epoch: ", "%04d" %(epoch+1), "Cost =", "{:.9f}".format(avg_cost))

        print("Accuracy: ", accuracy.eval(session=sess, feed_dict={X:mnist.test.images, Y:mnist.test.labels}))
        
    // 자율과제형/3머신러닝특강/src13/에서 와 같이 두개의 CNN과 softmax함수를 통해 classification 했으나 여기서는 tensorflow를 이용하여 세부적인 파라미터 값을 수월하게 조정할 수 있었음
[tf_9-MNIST_2.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/4%20%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D%20%EA%B0%9C%EC%9D%B8%20%EA%B3%B5%EB%B6%80/tf_9-MNIST_2.py)

### 참고사항
이번 강의를 학습하는 중에 Relu funtion의 dying relu 현상에 대해 이해가 안되는 부분이 있어 구글링, 논문분석을 통해 의문점을 해결하기도 했습니다.
정리한 내용은 [여기](https://brunch.co.kr/@kdh7575070/27)서 확인하실 수 있습니다.
