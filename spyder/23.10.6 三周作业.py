import numpy as np

# lst = [1,2,3,4]
# nd1 = np.array(lst)
# print(nd1,type(nd1))

# #random
# #0到1标准正态分布
# arr1 = np.random.randn(3, 2)
# #0到1均匀分布
# arr2 = np.random.rand(3, 3)
# #均匀分布的随机数（浮点数），前两个参数表示随机数的范围，第三个表示生成随机数的个数
# arr3 = np.random.uniform(0, 10, 2)
# #均匀分布的随机数（整数），前两个参数表示随机数的范围，第三个表示生成随机数的个数
# arr4 = np.random.randint(0, 10, 3)
# print(f'arr1 : {arr1}\narr2 : {arr2}\narr3 : {arr3}\narr4 : {arr4}')

# #为使每次生成的数据相同，可以设置一个种子
# np.random.seed(100)
# arr = np.random.rand(2,2)
# print(f"arr:{arr}")
# #打乱数组
# np.random.shuffle(arr)
# print(f"arr:{arr}")

# #创建特定形状数组
# #未初始化的数组
# arr1 = np.empty((2,3))
# #数组元素以 0 来填充
# arr2 = np.zeros((2, 3))
# #数组元素以 1 来填充
# arr3 = np.ones((2, 3))
# #数组以指定的数来进行填充，这里举例3
# arr4 = np.full((2, 3), 3)
# #生成单位，对角线上元素为 1，其他为0
# arr5 = np.eye(2)
# #二维矩阵输出矩阵对角线的元素，一维矩阵形成一个以一维数组为对角线元素的矩阵
# arr6 = np.diag(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
# #创建等差数列
# #1.linspace步长是(end - start) / (length - 1) 数列包含首尾数
# #2.arange 步长自己定 默认是1 
# arr7 = np.linspace(0, 10, 5)
# arr8 = np.arange(0, 5 ,2)
# print(f"arr1:{arr1}\narr2:{arr2}\narr3:{arr3}\narr4:{arr4}\narr5:{arr5}\narr6:{arr6}\narr7:{arr7}\narr8:{arr8}\n")

# 索引和切片
# a = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
# print(f'{a[0]}\n{a[1,2]}')
# b = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
# print(f"{b[0,1:3]}\n")

# # 获取离散数据
# x = np.array([[ 0, 1, 2],[ 3, 4, 5],[ 6, 7, 8],[ 9, 10, 11]]) 
# rows = np.array( [ [0,0],[3,3] ] ) #表示第1、4行
# cols = np.array( [ [0,2],[0,2] ] ) #表示第1、3列
# y = x[rows,cols]
# print(y)

#布尔索引
# x = np.array([[ 0, 1, 2],[ 3, 4, 5],[ 6, 7, 8],[ 9, 10, 11]]) 
# print(x[x > 5])
# b = x > 5
# print(b)

# # 元素查找定位 np.where(condition, x, y): 满足条件(condition)，输出x，不满足输出y
# a = np.array([2,4,6,8,10,3]).reshape(2,3)
# print(a)
# c = np.where(a > 3)
# print(c,a[c])

# #数组的拼接
# a = np.array([[1, 2], [3, 4]])
# b = np.array([[5, 6], [7, 8]])
# c = np.hstack((a,b))
# print(c)
# d = np.vstack((a,b))
# print(d)

# #分割
# x = np.arange(12).reshape(3, 4)
# y =np.split(x, 3)
# print(x,y)
# m = np.arange(9).reshape(1, 9)
# n = np.split(m, 3, axis = 1)
# print(m,n)

# 维度变换
# reshape 不改变原数组元素，返回一个新的shape维度的数组(维度变换)
# x = np.arange(12).reshape(3, 4)
# a = x.reshape(3 ,2 ,-1)
# b =x.reshape(3, -1)
# print(x)
# print(a)
# print(b)

# resize 改变向量的维度(修改向量本身)：
# arr =np.arange(10) 
# print(arr)
# arr.resize(2, 5) # 将向量 arr 维度变换为2行5列 
# print(arr)

# T 转置
# arr = np.arange(8).reshape(2, 4)
# print(arr)
# print(arr.T)

# ravel 向量展平
# arr = np.arange(8).reshape(2, 4)
# x = arr.ravel()
# print(arr,x)

# flatten 把矩阵转换为向量，这种需求经常出现在卷积网络与全连接层之间。
# arr = np.arange(8).reshape(2, 4)
# print(arr,arr.flatten())

# squeeze 把矩阵中含1的维度去掉
# arr = np.arange(8).reshape(2, 4, 1)
# print(arr.shape)
# print(arr.squeeze().shape)

# transpose 对高维矩阵进行轴对换，这个在深度学习中经常使用，比如把图片中表示颜色顺序的RGB改为GBR。
# arr = np.arange(12).reshape(2, 6, 1)
# print(arr.shape)
# print(arr.transpose(1, 2, 0).shape)

# swapaxes 将两个维度调换, 就是把对应的下标换个位置，类似于T
# arr = np.arange(20).reshape(4, 5)
# print(arr)
# print(arr.swapaxes(1, 0))

# Numpy数值计算
# a = np.array([[6, 3, 7, 4, 6], [9, 2, 6, 7, 4], [3, 7, 7, 2, 5], [4, 1, 7, 5, 1]])
# print(np.sum(a, axis = 0))
# print(np.sum(a, axis = 1))
# #排序
# arr = np.array([1, 3, 5, 2, 4])
# print(np.sort(arr))
# print(np.argsort(arr))

# 矩阵运算
# 对应元素相乘
# a = np.array([[1,0],[0,1]])
# b = np.array([[4,1],[2,2]])
# print(np.multiply(a, b)) # 等效于a * b，out : array([[4, 0], [0, 2]])
# # 点积
# print(np.dot(a, b))
# # 计算行列式
# arr = np.array([[1,2], [3,4]]) 
# print(np.linalg.det(arr))
# # 求逆
# print(np.linalg.inv(arr))
# # 特征值和特征向量
# A = np.random.randint(-10,10,(4,4))
# C = np.dot(A.T, A)
# vals, vecs = np.linalg.eig(C) 
# print(f'arr:\n{A}\n特征值 : {vals}, \n特征向量 : {vecs}')

# 插值运算







