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
   al_clear_to_color(al_map_rgb(0,0,255)); // color the full screen


   // load images
   ALLEGRO_BITMAP *image = al_load_bitmap("minecraft.png");
   ALLEGRO_BITMAP *lost_image = al_load_bitmap("lost.png");
   ALLEGRO_BITMAP *won_image = al_load_bitmap("won.png");

   // create event queue
   ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   // init variables
   int doexit = 0;
   int lost = 0;
   int won = 0;

   float player_x = 320;
   float player_y = 240;
   int player_size = al_get_bitmap_width(image);
   
   // middle of rectangle
   float comp_x = 320;
   float comp_y = 240;
   float size = 80;

   float palyer_move = 10;
   float comp_move = 7;
   
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

         int rand_dir = rand() % 4; // rand can 0 (up), 1 (down), 2 (right), 3 (left)
         switch(rand_dir) {
            case 0:
               comp_y = comp_y - comp_move;
               break;
            case 1:
               comp_y = comp_y + comp_move;
               break;
            case 2:
               comp_x = comp_x - comp_move;
               break;
            case 3:
               comp_x = comp_x + comp_move;
               break;
         }

         if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
               case ALLEGRO_KEY_PAD_8:
                  player_y = player_y - palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_2:
                  player_y = player_y + palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_4: 
                  player_x = player_x - palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_6:
                  player_x = player_x + palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_7:
                  player_x = player_x - palyer_move;
                  player_y = player_y - palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_9:
                    player_x = player_x + palyer_move;
                    player_y = player_y - palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_1:
                  player_x = player_x - palyer_move;
                  player_y = player_y + palyer_move;
                  break;
               case ALLEGRO_KEY_PAD_3:
                  player_x = player_x + palyer_move;
                  player_y = player_y + palyer_move;
                  break;
               case ALLEGRO_KEY_ESCAPE:
                  doexit = 1;
                  break;
            }
         }

         //check if won or lost
         if (time(NULL) - start_time > 10)
         {
            won = 1;
         }
         
         if (player_x < (comp_x - size) || player_y < (comp_y - size))
         {
            lost = 1;
         }
         if ((player_x + player_size) > (comp_x + size) || 
             (player_y + player_size) > (comp_y + size))
         {
            lost = 1;
         }
      }

      al_clear_to_color(al_map_rgb(0,0,255)); // color the full screen
      al_draw_filled_rectangle(comp_x - size, comp_y - size, 
         comp_x + size, comp_y + size, al_map_rgb(0,255,0));

      al_draw_bitmap(image, player_x, player_y, 0);

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
   }

   al_destroy_display(display); // destroy display

   return 0;
}
