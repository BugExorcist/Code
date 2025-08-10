# loader.py
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms
from PIL import Image
import torch
import os
from setting import CODE_TYPE, BATCH_SIZE, SEED, CHAR_NUMBER


class ImageDataSet(Dataset):
    def __init__(self, dir_path):
        super(ImageDataSet, self).__init__()
        self.img_path_list = [f"{dir_path}/{filename}" for filename in os.listdir(dir_path)]
        self.trans = transforms.Compose([
            transforms.ToTensor(),
            transforms.Grayscale()  # 每张图片都会被这行代码灰度化
        ])

    def __getitem__(self, idx):
        image = self.trans(Image.open(self.img_path_list[idx]))
        label = self.img_path_list[idx].split("-")[-1].replace(".png", "")
        label = one_hot_encode(label)
        return image, label

    def __len__(self):
        return len(self.img_path_list)


# 用torch.zeros()函数生成一个4行36列，值全是0的张量。接着循环标签中的各个字符，将字符在SEED中对应的索引获取到，然后将张量中对应位置的0，改成1。最后我们要返回一个一维的列表，长度是4*36=144
def one_hot_encode(label):
    """将字符转为独热码"""
    cols = len(SEED)
    rows = CHAR_NUMBER
    result = torch.zeros((rows, cols), dtype=float)
    for i, char in enumerate(label):
        j = SEED.index(char)
        result[i, j] = 1.0
    return result.view(1, -1)[0]


# 将模型预测的值从一维转成4行36列的二维张量，然后调用torch.argmax()函数寻找每一行最大值（也就是1）的索引。知道索引后就可以从SEED中找到对应的字符
def one_hot_decode(pred_result):
    """将独热码转为字符"""
    pred_result = pred_result.view(-1, len(SEED))
    index_list = torch.argmax(pred_result, dim=1)
    text = "".join([SEED[i] for i in index_list])
    return text


def get_loader(path):
    """加载数据"""
    dataset = ImageDataSet(path)
    dataloader = DataLoader(dataset, BATCH_SIZE, shuffle=True)
    return dataloader


if __name__ == '__main__':
    train_dataloader = get_loader(f"./train_{CODE_TYPE}")
    test_dataloader = get_loader(f"./test_{CODE_TYPE}")
    for X, y in train_dataloader:
        print(X.shape)
        print(y.shape)
        break
