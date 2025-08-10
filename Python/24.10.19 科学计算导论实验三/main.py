import numpy as np
import cupy as cp
import time

def matrix_operation(A, B, a, b): # 矩阵计算
    C = a * A + b * B
    return C

# 测试 CPU 版本
if __name__ == "__main__":
    dimensions = [500, 1000]  # 设定不同的矩阵维度
    a, b = 2.0, 3.0  # 常系数

    # 预热gpy
    for dim in dimensions:
        A_cp = cp.random.rand(1000, 1000)  # 随机生成一个1000*1000的矩阵
        B_cp = cp.random.rand(1000, 1000)
        C_gpu = matrix_operation(A_cp, B_cp, a, b)

    for dim in dimensions: # 遍历每一个维度
        A_np = np.random.rand(dim, dim) # 随机生成一个矩阵
        B_np = np.random.rand(dim, dim)

        cpu_start_time = time.time() # 开始计时（CPU）
        C_cpu = matrix_operation(A_np, B_np, a, b) # 进行矩阵运算
        cpu_end_time = time.time() # 结束计时

        # 转换为 CuPy 矩阵
        A_cp = cp.asarray(A_np)
        B_cp = cp.asarray(B_np)

        gpu_start_time = time.time() # 计时（GPU）
        C_gpu = matrix_operation(A_cp, B_cp, a, b) # 矩阵运算
        gpu_end_time = time.time() # 结束计时

        print(f"矩阵维度: {dim}x{dim}, CPU Time: {cpu_end_time - cpu_start_time:.5f} seconds") # 输出结果
        print(f"矩阵维度: {dim}x{dim}, GPU Time: {gpu_end_time - gpu_start_time:.5f} seconds")

        if np.allclose(C_cpu, cp.asnumpy(C_gpu)): # 比较两次运算的结果是否相同并输出结果
            print("返回值相同")
        else:
            print("返回值不同")
