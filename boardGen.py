import pygame
from PIL import Image, ImageDraw
import random

def generate_sudoku():
    base = 3
    side = base * base
    nums = random.sample(range(1, side + 1), side)
    board = [[nums[(base * (r % base) + r // base + c) % side] for c in range(side)] for r in range(side)]

    # Create an unsolved Sudoku board
    for _ in range(random.randint(10, 20)):
        row, col = random.randint(0, side - 1), random.randint(0, side - 1)
        board[row][col] = 0

    return board

def draw_sudoku(board):
    cell_size = 50
    margin = 5
    width = height = cell_size * len(board) + margin * 2

    pygame.init()
    screen = pygame.Surface((width, height))
    pygame.display.set_caption('Random Sudoku Board')

    font = pygame.font.Font(None, 36)

    for row in range(len(board)):
        for col in range(len(board[row])):
            value = str(board[row][col]) if board[row][col] != 0 else ""
            text = font.render(value, True, (0, 0, 0))
            text_rect = text.get_rect(center=(col * cell_size + cell_size // 2 + margin,
                                              row * cell_size + cell_size // 2 + margin))
            pygame.draw.rect(screen, (255, 255, 255), (col * cell_size + margin, row * cell_size + margin, cell_size, cell_size))
            screen.blit(text, text_rect)

    pygame.image.save(screen, 'sudoku_board.png')
    pygame.quit()

def save_sudoku_image(board):
    image_size = 500
    cell_size = image_size // len(board)

    image = Image.new('RGB', (image_size, image_size), color='white')
    draw = ImageDraw.Draw(image)

    for row in range(len(board)):
        for col in range(len(board[row])):
            value = str(board[row][col]) if board[row][col] != 0 else ""
            draw.rectangle([col * cell_size, row * cell_size, (col + 1) * cell_size, (row + 1) * cell_size], outline='black')
            draw.text((col * cell_size + cell_size // 2, row * cell_size + cell_size // 2),
                      value, fill='black', font=None, anchor='mm')

    image.save('sudoku_board_image.png')

if __name__ == "__main__":
    sudoku_board = generate_sudoku()
    draw_sudoku(sudoku_board)
    save_sudoku_image(sudoku_board)

