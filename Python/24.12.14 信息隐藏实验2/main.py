import tkinter as tk
from tkinter import messagebox
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import chi2, linregress
from matplotlib import rcParams
import matplotlib.image as pmg

# 设置字体为 SimHei（黑体）或其他支持中文的字体
rcParams['font.sans-serif'] = ['SimHei']  # 使用黑体
rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

def lsb_stegano1():
    try:
        img_path = "Images/image2.bmp"  # 替换为你的图像路径
        lsb_seq_path = "Images/output/lsb顺序隐写2.bmp"  # 输出隐写图像路径

        org_img = Image.open(img_path)
        img = org_img.copy()
        width, height = img.size
        mode = img.mode
        channels = 0

        if mode == 'RGB':
            img = img.convert('RGB')
            channels = 3
        elif mode == 'L':
            img = img.convert('L')
            channels = 1

        pixels = img.load()
        #hidden_data = "5120227113" * 1843  # 约20%
        hidden_data = "5120227113" * 6000 # 约65%
        start_marker = "START"
        end_marker = "END"
        hidden_data = start_marker + str(hidden_data) + end_marker
        binary_data = ''.join(format(ord(i), '08b') for i in hidden_data)
        data_len = len(binary_data)
        data_index = 0

        if channels == 3:
            if data_len > width * height * 3:
                raise ValueError("数据长度超过图像容量，请使用更大图像或减少数据量。")
        elif channels == 1:
            if data_len > width * height:
                raise ValueError("数据长度超过图像容量，请使用更大图像或减少数据量。")

        for y in range(height):
            for x in range(width):
                if channels == 3:
                    r, g, b = pixels[x, y]
                    if data_index < data_len:
                        r = (r & 0xFE) | int(binary_data[data_index])
                        data_index += 1
                    if data_index < data_len:
                        g = (g & 0xFE) | int(binary_data[data_index])
                        data_index += 1
                    if data_index < data_len:
                        b = (b & 0xFE) | int(binary_data[data_index])
                        data_index += 1

                    pixels[x, y] = (r, g, b)

                else:
                    gray = pixels[x, y]
                    if data_index < data_len:
                        gray = (gray & 0xFE) | int(binary_data[data_index])
                        data_index += 1

                    pixels[x, y] = gray

                if data_index >= data_len:
                    break

            else:
                continue
            break

        img.save(lsb_seq_path)
        messagebox.showinfo("LSB 隐写", f"数据顺序隐写成功，文件保存在：{lsb_seq_path}")

    except Exception as e:
        messagebox.showerror("错误", str(e))

def steganography_probability_analysis(image_array):
    histogram_counts = np.histogram(image_array, bins=range(257))[0]  # 统计每个灰度值的频数
    # 奇偶灰度值频数平均值
    even_value_counts = histogram_counts[2:255:2]  # 偶数灰度值
    mean_value_counts = (even_value_counts + histogram_counts[3:256:2]) / 2
    # 筛选非零频数的位置
    valid_mask = (mean_value_counts != 0)
    valid_count = np.sum(valid_mask)
    valid_indices = np.nonzero(valid_mask)[0]

    chi_squared_value = np.sum(((even_value_counts[valid_indices] - mean_value_counts[valid_indices]) ** 2) /
                               mean_value_counts[valid_indices])

    # 计算隐写检测的概率 p
    p = 1 - chi2.cdf(chi_squared_value, valid_count - 1)
    return p

