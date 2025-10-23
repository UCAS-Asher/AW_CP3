from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, color, position):
        self.color = color
        self.position = position

    def get_position():
        pass

    @abstractmethod
    def move(newPos):
        pass

    @abstractmethod
    def getSymbol():
        pass