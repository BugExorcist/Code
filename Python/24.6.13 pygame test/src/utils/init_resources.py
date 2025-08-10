import copy

import pygame

BIRD_INFO = []
MATERIAL_INFO = []
PIG_INFO = []
FULL_SLING_IMAGE = None
LEFT_SLING_IMAGE = None
RIGHT_SLING_IMAGE = None
SCREEN_WIDTH = 658
SCREEN_HEIGHT = 370

# 木头
wood_elasticity = 0.1  # 弹性


def init_sub_image(image, positions):
    all_info = []
    for item in positions:
        images = []
        for item_pos in item['image_pos']:
            print(item_pos)
            sub_image = image.subsurface(item_pos)
            images.append(sub_image)
        item["images"] = images
        all_info.append(item)
    return all_info


# 小鸟类资源
def init_bird_info():
    bird_image_path = "./src/resources/images/angry_birds.png"
    bird_image = pygame.image.load(bird_image_path).convert_alpha()
    bird_all_info = [
        {
            "name": "redBird",  # 对象名称类型
            "shape_name": "circle",  # 形状
            "radius": 17,  # 如果是圆形包含半径
            "elasticity": 0.95,  # 摩擦力
            "friction": 1,  # 弹性
            "mass": 40,  # 质量
            "collision_type": 0,  # 碰撞类型组
            "moment": 1000,  # 力矩
            "image_pos": [  # 图片位置信息
                (90, 15, 35, 35),
                (128, 15, 35, 35),
                (165, 15, 35, 35),
                (200, 15, 35, 35),
                (236, 15, 35, 35)
            ]
        },
        {
            "name": "blueBird",
            "shape_name": "circle",
            "radius": 12,
            "elasticity": 0.95,
            "friction": 1,
            "mass": 30,
            "moment": 1000,
            "collision_type": 0,
            "image_pos": [
                (107, 66, 25, 25),
                (135, 66, 25, 25),
                (166, 66, 25, 25),
                (200, 66, 25, 25),
                (230, 66, 25, 25)
            ]
        }
    ]

    global BIRD_INFO
    BIRD_INFO = init_sub_image(bird_image, bird_all_info)


# 其他资源
def init_material_info():
    material_image_path = "./src/resources/images/wood3.png"
    material_image = pygame.image.load(material_image_path).convert_alpha()
    material_all_info = [
        {
            "name": "longWood",
            "shape_name": "rect",  # 方形
            "elasticity": wood_elasticity,  # 弹性
            "friction": 0.4,  # 摩擦力
            "mass": 30,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (207, 220, 104, 12),
                (207, 232, 104, 12),
                (207, 244, 104, 12),
                (207, 256, 104, 12)
            ]
        },
        {
            "name": "mediumWood",
            "shape_name": "rect",  # 方形
            "elasticity": wood_elasticity,  # 弹性
            "friction": 1,  # 摩擦力
            "mass": 30,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (313, 234, 80, 12),
                (313, 245, 80, 12),
                (313, 256, 80, 12),
                (313, 267, 80, 12),
            ]
        },
        {
            "name": "shortWood",
            "shape_name": "rect",  # 方形
            "elasticity": wood_elasticity,  # 弹性
            "friction": 0.4,  # 摩擦力
            "mass": 30,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (310, 285, 42, 11),
                (310, 296, 42, 11),
                (352, 275, 42, 11),
                (268, 0, 42, 11)
            ]
        },
        {
            "name": "boxWood",
            "shape_name": "rect",  # 方形
            "elasticity": wood_elasticity,  # 弹性
            "friction": 0.4,  # 摩擦力
            "mass": 30,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (42, 0, 42, 42),
                (84, 0, 42, 42),
                (126, 0, 42, 42),
                (168, 0, 42, 42)
            ]
        },
        {
            "name": "bigCircleWood",
            "shape_name": "circle",  # 圆形
            "radius": 21,  # 半径
            "elasticity": wood_elasticity,  # 弹性
            "friction": 0.4,  # 摩擦力
            "mass": 30,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (128, 88, 42, 42),
                (170, 88, 42, 42),
                (212, 88, 42, 42)
            ]
        },
        {
            "name": "smallCircleWood",
            "shape_name": "circle",  # 圆形
            "radius": 10,  # 半径
            "elasticity": wood_elasticity,  # 弹性
            "friction": 0.4,  # 摩擦力
            "mass": 50,
            "moment": 5000,
            "collision_type": 1,
            "image_pos": [
                (190, 210, 20, 20),
                (190, 230, 20, 20),
                (190, 250, 20, 20),
                (190, 270, 20, 20)
            ]
        }
    ]

    global MATERIAL_INFO
    MATERIAL_INFO = init_sub_image(material_image, material_all_info)


