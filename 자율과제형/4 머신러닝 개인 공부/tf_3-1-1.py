import tensorflow as tf

X = [1,2,3]
Y = [1,2,3]

W = tf.Variable(5.)

hypothesis = X * W

#gradient를 사용자가 임의로 조정하고 싶을 때!

#비교위해서 아까 미분때 사용한 그래디언트를 그대로 가지고 오겠다
gradient = tf.reduce_mean((W * X - Y) * X )* 2

cost = tf.reduce_mean(tf.square(hypothesis - Y))
optimizer = tf.train.GradientDescentOptimizer(0.01)

#바로 Minimize하라고 안하고 이 코스트에 맞는 gradient를 계산해달라고 요청하기
#컴퓨터가알아서계산한래디언트얻기
gvs = optimizer.compute_gradients(cost)
#그래디언트적용시키기 - 이 사이에서 gvs를 수정해서 넘겨줄수있다
apply_gradients = optimizer.apply_gradients(gvs)

sess = tf.Session()
sess.run(tf.global_variables_initializer())

#요렇게 조정해준다
for step in range(100):
  print(step, sess.run([gradient, W, gvs])) #gvs 출력시 gvs적용시킨 gradient, W 리스트 보내준다
  sess.run(apply_gradients)
#결과는 아까 미분때 사용한 일반그래디언트함수 그대로 가지고 왔으므로 직접계산한 것과 gvs 적용시킨 것이 같다