def chi_square_analysis():
    try:
        img_path = "Images/image1.bmp"

        # 加载原图
        origin_image = Image.open(img_path).convert('L')  # 转换为灰度图
        # origin_image.show()
        origin_array = np.array(origin_image)

        # 确定隐写区域大小
        sz = origin_array.shape
        rt = 0.3  # 隐写覆盖率
        row = int(sz[0] * rt)  # 高度隐写区域
        col = sz[1]           # 宽度隐写区域

        # 生成随机隐写信息
        msg = np.random.choice([0, 1], size=(row, col), p=[0.5, 0.5])

        # 检查形状是否一致
        assert origin_array[0:row, 0:col].shape == msg.shape, "Shapes do not match!"

        # 嵌入隐写信息
        ste_array = np.copy(origin_array)
        ste_array[0:row, 0:col] = (ste_array[0:row, 0:col] & ~1) | msg

        # 可视化原图和隐写图的灰度直方图
        nI, _ = np.histogram(origin_array, bins=range(257))
        nS, _ = np.histogram(ste_array, bins=range(257))

        a, b = 0, 100
        x = range(a, b)
        plt.figure()
        plt.stem(x, nI[a:b])
        plt.title("Original Image Grayscale Histogram")
        plt.xlabel("Grayscale Value")
        plt.ylabel("Frequency")

        plt.figure()
        plt.stem(x, nS[a:b])
        plt.title("Stego Image Grayscale Histogram")
        plt.xlabel("Grayscale Value")
        plt.ylabel("Frequency")

        plt.show()

        # 隐写检测概率
        p1 = steganography_probability_analysis(origin_array)
        p2 = steganography_probability_analysis(ste_array)

        messagebox.showinfo("隐写检测结果", f"隐写检测的概率为: {p2:.4f}")

    except Exception as e:
        messagebox.showerror("错误", str(e))


def lsb_stegano2():
    try:
        img_path = "Images/image2.bmp"  # 替换为你的图像路径
        lsb_random_path = "Images/output/lsb随机隐写2 0.3.bmp"  # 输出隐写图像路径

        org_img = Image.open(img_path)
        img = org_img.copy()
        width, height = img.size
        mode = img.mode
        channels = 0

        if mode == 'RGB':
            img = img.convert('RGB')
            channels = 3
        elif mode == 'L':
            img = img.convert('L')
            channels = 1

        pixels = img.load()
        # hidden_data = "5120227113" * 3686 # 约40%
       # hidden_data = "5120227113" * 921 # 约10%
        hidden_data = "5120227113" * 2763 # 约30%
        #hidden_data = "5120227113" * 645 # 约7%

        start_marker = "START"
        end_marker = "END"
        hidden_data = start_marker + str(hidden_data) + end_marker
        binary_data = ''.join(format(ord(i), '08b') for i in hidden_data)
        data_len = len(binary_data)
        data_index = 0

        total_pixels = width * height * channels
        if data_len > total_pixels:
            raise ValueError("数据长度超过图像容量，请使用更大图像或减少数据量。")

        # 生成随机嵌入索引
        np.random.seed(42)  # 固定随机种子，解码时一致
        random_indices = np.random.permutation(total_pixels)

        # 嵌入数据
        for idx in random_indices:
            if data_index >= data_len:
                break
            y, x, c = idx // (width * channels), (idx % (width * channels)) // channels, idx % channels
            if channels == 3:
                r, g, b = pixels[x, y]
                if c == 0:
                    r = (r & 0xFE) | int(binary_data[data_index])
                    pixels[x, y] = (r, g, b)
                elif c == 1:
                    g = (g & 0xFE) | int(binary_data[data_index])
                    pixels[x, y] = (r, g, b)
                else:
                    b = (b & 0xFE) | int(binary_data[data_index])
                    pixels[x, y] = (r, g, b)
            else:
                gray = pixels[x, y]
                gray = (gray & 0xFE) | int(binary_data[data_index])
                pixels[x, y] = gray
            data_index += 1

        img.save(lsb_random_path)
        messagebox.showinfo("LSB 隐写", f"数据随机隐写成功，文件保存在：{lsb_random_path}")

    except Exception as e:
        messagebox.showerror("错误", str(e))

