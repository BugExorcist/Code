import pygame
from pymunk import Vec2d
from pytmx import load_pygame, TiledObjectGroup, TiledImageLayer
import pymunk as pm

from game_spirit.bird import StandbyBird, Bird
from game_spirit.material import Material
from game_spirit.pig import Pig
from utils.init_resources import get_bird_info, get_material_info, get_pig_info, init_all_sprite_info, get_sling_image
from utils.pm_utils import to_pymunk

SLING_HEIGHT = 105
LEFT_SLING_WIDTH = 15
BIRD_START_Y = 10

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
                    border_y = obj.y
                elif obj.kind == "pig":
                    pig = Pig(get_pig_info(obj.name), obj.x, obj.y, space, surface)
                    pig_group.add(pig)
                elif obj.kind == 'sling':
                    sling_x = obj.x

        if isinstance(layer, TiledImageLayer):
            background_file_name = layer.background_file_name
    sling_y = border_y - SLING_HEIGHT
    return bird_group, pig_group, material_group, background_file_name, sling_x, sling_y


def post_solve_collision(arbiter, space, data):
    """
    py碰撞后处理
    :param arbiter:
    :param space:
    :param data:
    :return:
    """
    count = len(arbiter.shapes)
    # print(count)
    # print("碰撞了")
    for item in data["pigs"]:
        if item is not None and arbiter.shapes[1] == item.shape:
            print("碰到了一只小猪")
            data["pigs"].remove(item)


class Level:
    def __init__(self, name, level_map_file, space, surface):
        self.bird_group, self.pig_group, self.material_group, \
            self.background_file_name, self.sling_x, self.sling_y = create_object(level_map_file, space, surface)

        self.name = name
        self.space = space
        self.surface = surface
        # 加载背景图像
        self.background_image = pygame.image.load("./resources/images/level/" + self.background_file_name).convert()
        self.full_sling_image, self.left_sling_image, self.right_sling_image = get_sling_image()
        self.current_standby_bird = None
        self.pm_bird_group = pygame.sprite.Group()
        self.sling_click = False
        self.set_new_bird()

        # 碰撞后处理
        handler = space.add_collision_handler(0, 2)
        handler.data["pigs"] = self.pig_group
        handler.post_solve = post_solve_collision

    def set_new_bird(self):
        if len(self.bird_group) == 0:
            self.current_standby_bird = None
            return

        for bird in self.bird_group:
            self.current_standby_bird = bird
            break
        self.current_standby_bird.pos_x = self.sling_x
        self.current_standby_bird.pos_y = self.sling_y + BIRD_START_Y

    def send_pm_bird(self, mouse_x, mouse_y):
        pm_x, pm_y = to_pymunk(mouse_x, mouse_y, self.surface)
        pm_sling_x, pm_sling_y = to_pymunk(self.sling_x, self.sling_y, self.surface)
        bird = Bird(self.current_standby_bird.bird_info, self.current_standby_bird.pos_x, self.current_standby_bird.pos_y,
                    Vec2d(pm_sling_x - pm_x, pm_sling_y - pm_y), self.space, self.surface)

        self.pm_bird_group.add(bird)
        self.bird_group.remove(self.current_standby_bird)
        self.current_standby_bird = None

    def run(self):
        self.surface.blit(self.background_image, (0, 0))
        self.surface.blit(self.right_sling_image, (self.sling_x + LEFT_SLING_WIDTH, self.sling_y))

        for bird in self.bird_group:
            bird.run()

        for material in self.material_group:
            material.run()

        for pig in self.pig_group:
            pig.run()

        for bird in self.pm_bird_group:
            bird.run()

        self.draw_sling()
        self.surface.blit(self.left_sling_image, (self.sling_x, self.sling_y))

    def draw_sling(self):
        sling_x, sling_y = self.sling_x, self.sling_y + BIRD_START_Y
        sling2_x, sling2_y = sling_x + 30, sling_y
        if self.sling_click:
            mouse_x, mouse_y = pygame.mouse.get_pos()

            pygame.draw.line(self.surface, (0, 0, 0), (sling_x, sling_y), (mouse_x, mouse_y), 4)
            pygame.draw.line(self.surface, (0, 0, 0), (sling2_x, sling2_y), (mouse_x, mouse_y), 4)
            pygame.draw.circle(self.surface, (0, 0, 0), (sling_x, sling_y), 5)
            pygame.draw.circle(self.surface, (0, 0, 0), (sling2_x, sling2_y), 5)

    def handel_sling(self, mouse_pressed, mouse_up):
        mouse_x, mouse_y = pygame.mouse.get_pos()
        if mouse_pressed and self.current_standby_bird is not None:
            if mouse_x > self.current_standby_bird.pos_x\
                and mouse_x < self.current_standby_bird.pos_x + self.current_standby_bird.radius * 2\
                and mouse_y > self.current_standby_bird.pos_y\
                and mouse_y < self.current_standby_bird.pos_y + self.current_standby_bird.radius * 2:

                self.sling_click = True
        elif self.sling_click:
            self.current_standby_bird.pos_x, self.current_standby_bird.pos_y = mouse_x, mouse_y
            if mouse_up:
                self.sling_click = False
                self.send_pm_bird(mouse_x, mouse_y)
                self.set_new_bird()