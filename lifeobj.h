#ifndef LIFEOBJ_HEADER
#define LIFEOBJ_HEADER

# include "cell.h"

struct life_object {
  int size_x, size_y;
  int obj[];
};

enum direction {
  LEFT   = 0b00010,
  RIGHT  = 0b00100,
  UP     = 0b01000,
  DOWN   = 0b10000,
  MIRROR = 0b00001
};

void obj_copy(struct game_map*, struct life_object*, int x, int y, enum direction);

#define DEF(...) struct life_object __VA_ARGS__;

DEF(
    GLIDER,
    LIGHT_SHIP,
    MIDDLE_SHIP,
    HEAVY_SHIP
);

#undef DEF

#endif
