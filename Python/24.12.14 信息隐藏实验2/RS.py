import numpy as np
import matplotlib.image as pmg
from tkinter import messagebox

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


