//compile as follows:
//gcc -Wall -o yonik yonatan.c `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


void init_all()
{
   al_init(); // initialize the library
   al_init_primitives_addon(); // init primitives addon (for line draw)
   al_install_keyboard();
   al_init_image_addon();
   srand(time(NULL));
}


int main(){
   
   // initialize all
   init_all();


   // create display
   ALLEGRO_DISPLAY *display = NULL; 
   display = al_create_display(640, 480); // create display
   al_clear_to_color(al_map_rgb(128,128,255)); // color the full screen


   // load images
   ALLEGRO_BITMAP *plane_img = al_load_bitmap("plane_game/plane.png");
   ALLEGRO_BITMAP *won_image = al_load_bitmap("plane_game/won.png");
   ALLEGRO_BITMAP *lost_image = al_load_bitmap("plane_game/lost.png");

   // create event queue
   ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   // init variables
   int doexit = 0;
   int lost = 0;
   int won = 0;

   float player_x = 320;
   //int player_size = al_get_bitmap_width(plane_img);

   float object_1_x = 30;
   float object_1_y = 10;
   float object_1_size = 30;

   float object_2_x = 30;
   float object_2_y = 10;
   float object_2_size = 30;

   float object_3_x = 30;
   float object_3_y = 10;
   float object_3_size = 30;

   int object_1_show = 0; 
   int object_2_show = 0; 
   int object_3_show = 0; 

   float speed = 10;
   int rare = 20;
   int player_speed = 14;
   int min_object_size = 20;

   time_t start_time = time(NULL);

   while(!doexit)
   {
      ALLEGRO_EVENT ev;
      ALLEGRO_TIMEOUT timeout;
      al_init_timeout(&timeout, 0.06);
      al_wait_for_event_until(event_queue, &ev, &timeout);

      if(ev.type == ALLEGRO_EVENT_KEY_DOWN 
         && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
      {
            doexit = 1;
      }


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
               case ALLEGRO_KEY_ESCAPE:
                  doexit = 1;
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

      al_clear_to_color(al_map_rgb(189,34,100)); // color the full screen

      //al_draw_bitmap(plane_img, player_x, 350, 0);
      al_draw_scaled_bitmap(plane_img,
         0, 0, al_get_bitmap_width(plane_img), al_get_bitmap_height(plane_img),
         player_x, 400, 50, 50, 0);



      if (object_1_show)
      {
         al_draw_rectangle(object_1_x, object_1_y, object_1_x + object_1_size, 
            object_1_y + object_1_size, al_map_rgb(0,255,0), 5);
      }

      if (object_2_show)
      {
         al_draw_rectangle(object_2_x, object_2_y, object_2_x + object_2_size, 
            object_2_y + object_2_size, al_map_rgb(0,255,0), 5);
      }

      if (object_3_show)
      {
         al_draw_rectangle(object_3_x, object_3_y, object_3_x + object_3_size, 
            object_3_y + object_3_size, al_map_rgb(0,255,0), 5);
      }

      if (won)
      {
         al_draw_scaled_bitmap(won_image,
            0, 0, al_get_bitmap_width(won_image), al_get_bitmap_height(won_image),
            0, 0, 640, 480, 0);
      }
      else if (lost)
      {
         al_draw_scaled_bitmap(lost_image,
            0, 0, al_get_bitmap_width(lost_image), al_get_bitmap_height(lost_image),
            0, 0, 640, 480, 0);
         //al_draw_bitmap(lost_image, 100, 100, 0);
      }

      al_flip_display(); // show display

      //=====================================================================================
   }

   al_destroy_display(display); // destroy display

   return 0;
}
