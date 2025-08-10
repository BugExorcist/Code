import os
import torch
from PIL import Image
from train import NeuralNetWork
from dataset import one_hot_decode
from torchvision import transforms
from setting import CODE_TYPE

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

def predict(model, file_path):
    trans = transforms.Compose([
        transforms.Grayscale(),
        transforms.Resize((60, 160)),  # 确保图像大小与模型期望的输入大小一致
        transforms.ToTensor()
    ])
    # 使用to()方法确保图像张量被转移到正确的设备上
    with torch.no_grad():
        image = Image.open(file_path).convert('L')  # Convert image to grayscale if it's not already
        X = trans(image).unsqueeze(0).to(device)  # 增加batch维度并移动到指定设备上
        pred = model(X)  # 模型的forward操作将在指定设备上执行
        # 如果one_hot_decode函数需要在CPU上执行，则需要将pred移回CPU
        if pred.device != torch.device('cpu'):
            pred = pred.cpu()
        text = one_hot_decode(pred)
        return text


def main():
    model = NeuralNetWork().to(device)  # 将模型移动到指定设备上
    model.load_state_dict(torch.load(f"./data/model_{CODE_TYPE}.pth", map_location=device))  # 加载模型状态到指定设备
    model.eval()
    correct = 0
    test_dir = f"./data/test_{CODE_TYPE}"
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
    print(f"Accuracy: {accuracy}")

if __name__ == '__main__':
    main()