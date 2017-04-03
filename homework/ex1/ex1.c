
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

    // Please draw a table on the screen as follows:
    //
    // ###################
    // #     #     #     #
    // #     #     #     #
    // #     #     #     #
    // ###################
    // #     #     #     #
    // #     #     #     #
    // #     #     #     #
    // ###################
    // #     #     #     #
    // #     #     #     #
    // #     #     #     #
    // ###################
    // 
    // Use the function (see example below):  
    // draw_line(x1, y1, x2, y2, Color);
    //
    // To create the executable use: make
    // To run use: ./ex1
    //
    // Good luck!

    // Example call
    draw_line(10, 10, 100, 200, COLOR_VIOLET);

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
