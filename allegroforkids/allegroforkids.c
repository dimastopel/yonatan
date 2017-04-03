#include "allegroforkids.h"


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

void clear_screen_rgb(unsigned char r, unsigned char g, unsigned char b)
{
   al_clear_to_color(al_map_rgb(r,g,b));
}

void do_loop()
{
   al_init_timeout(&timeout, 0.06);
   al_wait_for_event_until(event_queue, &ev, &timeout);

   if(ev.type == ALLEGRO_EVENT_KEY_DOWN 
      && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
   {
         exit(0);
   }


   static int current_left = 0;
   static int current_right = 0;

    if (current_left)
    {
        do_left();
    }

    if (current_right)
    {
        do_right();
    }

     if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev.keyboard.keycode) {
           case ALLEGRO_KEY_LEFT: 
              current_left = 1;
              do_left();
              break;
           case ALLEGRO_KEY_RIGHT:
              current_right = 1;
              do_right();
              break;
        }
     }

     if(ev.type == ALLEGRO_EVENT_KEY_UP) {
        switch(ev.keyboard.keycode) {
           case ALLEGRO_KEY_LEFT: 
              current_left = 0;
              break;
           case ALLEGRO_KEY_RIGHT:
              current_right = 0;
              break;
        }
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

Bitmap* load_bitmap(char* filename)
{
  return al_load_bitmap(filename);
}


void draw_pixel(int x, int y, Color color)
{
  al_put_pixel(x, y, color);
}

void draw_pixel_rgb(int x, int y, 
  unsigned char r, unsigned char g, unsigned char b)
{
  al_put_pixel(x, y, al_map_rgb(r, g, b));
}



/////////////

int get_random_number(int start, int end)
{
	return (rand() % (end - start)) + start;
}

int get_binary(int rare_of_true)
{
	return rand() % rare_of_true == 0;
}

ALLEGRO_COLOR get_random_color()
{
	return al_map_rgb(rand() % 256, rand() % 256, rand() % 256);
}

int is_collision(int x1, int y1, int size1, int x2, int y2, int size2)
{
	return ((x2 < x1 + size1)   &&
	        (x2 + size2 > x1) &&
    	    (y2 + size2 > y1) &&
        	(y2 < y1 + size1));
}



