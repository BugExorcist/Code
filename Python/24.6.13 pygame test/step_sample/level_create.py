import pygame
from pytmx import load_pygame, TiledObjectGroup, TiledImageLayer
import pymunk as pm

from game_spirit.bird import StandbyBird
from game_spirit.material import Material
from game_spirit.pig import Pig
from utils.init_resources import get_bird_info, get_material_info, get_pig_info, init_all_sprite_info
from utils.pm_utils import to_pymunk


def create_object(level_map_file, space, surface):
    # 资源初始化
    init_all_sprite_info()

    tmx_data = load_pygame(level_map_file)
    static_body = space.static_body
    bird_group = pygame.sprite.Group()
    pig_group = pygame.sprite.Group()
    material_group = pygame.sprite.Group()
    background_file_name = "level_1.png"

    for layer in tmx_data.visible_layers:
        if isinstance(layer, TiledObjectGroup):
            for obj in layer:
                if obj.kind == "bird":
                    bird = StandbyBird(get_bird_info(obj.name), obj.x, obj.y, surface)
                    bird_group.add(bird)
                elif obj.kind == "material":
                    material = Material(get_material_info(obj.name), obj.x, obj.y, space, surface)
                    material_group.add(material)
                elif obj.kind == "board":
                    x, y = to_pymunk(obj.x, obj.y, surface)
                    line = pm.Segment(static_body, (0, y), (x + obj.width, y), 1.0)
                    line.elasticity = 0.95
                    line.friction = 1
                    line.collision_type = 1
                    space.add(line)
                elif obj.kind == "pig":
                    pig = Pig(get_pig_info(obj.name), obj.x, obj.y, space, surface)
                    pig_group.add(pig)

        if isinstance(layer, TiledImageLayer):
            background_file_name = layer.background_file_name

    return bird_group, pig_group, material_group, background_file_name


class Level:
    def __init__(self, name, level_map_file, space, surface):
        self.bird_group, self.pig_group, self.material_group, \
            self.background_file_name = create_object(level_map_file, space, surface)

        self.name = name
        self.apace = space
        self.surface = surface
        self.background_image = pygame.image.load("./resources/images/level/" + self.background_file_name).convert()




    def run(self):
        self.surface.blit(self.background_image, (0, 0))

        for bird in self.bird_group:
            bird.run()

        for material in self.material_group:
            material.run()

        for pig in self.pig_group:
            pig.run()
