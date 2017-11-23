from ctypes import *
import numpy
import os

base_dir = os.path.dirname(os.path.abspath(__file__))

class Cell(Structure):
    _fields_ = [
            ("x", c_int),
            ("y", c_int),
            ("is_alive", c_bool),
            ("r", c_int),
            ("g", c_int),
            ("b", c_int),
            ]

    def __init__(self, x, y, is_alive, r, g, b):
        self.x = x
        self.y = y
        self.is_alive = is_alive
        self.r = r
        self.g = g
        self.b = b


class GameMap(Structure):
    _fields_ = [
            ("width", c_int),
            ("height", c_int),
            ("cells", POINTER(POINTER(Cell))),
            ]

    def __init__(self):
        pass

lg = CDLL(base_dir + "/lg.so")

def blur(data, n, size):
    game_map = GameMap()
    lg.init_game_map(byref(game_map), size, size)
    ndata = data.tolist()
    for i in range(size):
        for j in range(size):
            game_map.cells[i][j].r = ndata[i][j][0]
            game_map.cells[i][j].g = ndata[i][j][1]
            game_map.cells[i][j].b = ndata[i][j][2]

    for i in range(6):
        if n & 1:
            lg.random_spawn(byref(game_map), 25)
        n >>= 1
        lg.next(byref(game_map))

    after = [[[0, 0, 0] for x in range(size)] for y in range(size)]
    for i in range(size):
        for j in range(size):
            after[i][j][0] = game_map.cells[i][j].r
            after[i][j][1] = game_map.cells[i][j].g
            after[i][j][2] = game_map.cells[i][j].b

    after = numpy.array(after, dtype=numpy.float32)
    return after

