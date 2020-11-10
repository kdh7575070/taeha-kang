import numpy as np
import tensorflow as tf

sess = tf.Session()

x = [[1., 2.],
     [3., 4.]]
print('mean')
print(sess.run(tf.reduce_mean(x)))
print(sess.run(tf.reduce_mean(x, axis=0)))
print(sess.run(tf.reduce_mean(x, axis=1)))
print(sess.run(tf.reduce_mean(x, axis=-1)))
print('')
print('sum')
print(sess.run(tf.reduce_sum(x)))
print(sess.run(tf.reduce_sum(x, axis=0)))
print(sess.run(tf.reduce_sum(x, axis=1)))
print(sess.run(tf.reduce_sum(x, axis=-1)))
print('')

print('argmax')
y = [[0,1,2],
     [2,1,0]]
print(sess.run(tf.argmax(y, axis=0)))
print(sess.run(tf.argmax(y, axis=1)))
print(sess.run(tf.argmax(y, axis=-1)))
print('')

print('reshape')
t = np.array([[[0,1,2],
              [3,4,5]],

              [[6,7,8],
               [9,10,11]]])
print(t.shape)
print(sess.run(tf.reshape(t, shape=[-1,3])))
print(sess.run(tf.reshape(t, shape=[-1,3])).shape)
print('')
print(sess.run(tf.reshape(t, shape=[-1,1,3])))
print(sess.run(tf.reshape(t, shape=[-1,1,3])).shape)
print('')

print('sqeeze expand')
print(sess.run(tf.squeeze([[0],[1],[2]])))
print('')
print(sess.run(tf.expand_dims([0,1,2],1)))
print('')

print('one hot')
print(sess.run(tf.one_hot([[0],[1],[2],[0]], depth=3)))
print('')
h = tf.one_hot([[0],[1],[2],[0]], depth=3)
print(sess.run(tf.reshape(h, shape=[-1,3])))
print('')

print('casting')
print(sess.run(tf.cast([1.8, 2.2, 3.3, 4.9], tf.int32))) #내림
print(sess.run(tf.cast([True, False, 1==1, 0==1], tf.int32)))
print('')

print('stack')
a = [1,4]
b = [2,5]
c = [3,6]
print(sess.run(tf.stack([a,b,c])))
print(sess.run(tf.stack([a,b,c], axis=1)))
print('')

print('ones and zeros like')
d = [[0,1,2],
     [2,1,0]]
print(sess.run(tf.ones_like(d)))
print(sess.run(tf.zeros_like(d)))
print('')

print('zip')
for x1,y1 in zip([1,2,3],[4,5,6]):
    print(x1,y1)
print('')
for x1,y1,z1 in zip([1,2,3],[4,5,6],[7,8,9]):
    print(x1,y1,z1)