
// Plane 2 game 
// Stopel's

#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include "allegroforkids.h"

int screen_width = 640;
int screen_height = 480;

ALLEGRO_BITMAP * plane_image;
ALLEGRO_BITMAP * lost_image;

int doexit = 0;
int lost = 0;

float player_x = 320;
int player_speed = 5;
int player_size = 50;
int player_y = 400;

float object_1_x;
float object_1_y;
float object_1_size;
ALLEGRO_COLOR object_1_color;

int object_1_show = 0;

float object_speed = 15;
int object_rare = 1;
int min_object_size = 50;
int max_object_size = 150;

int current_right = 0;
int current_left = 0;

int main() {

  init(screen_width, screen_height);

  plane_image = al_load_bitmap("plane.png");
  lost_image = al_load_bitmap("lost.png");

  while (!doexit) {

    do_loop();

    //GENERATE AND MOVE OBJECTS

    if (object_1_show) {
      object_1_y = object_1_y + object_speed;
      if (object_1_y > screen_height) {
        object_1_show = 0;
      }
    } else {
      object_1_show = get_binary(object_rare);
      if (object_1_show) {
        object_1_x = get_random_number(0, screen_width);
        object_1_size = get_random_number(min_object_size, max_object_size);
        object_1_y = object_1_size * -1;
        object_1_color = get_random_color();
      }
    }

    // DETECT COLLISION
    if (is_collision(player_x, player_y, player_size, object_1_x, object_1_y, object_1_size))
    {
        // we have a collision
        object_1_show = 0;
        lost = 1;
    }

    // WE PAINT FROM HERE

    // clear the screen
    clear_screen_rgb(163, 214, 255);

    // draw plane  
    if (!lost)
    { 
        draw_image(plane_image, player_x, player_y, player_size, player_size);
    }

    // draw object
    if (object_1_show) {
      draw_rect(object_1_x, object_1_y, object_1_size, object_1_size, object_1_color);
    }

    //draw lost / won
    if (lost)
    { 
        draw_image(lost_image, 0, 0, screen_width, screen_height);
    }


    // show display
    show();

    //=====================================================================================
  }

  destroy();

  return 0;
}

void do_left() {
  player_x = player_x - player_speed;
}

void do_right() {
  player_x = player_x + player_speed;
}