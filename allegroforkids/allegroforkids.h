

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#ifndef ALLEGROFORKIDS
#define ALLEGROFORKIDS


// Definitions
#define Bitmap ALLEGRO_BITMAP
#define Color ALLEGRO_COLOR


// Variables

ALLEGRO_DISPLAY *display; 
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_EVENT ev;
ALLEGRO_TIMEOUT timeout;

ALLEGRO_COLOR COLOR_RED;
ALLEGRO_COLOR COLOR_GREEN;
ALLEGRO_COLOR COLOR_BLUE;
ALLEGRO_COLOR COLOR_CYAN;
ALLEGRO_COLOR COLOR_YELLOW;
ALLEGRO_COLOR COLOR_VIOLET;

// Graphics related functions

void init(int screen_width, int screen_height);
void clear_screen(ALLEGRO_COLOR color);
void clear_screen_rgb(unsigned char r, unsigned char g, unsigned char b);
void do_loop();
void draw_image(ALLEGRO_BITMAP *image, float x, float y, float width, float height);
void draw_pixel(int x, int y, Color color);
void draw_pixel_rgb(int x, int y, unsigned char r, unsigned char g, unsigned char b);
void draw_rect(float x, float y, float width, float height, ALLEGRO_COLOR color);
void draw_line(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color);
void draw_circle(float x1, float y1, float r, ALLEGRO_COLOR color);
void show();
void destroy();
Bitmap* load_bitmap(char* filename);

// General functions

int get_random_number(int start, int end);
int get_binary(int rare_of_true);
ALLEGRO_COLOR get_random_color();
int is_collision(int x1, int y1, int size1, int x2, int y2, int size2);

void do_left();
void do_right();

#endif
