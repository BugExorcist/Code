from torch.utils.data import Dataset, DataLoader
from torchvision import transforms
from PIL import Image
import torch
import os
from setting import CODE_TYPE, BATCH_SIZE, SEED, CHAR_NUMBER


class ImageDataSet(Dataset):
    def __init__(self, dir_path):
        super(ImageDataSet, self).__init__()
        # 初始化时，通过遍历目录列出所有图片文件的路径
        self.img_path_list = [f"{dir_path}/{filename}" for filename in os.listdir(dir_path)]
        # 定义图片预处理流程，转换为灰度图并转为Tensor
        self.trans = transforms.Compose([
            transforms.Grayscale(),
            transforms.ToTensor()
        ])

    def __getitem__(self, idx):
        # 根据索引获取图片，并应用预处理流程
        image = self.trans(Image.open(self.img_path_list[idx]))
        # 从图片路径中提取标签，并调用one_hot_encode进行编码
        label = self.img_path_list[idx].split("-")[-1].replace(".png", "")
        label = one_hot_encode(label)
        return image, label

    def __len__(self):
        # 返回数据集的大小
        return len(self.img_path_list)


def one_hot_encode(label):
    # 定义将字符标签转为独热码的函数
    cols = len(SEED)  # 独热码列数，等于字符集大小
    rows = CHAR_NUMBER
    result = torch.zeros((rows, cols), dtype=float)
    for i, char in enumerate(label):
        j = SEED.index(char)  # 查找字符在SEED中的索引
        result[i, j] = 1.0  # 将对应位置设为1
    return result.view(1, -1)[0]  # 将二维张量转换为一维列表


def one_hot_decode(pred_result):
    # 定义将独热码转为字符的函数
    pred_result = pred_result.view(-1, len(SEED))  # 将一维张量转换为二维张量
    index_list = torch.argmax(pred_result, dim=1)  # 获取每行最大值索引
    text = "".join([SEED[i] for i in index_list])  # 根据索引从SEED中查找字符并拼接
    return text


def get_loader(path):
    # 定义加载数据的函数
    dataset = ImageDataSet(path)  # 创建数据集对象
    dataloader = DataLoader(dataset, BATCH_SIZE, shuffle=True)  # 创建数据加载器
    return dataloader


if __name__ == '__main__':
    # 主程序入口
    train_dataloader = get_loader(f"./data/train_{CODE_TYPE}")  # 创建训练数据加载器
    test_dataloader = get_loader(f"./data/test_{CODE_TYPE}")  # 创建测试数据加载器
    for X, y in train_dataloader:
        print(X.shape)  # 打印训练数据图片张量的形状
        print(y.shape)  # 打印训练数据标签张量的形状
        break  # 只打印第一批数据的形状