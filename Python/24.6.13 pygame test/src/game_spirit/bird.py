import pygame.sprite
import pymunk as pm

from src.game_spirit import ActionByMulti
from src.utils.pm_utils import *


class StandbyBird(pygame.sprite.Sprite):
    """
    站立的小鸟类
    """
    def __init__(self, bird_info, pos_x, pos_y, surface):
        super(StandbyBird, self).__init__()

        self.surface = surface
        self.action = ActionByMulti(bird_info['images'], True)
        self.pos_x = pos_x
        self.pos_y = pos_y
        self.radius = bird_info['radius']
        self.bird_info = bird_info

    def run(self):
        """
        绘制
        :return:
        """
        current_image = self.action.get_image()
        self.surface.blit(current_image, (self.pos_x, self.pos_y))
        # 绘制外框
        # pygame.draw.circle(self.surface, (0, 0, 255),
        #                    (self.pos_x + self.radius, self.pos_y + self.radius),
        #                    self.radius, 4)


class Bird(pygame.sprite.Sprite):
    """
    飞行的小鸟类
    """
    mass = 40  # 质量
    #                                            冲力
    def __init__(self, bird_info, pos_x, pos_y, impulse, space, surface):
        super(Bird, self).__init__()
        # 冲力比较小，所以要乘一个数值，这个数值可以放在bird_info中因为不同的鸟可能冲力不同
        self.impulse = impulse * 150
        self.surface = surface
        self.space = space
        self.radius = bird_info["radius"]
        self.mass = bird_info["mass"]

        # pymunk   旋转力矩
        inertia = pm.moment_for_circle(self.mass, 0, self.radius, (0, 0))
        self.body = pm.Body(self.mass, inertia)
        self.body.position = to_pymunk(pos_x + self.radius, pos_y + self.radius, surface)
        # 冲力
        self.body.apply_impulse_at_local_point(self.impulse)
        # 形状
        self.shape = pm.Circle(self.body, self.radius, (0, 0))
        # 弹性
        self.shape.elasticity = bird_info["elasticity"]
        # 摩擦
        self.shape.friction = bird_info["friction"]
        # 碰撞类型
        self.shape.collision_type = bird_info["collision_type"]
        # 添加body
        self.space.add(self.body, self.shape)

        self.action = ActionByMulti(bird_info['images'], True)


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

