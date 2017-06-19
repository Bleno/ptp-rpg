#include <defs.h>


typedef struct Label
{
	int x, y;
	int r, g, b;
	SDL_Surface *text;
} Label;

typedef struct Widget
{
	int x, y, disabled, hidden;
	int *value, maxValue, minValue;
	int r, g, b;
	void (*clickAction)(void);
	void (*rightAction)(void);
	void (*leftAction)(void);
	Label *label;
	SDL_Surface *normalState, *selectedState, *disabledState;
} Widget;

typedef struct Menu
{
	int index, x, y, w, h, widgetCount;
	int startY, endY;
	SDL_Surface *background;
	Widget **widgets;
	Label **labels;
	void (*action)(void);
	void (*returnAction)(void);
} Menu;