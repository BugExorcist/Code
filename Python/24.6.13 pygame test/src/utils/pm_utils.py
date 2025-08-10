def to_pygame(p, surface):
    """
    转换pymunk坐标到pygame
    :param p: 位置信息
    :param surface: 窗口屏幕
    :return: pygame下的坐标
    """
    return int(p.x), int(-p.y + surface.get_height())


def to_pymunk(x, y, surface):
    """
    转换pygame坐标到pymunk
    :param x:
    :param y:
    :param surface: 窗口屏幕
    :return: pymunk 坐标
    """
    return x, surface.get_height() - y
