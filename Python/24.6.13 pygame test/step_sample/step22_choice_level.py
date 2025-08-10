from turtle import Vec2D

import pygame.image
import sys
import pymunk as pm

from game_level.choice_level import ChoiceLevel
from src.game_level.welcome import Welcome
from src.game_spirit.bird import *
from step_sample.level_sling import Level
from utils.init_resources import init_all_sprite_info


def step22_choice_level():
    """
    choice的创建测试
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
    init_all_sprite_info()

    choice_level = ChoiceLevel(space, screen)

    # 程序主结构
    while True:
        # 初始化
        mouse_pressed = False
        mouse_up = False
        # 获取事件 包括键盘，鼠标等输入事件
        for event in pygame.event.get():
            # 关闭事件，进行退出处理
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                no = choice_level.choice()

                mouse_pressed = True
                print("mouse_left_button_down:" + str(no))
            elif event.type == pygame.MOUSEBUTTONUP and event.button == 1:
                mouse_up = True
                print("mouse_left_button_up")

        choice_level.run()
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()
        # 更新环境（根据帧数取值）
        space.step(1.0 / 40.0)


if __name__ == '__main__':
    step22_choice_level()
