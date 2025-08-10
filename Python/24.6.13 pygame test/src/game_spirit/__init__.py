import pygame

class ActionByMulti:
    """
    多张图片的动作管理
    """

    def __init__(self, images, is_loop: bool):
        """
        初始化
        """
        self.image_index = 0
        self.action_images = images
        self.is_loop = is_loop
        self.image_count = len(images)

    def get_image(self) -> pygame.surface.Surface:
        """
        获取当前显示的图片
        :return: surface图像
        """
        current_image = self.action_images[self.image_index]
        self.image_index += 1
        if self.image_index >= len(self.action_images):
            if self.is_loop:
                self.image_index = 0
            else:
                self.image_index -= 1
        return current_image

    def is_end(self) -> bool:
        """
        判断图片轮播是否结束
        :return:
        """
        if self.is_loop:
            return False
        else:
            if self.image_index == len(self.action_images) - 1:
                return True
            else:
                return False