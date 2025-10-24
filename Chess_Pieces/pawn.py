from chess_piece import *

class Pawn(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def can_move_to(self, newPos):
        if self.position[1] + 1 == newPos and self.position[1] != [8]:
            return True
        else:
            return False

    def get_symbol():
        return "P"