def mlsb_stegano():
    try:
        img_path = "Images/image2.bmp"
        mlsb_output_path = "Images/output/mlsb隐写2.bmp"  # 输出隐写图像路径

        org_img = Image.open(img_path)
        img = org_img.copy()
        width, height = img.size
        mode = img.mode
        channels = 0

        if mode == 'RGB':
            img = img.convert('RGB')
            channels = 3
        elif mode == 'L':
            img = img.convert('L')
            channels = 1

        pixels = img.load()
        #hidden_data = "5120227113" * 3686 # 约40%
        hidden_data = "5120227113" * 921  # 约10%
        start_marker = "START"
        end_marker = "END"
        hidden_data = start_marker + str(hidden_data) + end_marker
        binary_data = ''.join(format(ord(i), '08b') for i in hidden_data)
        data_len = len(binary_data)
        data_index = 0

        total_pixels = width * height * channels
        if data_len > total_pixels * 2:  # 因为每个像素能嵌入 2 位
            raise ValueError("数据长度超过图像容量，请使用更大图像或减少数据量。")

        # 嵌入数据
        for y in range(height):
            for x in range(width):
                if data_index >= data_len:
                    break
                if channels == 3:
                    r, g, b = pixels[x, y]
                    if data_index < data_len:
                        r = (r & 0xFC) | int(binary_data[data_index:data_index+2], 2)  # 占用两位
                        data_index += 2
                    if data_index < data_len:
                        g = (g & 0xFC) | int(binary_data[data_index:data_index+2], 2)
                        data_index += 2
                    if data_index < data_len:
                        b = (b & 0xFC) | int(binary_data[data_index:data_index+2], 2)
                        data_index += 2
                    pixels[x, y] = (r, g, b)
                else:
                    gray = pixels[x, y]
                    if data_index < data_len:
                        gray = (gray & 0xFC) | int(binary_data[data_index:data_index+2], 2)
                        data_index += 2
                    pixels[x, y] = gray

        img.save(mlsb_output_path)
        messagebox.showinfo("MLSB 隐写", f"数据隐写成功，文件保存在：{mlsb_output_path}")

    except Exception as e:
        messagebox.showerror("错误", str(e))

def plot_histograms_and_diff(fig, original_hist, embedded_hist, channel_name, axes):
    """
    绘制每列包含三个直方图，从上到下分别是原始图、嵌入图、差异图。
    """
    # 定义颜色和标题
    color = 'black'
    titles = [
        f'Original {channel_name} Channel Histogram',
        f'Embedded {channel_name} Channel Histogram',
        f'{channel_name} Channel Histogram Difference'
    ]

    # 绘制原始、嵌入和差异的直方图
    axes[0].bar(np.arange(256), original_hist, color=color, alpha=0.7, label='Original')
    axes[1].bar(np.arange(256), embedded_hist, color=color, alpha=0.7, label='Embedded')
    hist_diff = np.abs(original_hist - embedded_hist)
    axes[2].bar(np.arange(256), hist_diff, color=color, alpha=0.7, label='Difference')

    # 设置轴的属性
    for i, ax in enumerate(axes):
        ax.set_xlim([0, 256])  # 设置像素范围
        ax.set_xlabel('Pixel Value')
        ax.set_ylabel('Frequency')
        ax.legend()
        ax.set_title(titles[i])

def compare_information_lsb_mlsb(image1_path, image2_path): #信息体积估计
    original_img = Image.open(image1_path)
    original_pixels = np.array(original_img)
    embedded_img = Image.open(image2_path)
    embedded_pixels = np.array(embedded_img)

    fig, axes = plt.subplots(nrows=3, ncols=3, figsize=(15, 15))
    plt.tight_layout()

    if len(original_pixels.shape) == 3:  # RGB 图像
        original_pixels = original_pixels.reshape(-1, 3)
        embedded_pixels = embedded_pixels.reshape(-1, 3)

        hist_original = []
        hist_embedded = []
        for channel, channel_name in enumerate(['Red', 'Green', 'Blue']):
            hist_original.append(np.histogram(original_pixels[:, channel], bins=256, range=(0, 256))[0])
            hist_embedded.append(np.histogram(embedded_pixels[:, channel], bins=256, range=(0, 256))[0])

            plot_histograms_and_diff(fig, hist_original[channel], hist_embedded[channel], channel_name,
                                     axes[:, channel])

        # 显示所有子图
        plt.show()

        # 计算信息量
        # hist_diff = [np.abs(hist_original - hist_embedded) for hist_original, hist_embedded in zip(np.hsplit(original_pixels, 3), np.hsplit(embedded_pixels, 3))]
        hist_diff = [np.abs(hist_original[i] - hist_embedded[i]) for i in range(3)]
        info_volume = sum(np.sum(diff) for diff in hist_diff)
    else:  # 灰度图像
        original_pixels = original_pixels.flatten()
        embedded_pixels = embedded_pixels.flatten()

        hist_original, _ = np.histogram(original_pixels, bins=256, range=(0, 256))
        hist_embedded, _ = np.histogram(embedded_pixels, bins=256, range=(0, 256))

        plot_histograms_and_diff(fig, hist_original, hist_embedded, 'Gray', axes[:, 0])

        # 显示所有子图
        plt.show()

        # 计算信息量
        hist_diff = np.abs(hist_original - hist_embedded)
        info_volume = np.sum(hist_diff)
    messagebox.showinfo("信息量估计",f"信息体积估计为：{info_volume}")


