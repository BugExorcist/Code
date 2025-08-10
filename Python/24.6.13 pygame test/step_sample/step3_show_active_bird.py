import pygame.image
import sys

def load_dird_images1():
    """
    通过多张图像来产生动画效果的加载方式
    :return: 图像的数组
    """
    actor_images = []
    for i in range(1, 7):
        #产生文件名
        imagr_file_path = "./resources/bird_{}.png".format(i)
        print(imagr_file_path)
        #加载图像
        image = pygame.image.load(imagr_file_path).convert_alpha()
        actor_images.append(image)
    return actor_images

def load_dird_images2():
    """
    通过单张图片产生动画效果的加载方式
    :return: 图像的数组
    """
    imagr_file_path = "./resources/birds.png"
    image = pygame.image.load(imagr_file_path).convert_alpha()
    actor_images = []
    x = 92
    y = 17
    w = 36
    h = 31
    for i in range(0, 5):
        sub_image = image.subsurface((x, y, w, h))
        actor_images.append(sub_image)
        x += w
    return actor_images


def step3_show_action_birds():
    # pygame 初始化
    pygame.init()
    # 创建游戏时钟 Clock对象帮助我们确定程序要以多少最大的帧速率运行
    clock = pygame.time.Clock()
    # 初始化显示设置，设置窗口大小 set_mode(size=(0, 0), flags=0, depth=0, display=0, vsync=0)
    screen = pygame.display.set_mode((712, 400), 0, 32)
    # 打开图片 并修改像素格式
    background_surface = pygame.image.load("./resources/angry_birds.png").convert()
    actor_bird_images = load_dird_images2()
    no = 0
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
        screen.blit(actor_bird_images[no], (200, 100))
        # 每秒显示40帧的频率等待刷新
        clock.tick(40)
        # 刷新显示
        pygame.display.flip()

        no += 1
        if no >= len(actor_bird_images):
            no = 0


if __name__ == '__main__':
    step3_show_action_birds()