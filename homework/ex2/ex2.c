
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

    // Now, that you have a table, please draw an X i
    // in the middle square. Please see the illustration below. 
    // You can use the same draw_line function. 
    //
    // ###################
    // #     #     #     #
    // #     #     #     #
    // #     #     #     #
    // ###################
    // #     # # # #     #
    // #     #  #  #     #
    // #     # # # #     #
    // ###################
    // #     #     #     #
    // #     #     #     #
    // #     #     #     #
    // ###################
    // 
    // To create the executable use: make
    // To run use: ./ex2
    //
    // Good luck!

    draw_line(0, 0, 0, 768, COLOR_RED);
    draw_line(0, 768, 1024, 768, COLOR_RED);
    draw_line(1024, 768, 1024, 0, COLOR_RED);
    draw_line(1024, 0, 0, 0, COLOR_RED);
    draw_line(341, 0, 341, 768, COLOR_RED);
    draw_line(682, 0, 682, 768, COLOR_RED);
    draw_line(0, 256, 1024, 256, COLOR_RED);
    draw_line(0, 512, 1024, 512, COLOR_RED);

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
