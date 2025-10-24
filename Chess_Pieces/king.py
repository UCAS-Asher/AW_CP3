from chess_piece import *

class King(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def can_move_to(self, newPos):
        if self.position[0] + 1 == newPos and self.position[0] != 8:
            return True
        elif self.position[0] - 1 == newPos and self.position[0] != 1:
            return True
        elif self.position[1] + 1 == newPos and self.position[1] != 8:
            return True
        elif self.position[1] - 1 == newPos and self.position[1] != 1:
            return True
        else:
            return False

    def get_symbol():
        return "K"