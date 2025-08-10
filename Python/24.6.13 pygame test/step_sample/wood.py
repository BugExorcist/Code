import math

import pygame.sprite
import pymunk as pm
from pymunk import Vec2d

from src.utils.pm_utils import to_pymunk, to_pygame


class Wood(pygame.sprite.Sprite):
    """
    木头类
    """
    def __init__(self, type, pos, space, surface):
        super(Wood, self).__init__()

        moment = 500
        mass = 20
        # 放大图像倍数
        scale_factor = 1

        self.body = pm.Body(mass, moment)

        self.surface = surface
        self.type = type
        x, y = pos
        horizontal_wood = pygame.image.load("./resources/wood1.png").convert_alpha()
        vertical_wood = pygame.image.load("./resources/wood2.png").convert_alpha()

        if type == "horizontal":
            rect = pygame.Rect(126, 146, 83, 9)
            self.image = horizontal_wood.subsurface(rect).copy()
            x += 85
            y += 12
            # 放大图像
            # original_size = self.image.get_size()
            # new_size = (int(original_size[0] * scale_factor), int(original_size[1] * scale_factor))
            # self.image = pygame.transform.scale(self.image, new_size)

            self.body.position = Vec2d(*to_pymunk(x, y, self.surface))
            self.shape = pm.Poly.create_box(self.body, (83 * scale_factor, 9 * scale_factor))
        elif type == "vertical":
            rect = pygame.Rect(8, 126, 9, 40)
            self.image = vertical_wood.subsurface(rect).copy()
            # 放大图像
            # original_size = self.image.get_size()
            # new_size = (int(original_size[0] * scale_factor), int(original_size[1] * scale_factor))
            # self.image = pygame.transform.scale(self.image, new_size)

            x += 12
            y += 85
            self.body.position = Vec2d(*to_pymunk(x, y, self.surface))
            self.shape = pm.Poly.create_box(self.body, (9 * scale_factor, 40 * scale_factor))

        self.shape.color = (0, 0, 255)
        self.shape.elasticity = 0.95
        self.shape.friction = 0.4
        self.shape.collision_type = 2

        space.add(self.body, self.shape)

    def run(self):
        p = self.body.position
        angle_degrees = math.degrees(self.body.angle) + 180
        rotated_image = pygame.transform.rotate(self.image, angle_degrees)

        offset = Vec2d(*rotated_image.get_size()) / 2
        p = to_pygame(p, self.surface)
        p = p - offset
        self.surface.blit(rotated_image, p)

        ps = [p.rotated(self.body.angle) + self.body.position for p in self.shape.get_vertices()]
        ps.append(ps[0])
        pygame_ps = []
        for item in ps:
            pygame_ps.append(to_pygame(item, self.surface))

        if self.type == "horizontal":
            color = pygame.Color("red")
        else:
            color = pygame.Color("blue")

        pygame.draw.lines(self.surface, color, False, pygame_ps)

        x, y = p
        if self.type == "horizontal":
            self.rect = pygame.Rect(x, y, 9, 83)
        else:
            self.rect = pygame.Rect(x, y, 40, 9)




