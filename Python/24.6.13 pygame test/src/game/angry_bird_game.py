import sys

import pygame
import pymunk as pm

from game_level.choice_level import ChoiceLevel
from game_level.level import Level
from game_level.welcome import Welcome
from utils.init_resources import init_all_sprite_info


class AngryBirdGame:
    def __init__(self):
        # pygame 初始化
        pygame.init()
        # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
        self.clock = pygame.time.Clock()
        # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
        self.screen = pygame.display.set_mode((658, 370), 0, 32)

        # 设置环境的重力参数
        self.space = pm.Space()
        self.space.gravity = (0.0, -900.0)
        init_all_sprite_info()

        self.welcome = Welcome(self.space, self.screen)
        self.choice_level = ChoiceLevel(self.space, self.screen)
        self.status = "welcome"

        pygame.mixer.init()

    def run(self):
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
                    mouse_pressed = True
                    if self.status == 'choice':
                        no = self.choice_level.choice()
                        print("mouse_left_button_down:" + str(no))
                elif event.type == pygame.MOUSEBUTTONUP and event.button == 1:
                    mouse_up = True
                    print("mouse_left_button_up")

            if self.status == 'welcome':
                self.welcome.run()
                if self.welcome.status == 'end':
                    self.status = 'choice'

            elif self.status == 'choice':
                self.choice_level.run()
                if self.choice_level.status == 'end':
                    level_number = self.choice_level.level_number
                    self.status = "level"
                    self.current_level = Level("level" + str(level_number),
                                               './src/resources/level/level-' + str(level_number) + '.tmx',
                                               self.space, self.screen)
                    self.choice_level.status = "start"
            elif self.status == 'level':
                self.current_level.handel_sling(mouse_pressed, mouse_up)
                self.current_level.run()
                if self.current_level.status == 'end':
                    self.status = 'choice'


            # 每秒显示60帧的频率等待刷新
            self.clock.tick(60)
            # 刷新显示
            pygame.display.flip()
            # 更新环境（根据帧数取值）
            self.space.step(1.0 / 60.0)
