import sys
import pygame
import pymunk as pm
from pytmx import TiledObjectGroup

from src.utils.pm_utils import to_pymunk
from step_sample.pygame_demo import TiledRenderer
from step_sample.wood_smail import init_image, SmallWood


def creat_object(tiled_render, space, surface):
    wood_image_dict = init_image()
    wood_group = pygame.sprite.Group()
    static_body = space.static_body
    for layer in tiled_render.tmx_data.visible_layers:
        if isinstance(layer, TiledObjectGroup):
            for obj in layer:
                if obj.name == "box":
                    wood = SmallWood("box", wood_image_dict["box"], obj.x, obj.y, obj.width, obj.height,
                                     space, surface)
                    wood_group.add(wood)

                elif obj.name == "horizontal":
                    wood = SmallWood("horizontal", wood_image_dict["horizontal"], obj.x, obj.y, obj.width,
                                     obj.height, space, surface)
                    wood_group.add(wood)

                elif obj.name == "board":
                    x, y = to_pymunk(obj.x, obj.y, surface)
                    line = pm.Segment(static_body, (0, y), (x + obj.width, y), 1.0)
                    line.elasticity = 0.95
                    line.friction = 1
                    line.collision_type = 1
                    space.add(line)

    return wood_group


def step11_reader_tmx_object():
    space = pm.Space()
    space.gravity = (0.0, -900)
    # pygame 初始化
    pygame.init()
    # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
    clock = pygame.time.Clock()
    # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
    screen = pygame.display.set_mode((660, 370), 0, 32)
    tiled_render = TiledRenderer("./resources/map/map_demo.tmx")
    background = pygame.image.load("./resources/level_1.png").convert()
    wood_group = creat_object(tiled_render, space, screen)


    # 程序主结构
    while True:
        # 获取事件 包括键盘，鼠标等输入事件
        for event in pygame.event.get():
            # 关闭事件，进行退出处理
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        # 绘制背景图像到屏幕上
        screen.blit(background, (0, 0))
        for item in wood_group:
            item.run()
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()
        space.step(1/40)


if __name__ == '__main__':
    step11_reader_tmx_object()

