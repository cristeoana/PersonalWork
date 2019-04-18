import unittest
from lab10.data.Board import Board
from lab10.data.PlayGame import Play
from lab10.data.data import Square


class TestBoard(unittest.TestCase):
    def setUp(self):
        self._c = Board(4, 4)

    def test(self):
        self.assertTrue(self._c._Available(1, 1), None)

        self.assertTrue(self._c.isok(), None)

        self.assertFalse(self._c.checkwinCortana(), None)


class TestSquare(unittest.TestCase):
    def setUp(self):
        self._p = Square(1, 1)

    def test(self):
        self.assertEqual(self._p.get_x(), 1, None)

        self.assertEqual(self._p.get_y(), 1, None)