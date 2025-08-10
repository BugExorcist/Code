import pygame
import pymunk as pm
from pymunk import Vec2d

from game_spirit.bird import Bird
from utils.init_resources import get_bird_info, SCREEN_WIDTH, SCREEN_HEIGHT
from utils.pm_utils import to_pymunk, to_pygame


class Welcome:
    def __init__(self, space, surface):
        self.space = space
        self.surface = surface
        self.background_image = pygame.image.load("./src/resources/images/welcome.png").convert()
        self.bird = Bird(get_bird_info("redBird"), 10, 300, Vec2d(100, 0), self.space, self.surface)

        x, y = to_pymunk(surface.get_width(), surface.get_height(), self.surface)
        static_body = space.static_body
        static_lines = [pm.Segment(static_body, (0.0, y), (x, y), 0)]
        for line in static_lines:
            line.elasticity = 0.95
            line.friction = 1
            line.collision_type = 1

        space.add(*static_lines)
        self.status = "start"

        pygame.mixer.music.load("./src/resources/sounds/title_theme.wav")
        pygame.mixer.music.play(-1)

    def run(self):
        self.surface.blit(self.background_image, (0, 0))
        self.bird.run()

        pos_x, pos_y = to_pygame(self.bird.body.position, self.bird.surface)
        pos_x, pos_y = pos_x - self.bird.radius, pos_y - self.bird.radius

        if pos_x >= SCREEN_WIDTH or pos_y >= SCREEN_HEIGHT:
            self.status = "end"
            pygame.mixer.music.stop()

