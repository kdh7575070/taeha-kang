import tensorflow as tf

hello = tf.constant("Hello, TensorFlow!")
sess = tf.Session() #세션 만들어줘야 프린트 가능
print(sess.run(hello))

#
node1 = tf.constant(3.0, tf.float32) #데이타 타입 주는 것
node2 = tf.constant(4.0) #굳이 데이타 타입 안줘도 f32로 자동
node3 = tf.add(node1, node2) #또는 node3= node1 + node2

#
print("node1:", node1, "node2", node2)
print("ndoe3:", node3)
# 이렇게 실행하면 이런형태의 텐서야 라고만 말해주고 결과값은 안나온다

sess = tf.Session()
print("sess.run(node1, node2):", sess.run([node1, node2]))
print("sess.run(node3):", sess.run(node3))
# 이렇게 해야 우리가 원하는 결과값(3,4, 7)을 얻을 수 있다
# 즉 기존의 프로그래밍과 다르게 1. 우선 그래프를 빌드하고 2. 세션을 통해 실행하고 3. 그래프 속의 값을 업데이트 혹은 리턴