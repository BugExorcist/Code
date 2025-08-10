# pygame程序基本结构演示1

import pygame
import sys

def step2_show_image():
    # pygame 初始化
    pygame.init()
    # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
    clock = pygame.time.Clock()
    # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
    screen = pygame.display.set_mode((712, 400), 0, 32)
    # 打开图片 并修改像素格式
    # the pygame.image.load() function can support the following formats.
    #         BMP
    #         GIF (non-animated)
    #         JPEG
    #         LBM (and PBM, PGM, PPM)
    #         PCX
    #         PNG
    #         PNM
    #         SVG (limited support, using Nano SVG)
    #         TGA (uncompressed)
    #         TIFF
    #         WEBP
    #         XPM
    background_surface = pygame.image.load("./resources/angry_birds.png").convert()
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
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()


if __name__ == '__main__':
    step2_show_image()