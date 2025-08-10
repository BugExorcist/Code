import pygame.image
import sys

from step_sample.action_bird import ActivateBird


def step4_show_action_birds_by_class():
    """
    通过类调用的方式实现小鸟跳跃
    :return:
    """
    # pygame 初始化
    pygame.init()
    # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
    clock = pygame.time.Clock()
    # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
    screen = pygame.display.set_mode((658, 370), 0, 32)
    # 打开图片 并修改像素格式
    background_surface = pygame.image.load("./resources/welcome.png").convert()
    bird = ActivateBird("./resources/angry_birds.png", 0, 300, screen)

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
        bird.run()
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()


if __name__ == '__main__':
    step4_show_action_birds_by_class()
