
class Square:
    def __init__(self, x, y):
        self._x = x
        self._y = y

    def get_x(self):
        return self._x

    def get_y(self):
        return self._y




'''
class Board:
    def __init__(self):
        self._board = [[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],
                       [0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0]]

    def __str__(self):
        z = ""
        for i in self._board:
            z += " | "
            for j in i:
                if j == 1:
                    z += 'X'
                if j == -1:
                    z += 'O'
                if j ==2:
                    z += 'z'
                z += " | "
            # z[len(z) - 1]="\n"
            z += "\n_ _ _ _ _ _ _ _\n"
        return z

    def move(self, pos, val):
        if pos.get_x() not in [0, 1, 2, 3, 4, 5] or pos.get_y() not in [0, 1, 2, 3, 4, 5]:
            raise Exception("Moved outside the board!")
        elif self._board[pos.get_x()][pos.get_y()] != 0:
            raise Exception("Square already taken!")
        self._board[pos.get_x()][pos.get_y()] = val
        


    def getValidMoves(self):
        board = self._board
        validMoves = []
        for i in range(0,5):
            for j in range(0,5):
                if (board[i][j]==0):
                    validMoves.append(Square(i,j))
        return validMoves

    def checkWin(self):
        cx = 0
        co = 0
        for i in self._board:
            for j in i:
                if j==1:
                    cx+=1
                if j==-1:
                    co+=1
        if cx<co:
            return -7   #user win
        if cx>co:
            return -8   #computer win
        if cx==co:
            return 0

    def checkDraw(self):
       board = self._board
       for i in range(0,5):
           for j in range(0,5):
               if (board[i][j]==0):
                   return False
       return True


class GamePlay():
    def __init__(self):
        self._boardControl = Board()

    def moveUser(self, pos):
        self._boardControl.move(pos, 1)

    def moveAI(self):
        validMoves = self._boardControl.getValidMoves()
        poz = random.randint(0, len(validMoves)-1)
        mov = validMoves[poz]
        self._boardControl.move(mov, -1)


class UI():
    def __init__(self):
        self._play = GamePlay()

    def startUI(self):
        turn = 0
        while self._play._boardControl.checkDraw() == False:
            if(turn%2 == 0):
                x=int(input("x coordinates:"))
                y=int(input("y coordinates:"))
                mov = Square(x,y)
                self._play.moveUser(mov)
            else:
                self._play.moveAI()
            turn+=1
            print(str(self._play._boardControl))

        if self._play._boardControl.checkWin()==0:
            print("Remise")
        if self._play._boardControl.checkWin()==-7:
            print("You win!")
        if self._play._boardControl.checkWin() == -8:
            print("I win!")

play = UI()
play.startUI()
'''

