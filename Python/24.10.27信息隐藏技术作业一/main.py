import random
import shutil
import struct
from PIL import Image

# 实验需要用到的所有路径
original_path = "F:/Temp/yacht.bmp" #被操作图片路径
path1 = "F:/Temp/after/yacht_h.bmp" #头文件隐写后的图片路径
path2 = "F:/Temp/after/yacht_m.bmp" #尾部隐写后的图片路径
path3 = "F:/Temp/after/yacht_cover.bmp" #数据区隐写后的图片路径
txtmax = 'F:/Temp/info/txtmax.txt'#大文件路径
txtmin = 'F:/Temp/info/txtmin.txt'#小文件路径
txtcover = 'F:/Temp/info/txtcover.txt'


# 头文件冗余的数据隐写
def hide_h():
    shutil.copy(original_path, path1)
    with open(path1, 'r+b') as f:  # 以二进制形式打开文件
        user_input = input('请输入需要隐写的信息（<=4字节）:')
        if len(user_input) > 4:
            print("输入信息太长，请重新输入")
            hide_h()  # 递归调用
            return  # 退出当前函数

        f.seek(0x0006)  # 移动光标到指定的位置
        f.write(user_input.encode())  # 写入内容
        print("信息写入成功")

    menu()  # 调用菜单


# 头文件冗余的数据分析提取
def check_h():
    with open(path1, 'rb') as f: #以二进制形式打开文件
        f.seek(0x0006) #移动光标到指定位置
        ReserverData = f.read(4) #读取4字节的数据
        if (ReserverData != 0x0000): #判断是否被隐写
            print("有隐写信息:",ReserverData.decode())
            info = open('F:/Temp/info/hidden_header.txt', mode='w', encoding='utf-8')  # 提取内容的目标文件
            info.write(ReserverData.decode())
            info.close()
            print("隐写内容已提取到:F:/Temp/info/hidden_h.txt")
        else:
            print("无隐写信息")
    menu()


#文件尾部追加的数据隐写
def hide_m():
    print("1.数据量较大（大于25%） 2.数据量较小（小于1%）")
    flag = eval(input("请选择: "))
    if flag == 1:
        with open(txtmax, 'r', encoding='utf-8') as f:
            hidden_text = f.read()
    elif flag == 2:
        with open(txtmin, 'r', encoding='utf-8') as f:
            hidden_text = f.read()
    else:
        print("请重新输入")
        hide_m()
    # 添加前缀标识隐写内容
    hidden_text = f'<!--HIDDEN:{hidden_text}-->'
    # 读取原始 BMP 图片
    with open(original_path, 'rb') as img_file:
        img_data = img_file.read()
    # 将隐写内容添加到图片的尾部
    new_img_data = img_data + hidden_text.encode('utf-8')
    # 写入隐写后的图片文件
    with open(path2, 'wb') as new_img_file:
        new_img_file.write(new_img_data)
    print("隐写成功")
    menu()  # 调用菜单


#文件尾部追加的数据分析
def check_m():
    # 读取隐写后的 BMP 图片
    with open(path2, 'rb') as img_file:
        img_data = img_file.read()

    # 解码为字符串并查找隐写内容
    img_data_str = img_data.decode('utf-8', errors='ignore')

    # 查找标记
    start_marker = '<!--HIDDEN:'
    end_marker = '-->'
    start_index = img_data_str.find(start_marker)
    end_index = img_data_str.find(end_marker, start_index)
    # 获取原文件大小
    original_size = len(img_data)
    if start_index != -1 and end_index != -1:
        print("检测到隐写内容")
        hidden_text = img_data_str[start_index + len(start_marker):end_index]
        # 获取隐写内容大小
        hidden_size = len(hidden_text)
        with open('F:/Temp/info/hidden_m.txt', 'w', encoding='utf-8') as f:
            f.write(hidden_text)

        print("隐写内容已提取到: F:/Temp/info/hidden_m.txt")
        print(f"隐写内容大小: {hidden_size} 字节")
        print(f"原文件大小: {original_size} 字节")
    else:
        print("未检测到隐写内容")

    menu()

