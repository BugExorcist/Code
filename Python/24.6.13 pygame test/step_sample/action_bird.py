import pygame.sprite

from step_sample.action_multi_image import ActionByMultiImage


class ActivateBird(pygame.sprite.Sprite):
    """
    活动的小鸟类
    """
    pos_x = 100
    pos_y = 200
    image_width = 36
    image_height = 31
    image_start_x = 92
    image_start_y = 17

    speed_x = 5
    speed_y = 20

    def __init__(self, image_part: str, pos_x, pos_y, surface):
        super(ActivateBird, self).__init__()
        self.surface = surface
        self.action = ActionByMultiImage(image_part, self.image_start_x, self.image_start_y,
                                         self.image_width, self.image_height, 1, 4, True)
        self.init_x = pos_x
        self.init_y = pos_y

        self.pos_x = pos_x
        self.pos_y = pos_x

        self.rect = pygame.Rect(pos_x, pos_y, self.image_width, self.image_height)

    def move(self):
        if self.pos_x >= 658:  # 背景的像素长度
            self.pos_x = self.init_x
            self.pos_y = self.init_y
            return

        self.pos_x += self.speed_x
        self.pos_y -= self.speed_y
        self.speed_y -= 3
        if self.speed_y <= -30:
            self.speed_y = 20
            self.pos_y = self.init_y

    def run(self):
        """
        运动和绘制
        :return:
        """
        current_image = self.action.get_image()
        self.surface.blit(current_image, (self.pos_x, self.pos_y))
        self.move()
