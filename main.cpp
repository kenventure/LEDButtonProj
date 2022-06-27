#include <iostream>
#include "DisplayFactory.h"
#include "IDisplay.h"
#include "LEDGameController.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
	
	DisplayFactory factory1;
	
	IDisplay* display = factory1.GetDisplay(((char*)"Console"));
	LEDGameController controller1(display);
	controller1.Start();
    return 0;
}
