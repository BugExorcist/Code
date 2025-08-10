import math
import random

import pygame
import pymunk as pm
from pymunk import Vec2d

from utils.pm_utils import to_pymunk, to_pygame


class Material(pygame.sprite.Sprite):
    """
    木头类
    """
    def __init__(self, material_info, pos_x, pos_y, space, surface):
        super(Material, self).__init__()

        moment = material_info['moment']
        mass = material_info['mass']
        self.body = pm.Body(mass, moment)
        self.surface = surface
        self.space = space

        image_count = len(material_info['images'])
        index = random.randint(0, image_count - 1)
        self.image = material_info['images'][index]
        x, y, w, h = material_info['image_pos'][index]
        self.width = w
        self.height = h
        self.shape_name = material_info['shape_name']

        if self.shape_name == 'circle':
            self.radius = material_info['radius']
            self.shape = pm.Circle(self.body, self.radius, (0, 0))
        else:
            self.shape = pm.Poly.create_box(self.body, (w, h))
        self.body.position = Vec2d(*to_pymunk(pos_x + w/2, pos_y + h/2, surface))
        # 弹性
        self.shape.elasticity = material_info["elasticity"]
        # 摩擦
        self.shape.friction = material_info["friction"]
        # 碰撞类型
        self.shape.collision_type = material_info["collision_type"]
        # 添加body
        space.add(self.body, self.shape)

    def run(self):
        """
        绘制和运动
        :return:
        """
        p = self.body.position
        angle_degrees = math.degrees(self.body.angle) + 180
        rotated_image = pygame.transform.rotate(self.image, angle_degrees)

        offset = Vec2d(*rotated_image.get_size()) / 2
        p = to_pygame(p, self.surface)
        p = p - offset
        self.surface.blit(rotated_image, p)

        # color = pygame.Color("red")
        # if self.shape_name == "circle":
        #     pygame.draw.circle(self.surface, color, to_pygame(p, self.surface), self.radius, 2)
        # else:
        #     ps = [p.rotated(self.body.angle) + self.body.position for p in self.shape.get_vertices()]
        #     ps.append(ps[0])
        #     pygame_ps = []
        #     for item in ps:
        #         pygame_ps.append(to_pygame(item, self.surface))
        #     pygame.draw.lines(self.surface, color, False, pygame_ps)


