#include <string.h>
#include <stdio.h>
# include "lifeobj.h"
# include "cell.h"
static void rev(int sx, int sy, int to[sy * sx], int target[]){
  for(int i = 0; i < sy; i++) {
    for(int j = 0; j < sx; j++) {
      to[i * sx + j] = target[(sy - 1 - i) * sx + j];
    }
  }
}

void obj_copy(struct game_map* game, struct life_object* lifeobj, int x, int y, enum direction dir) {
  int size = lifeobj -> size_y * lifeobj -> size_x;
  int objmap[size];
  if(dir & MIRROR) {
    rev(lifeobj -> size_x, lifeobj -> size_y, objmap, lifeobj -> obj);
    dir ^= MIRROR;
  } else {
    memcpy(objmap, lifeobj -> obj, size * sizeof(int));
  }

  switch(dir) {
    case RIGHT:
      for(int i = 0; i < lifeobj -> size_y; i++) {
        for(int j = 0; j < lifeobj -> size_x; j++) {
          game -> cells[y + i][x + j].is_alive = objmap[i * lifeobj -> size_x + j];
        }
      }
      break;
    case LEFT:
      for(int i = 0; i < lifeobj -> size_y; i++) {
        for(int j = 0; j < lifeobj -> size_x; j++) {
          game -> cells[y + i][x + j].is_alive = objmap[i * lifeobj -> size_x + lifeobj -> size_x - 1 - j];
        }
      }
      break;
    case DOWN:
      for(int i = 0; i < lifeobj -> size_x; i++) {
        for(int j = 0; j < lifeobj -> size_y; j++) {
          game -> cells[y + i][x + j].is_alive = objmap[j * lifeobj -> size_x + i];
        }
      }
      break;
    case UP:
      for(int i = 0; i < lifeobj -> size_x; i++) {
        for(int j = 0; j < lifeobj -> size_y; j++) {
          game -> cells[y + i][x + j].is_alive = objmap[j * lifeobj -> size_x + (lifeobj -> size_x - 1 - i)];
        }
      }
      break;
    default:
      break;
  }
}

struct life_object GLIDER = {3, 3, {
  0, 1, 0,
  0, 0, 1,
  1, 1, 1,
}};

struct life_object LIGHT_SHIP = {5, 4, {
  0, 0, 0, 1, 0,
  0, 0, 0, 0, 1,
  1, 0, 0, 0, 1,
  0, 1, 1, 1, 1,
}};

struct life_object MIDDLE_SHIP = {6, 4, {
  0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 1,
  0, 1, 1, 1, 1, 1,
}};

struct life_object HEAVY_SHIP = {7, 4, {
  0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  0, 1, 1, 1, 1, 1, 1,
}};