def embed_message_with_lsb(cover_img, secret_bits, bits_per_pixel): #抗分析lsb
    # 将图像展平为一维数组
    cover_flat = cover_img.flatten()
    num_bits = len(secret_bits)
    num_pixels = num_bits // bits_per_pixel

    if num_pixels > len(cover_flat):
        print("数据量超出图像容量，请选择更大的图像或减少数据量。")
        return

    np.random.seed(42)
    # 随机选择嵌入位置
    embed_positions = cover_flat[:num_pixels]
    stego_flat = cover_flat.copy()

    prev_lsb_value = 0
    for i, pos in enumerate(embed_positions):
        secret_value = int(''.join(map(str, secret_bits[i * bits_per_pixel:(i + 1) * bits_per_pixel])), 2)
        pixel_value = cover_flat[pos]
        lsb_value = pixel_value % (2 ** bits_per_pixel)
        new_value = pixel_value + secret_value - (prev_lsb_value + lsb_value) % (2 ** bits_per_pixel)

        # 保证新值不超出像素值范围
        if new_value > 255:
            new_value -= 2 ** bits_per_pixel
        elif new_value < 0:
            new_value += 2 ** bits_per_pixel

        stego_flat[pos] = new_value
        prev_lsb_value = lsb_value

    stego_img = stego_flat.reshape(cover_img.shape)
    return stego_img


def random_embedding(origin_img, embedding_level):
    # 随机隐写
    img_height, img_width = origin_img.shape[:2]
    num_pixels = int(round(img_width * img_height * embedding_level))
    secret_data = np.random.choice([0, 1], size=num_pixels, p=[0.5, 0.5])
    secret_data = ''.join(map(str, secret_data))

    stego_img = embed_message_with_lsb(origin_img, secret_data, 1)
    return stego_img


def classic_lsb_embedding(origin_img, embedding_level):
    # 经典的 LSB 隐写
    img_size = origin_img.shape
    total_pixels = int(np.prod(img_size) * embedding_level)
    indices = np.random.choice(origin_img.size, total_pixels, replace=False)

    flattened_img = origin_img.flatten()
    secret_message = np.random.choice([0, 1], size=total_pixels, p=[0.5, 0.5])
    flattened_img[indices] = (flattened_img[indices] & ~1) | secret_message
    return flattened_img.reshape(img_size)


def calculate_f1_f2(img_array):
    # 计算图像的 F1 和 F2 值
    hist, _ = np.histogram(img_array, bins=256, range=(0, 256))
    f1 = np.sum(np.abs(hist[1::2] - hist[::2]))
    f2 = np.sum(np.abs(hist[2::2] - hist[1:-1:2]))
    return f1, f2


