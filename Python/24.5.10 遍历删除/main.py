#把一个文件夹中所有文件夹下命名类似为 abc删除d 的文件删除其中的‘删除’字符 如 abc删除d -> abcd
import os
import subprocess

# 处理文件名称 并且解压rar文件
# zip_file_path 压缩包路径
# output_folder 解压输出路径

password = 'www.cyzd.me次元终点'  # 解压密码，如果无密码则设为 None
def traverse_folders(root_folder):
    for foldername in os.listdir(root_folder): #得到目标文件夹中每个文件的名称
        folder_path = os.path.join(root_folder, foldername)
        if os.path.isdir(folder_path):
            for filename in os.listdir(folder_path):
                str = filename[-3:-1]
                if str == '删除':
                    new_filename = filename.replace('删除', '')
                    old_filepath = os.path.join(folder_path, filename)
                    new_filepath = os.path.join(folder_path, new_filename)
                    os.rename(old_filepath, new_filepath)
                    print(new_filepath)
                    extract_rar_with_7z(new_filepath, password)


def extract_rar_with_7z(rar_path, password=None):
    # 获取压缩包所在的目录
    extract_to = os.path.dirname(rar_path)

    # 确保解压路径存在
    if not os.path.exists(extract_to):
        os.makedirs(extract_to)

    try:
        # 构建解压命令，使用完整的 7z.exe 路径
        command = [r'C:\Apps\7-Zip\7z.exe', 'x', rar_path, f'-o{extract_to}']
        if password:
            command.append(f'-p{password}')  # 添加密码选项

        # 打印完整命令
        print(f"执行命令: {' '.join(command)}")

        # 调用 subprocess 运行 7z 命令并捕获输出
        print(f"正在使用 7z 解压文件: {rar_path}")

        # 使用 Popen 允许我们实时读取输出并捕获错误
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)

        # 逐行读取 7z 的输出并显示
        for line in process.stdout:
            print(line.strip())  # 显示 7z 的每一行输出

            # 解析输出中的进度信息
            if '%' in line:
                print(f"当前进度: {line.strip()}")

        # 读取并显示错误输出
        stderr_output = process.stderr.read()
        if stderr_output:
            print(f"错误输出: {stderr_output.strip()}")

        process.wait()

        # 检查进程是否成功完成
        if process.returncode == 0:
            print(f"解压成功: {rar_path}")
        else:
            print(f"解压失败，错误代码: {process.returncode}")

    except Exception as e:
        print(f"发生错误: {e}")

# 删除.rar
def del_zip(root_folder):
    for foldername in os.listdir(root_folder): #得到目标文件夹中每个文件的名称
        folder_path = os.path.join(root_folder, foldername)
        if os.path.isdir(folder_path):
            for filename in os.listdir(folder_path):
                str = filename[-3:]
                if str == 'rar':
                    target_filepath = os.path.join(folder_path, filename)
                    try:
                        os.remove(target_filepath)
                    except OSError as e:
                        print(f"删除文件 '{target_filepath}' 时出错：{e}")

import time
from moviepy.editor import *
def get_audio(video_path, audio_path):
    st = time.time()
    video = VideoFileClip(video_path)
    audio = video.audio
    audio.write_audiofile(audio_path, codec='flac')
    print("消耗时间：{}".format(time.time() - st))

def batch_audio(root_folder, audio_path):
    for foldername in os.listdir(root_folder): #得到目标文件夹中每个文件的名称
        folder_path = os.path.join(root_folder, foldername)
        if os.path.isdir(folder_path):
            for filename in os.listdir(folder_path):
                suffix = filename[-3:]
                if suffix == 'mp4':
                    st = time.time()
                    audio_name = foldername + filename[:-4] + ".flac"
                    video_path = os.path.join(folder_path, filename)
                    video = VideoFileClip(video_path)
                    audio = video.audio
                    new_audio_path = os.path.join(audio_path, audio_name)
                    audio.write_audiofile(new_audio_path, codec='flac')
                    print("消耗时间：{}".format(time.time() - st))


# 替换文件夹集合根目录
root_folder = "F:/BaiduNetdiskDownload/1a"

# 处理文件名称 并且解压
traverse_folders(root_folder)

# 删除.zip
#del_zip(root_folder)

# # 处理视频音频
# video_path = 'F:/FFOutput/a1/20240517 2049/c4a55146_2024-05-16_23-38-34.mp4'
# audio_path = 'F:/FFOutput/b2/audiob2'
# # get_audio(video_path, audio_path)
# batch_audio(root_folder, audio_path)
