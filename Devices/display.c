#include "display_dev_res.c"
// Display device
UINT32* framebuffer_base;
uint32_t pixels_per_scanline;
uint32_t screen_width;
uint32_t screen_height;

void displayInit(UINT32* framebuf_base, uint32_t p_p_s, uint32_t scr_w, uint32_t scr_h) 
{
	// First, initialize some global variables
	framebuffer_base = framebuf_base;
	pixels_per_scanline = p_p_s;
	screen_width = scr_w;
	screen_height = scr_h;
}