#AW Chess Pieces
from abc import ABC, abstractmethod



class ChessGame():
    def __init__(self):
        self.white_pieces = [Rook("Rook 1", "white", "A1"), Knight("Knight 1", "white", "B1"), Bishop("Bishop 1", "white", "C1"), Queen("Queen", "white", "D1"), King("King", "white", "E1"), Bishop("Bishop 2", "white", "F1"), Knight("Knight 2", "white", "G1"), Rook("Rook 2", "white", "H1"), Pawn("Pawn 1", "white", "A2"), Pawn("Pawn 2", "white", "B2"), Pawn("Pawn 3", "white", "C2"), Pawn("Pawn 4", "white", "D2"), Pawn("Pawn 5", "white", "E2"), Pawn("Pawn 6", "white", "F2"), Pawn("Pawn 7", "white", "G2"), Pawn("Pawn 8", "white", "H2")]
        self.black_pieces = [Rook("Rook 1", "black", "A8"), Knight("Knight 1", "black", "B8"), Bishop("Bishop 1", "black", "C8"), Queen("Queen", "black", "D8"), King("King", "black", "E8"), Bishop("Bishop 2", "black", "F8"), Knight("Knight 2", "black", "G8"), Rook("Rook 2", "black", "H8"), Pawn("Pawn 1", "black", "A7"), Pawn("Pawn 2", "black", "B7"), Pawn("Pawn 3", "black", "C7"), Pawn("Pawn 4", "black", "D7"), Pawn("Pawn 5", "black", "E7"), Pawn("Pawn 6", "black", "F7"), Pawn("Pawn 7", "black", "G7"), Pawn("Pawn 8", "black", "H7")]

    def move_piece(self, name, color, NewPos):
        for piece in self.white_pieces:#checks all pieces to find the piece
            if piece.name == name and piece.color == color:
                if piece.can_move_to(NewPos) == True:#if the move is valid
                    piece.position = NewPos
                    print(f"{piece.color} {piece.name}, Symbol {piece.get_symbol()} is at {NewPos}")
                    for x in self.white_pieces:#for capturing
                        if x.position == NewPos:
                            self.remove_piece(x)
                    for y in self.white_pieces:
                        if y.position == NewPos:
                            self.remove_piece(x)
                else:
                    print(f"Invalid Move! {piece.name}, Symbol {piece.get_symbol()} is at {piece.position}")
        for piece in self.black_pieces:
            if piece.name == name and piece.color == color:
                if piece.can_move_to(NewPos) == True:
                    piece.position = NewPos
                    print(f"{piece.color} {piece.name}, Symbol {piece.get_symbol()} is at {NewPos}")
                    for x in self.white_pieces:
                        if x.position == NewPos:
                            self.remove_piece(x)
                    for y in self.white_pieces:
                        if y.position == NewPos:
                            self.remove_piece(x)
                else:
                    print(f"Invalid Move! {piece.name}, Symbol {piece.get_symbol()} is at {piece.position}")


    def remove_piece(self, piece):#removes pieces off the board
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
    def can_move_to(newPos):
        pass

    @abstractmethod
    def get_symbol():
        pass

class King(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])


        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            if abs(x2 - x1) <= 1 and abs(y2 - y1) <= 1 and (x1 != x2 or y1 != y2):
                return True
            else:
                return False
        else:
            return False

        

    def get_symbol(self):
        return "K"
    
class Queen(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])


        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            if (x1 == x2 and y1 != y2) or (y1 == y2 and x1 != x2) or (abs(x2 - x1) == abs(y2 - y1)):
                return True
            else:
                return False
        else:
            return False


    def get_symbol(self):
        return "Q"
    
class Bishop(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])

        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            if abs(x2 - x1) == abs(y2 - y1):
                return True
            else:
                return False
        else:
            return False

    def get_symbol(self):
        return "B"
    
class Knight(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])

        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            x = abs(x2 - x1)
            y = abs(y2 - y1)
            if (x == 2 and y == 1) or (x == 1 and y == 2):
                return True
            else:
                return False
        else:
            return False

    def get_symbol(self):
        return "k"
    
class Rook(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])

        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            if x1 == x2 or y1 == y2:
                return True
            else:
                return False
        else:
            return False

    def get_symbol(self):
        return "R"

class Pawn(ChessPiece):
    def __init__(self, name, color, position):
        super().__init__(name, color, position)

    def can_move_to(self, newPos):
        # Convert column letters to numbers 
        x1 = ord(self.position[0].upper()) - ord("A") + 1
        y1 = int(self.position[1])

        x2 = ord(newPos[0].upper()) - ord("A") + 1
        y2 = int(newPos[1])

        # Ensure the target position is within the board
        if 1 <= x2 <= 8 and 1 <= y2 <= 8:
            y = y2 - y1
            if x1 == x2:
                if y == 1:
                    return True
                # Move forward 2 squares from starting position
                elif y == 2 and y1 == 2 or y1 == 7:
                    return True
            else:
                return False
        else:
            return False

    def get_symbol(self):
        return "P"