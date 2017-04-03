
// Plane 2 game 
// Stopel's

#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include "allegroforkids.h"


// Screen size
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 90

float arr1[SCREEN_WIDTH][SCREEN_HEIGHT];
float arr2[SCREEN_WIDTH][SCREEN_HEIGHT];

int main() {

  init(SCREEN_WIDTH, SCREEN_HEIGHT);

  for (int i = 0; i < SCREEN_WIDTH; i++)
  {
    for (int j = 0; j < SCREEN_HEIGHT; j++)
    {
      arr1[i][j] = 0;
      arr2[i][j] = 0;
    }
  }

  
  // create hot objects
  for (int i = 20; i < 50; i++)
  {
    for (int j = 20; j < 50; j++)
    {
      arr1[i][j] = 250;
      arr2[i][j] = 250;
      arr1[i+20][j+20] = 250;
      arr2[i+20][j+20] = 250;
    }
  }


  int curr = 2;
  int iteration = 0;

  while (true) {

    do_loop();
    clear_screen_rgb(0, 0, 0);

    // calc next moment
    
    for (int i = 1; i < SCREEN_WIDTH - 1; i++)
    {
      for (int j = 1; j < SCREEN_HEIGHT - 1; j++)
      {
        if (curr == 1) 
        {
          arr1[i][j] = (arr2[i  ][j  ] + 
                        arr2[i-1][j  ] + arr2[i+1][j  ] +
                        arr2[i  ][j-1] + arr2[i  ][j+1]) / 5;

          unsigned char color = arr1[i][j];
          draw_pixel_rgb(i,j,color,color,color);
        }
        else
        {
          arr2[i][j] = (arr1[i  ][j  ] + 
                        arr1[i-1][j  ] + arr1[i+1][j  ] +
                        arr1[i  ][j-1] + arr1[i  ][j+1]) / 5;
          unsigned char color = arr2[i][j];
          draw_pixel_rgb(i,j,color,color,color);
        }
      }
    }
    
    /*
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
      for (int j = 0; j < SCREEN_HEIGHT; j++)
      {
        if (curr == 1) 
        {
          unsigned char color = arr1[i][j];
          draw_pixel_rgb(i,j,color,color,color);
        }
        else
        {
          unsigned char color = arr2[i][j];
          draw_pixel_rgb(i,j,color,color,color);
        }
      }
    }
    */

    show();

    if (curr == 1)
    {
      curr = 2;
    }
    else
    {
      curr = 1;
    }

    printf("Iteration: %d\n", iteration);
    iteration++;
  }

  destroy();
  return 0;
}

void do_left() {
  //player_x = player_x - player_speed;
}

void do_right() {
  //player_x = player_x + player_speed;
}