from lab10.data.data import Square


class Board:
    def __init__(self, i, j):
        '''
        Initialize the board.
        input: i- the number of rows
               j-the numbers of columns
        '''
        self._board = []
        m = 0
        while m < i:
            l = []
            for b in range(0, j):
                l.append(0)

            self._board.append(l)
            m += 1
        self._i = i - 1
        self._j = j - 1

    def __str__(self):
        '''
        Overloads the string
        Input -
        Output - A string that contains the board and the moves
        '''
        z = "  "
        for o in self._board:
            pass
        i = 0
        for t in o:
            z += "----"

        z += "\n"
        for i in self._board:
            z += " | "
            for j in i:
                if j == 20:
                    z += "X"
                elif j == 30:
                    z += "0"
                elif j == 1:
                    z += "-"
                else:
                    z += " "

                z += " | "
            z += "\n"
            z += "  "
            for t in o:
                z += "----"
            z += "\n"
        return z

    def _Available(self, x, y):
        '''
        Checks if a square is available.
        input: x-the row
               y-the column
        output: False if the square is taken or True otherwise.
        '''
        b = self._board
        n = self._i
        m = self._j
        if x == 0:
            if y == 0:
                if b[1][1] + b[0][1] + b[1][0] + b[0][0] < 10:
                    return True
                else:
                    return False
            elif y == m:
                if b[0][m] + b[1][m - 1] + b[1][m] + b[0][m - 1] < 10:
                    return True
                else:
                    return False
            else:

                if b[0][y - 1] + b[0][y + 1] + b[1][y - 1] + b[1][y] + b[1][y + 1] + b[0][y] < 10:
                    return True
                else:
                    return False
        elif x == n:
            if y == 0:
                if b[n][1] + b[n - 1][0] + b[n - 1][1] + b[n][0] < 10:
                    return True
                else:
                    return False

            elif y == m:
                if b[n][m - 1] + b[n - 1][m - 1] + b[n - 1][m] + b[n][m] < 10:
                    return True
                else:
                    return False
            else:
                if b[n][y - 1] + b[n][y + 1] + b[n - 1][y] + b[n - 1][y - 1] + b[n - 1][y + 1] < 10:
                    return True
                else:
                    return False
        else:
            if y == 0:
                if b[x][0] + b[x - 1][0] + b[x + 1][0] + b[x + 1][1] + b[x - 1][1] + b[x][1] < 10:
                    return True
                else:
                    return False
            elif y == m:
                if b[x][m] + b[x - 1][m] + b[x + 1][m] + b[x + 1][m - 1] + b[x - 1][m - 1] + b[x][m - 1] < 10:
                    return True
                else:
                    return False
            else:
                if b[x][y] + b[x + 1][y] + b[x - 1][y] + b[x - 1][y - 1] + b[x][y - 1] + b[x + 1][y - 1] + b[x - 1][
                            y + 1] + b[x][y + 1] + b[x + 1][y + 1] < 10:
                    return True
                else:
                    return False

    def move(self, pos, v):
        '''
        Makes a move if it is possible.
        input: pos- the position where we want to to the move
               v-the value of the move that we want to make.
        output:-
        '''
        i = self._i
        j = self._j
        if pos.get_x() > int(i) or pos.get_x() < 0 or pos.get_y() > int(j) or pos.get_y() < 0:
            raise Exception("This square does not exist!")
        if self._Available(pos.get_x(), pos.get_y()) == False:
            raise Exception("Square unavailable!")

        b = self._board
        n = self._i
        m = self._j
        x = pos.get_x()
        y = pos.get_y()

        if x == 0:
            if y == 0:

                b[1][1] = 1
                b[0][1] = 1
                b[1][0] = 1
                b[0][0] = 1

            elif y == m:

                b[0][m] = 1
                b[1][m - 1] = 1
                b[1][m] = 1
                b[0][m - 1] = 1

            else:

                b[0][y] = 1
                b[0][y - 1] = 1
                b[0][y + 1] = 1
                b[1][y - 1] = 1
                b[1][y] = 1
                b[1][y + 1] = 1



        elif x == n:
            if y == 0:

                b[n][1] = 1
                b[n - 1][0] = 1
                b[n - 1][1] = 1
                b[n][0] = 1

            elif y == m:

                b[n][m - 1] = 1
                b[n - 1][m - 1] = 1
                b[n - 1][m] = 1
                b[n][m] = 1

            else:

                b[n][y - 1] = 1
                b[n][y + 1] = 1
                b[n - 1][y] = 1
                b[n - 1][y - 1] = 1
                b[n - 1][y + 1] = 1

        else:
            if y == 0:

                b[x][0] = 1
                b[x - 1][0] = 1
                b[x + 1][0] = 1
                b[x + 1][1] = 1
                b[x - 1][1] = 1
                b[x][1] = 1

            elif y == m:

                b[x][m] = 1
                b[x - 1][m] = 1
                b[x + 1][m] = 1
                b[x + 1][m - 1] = 1
                b[x - 1][m - 1] = 1
                b[x][m - 1] = 1
            else:

                b[x + 1][y] = 1
                b[x - 1][y] = 1
                b[x - 1][y - 1] = 1
                b[x][y - 1] = 1
                b[x + 1][y - 1] = 1
                b[x - 1][y + 1] = 1
                b[x][y + 1] = 1
                b[x + 1][y + 1] = 1

        self._board = b
        self._board[pos.get_x()][pos.get_y()] = v

    def isok(self):
        '''
        Checks if there is a possible move.
        '''
        b = self._board
        for i in b:
            for j in i:
                if j == 0:
                    return True
        return False

    def _getMoves(self):
        '''
        Looks for valid moves.
        output: - the valid moves.
        '''
        b = self._board
        validMoves = []
        a = b[0]
        for i in range(0, len(b)):
            for j in range(0, len(a)):
                if (b[i][j] == 0):
                    validMoves.append(Square(i, j))
        return validMoves




    def checkwinComputer(self):
        '''
        Checks if the computer can win the game
        output: True if it is possible, False otherwise.
        '''
        b = self._board
        moves = self._getMoves()

        if len(moves) == 9:
            if moves[0].get_x() == moves[1].get_x() == moves[2].get_x():
                if int(moves[0].get_y()) + 2 == int(moves[1].get_y()) + 1 == int(moves[2].get_y()):
                    if moves[3].get_x() == moves[4].get_x() == moves[5].get_x():
                        if moves[6].get_x() == moves[7].get_x() == moves[8].get_x():
                            if int(moves[3].get_y()) + 2 == int(moves[4].get_y()) + 1 == int(moves[5].get_y()):
                                if int(moves[6].get_y()) + 2 == int(moves[7].get_y()) + 1 == int(moves[8].get_y()):
                                    return True
        if len(moves) == 6:
            if moves[0].get_x() == moves[1].get_x() == moves[2].get_x():
                if int(moves[0].get_y()) + 2 == int(moves[1].get_y()) + 1:
                    if moves[3].get_x() == moves[4].get_x() == moves[5].get_x():
                        if int(moves[2].get_y()) + 2 == int(moves[3].get_y()) + 1:
                            if int(moves[4].get_y()) + 2 == int(moves[5].get_y()) + 1:
                                return True

        if len(moves) == 6:
            if moves[0].get_x() == moves[1].get_x():
                if int(moves[0].get_y()) + 2 == int(moves[1].get_y()) + 1 == int(moves[2].get_y()):
                    if moves[2].get_x() == moves[3].get_x():
                        if moves[4].get_x() == moves[5].get_x():
                            if int(moves[3].get_y()) + 2 == int(moves[4].get_y()) + 1 == int(moves[5].get_y()):
                                return True
        return False
