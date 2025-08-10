from turtle import Vec2D

import pygame.image
import sys
import pymunk as pm

from game_spirit.material import Material
from game_spirit.pig import Pig
from src.game_spirit.bird import *
from src.utils.init_resources import init_all_sprite_info, get_bird_info, get_material_info, get_pig_info
from src.utils.pm_utils import to_pymunk
from step_sample.level_create import Level


def step17_level_create():
    """
    关卡的创建测试
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

    level1 = Level("level1", './resources/level/level-1.tmx', space, screen)

    # 程序主结构
    while True:
        # 获取事件 包括键盘，鼠标等输入事件
        for event in pygame.event.get():
            # 关闭事件，进行退出处理
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        # 绘制关卡
        level1.run()
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()
        # 更新环境（根据帧数取值）
        space.step(1.0 / 40.0)


if __name__ == '__main__':
    step17_level_create()
