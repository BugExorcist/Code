import pygame
from pytmx import load_pygame, TiledObjectGroup, TiledImageLayer


class ChoiceLevel:
    def __init__(self, space, surface):
        self.number_group = pygame.sprite.Group()
        self.surface = surface
        self.space = space
        # number 图片
        self.init_number_image()
        # 创建 number精灵对象
        self.create_object()

        self.status = 'start'
        self.level_number = 1


    def init_number_image(self):
        self.number_image = pygame.image.load("./src/resources/images/level/number.png")
        self.number_image_list = []
        y = 0
        for row in range(0, 4):
            x = 0
            for col in range(0, 3):
                image = self.number_image.subsurface(x, y, 179, 170)
                self.number_image_list.append(image)
                x += 179
            y += 170

    def create_object(self):
        self.map_data = load_pygame("./src/resources/level/choice_level.tmx")
        for layer in self.map_data.visible_layers:
            if isinstance(layer, TiledObjectGroup):
                if layer.name != 'level':
                    continue
                for obj in layer:
                    number_sprite = pygame.sprite.Sprite()
                    name = obj.name
                    temp = name.split('-')
                    no = int(temp[1])
                    no -= 1
                    image = self.number_image_list[no]
                    scale_image = pygame.transform.scale(image, (60, 60))
                    number_sprite.image = scale_image
                    number_sprite.rect = pygame.Rect(obj.x, obj.y, 60, 60)
                    number_sprite.no = no + 1
                    self.number_group.add(number_sprite)

            elif isinstance(layer, TiledImageLayer):
                self.background_image = pygame.image.load("./src/resources/images/level/" + layer.image_name).convert()

    def run(self):
        self.surface.blit(self.background_image, (0, 0))
        self.number_group.draw(self.surface)

    def choice(self):
        mouse_x, mouse_y = pygame.mouse.get_pos()
        for item in self.number_group:
            if item.rect.collidepoint(mouse_x, mouse_y):
                self.level_number = item.no
                self.status = 'end'
                return item.no
        return None