def estimate_message_volume(img_path, alpha):
    original_img = Image.open(img_path)
    img_array = np.array(original_img)

    # 选择隐写方式
    #stego_img_first = classic_lsb_embedding(img_array, alpha)
    stego_img_first = random_embedding(img_array, alpha)

    F1_values = []
    F2_values = []
    beta_values = np.arange(0.1, 1.1, 0.1)

    # 使用不同的隐写率计算 F1 和 F2
    for beta in beta_values:
        stego_img = classic_lsb_embedding(stego_img_first, beta)
        F1, F2 = calculate_f1_f2(stego_img)
        F1_values.append(F1)
        F2_values.append(F2)

    # 对 F1 和 F2 进行线性拟合
    n = 4
    slope_f1, intercept_f1, _, _, _ = linregress(beta_values[:n], F1_values[:n])
    slope_f2, intercept_f2, _, _, _ = linregress(beta_values[:n], F2_values[:n])

    # 求解两条拟合线的交点
    beta_intercept = (intercept_f2 - intercept_f1) / (slope_f1 - slope_f2)

    # 估计隐写率
    alpha_estimated = beta_intercept / (beta_intercept - 1)

    # 延长 F1 和 F2 的拟合线
    beta_ext = np.linspace(-1, 1, 50)
    F1_ext = slope_f1 * beta_ext + intercept_f1
    F2_ext = slope_f2 * beta_ext + intercept_f2

    # 绘制 F1 和 F2 的变化图
    plt.figure(figsize=(8, 6))
    plt.scatter(beta_values, F1_values, c='red', label='F1', marker='o')
    plt.scatter(beta_values, F2_values, c='blue', label='F2', marker='s')
    plt.plot(beta_ext, F1_ext, 'r--', label='F1延长线')
    plt.plot(beta_ext, F2_ext, 'b--', label='F2延长线')
    plt.axvline(x=beta_intercept, color='gray', linestyle='--', label=f'交点 β = {beta_intercept:.2f}')

    plt.xlim(-1, 1)
    plt.ylim(0, max(F1_values + F2_values) * 1.1)

    plt.xlabel('隐写率 β')
    plt.ylabel('统计值 F1, F2')
    plt.title('F1 和 F2 的变化及隐写率估计')
    plt.legend()
    plt.grid()
    plt.show()
    # 弹出结果
    messagebox.showinfo("信息量估计法分析", f"实际隐写率 α: {alpha:.2f}, 估计隐写率 : {abs(alpha_estimated):.2f}")

def compute_smoothness(x):
    """计算平滑度：相邻像素之间的绝对差值之和"""
    return np.sum(np.abs(np.diff(x)))


def divide_into_blocks(picture):
    """将图像分成8x8大小的块"""

    x, y = picture.shape[0] // 8, picture.shape[1] // 8
    Block_p = np.zeros((x * y, 8, 8))
    BlockNum = 0
    for i in range(x):
        for j in range(y):
            for k in range(8):
                for h in range(8):
                    Block_p[BlockNum, k, h] = picture[i * 8 + k, j * 8 + h]
            BlockNum += 1
    return Block_p


def modify_pixel_value(block, flag):
    """根据flag调整像素值"""
    if flag == 1:
        if block % 2 == 0:
            block = block + 1
        else:
            block = block - 1
    elif flag == -1:
        if block % 2 == 0:
            block = block - 1
        else:
            block = block + 1
    return block

def modify_block(block, flag):
    """修改8x8块中的像素值"""
    modified_block = block.copy()
    for m in range(8):
        for n in range(8):
            flag_value = 1 if (m * 8 + n) % 2 == 0 else 0
            modified_block[m, n] = modify_pixel_value(modified_block[m, n], flag * flag_value)
    return modified_block


def calculate_parameters(img_array):
    """计算图像的相关参数"""
    computer = img_array.copy()
    RM = SM = NRM = NSM = 0
    ori = divide_into_blocks(computer)
    Fori = divide_into_blocks(computer)
    NFori = divide_into_blocks(computer)

    for m in range(ori.shape[0]):
        Fori[m, :, :] = modify_block(Fori[m, :, :], 1)
        NFori[m, :, :] = modify_block(NFori[m, :, :], -1)
        if compute_smoothness(Fori[m, :, :]) > compute_smoothness(ori[m, :, :]):
            RM = RM + 1
        if compute_smoothness(Fori[m, :, :]) < compute_smoothness(ori[m, :, :]):
            SM = SM + 1
        if compute_smoothness(NFori[m, :, :]) > compute_smoothness(ori[m, :, :]):
            NRM = NRM + 1
        if compute_smoothness(NFori[m, :, :]) < compute_smoothness(ori[m, :, :]):
            NSM = NSM + 1

    return RM, SM, NRM, NSM