def hide_cover(mode='sequential'):
    '''图像的数据区进行数据直接覆盖方式的隐写'''
    # 添加起始和结束标记
    marker_start = "<!--HIDDEN_DATA_START-->"
    marker_end = "<!--HIDDEN_DATA_END-->"
    with open(txtcover, 'r', encoding='utf-8') as file:
        txt = file.read()
        data_to_hide = marker_start + txt + marker_end
        # 将数据转换成二进制形式
        binary_data = ''.join(format(ord(char), '08b') for char in data_to_hide)
        # 打开图片
        img = Image.open(original_path)
        pixels = img.load()
        width, height = img.size
        if mode == 'sequential':
            embed_sequentially(pixels, width, height, binary_data)
        elif mode == 'random':
            embed_randomly(pixels, width, height, binary_data)
        else:
            raise ValueError("不支持的嵌入模式")
        # 保存结果图片
        img.save(path3)
        print(f"数据嵌入成功，已保存至 {path3}")


def embed_sequentially(pixels, width, height, binary_data):
    data_index = 0
    total_bits = len(binary_data)

    for y in range(height):
        for x in range(width):
            if data_index < total_bits:
                # 每个像素有 3 个通道，取出当前像素的 RGB 值
                r, g, b = pixels[x, y]

                # 根据二进制数据覆盖 RGB 通道
                if data_index < total_bits:
                    r = int(binary_data[data_index]) * 255  # 将 0/1 转为 0/255
                    data_index += 1
                if data_index < total_bits:
                    g = int(binary_data[data_index]) * 255
                    data_index += 1
                if data_index < total_bits:
                    b = int(binary_data[data_index]) * 255
                    data_index += 1

                # 更新像素值
                pixels[x, y] = (r, g, b)
            else:
                return  # 数据已全部嵌入


