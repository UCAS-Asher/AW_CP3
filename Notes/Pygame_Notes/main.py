#AW Pygame Notes

#How do you set up pygame?

#What is the purpose of the "While running" loop?

#How do you create a screen in pygame?

#How are objects placed on the screen in pygame?

#What events can I listen for in pygame? What do those events do?

#How can I detect collision with pygame?

#How do you add sounds in pygame?


import pygame

pygame.init()

screen = pygame.display.set_mode((1200, 720))
pygame.display.set_caption("Pygame Tutorial")
pos_x = 100
pos_y = 200

ufo = pygame.image.load('Notes/Pygame_Notes/skull7.png')
ufo_rect = ufo.get_rect(topleft = (512, 512))

while True:
    screen.fill((155, 200, 255))

    pygame.draw.rect(screen, (20, 200, 255), (pos_x, pos_y, 100, 100))
    pygame.draw.circle(screen, (0, 150, 255), (500, 500), 50)

    screen.blit(ufo, ufo_rect)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            pos_x -= 5
        elif keys[pygame.K_RIGHT]:
            pos_x += 5
        elif keys[pygame.K_UP]:
            pos_y += 5
        elif keys[pygame.K_DOWN]:
            pos_y -= 5


    pygame.display.flip()
