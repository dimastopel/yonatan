
// Plane 2 game 
// Stopel's

#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include "allegroforkids.h" 

// Screen size
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

// Player constants
#define PLAYER_SIZE 50

// Pictures
Bitmap * plane_image;
Bitmap * lost_image;

// flags
int lost = 0;

// player settings
int player_x = 320;
int player_speed = 5;
int player_y = SCREEN_HEIGHT - PLAYER_SIZE - 50;

// object settings
float object_1_x;
float object_1_y;
float object_1_size;
Color object_1_color;
int object_1_show = 0;
float object_speed = 15;
int object_rare = 1;
int min_object_size = 50;
int max_object_size = 150;

int main() {

  init(SCREEN_WIDTH, SCREEN_HEIGHT);

  plane_image = load_bitmap("plane.png");
  lost_image = load_bitmap("lost.png");

  while (true) {

    do_loop();

    //GENERATE AND MOVE OBJECTS

    if (object_1_show) {
      object_1_y = object_1_y + object_speed;
      if (object_1_y > SCREEN_HEIGHT) {
        object_1_show = 0;
      }
    } else {
      object_1_show = get_binary(object_rare);
      if (object_1_show) {
        object_1_x = get_random_number(0, SCREEN_WIDTH);
        object_1_size = get_random_number(min_object_size, max_object_size);
        object_1_y = object_1_size * -1;
        object_1_color = get_random_color();
      }
    }

    // DETECT COLLISION
    if (is_collision(player_x, player_y, PLAYER_SIZE, object_1_x, object_1_y, object_1_size))
    {
        // we have a collision
        object_1_show = 0;
        lost = 1;
    }

    // We paint from here

    // clear the screen
    clear_screen_rgb(163, 214, 255);

    // draw player  
    if (!lost)
    { 
        draw_image(plane_image, player_x, player_y, PLAYER_SIZE, PLAYER_SIZE);
    }

    // draw object
    if (!lost && object_1_show) 
    {
        draw_rect(object_1_x, object_1_y, object_1_size, object_1_size, object_1_color);
    }

    //draw lost / won
    if (lost)
    { 
        draw_image(lost_image, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
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