from abc import ABC, abstractmethod



class ChessGame():
    def __init__(self):
        self.white_pieces = []
        self.black_pieces = []

    def move_piece(piece, NewPos):
        piece.position = NewPos
        print(f"{piece.name}, Symbol {piece.get_symbol()} is at {NewPos}")

    def remove_piece(self, piece):
        if piece.color == "white":
            self.white_pieces.remove(piece)
        elif piece.color == "black":
            self.black_pieces.remove(piece)

    def get_pieces_left(self, color):
        if color == "white":
            print("White Pieces")
            for piece in self.white_pieces:
                print(f"{type(piece).__name__} Position: {piece.position}")
        elif color == "black":
            print("Black Pieces")
            for piece in self.black_pieces_pieces:
                print(f"{type(piece).__name__} Position: {piece.position}")

    def get_pieces_at(self, position):
        for piece in self.white_pieces:
            if piece.position == position:
                return piece
        for piece in self.black_pieces:
            if piece.position == position:
                return piece
            

class ChessPiece(ABC):
    def __init__(self, name, color, position):
        self.name = name
        self.color = color
        self.position = position

    def get_position(self):
        return self.position

    @abstractmethod
    def move(newPos):
        pass

    @abstractmethod
    def get_symbol(piece):
        pass

class King(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos, white_pieces, black_pieces):
        if self.position[0] == "A":
            x1 = 1
        elif self.position[0] == "B":
            x1 = 2
        elif self.position[0] == "C":
            x1 = 3
        elif self.position[0] == "D":
            x1 = 4
        elif self.position[0] == "E":
            x1 = 5
        elif self.position[0] == "F":
            x1 = 6
        elif self.position[0] == "G":
            x1 = 7
        elif self.position[0] == "H":
            x1 = 8
        y1 = int(self.position[1])

        if newPos[0] == "A":
            x2 = 1
        elif newPos[0] == "B":
            x2 = 2
        elif newPos[0] == "C":
            x2 = 3
        elif newPos[0] == "D":
            x2 = 4
        elif newPos[0] == "E":
            x2 = 5
        elif newPos[0] == "F":
            x2 = 6
        elif newPos[0] == "G":
            x2 = 7
        elif newPos[0] == "H":
            x2 = 8
        y2 = int(newPos[1])


        if 0 <= x2 < 8 and 0 <= y2 < 8:
            if abs(x2 - x1) <= 1 and abs(y2 - y1) <= 1 and (x1 != x2 or y1 != y2):
                return True
            else:
                return False
        else:
            return False

        

    def get_symbol():
        return "K"
    
class Queen(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos, white_pieces, black_pieces):
        if self.position[0] == "A":
            x1 = 1
        elif self.position[0] == "B":
            x1 = 2
        elif self.position[0] == "C":
            x1 = 3
        elif self.position[0] == "D":
            x1 = 4
        elif self.position[0] == "E":
            x1 = 5
        elif self.position[0] == "F":
            x1 = 6
        elif self.position[0] == "G":
            x1 = 7
        elif self.position[0] == "H":
            x1 = 8
        y1 = int(self.position[1])

        if newPos[0] == "A":
            x2 = 1
        elif newPos[0] == "B":
            x2 = 2
        elif newPos[0] == "C":
            x2 = 3
        elif newPos[0] == "D":
            x2 = 4
        elif newPos[0] == "E":
            x2 = 5
        elif newPos[0] == "F":
            x2 = 6
        elif newPos[0] == "G":
            x2 = 7
        elif newPos[0] == "H":
            x2 = 8
        y2 = int(newPos[1])



        if 0 <= x2 < 8 and 0 <= y2 < 8:
            if (x1 == x2 and y1 != y2) or (y1 == y2 and x1 != x2) or (abs(x2 - x1) == abs(y2 - y1)):
                return True
            else:
                return False
        else:
            return False


    def get_symbol():
        return "Q"
    
class Bishop(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(newPos):
        pass

    def get_symbol():
        return "B"
    
class Knight(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(newPos):
        pass

    def get_symbol():
        return "k"
    
class Rook(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(newPos):
        pass

    def get_symbol():
        return "R"

class Pawn(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(newPos):
        pass

    def get_symbol():
        return "P"