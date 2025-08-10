from turtle import Vec2D

import pygame.image
import sys
import pymunk as pm

from game_spirit.material import Material
from src.game_spirit.bird import *
from src.utils.init_resources import init_all_sprite_info, get_bird_info, get_material_info
from src.utils.pm_utils import to_pymunk


def step15_show_material():
    """
    材料类测试
    :return:
    """
    # pygame 初始化
    pygame.init()
    # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
    clock = pygame.time.Clock()
    # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
    screen = pygame.display.set_mode((658, 370), 0, 32)

    # 设置环境的重力参数
    space = pm.Space()
    space.gravity = (0.0, -900.0)
    # 资源初始化
    init_all_sprite_info()

    # 打开图片 并修改像素格式
    background_surface = pygame.image.load("./resources/images/welcome.png").convert()
    # 小鸟
    # standby_bird = StandbyBird(get_bird_info('redBird'), 50, 50, screen)
    # red_bird = Bird(get_bird_info('redBird'), 20, 100, Vec2D(150, 50), space, screen)
    # blue_bird = Bird(get_bird_info('blueBird'), 120, 100, Vec2D(150, 50), space, screen)
    # 材料
    material = Material(get_material_info("boxWood"), 100, 50, space, screen)



    x, y = to_pymunk(screen.get_width(), screen.get_height(), screen)  # x = 658 y = 0
    static_body = space.static_body
    static_lines = [pm.Segment(static_body, (0.0, y), (x, y), 0)]
    for line in static_lines:
        line.elasticity = 0.95
        line.friction = 1
        line.collision_type = 1

    space.add(*static_lines)

    # 程序主结构
    while True:
        # 获取事件 包括键盘，鼠标等输入事件
        for event in pygame.event.get():
            # 关闭事件，进行退出处理
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        # 绘制背景图像到屏幕上
        screen.blit(background_surface, (0, 0))
        # 绘制小鸟的图像
        # standby_bird.run()
        # red_bird.run()
        # blue_bird.run()
        # 绘制材料图形
        material.run()
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()
        # 更新环境（根据帧数取值）
        space.step(1.0 / 40.0)


if __name__ == '__main__':
    step15_show_material()