# 猪资源
def init_pig_info():
    pig_image_path = "./src/resources/images/pig.png"
    pig_image = pygame.image.load(pig_image_path).convert_alpha()
    pig_all_info = [
        {
            "name": "pig",
            "shape_name": "circle",  # 圆形
            "radius": 21,  # 半径
            "elasticity": 0,  # 弹性
            "friction": 1,  # 摩擦力
            "collision_type": 2,
            "mass": 50,
            "moment": 100,
            "image_pos": [
                # (218, 356, 42, 40),
                (217, 397, 42, 40),
                # (220, 437, 42, 40),
            ]
        },
        {
            "name": "helmetPig",
            "shape_name": "circle",  # 圆形
            "radius": 24,  # 半径
            "elasticity": 0,  # 弹性
            "friction": 1,  # 摩擦力
            "collision_type": 2,
            "mass": 50,
            "moment": 5000,
            "image_pos": [
                (217, 256, 49, 45),
                (268, 65, 49, 45),
                (315, 65, 49, 45),
                (363, 65, 49, 45)
            ]
        }
    ]

    global PIG_INFO
    PIG_INFO = init_sub_image(pig_image, pig_all_info)


# 弹弓资源
def init_sling_info():
    global FULL_SLING_IMAGE
    FULL_SLING_IMAGE = pygame.image.load("./src/resources/images/sling.png")
    FULL_SLING_IMAGE = pygame.transform.scale(FULL_SLING_IMAGE,
                                              (int(FULL_SLING_IMAGE.get_width() / 2),
                                               int(FULL_SLING_IMAGE.get_height() / 2)))

    sling_image = pygame.image.load("./src/resources/images/sling1.png")

    global LEFT_SLING_IMAGE
    global RIGHT_SLING_IMAGE

    LEFT_SLING_IMAGE = sling_image.subsurface((13, 1, 49, 135))
    RIGHT_SLING_IMAGE = sling_image.subsurface((97, 1, 44, 210))
    LEFT_SLING_IMAGE = pygame.transform.scale(LEFT_SLING_IMAGE,
                                              (int(LEFT_SLING_IMAGE.get_width() / 2),
                                               int(LEFT_SLING_IMAGE.get_height() / 2)))
    RIGHT_SLING_IMAGE = pygame.transform.scale(RIGHT_SLING_IMAGE,
                                               (int(RIGHT_SLING_IMAGE.get_width() / 2),
                                                int(RIGHT_SLING_IMAGE.get_height() / 2)))


def init_all_sprite_info():
    init_bird_info()
    init_material_info()
    init_pig_info()
    init_sling_info()


def get_sling_image():
    return FULL_SLING_IMAGE, LEFT_SLING_IMAGE, RIGHT_SLING_IMAGE


def get_bird_info(name):
    global BIRD_INFO
    for item in BIRD_INFO:
        if item["name"] == name:
            return item
    return None


def get_material_info(name):
    global MATERIAL_INFO
    for item in MATERIAL_INFO:
        if item["name"] == name:
            return item
    return None


def get_pig_info(name):
    global PIG_INFO
    for item in PIG_INFO:
        if item["name"] == name:
            return item
    return None
