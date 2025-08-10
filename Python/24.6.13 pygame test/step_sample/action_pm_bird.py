import pygame.sprite
import pymunk as pm
from pymunk import Vec2d

from src.utils.pm_utils import *
from step_sample.action_multi_image import ActionByMultiImage


class ActivatePmBird(pygame.sprite.Sprite):
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

    mass = 40  # 质量
    radius = 17  # 半径

    def __init__(self, image_part: str, pos_x, pos_y, space, surface):
        super(ActivatePmBird, self).__init__()
        # pygame
        self.surface = surface
        self.action = ActionByMultiImage(image_part, self.image_start_x, self.image_start_y,
                                         self.image_width, self.image_height, 1, 4, True)
        self.init_x = pos_x
        self.init_y = pos_y

        self.pos_x = pos_x
        self.pos_y = pos_x

        self.rect = pygame.Rect(pos_x, pos_y, self.image_width, self.image_height)

        # pymunk
        self.space = space
        inertia = pm.moment_for_circle(self.mass, 0, self.radius, (0, 0))  # 惯性
        self.body = pm.Body(self.mass, inertia)
        self.body.position = to_pymunk(pos_x + self.radius, pos_y + self.radius, self.surface)
        impulse = Vec2d(150, 50) * 50  # 冲量向量
        self.body.apply_impulse_at_local_point(impulse)
        self.shape = pm.Circle(self.body, self.radius, (0, 0))
        self.shape.elasticity = 0.95  # 弹性
        self.shape.friction = 1  # 摩擦系数
        self.shape.collision_type = 0
        self.space.add(self.body, self.shape)

    def run(self):
        """
        运动和绘制
        :return:
        """
        self.pos_x, self.pos_y = to_pygame(self.body.position, self.surface)
        # 返回是物体的中心，还要减去半径
        self.pos_x -= self.radius
        self.pos_y -= self.radius

        current_image = self.action.get_image()
        self.surface.blit(current_image, (self.pos_x, self.pos_y))
        pygame.draw.circle(self.surface, (0, 0, 255),
                           (self.pos_x + self.radius, self.pos_y + self.radius),
                           self.radius, 4)
        self.rect = pygame.Rect(self.pos_x, self.pos_y, 2 * self.radius, 2 * self.radius)