def embed_randomly(pixels, width, height, binary_data):
    data_index = 0
    total_bits = len(binary_data)
    total_pixels = width * height
    random_indices = random.sample(range(total_pixels), total_bits // 3)

    for index in random_indices:
        if data_index < total_bits:
            x = index % width
            y = index // width
            r, g, b = pixels[x, y]

            if data_index < total_bits:
                r = int(binary_data[data_index]) * 255
                data_index += 1
            if data_index < total_bits:
                g = int(binary_data[data_index]) * 255
                data_index += 1
            if data_index < total_bits:
                b = int(binary_data[data_index]) * 255
                data_index += 1

            # 更新像素值
            pixels[x, y] = (r, g, b)
        else:
            return  # 数据已全部嵌入

def check_cover():
    pass


def display_menu(options):
    for i, option in enumerate(options, 1):
        print(f"{i}. {option}")
    return int(input("> "))


def cover_hide():
    stegano_options = [
        "顺序嵌入",
        "随机位置嵌入",
        "返回"
    ]

    while True:
        choice = display_menu(stegano_options)
        print("")
        if choice == 1:
            hide_cover(mode='sequential')
        elif choice == 2:
            hide_cover(mode='random')
        elif choice == 3:
            break
        else:
            print("请重新输入")

def hide():
    stegano_options = [
        "头文件冗余的数据隐写",
        "文件尾部追加的数据隐写",
        "数据区数据直接覆盖方式的隐写",
        "返回"
    ]

    while True:
        choice = display_menu(stegano_options)
        print("")
        if choice == 1:
            hide_h()
        elif choice == 2:
            hide_m()
        elif choice == 3:
            cover_hide()
        elif choice == 4:
            break
        else:
            print("请重新输入")


def check():
    analysis_options = [
        "头文件冗余的数据分析提取",
        "文件尾部追加的数据分析提取",
        "数据区数据直接覆盖方式的分析提取",
        "返回"
    ]

    while True:
        choice = display_menu(analysis_options)
        print("")
        if choice == 1:
            check_h()
        elif choice == 2:
            check_m()
        elif choice == 3:
            check_cover()
        elif choice == 4:
            break
        else:
            print("请重新输入")


def menu():
    main_options = [
        "隐写",
        "分析与提取",
        "退出"
    ]

    while True:
        choice = display_menu(main_options)
        print("")
        if choice == 1:
            hide()
        elif choice == 2:
            check()
        elif choice == 3:
            print("退出程序")
            break
        else:
            print("请重新输入")


if __name__ == '__main__':
    menu()


# def hide_lsb(mode='sequential'):
#     '''图像的数据区进行数据直接覆盖方式的隐写'''
#     # 添加起始和结束标记
#     marker_start = "<!--HIDDEN_DATA_START-->"
#     marker_end = "<!--HIDDEN_DATA_END-->"
#     with open(txtlsb, 'r', encoding='utf-8') as file:
#         txt = file.read()
#         data_to_hide = marker_start + txt + marker_end
#
#         # 将数据转换成二进制形式
#         binary_data = ''.join(format(ord(char), '08b') for char in data_to_hide)
#
#         # 打开图片
#         img = Image.open(original_path)
#         pixels = img.load()
#         width, height = img.size
#
#         if mode == 'sequential':
#             embed_sequentially(pixels, width, height, binary_data)
#         elif mode == 'random':
#             embed_randomly(pixels, width, height, binary_data)
#         else:
#             raise ValueError("不支持的嵌入模式")
#
#         # 保存结果图片
#         img.save(path3)
#         print(f"数据嵌入成功，已保存至 {path3}")
#
# def embed_sequentially(pixels, width, height, binary_data):
#     """按顺序在像素中嵌入数据"""
#     index = 0
#     for y in range(height):
#         for x in range(width):
#             if index < len(binary_data):
#                 r, g, b = pixels[x, y]
#                 r = (r & 0xFE) | int(binary_data[index])
#                 index += 1
#                 if index < len(binary_data):
#                     g = (g & 0xFE) | int(binary_data[index])
#                     index += 1
#                 if index < len(binary_data):
#                     b = (b & 0xFE) | int(binary_data[index])
#                     index += 1
#                 pixels[x, y] = (r, g, b)
#             if index >= len(binary_data):
#                 break
#         if index >= len(binary_data):
#             break
#
#
# def embed_randomly(pixels, width, height, binary_data):
#     """随机地在像素中嵌入数据"""
#     total_pixels = width * height
#     if len(binary_data) > total_pixels:
#         raise ValueError("数据过长，无法嵌入到图片中")
#
#     indices = sorted(random.sample(range(total_pixels), len(binary_data)))
#
#     for i, idx in enumerate(indices):
#         y, x = divmod(idx, width)  # 注意这里应该是 y, x 而不是 x, y
#         if x >= width or y >= height:
#             raise IndexError(f"Invalid pixel access at ({x}, {y})")
#         r, g, b = pixels[x, y]
#         bit = int(binary_data[i])
#         channel = random.choice(['r', 'g', 'b'])
#         if channel == 'r':
#             r = (r & 0xFE) | bit
#         elif channel == 'g':
#             g = (g & 0xFE) | bit
#         else:
#             b = (b & 0xFE) | bit
#         pixels[x, y] = (r, g, b)
#
#
# def check_lsb():
#     """从图片中提取顺序嵌入的隐藏数据。"""
#     img = Image.open(path3)
#     pixels = img.load()
#     width, height = img.size
#
#     binary_data = ''.join(str((pixels[x, y][c] & 1)) for y in range(height) for x in range(width) for c in range(3))
#     text_data = ''.join(chr(int(binary_data[i:i + 8], 2)) for i in range(0, len(binary_data), 8))
#
#     marker_start = "<!--HIDDEN_DATA_START-->"
#     marker_end = "<!--HIDDEN_DATA_END-->"
#     start_index = text_data.find(marker_start)
#     end_index = text_data.find(marker_end, start_index + len(marker_start))
#
#     if start_index != -1 and end_index != -1:
#         hidden_data = text_data[start_index + len(marker_start):end_index]
#         print(hidden_data)
#         # 将隐藏数据写入文件
#         with open('F:/Temp/info/hidden_lsb.txt', 'w', encoding='utf-8') as file:
#             file.write(hidden_data)
#         print("隐藏数据已写入F:/Temp/info/hidden_lsb.txt")
#     else:
#         print("没有找到隐藏数据")
