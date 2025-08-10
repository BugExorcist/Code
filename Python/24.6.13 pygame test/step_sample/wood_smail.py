import math

import pygame
import pymunk as pm
from pymunk import Vec2d


from src.utils.pm_utils import to_pymunk, to_pygame

position_data = {
    "box": {
        "x": 0,
        "y": 0,
        "width": 40,
        "height": 40
    },
    "horizontal": {
        "x": 147,
        "y": 80,
        "width": 84,
        "height": 12
    }
}


def init_image():
    wood_image = pygame.image.load("./resources/wood1.png").convert_alpha()
    wood_image_dict = {}
    for item in position_data:
        pos = position_data[item]
        rect = pygame.Rect(pos["x"], pos["y"], pos["width"], pos["height"])
        wood_image_dict[item] = wood_image.subsurface(rect).copy()
    return wood_image_dict





class SmallWood(pygame.sprite.Sprite):
    """
    木头类
    """
    def __init__(self, type, image, x, y, w, h, space, surface):
        super(SmallWood, self).__init__()

        moment = 500
        mass = 20

        self.body = pm.Body(mass, moment)

        self.surface = surface
        self.type = type
        self.space = space
        self.image = image
        x = x + w / 2
        y = y + h / 2
        self.body.position = Vec2d(*to_pymunk(x, y, self.surface))
        self.shape = pm.Poly.create_box(self.body, (w, h))
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

        color = pygame.Color("red")
        pygame.draw.lines(self.surface, color, False, pygame_ps)