def rs_analyze(img_path):
    """分析图像并计算每个通道的参数"""
    if type(img_path) == str:
        img = pmg.imread(img_path)
    else:
        img = img_path.copy()
    img_array = np.array(img)

    isBgr = True
    if len(img_array.shape) > 2:
        pass
    else:
        isBgr = False

    for c in range(3) if isBgr else [0]:
        if isBgr:
            RM, SM, NRM, NSM = calculate_parameters(img_array[:, :, c])
            color = ['Blue', 'Green', 'Red']
        else:
            RM, SM, NRM, NSM = calculate_parameters(img_array)
            color = ['Gray']

        print(f"{color[c]} channel:")
        print(f"RM: {RM}, SM: {SM}, R_M: {NRM}, S_M: {NSM}")

        array_reverse = np.array(img)
        for i in range(array_reverse.shape[0]):
            for j in range(array_reverse.shape[1]):
                if isBgr:
                    array_reverse[i, j, c] = modify_pixel_value(array_reverse[i, j, c], 1)
                else:
                    array_reverse[i, j] = modify_pixel_value(array_reverse[i, j], 1)

        if isBgr:
            RM_reverse, SM_reverse, NRM_reverse, NSM_reverse = calculate_parameters(array_reverse[:, :, c])
        else:
            RM_reverse, SM_reverse, NRM_reverse, NSM_reverse = calculate_parameters(array_reverse)

        print(f"Reverse {color[c]} channel:")
        print(f"RM: {RM_reverse}, SM: {SM_reverse}, R_M: {NRM_reverse}, S_M: {NSM_reverse}")

        d0 = RM - SM
        d1 = RM_reverse - SM_reverse
        d2 = NRM - NSM
        d3 = NRM_reverse - NSM_reverse
        args = [2 * (d0 + d1), d2 - d3 - d1 - 3 * d0, d0 - d2]

        a, b = np.roots(args)
        if a > b:
            print(f"{color[c]}通道估计隐写率为：", b / (b - 0.5))

        else:
            print(f"{color[c]}通道估计隐写率为：", a / (a - 0.5))



def RS(img_path, alpha):
    # 加载原始图像并转为数组
    org_img = Image.open(img_path).convert('L')
    img = org_img.copy()
    origin_array = np.array(img)

    #ste_array_first = classic_lsb_embedding(origin_array, alpha)
    ste_array_first = random_embedding(origin_array, alpha)

    rs_analyze(ste_array_first)
    lv = np.arange(0, 1.1, 0.2)
    results = []

    for i in lv:
        # 依次在不同隐写率下进行LSB隐写
        ste_array = classic_lsb_embedding(ste_array_first, i)

        # 计算隐写后的图像参数
        RM, SM, NRM, NSM = calculate_parameters(ste_array)

        # 计算每个类别的占比，避免除零错误
        total = RM + SM + NRM + NSM
        if total == 0:  # 防止除以零的错误
            P_RM = P_SM = P_NRM = P_NSM = 0
        else:
            P_RM = RM / total
            P_SM = SM / total
            P_NRM = NRM / total
            P_NSM = NSM / total

        results.append((P_RM, P_SM, P_NRM, P_NSM))

    # 绘制结果曲线
    plot_results(lv, results, alpha)


def plot_results(lv, results, alpha):
    """
    绘制隐写率变化下的RS分析结果曲线。
    """
    # 解压结果数据
    P_RM, P_SM, P_NRM, P_NSM = zip(*results)

    # 绘制隐写率变化图
    plt.figure(figsize=(8, 6))
    plt.plot(lv, P_RM, label='Rm', color='blue')
    plt.plot(lv, P_SM, label='Sm', color='orange')
    plt.plot(lv, P_NRM, label='R-m', color='yellow')
    plt.plot(lv, P_NSM, label='S-m', color='purple')

    # 设置图表标签和标题
    plt.xlabel('隐写率')
    plt.ylabel('占比')
    plt.title(f'原隐写率：{alpha}，正则/奇异组占比随隐写率变化的曲线')
    plt.legend(loc='upper right')
    plt.grid(True)
    plt.show()

