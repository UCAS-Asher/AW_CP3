class ChessGame():
    def __init__(self):
        self.white_pieces = []
        self.black_pieces = []

    def move_piece(piece, NewPos):
        piece.position = NewPos

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