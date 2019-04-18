from lab10.data.Board import Board
import random


class Play:
    def __init__(self, i, j):
        '''
        Initialize the board of the game.
        input: i- the number of rows
               j-the numbers of colums
        '''
        self._play = Board(i, j)

    def __str__(self):
        '''
        Overloads the string
        '''
        return str(self._play)

    def moveUser(self, pos):
        '''
        Makes the move of the user.
        input: pos- the position where we want to to the move.
        output:A message if the move is impossible to be made.
        '''
        try:
            self._play.move(pos, 20)
        except Exception as e:
            return e

    def moveComputer(self):
        '''
        Makes the move of the computer.
        input: pos- the position where we want to make the move.
        output:A message if the move is impossible to be made.
        '''

        vM = self._play._getMoves()

        if self._play.checkwinComputer() == False:
            pos = random.randint(0, len(vM) - 1)
            mov = vM[pos]
            self._play.move(mov, 30)
        else:
            pos = 4
            mov = vM[pos]
            self._play.move(mov, 30)
