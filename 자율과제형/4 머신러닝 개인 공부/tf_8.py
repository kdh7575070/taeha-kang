import numpy as np
import tensorflow as tf
import pprint as pp

t=np.array([0.,1.,2.,3.,4.,5.,6.])
pp.pprint(t)
print(t.ndim) #rank
print(t.shape) #shape
print(t[0],t[1],t[-1])
print(t[2:5],t[4:-1])
print(t[:2],t[3:])

#shape, rank, axis => matrix에서 가장 중요

t1 = tf.constant([1,2,3,4])
t2 = tf.constant([[1,2],[3,4]])
t3 = tf.constant([[[[1,2,3,4],[5,6,7,8],[9,10,11,12]],[[13,14,15,16],[17,18,19,20],[21,22,23,24]]]])

#shape => 각 랭크별 요소의 개수 - 랭크를 하나씩 떼면서 계산
          #행렬곱을 할 때는 셰잎을 잘 따지자 (2*3) (3*2) 요렇게
#rank => 차원 - 시작 [[[의 개수
#axis => 가장 바깥의 차원이 차원 0 부터해서 차원이 1 늘어날수록 axis 1씩 증가
        #즉 일반적인 mxm 행렬 에서는 행이 차원 0 열이 차원 1
        #가장 많이 쓰이는 것으로는 axis=-1 이 있는데 이건 가장 안쪽의 차원이 되겠지!
        #ex: tf.reduce_mean(tf.reduce_sum(x, axis=-1)).eval() 즉 열들의 합 열

sess = tf.InteractiveSession()

print(t1.shape) #[ 이므로 1차 콤마가 없으므로 그 안에는 4개를 뜻하는 (4)
print(t2.shape) #[[ 이므로 2차 (콤마하나) 그 안에는 각각 두개씩 두개 (2,2)
print(t3.shape) #[[[[ 이므로 4차 (콤마셋) 그 안에는 각각 네개씩 세개가 두개쌍이며 그건 또 하나이므로 밖에서부터 (1,2,3,4)
#[4,3,2,1] 에서 4의차원이 3 3의차원이 2 2의차원이 1 1의차원이 0

#행렬 곱을 할때는 tf.matmul( , ) 을 써야지 행렬*행렬 하면 안된다