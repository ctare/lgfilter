#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cell.h"
#include "lifegame.h"
#include "image.h"
#include "lifeobj.h"
#include "util.h"

#define rep(i, n) for(int i = 0; i < (n); i++)
int main(int argc, char* argv[]){
  struct game_map game;
  init_game_map(&game, 40, 60);
  obj_copy(&game, &HEAVY_SHIP, 0, 1, RIGHT);
  obj_copy(&game, &HEAVY_SHIP, 0, 10, RIGHT | MIRROR);

  rep(i, 120) {
    /* if(i == 20) obj_copy(&game, &LIGHT_SHIP, 0, 7, RIGHT); */
    usleep(100000);
    next(&game);
    printf("[0;0H");
    print_map(&game);
  }

  /* long n; */
  /* if(argc > 1) { */
  /*   n = atol(argv[1]); */
  /* } else { */
  /*   puts("please number"); */
  /*   return 0; */
  /* } */
  /*  */
  /* char output_name[300]; */
  /* sprintf(output_name, "./output/output%ld.bmp", n); */
  /*  */
  /* char input_name[300] = "image.bmp"; */
  /* if(argc > 2) { */
  /*   for(int i = 2; i < argc; i++) { */
  /*     switch(*(argv[i] + 1)) { */
  /*       case 'i': */
  /*         sprintf(input_name, "%s", argv[i + 1]); */
  /*         break; */
  /*       case 'o': */
  /*         sprintf(output_name, "%s", argv[i + 1]); */
  /*         break; */
  /*       default: */
  /*         break; */
  /*     } */
  /*   } */
  /* } */
  /*  */
  /* struct bmp_image bmp; */
  /* load_bmp(&bmp, input_name); */
  /*  */
  /* struct game_map game; */
  /* init_game_map(&game, bmp.width, bmp.height); */
  /*  */
  /* srand(10); */
  /*  */
  /* plot(&bmp, &game); */
  /*  */
  /* for(int i = 0; i < 80; i++) { */
  /*   if(n & 1) { */
  /*     random_spawn(&game, 50); */
  /*   } */
  /*   n >>= 1; */
  /*  */
  /*   next(&game); */
  /* } */
  /*  */
  /* for(int i = 0; i < game.height; i++) { */
  /*   for(int j = 0; j < game.width; j++) { */
  /*     bmp.data[i][j][0] = game.cells[i][j].r; */
  /*     bmp.data[i][j][1] = game.cells[i][j].g; */
  /*     bmp.data[i][j][2] = game.cells[i][j].b; */
  /*   } */
  /* } */

  /* write_bmp(&bmp, output_name); */
}

