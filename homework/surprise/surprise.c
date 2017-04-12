//////////////////////////////////////////////////
// This is part of exersizes for Yonatan Stopel //
//////////////////////////////////////////////////

#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include "allegroforkids.h" 

// Screen size
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

// Player constants
#define PLAYER_SIZE 50

int main() {

  init(SCREEN_WIDTH, SCREEN_HEIGHT);


  while (true) {

    do_loop();

    // clear the screen
    clear_screen(COLOR_CYAN);

    ///////////////////////////
    // YOUR CODE STARTS HERE //
    ///////////////////////////

    draw_line(682, 512, 1024, 256, COLOR_RED);

    ///////////////////////////
    // YOUR CODE ENDS HERE   //
    ///////////////////////////

    // show display
    show();

    //=====================================================================================
  }

  destroy();

  return 0;
}

void do_left(){}
void do_right(){} 