def new_lsb_stegano(image_path, embedding_level, output_path):
    """
        随机隐写：在图像中嵌入伪随机秘密数据。
        :param image_path: 输入图像路径
        :param embedding_level: 嵌入比例 (0到1之间)
        :param output_path: 输出隐写图像路径
        :return: 隐写后的图像
        """
    # 读取图像并转换为灰度图
    origin_img = Image.open(image_path).convert('L')
    img_array = np.array(origin_img)

    img_height, img_width = img_array.shape[:2]
    num_pixels = int(round(img_width * img_height * embedding_level))

    # 生成随机的秘密数据
    secret_data = np.random.choice([0, 1], size=num_pixels, p=[0.5, 0.5])

    # 调用嵌入函数
    stego_img_array = embed_message_with_lsb(img_array, secret_data, bits_per_pixel=1)

    # 保存结果图像
    stego_img = Image.fromarray(stego_img_array.astype(np.uint8))
    stego_img.save(output_path)

    print(f"隐写图像已保存至: {output_path}")
    return stego_img
def lsb_stegano1_ui(): #lsb顺序隐写
    lsb_stegano1()

def lsb_stegano2_ui(): #lsb离散隐写
    lsb_stegano2()

def mlsb_stegano_ui(): # MLSB 隐写
    mlsb_stegano()

def new_lsb_stegano_ui(): # 抗分析 LSB 隐写
    input_image_path = "Images/image2.bmp"  # 替换为你的输入图像路径
    output_image_path = "Images/output/抗分析lsb2 0.07.bmp"  # 输出隐写图像路径
    embedding_ratio = 0.07  # 嵌入比例
    new_lsb_stegano(input_image_path, embedding_ratio, output_image_path)

def chi_square_analysis_ui(): #卡方分析
    chi_square_analysis()

def information_difference_ui(): # 信息体积估计
    image1_path = "Images/image2.bmp"
    image2_path = "Images/output/mlsb隐写2.bmp"
    compare_information_lsb_mlsb(image1_path, image2_path)
def estimate_information_volume_ui(): # 信息量估计法分析
    image_path = "Images/image2.bmp"
    alpha = 0.3 # 隐写率
    estimate_message_volume(image_path,alpha)

def rs_analysis_ui(): # RS 分析
    image_path = "Images/image2.bmp"
    alpha = 0.3  # 隐写率
    RS(image_path, alpha)

def stego_menu():
    stego_window = tk.Toplevel()
    stego_window.title("图像隐写功能")

    tk.Label(stego_window, text="选择隐写方式", font=("Arial", 14)).pack(pady=10)
    tk.Button(stego_window, text="1. LSB 顺序隐写", command=lsb_stegano1_ui, width=30).pack(pady=5)
    tk.Button(stego_window, text="1. LSB 随机隐写", command=lsb_stegano2_ui, width=30).pack(pady=5)
    tk.Button(stego_window, text="2. MLSB 随机隐写", command=mlsb_stegano_ui, width=30).pack(pady=5)
    tk.Button(stego_window, text="3. 抗分析 LSB 随机隐写", command=new_lsb_stegano_ui, width=30).pack(pady=5)
    tk.Button(stego_window, text="返回", command=stego_window.destroy, width=30).pack(pady=5)

def analysis_menu():
    analysis_window = tk.Toplevel()
    analysis_window.title("隐写分析功能")

    tk.Label(analysis_window, text="选择分析方式", font=("Arial", 14)).pack(pady=10)
    tk.Button(analysis_window, text="1. 卡方分析", command=chi_square_analysis_ui, width=30).pack(pady=5)
    tk.Button(analysis_window, text="2. 信息体积估计", command=information_difference_ui, width=30).pack(pady=5)
    tk.Button(analysis_window, text="3. 信息量估计法分析", command=estimate_information_volume_ui, width=30).pack(pady=5)
    tk.Button(analysis_window, text="4. RS 分析", command=rs_analysis_ui, width=30).pack(pady=5)
    tk.Button(analysis_window, text="返回", command=analysis_window.destroy, width=30).pack(pady=5)

def main_menu():
    root = tk.Tk()
    root.title("图像隐写与分析工具")

    tk.Label(root, text="图像隐写与分析工具", font=("Arial", 16)).pack(pady=20)

    tk.Button(root, text="1. 图片隐写", command=stego_menu, width=30, height=2).pack(pady=10)
    tk.Button(root, text="2. 图片分析", command=analysis_menu, width=30, height=2).pack(pady=10)
    tk.Button(root, text="3. 退出", command=root.quit, width=30, height=2).pack(pady=10)

    root.mainloop()

if __name__ == "__main__":
    main_menu()
