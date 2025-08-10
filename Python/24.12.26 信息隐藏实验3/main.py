import tkinter as tk
from tkinter import simpledialog, messagebox
from PIL import ImageTk, Image
import numpy as np
import jpegio as jio
import time
import matplotlib.pyplot as plt
from matplotlib import rcParams

# 设置字体为 SimHei（黑体）或其他支持中文的字体
rcParams['font.sans-serif'] = ['SimHei']
rcParams['axes.unicode_minus'] = False

# 配置参数
COVER = 'cover.jpg'  # 原始图像文件名
STEGO = 'stego.jpg'  # 隐写图像文件名
name = 'JSteg'  # 算法名称
message_len = 40000  # 初始隐写信息长度

# 生成随机的二进制信息
message = np.random.randint(0, 2, message_len)  # 随机生成二进制信息
np.savetxt('message.txt', message, fmt='%d')  # 保存秘密信息到文件

def jsteg_simulation(cover_image, stego_image, message):
    try:
        # 读取 JPEG 原始图像并提取 DCT 系数
        jpeg_data = jio.read(cover_image)
        prime_dct = jpeg_data.coef_arrays[0].copy()  # 复制亮度通道（Y）的 DCT 系数
        dct = prime_dct.copy()  # 创建 DCT 副本用于修改
    except Exception as e:
        raise ValueError("读取原始图像时发生错误: " + str(e))

    # 查找可以嵌入信息的 AC 系数（非 DC 且绝对值大于 1）
    ac_location = dct.copy()
    ac_location[::8, ::8] = 0  # 排除 DC 系数
    ac_location[np.abs(ac_location) <= 1] = 0  # 将绝对值小于等于 1 的位置设为 0
    ac_indices = np.transpose(np.nonzero(ac_location))  # 获取所有可用 AC 系数的位置索引

    nc_ac = len(ac_indices)  # 计算可用的 AC 系数数量
    message_len = len(message)

    # 检查消息是否可以嵌入
    if message_len > nc_ac:
        raise ValueError("错误: 消息过长，无法嵌入。")

    # 将消息嵌入到 DCT 系数中
    for i_msg, (x, y) in enumerate(ac_indices[:message_len]):
        dct_value = dct[x, y]  # 当前的 DCT 系数
        if dct_value > 0:
            dct[x, y] = dct_value + message[i_msg] - (dct_value % 2)  # 嵌入消息比特
        else:
            dct[x, y] = dct_value + message[i_msg] - ((dct_value + 1) % 2)

    # 保存嵌入信息后的隐写图像
    try:
        jpeg_data.coef_arrays[0] = dct
        jio.write(jpeg_data, stego_image)
    except Exception as e:
        raise ValueError("保存隐写图像时发生错误: " + str(e))

    return nc_ac, prime_dct, dct

def update_message_len():
    global message_len, message
    new_len = simpledialog.askinteger("输入信息长度", "请输入新的信息长度:", minvalue=1, maxvalue=100000)
    if new_len is not None:
        message_len = new_len
        message = np.random.randint(0, 2, message_len)
        np.savetxt('message.txt', message, fmt='%d')  # 更新保存的消息

        # 重新执行隐写操作
        start_time = time.time()
        nz_ac, prime_dct, modified_dct = jsteg_simulation(COVER, STEGO, message)
        elapsed_time = time.time() - start_time

        print("-----------------------------------")
        print(f"{name} 模拟完成")
        print(f"原始图像: {COVER}")
        print(f"隐写图像: {STEGO}")
        print(f"原始图像中非零 AC 系数的数量: {nz_ac}")
        print(f"嵌入信息的比特数: {len(message)}")
        print(f"运行时间: {elapsed_time:.4f} 秒")
        print("-----------------------------------")

        # 显示图片
        cover_img = Image.open(COVER).convert("L")  # 转为灰度
        stego_img = Image.open(STEGO).convert("L")  # 转为灰度

        fig, axes = plt.subplots(2, 2, figsize=(10, 8))
        axes[0, 0].imshow(cover_img, cmap='gray')  # 设置为灰度
        axes[0, 0].set_title("原始图像 (未嵌入信息)")
        axes[0, 1].hist(prime_dct.flatten(), bins=20, range=(-10, 10))
        axes[0, 1].set_title("嵌入前的 DCT 系数分布")

        axes[1, 0].imshow(stego_img, cmap='gray')  # 设置为灰度
        axes[1, 0].set_title("隐写图像 (已嵌入信息)")
        axes[1, 1].hist(modified_dct.flatten(), bins=20, range=(-10, 10))
        axes[1, 1].set_title("嵌入后的 DCT 系数分布")

        plt.tight_layout()
        plt.show()

# 创建主窗口
root = tk.Tk()
root.title("JSteg 隐写算法模拟")

# 添加按钮和标签
label = tk.Label(root, text="欢迎使用 JSteg 隐写算法模拟", font=("Arial", 14))
label.pack(pady=10)

update_button = tk.Button(root, text="写入信息长度并更新", command=update_message_len, font=("Arial", 12))
update_button.pack(pady=20)

# 启动UI
root.mainloop()
