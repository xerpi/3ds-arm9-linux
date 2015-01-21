/*
 * Wrap-around code for a console using the
 * DECstation PROM io-routines.
 *
 * Copyright (c) 1998 Harald Koerfgen
 */

#include <linux/tty.h>
#include <linux/ptrace.h>
#include <linux/init.h>
#include <linux/console.h>
#include <linux/fs.h>
#include <asm/io.h>

static int n3ds_console_x;
static int n3ds_console_y;

extern const unsigned char msx_font[];

#define SCREEN_TOP_W  (400)
#define SCREEN_BOT_W  (340)
#define SCREEN_TOP_H  (240)
#define SCREEN_BOT_H  (240)

#define FB_TOP_LEFT1  (0x20184E60)
#define FB_TOP_LEFT2  (0x201CB370)
#define FB_TOP_RIGHT1 (0x20282160)
#define FB_TOP_RIGHT2 (0x202C8670)
#define FB_BOT_1	  (0x202118E0)
#define FB_BOT_2	  (0x20249CF0)

#define FB_TOP_SIZE	  (0x46500)
#define FB_BOT_SIZE	  (0x3BC40)

#define RED	   0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define CYAN   0x00FFFF
#define BLACK  0x000000
#define WHITE  0xFFFFFF

static void draw_plot(int x, int y, u32 color)
{
	u8 *base = (u8*)((SCREEN_TOP_H-y-1)*3 +x*3*SCREEN_TOP_H);
	u8 *p1 = base + FB_TOP_LEFT1;
	u8 *p2 = base + FB_TOP_LEFT2;
	u8 *p3 = base + FB_TOP_RIGHT1;
	u8 *p4 = base + FB_TOP_RIGHT2;
	p1[0] = p2[0] = p3[0] =	 p4[0] = color & 0xFF;
	p1[1] = p2[1] = p3[1] =	 p4[1] = (color>>8) & 0xFF;
	p1[2] = p2[2] = p3[2] =	 p4[2] = (color>>16) & 0xFF;
}

static void draw_fillrect(int x, int y, int w, int h, u32 color)
{
	int i, j;
	for (i = 0; i < w; ++i) {
		for (j = 0; j < h; ++j) {
			draw_plot(x+i, y+j, color);
		}
	}
}

static int font_draw_char(int x, int y, u32 color, char c)
{
	u8 *font = (u8*)(msx_font + (c - (u32)' ') * 8);
	int i, j;
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			if ((*font & (128 >> j))) draw_plot(x+j, y+i, color);
		}
		++font;
	}
	return x+8;
}

//Returns Y
static int font_draw_string(int x, int y, u32 color, const char *string)
{
	int startx = x;
	if (string == NULL) return y;
	while (*string) {
		if (*string == '\n') {
			x = startx;
			y+=10;
		} else if (*string == ' ') {
			x+=8;
		} else if(*string == '\t') {
			x+=8*4;
		} else if (*string >= ' ' && *string <= 0x7E) {
			if (x > (SCREEN_TOP_W-8)) {
				x = startx;
				y += 10;
			}
			draw_fillrect(x, y, 8, 8, BLACK);
			font_draw_char(x, y, color, *string);
			x+=8;
		}
		string++;
	}
	return y;
}

static void n3ds_console_print(const char *string)
{
	n3ds_console_y = font_draw_string(10, n3ds_console_y, WHITE, string) + 10;
	if (n3ds_console_y > (SCREEN_TOP_H-10)) n3ds_console_y = 10;
	else draw_fillrect(0, n3ds_console_y, SCREEN_TOP_W, 8, BLACK);
}

/****************************************************************************/
#ifdef CONFIG_N3DS_TEXT_CONSOLE_STEP_BY_STEP
extern void black_screen();
#define IO_PAD ((volatile unsigned int*)0x10146000)
#define PAD_NONE   (0xFFF)
#define PAD_A	  (1<<0)
static int CheckButtons(uint32_t mask)
{
	uint32_t value = ~mask & PAD_NONE;
	return (*IO_PAD == value);
}
#endif

extern void n3ds_console_write(struct console *co, const char *s,
			       unsigned count)
{
#ifdef CONFIG_N3DS_TEXT_CONSOLE_STEP_BY_STEP
	black_screen();
	n3ds_console_x = 10;
	n3ds_console_y = 10;
#endif

	n3ds_console_print(s);
	
#ifdef CONFIG_N3DS_TEXT_CONSOLE_STEP_BY_STEP
	/* Step-by-step mode (press A button for next line of output).
	 * This is really ugly but really useful at times :) */
	while (!CheckButtons(PAD_A)) ;
	while (CheckButtons(PAD_A)) ;
#endif
}

/*
 *	Initialize the 3DS screen.
 */
static int __init n3ds_console_setup(struct console *co, char *options)
{
	n3ds_console_x = 10;
	n3ds_console_y = 10;

	return 0;
}

/*
static struct console sercons =
{
	.name	= "ttyS",
	.write	= n3ds_console_write,
	.setup	= n3ds_console_setup,
	.flags	= CON_PRINTBUFFER,
	.index	= -1,
};
*/
/*
 *    Register console.
 */

extern int __init n3ds_console_init(void)
{
	//register_console(&sercons);
	n3ds_console_setup(NULL, NULL);
	
	n3ds_console_print("Console init!");

	return 0;
}

