LED Project

Written by: Kenneth Tham on 26 June 2022

This program implements the LED button game.

The design caters for exetensibility in case the display changes.

IDisplay is the generic interface class and ConsoleDisplay is the specific implementation.

To compile the program:
	1. Unzip folder and copy to Linux system.
	2. Execute the command "g++ -Wall -c main.cpp IDisplay.cpp ConsoleDisplay.cpp LEDGameController.cpp DisplayFactory.cpp"
	3. Execute the 2nd command "g++ -Wall main.o LEDGameController.o IDisplay.o ConsoleDisplay.o DisplayFactory.o -o main.exe"
	4. Check that main.exe is generated in the folder.
	
To test the program:
	1. Run the program with command "./main.exe"
	2. You should see the menu and the test sequence answer printed in the first run for the first sequence.
	3. Enter a sequence different from the test sequence answer.
	4. Check that the 3 LEDS display the correct color. Ie. GREEN for correct letter and position. ORANGE for correct letter and wrong position
		RED for wrong letter and wrong position.
	5. Enter the correct sequence
	6. Check that the success message is displayed and the menu is printed again.
	7. Restart program by pressing Ctrl+C and executing the command "./main.exe" again.
	8. Enter another seqeuence different from test sequence and check the colors again.
	7. Conduct freeplay test by testing on the subsequent sequence after the 1st sequence. The sequence answer is not printed for subsequent sequences.


How to extend the program for other types of displays/hardware:
	1. Create another class deriving from IDisplay and implementing the interfaces in IDisplay.
	2. In DisplayFactory class, add an include reference to the new display class.
	3. In DisplayFactory class, modify GetDisplay method to return the new display based on an input string parameter.
	4. Modify main.cpp to call GetDisplay method with new input string parameter.
	5. Compile and run the test program.

