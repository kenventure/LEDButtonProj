
#include "ConsoleDisplay.h"
#include "IDisplay.h"
#include <string.h>


class DisplayFactory
{
	public:
		DisplayFactory()
		{};
		
		IDisplay* GetDisplay (char* display)
		{
			if (strcmp(display, "Console")==0)
			{
				return new ConsoleDisplay();
			}
			return 0;
		}
		
	
};