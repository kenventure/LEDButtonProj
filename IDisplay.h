#ifndef DEF_IDisplay
#define DEF_IDisplay

enum LED_COLOUR{
	ORANGE,
	GREEN,
	RED
};

class IDisplay
{
	public:
	virtual void DisplayMenu() = 0;
	
	virtual char GetInput(){return 0;};
	
	virtual void DisplayLEDColour (LED_COLOUR col1, LED_COLOUR col2, LED_COLOUR col3){};
	
	virtual void PrintSuccess(){};
};

#endif