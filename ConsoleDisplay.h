#include "IDisplay.h"
#include <iostream>

using namespace std;

class ConsoleDisplay:public IDisplay
{
	private:
		char m_ColStr[3][10] = {"ORANGE", "GREEN", "RED"};
	
	
	public:
	
	ConsoleDisplay(){};
	
	virtual void DisplayMenu()
	{
		cout<<"Enter SEQUENCE of 3 characters (A, B or C)\n";
	};
	
	virtual char GetInput()
	{
		char input;
		cin>>input;
		return input;
	};
	
	virtual void PrintSuccess()
	{
		cout<<"Congratualations, you got it right!\n";
	}
	virtual void DisplayLEDColour (LED_COLOUR col1, LED_COLOUR col2, LED_COLOUR col3){
		cout<<"LED1: "<<m_ColStr[col1]<<" LED2: "<<m_ColStr[col2]<<" LED3: "<<m_ColStr[col3]<<endl;
	};
};

