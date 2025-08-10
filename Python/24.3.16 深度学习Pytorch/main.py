from torch.utils.data import Dataset
import cv2 as cv
import os


class MyData(Dataset):
    def __init__(self, root_dir, label_dir):
        self.root_dir = root_dir
        self.label_dir = label_dir
        self.path = os.path.join(self.root_dir, self.label_dir)
        self.img_path = os.listdir(self.path)

    def __getitem__(self, idx):
        img_mane = self.img_path[idx]
        img_item_path = os.path.join(self.root_dir, self.label_dir, img_mane)
        img = cv.imread(img_item_path)
        label = self.label_dir
        return img, label

    def __len__(self):
        return len(self.img_path)

root_dir = "my_data/hymenoptera_data/train"
ants_label = "ants"
bees_label = "bees"
ants_dataset = MyData(root_dir, ants_label)
bees_dataset = MyData(root_dir, bees_label)
train_dataset = ants_dataset + bees_dataset


img1, label1 = ants_dataset[0]
cv.imshow(label1, img1)
cv.waitKey(0)

