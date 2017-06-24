#include "input.h"

void getInput()
{
	SDL_Event event;
	
	/* Loop through waiting messages and process them */
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						input.up = 1;
						break;
					case SDLK_DOWN:
						input.down = 1;
						break;
					default:
						break;
				}
				break;
			case SDL_KEYUP:
			    switch(event.key.keysym.sym)
			    {
			    	case SDLK_UP:
			    		input.up = 0;
			    		break;
			    	case SDLK_DOWN:
			    		input.down = 0;
			    		break;
			    	default:
			    		break;
			    }
				break;
			default:
				break;
		}
	}
}
