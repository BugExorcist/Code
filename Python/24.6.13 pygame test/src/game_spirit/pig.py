import pygame
import pymunk as pm

from game_spirit import ActionByMulti
from utils.pm_utils import to_pymunk, to_pygame


class Pig(pygame.sprite.Sprite):
    """
    猪类
    """
    mass = 40  # 质量

    def __init__(self, pig_info, pos_x, pos_y, space, surface):
        super(Pig, self).__init__()

        self.surface = surface
        self.space = space
        self.radius = pig_info["radius"]
        self.mass = pig_info["mass"]

        # pymunk   旋转力矩
        inertia = pm.moment_for_circle(self.mass, 0, self.radius, (0, 0))
        self.body = pm.Body(self.mass, inertia)
        self.body.position = to_pymunk(pos_x + self.radius, pos_y + self.radius, surface)
        # 形状
        self.shape = pm.Circle(self.body, self.radius, (0, 0))
        # 弹性
        self.shape.elasticity = pig_info["elasticity"]
        # 摩擦
        self.shape.friction = pig_info["friction"]
        # 碰撞类型
        self.shape.collision_type = pig_info["collision_type"]
        # 添加body
        self.space.add(self.body, self.shape)

        self.action = ActionByMulti(pig_info['images'], True)

    def run(self):
        """
        运动和绘制
        :return:
        """
        self.pos_x, self.pos_y = to_pygame(self.body.position, self.surface)
        # 返回是物体的中心，还要减去半径 变成图片加载位置
        self.pos_x -= self.radius
        self.pos_y -= self.radius

        current_image = self.action.get_image()
        self.surface.blit(current_image, (self.pos_x, self.pos_y))

        # pygame.draw.circle(self.surface, (0, 0, 255),
        #                    (self.pos_x + self.radius, self.pos_y + self.radius),
        #                    self.radius, 4)
