from lab10.data.data import Square
from lab10.data.PlayGame import Play


class UI:
    @staticmethod
    def printlst(self, l):
        for i in l:
            print(str(i))
            print("\n")

    def __init__(self):
        print("Give the size of the board")
        ok = 1
        while ok == 1:
            try:
                i = int(input("n = "))
                ok = 0
            except ValueError:
                print("\tn must be an integer.\n")
            if i < 3:
                ok = 1
                print("\tn must be >2.\n")

        while ok == 0:
            try:
                j = int(input("m = "))
                ok = 1
            except ValueError:
                print("\tm must be an integer.\n")

            if j < 3:
                ok = 0
                print("\tm must be >2.\n")

        self._play = Play(i, j)

    def startUI(self):
        print((self._play))
        ok = 1
        while ok == 1:
            okk = 0
            while okk == 0:
                try:
                    x = int(input("x coordinates:"))
                    okk = 1
                except ValueError:
                    print("\tx must be integer\n")
            okk = 0
            while okk == 0:
                try:
                    y = int(input("y coordinates:"))
                    okk = 1
                except ValueError:
                    print("\ty must be integer\n")
            mov = Square(x, y)
            response = self._play.moveUser(mov)
            if response:
                print(response)

            else:
                if self._play._play.isok() == False:
                    ok == 0
                    print("Congratulation, you win!")
                    print((self._play))
                    break
                response = self._play.moveComputer()
                if response:
                    print(response)

                if self._play._play.isok() == False:
                    ok == 0
                    print("I win!")
                    print((self._play))
                    break
                print((self._play))
