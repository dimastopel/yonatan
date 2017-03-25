//compile as follows:
//gcc -Wall -o plane plane.c `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



// INTERNAL

ALLEGRO_DISPLAY *display = NULL; 
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMEOUT timeout;

ALLEGRO_COLOR COLOR_RED;
ALLEGRO_COLOR COLOR_GREEN;
ALLEGRO_COLOR COLOR_BLUE;
ALLEGRO_COLOR COLOR_CYAN;
ALLEGRO_COLOR COLOR_YELLOW;
ALLEGRO_COLOR COLOR_VIOLET;

void init(int screen_width, int screen_height)
{
   al_init();
   al_init_primitives_addon();
   al_install_keyboard();
   al_init_image_addon();
   srand(time(NULL));

   display = al_create_display(screen_width, screen_height);

   event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   COLOR_RED = al_map_rgb(255,0,0);
   COLOR_GREEN = al_map_rgb(0,255,0);
   COLOR_BLUE = al_map_rgb(0,0,255);
   COLOR_CYAN = al_map_rgb(0,255,255);
   COLOR_YELLOW = al_map_rgb(255,255,0);
   COLOR_VIOLET = al_map_rgb(238,130,238);
}

void clear_screen(ALLEGRO_COLOR color)
{
   al_clear_to_color(color);
}


void init_loop()
{
   al_init_timeout(&timeout, 0.06);
   al_wait_for_event_until(event_queue, &ev, &timeout);

   if(ev.type == ALLEGRO_EVENT_KEY_DOWN 
      && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
   {
         exit(0);
   }

}

void draw_image(ALLEGRO_BITMAP *image, float x, float y, float width, float height)
{
   al_draw_scaled_bitmap(image,
      0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image),
      x, y, width, height, 0);
}

void draw_rect(float x, float y, float width, float height, ALLEGRO_COLOR color)
{
   al_draw_rectangle(x, y, x + width, y + height, color, 5);
}

void show()
{
   al_flip_display(); // show display
}

void destroy() 
{
   al_destroy_display(display); // destroy display
}


// END INTERNAL

int main(){


   // screen size
   int screen_width = 640;
   int screen_height = 480;
   
   // initialize all
   init(screen_width, screen_height);

   // load images
   ALLEGRO_BITMAP *plane_image = al_load_bitmap("plane.png");
   ALLEGRO_BITMAP *won_image = al_load_bitmap("won.png");
   ALLEGRO_BITMAP *lost_image = al_load_bitmap("lost.png");


   // init variables
   int doexit = 0;
   int lost = 0;
   int won = 0;

   float player_x = 320;
   int player_speed = 14;

   float object_1_x = 14;
   float object_1_y = 2;
   float object_1_size = 34;

   float object_2_x = 12;
   float object_2_y = 39;
   float object_2_size = 24;

   float object_3_x = 26;
   float object_3_y = 15;
   float object_3_size = 18;

   int object_1_show = 0; 
   int object_2_show = 0; 
   int object_3_show = 0; 

   float speed = 10;
   int rare = 1;
   int min_object_size = 100;

   time_t start_time = time(NULL);

   while(!doexit)
   {

      init_loop();


      if (!lost)
      {

         if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
               case ALLEGRO_KEY_PAD_4: 
                  player_x = player_x - player_speed;
                  break;
               case ALLEGRO_KEY_PAD_6:
                  player_x = player_x + player_speed;
                  break;
            }
         }

         //check if won or lost
         if (time(NULL) - start_time > 30)
         {
            won = 1;
         }
      }

      //GENERATE AND MOVE OBJECTS
      if (!object_1_show && rand() % rare == 0)
      {
         object_1_show = 1;
         object_1_x = rand() % 640;
         object_1_size = rand() % 100 + min_object_size;
      }
      else if (object_1_show)
      {
         object_1_y = object_1_y + speed;
         if (object_1_y > 480)
         {
            object_1_show = 0;
            object_1_y = 10;
         }
      }

      if (!object_2_show && rand() % rare == 0)
      {
         object_2_show = 1;
         object_2_x = rand() % 640;
         object_2_size = rand() % 100 + min_object_size;
      }
      else if (object_2_show)
      {
         object_2_y = object_2_y + speed;
         if (object_2_y > 480)
         {
            object_2_show = 0;
            object_2_y = 10;
         }
      }

      if (!object_3_show && rand() % rare == 0)
      {
         object_3_show = 1;
         object_3_x = rand() % 640;
         object_3_size = rand() % 100 + min_object_size;
      }
      else if (object_3_show)
      {
         object_3_y = object_3_y + speed;
         if (object_3_y > 480)
         {
            object_3_show = 0;
            object_3_y = 10;
         }
      }


      // WE PAINT FROM HERE
      //===========================================================================

      // clear the screen
      clear_screen(COLOR_VIOLET);
      
      // draw plane   
      draw_image(plane_image, player_x, 400, 50, 50);

      if (object_1_show)
      {
         draw_rect(object_1_x, object_1_y, object_1_size, object_1_size, COLOR_GREEN);
      }

      if (object_2_show)
      {
         draw_rect(object_2_x, object_2_y, object_2_size, object_2_size, COLOR_GREEN);
      }

      if (object_3_show)
      {
         draw_rect(object_3_x, object_3_y, object_3_size, object_3_size, COLOR_GREEN);
      }

      if (won)
      {
         draw_image(won_image, 0, 0, screen_width, screen_height);
      }
      else if (lost)
      {
         draw_image(lost_image, 0, 0, screen_width, screen_height);
         //al_draw_bitmap(lost_image, 100, 100, 0);
      }

      // show display
      show();

      //=====================================================================================
   }

   // destroy all
   destroy();

   return 0;
}
