# main.py
import os
import torch
from PIL import Image
from train import NeuralNetWork
from loader import one_hot_decode
from torchvision import transforms
from setting import CODE_TYPE

device = "cuda" if torch.cuda.is_available() else "cpu"


def predict(model, file_path):
    trans = transforms.Compose([
        transforms.Grayscale(),  # 先转换为灰度图
        transforms.ToTensor(),  # 再转换为张量
    ])
    with torch.no_grad():
        image = Image.open(file_path)
        X = trans(image).unsqueeze(0).to(device)  # 增加一个batch维度，并移动到指定设备
        pred = model(X)
        text = one_hot_decode(pred)
        return text


def main():
    model = NeuralNetWork().to(device)
    model.load_state_dict(torch.load(f"./model_{CODE_TYPE}.pth", map_location=torch.device("cpu")))
    model.eval()

    correct = 0
    test_dir = f"./test_{CODE_TYPE}"
    total = len(os.listdir(test_dir))
    for filename in os.listdir(test_dir):
        file_path = f"{test_dir}/{filename}"
        real_captcha = file_path.split("-")[-1].replace(".png", "")
        pred_captcha = predict(model, file_path)
        if pred_captcha == real_captcha:
            correct += 1
            print(f"{file_path}的预测结果为{pred_captcha}，预测正确")
        else:
            print(f"{file_path}的预测结果为{pred_captcha}，预测错误")
    accuracy = f"{correct / total * 100:.2f}%"
    print(accuracy)


if __name__ == '__main__':
    main()
