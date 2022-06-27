
#include "IDisplay.h"

#include <stdlib.h>
#include <iostream>
#include <time.h>

class LEDGameController
{
	private:
		IDisplay* m_Display;
		static const int LED_SIZE = 3;
		LED_COLOUR m_LEDs[LED_SIZE];
		
		char* m_Sequence;
		char  m_SeqChar[3];
		
		void GenerateSeqeuence()
		{
			int seconds = time(NULL);
			seconds = seconds%3;
			for (int i = 0; i < LED_SIZE; i++)
			{
				m_Sequence[i] = m_SeqChar [(rand()+seconds)%LED_SIZE];				
			}
			m_Sequence[3]='\0';
		}
	public:
		LEDGameController (IDisplay* pDisplay):m_Display(pDisplay){

			m_Sequence = new char[LED_SIZE+1];
			m_SeqChar[0]='A';
			m_SeqChar[1]='B';
			m_SeqChar[2]='C';
			
	}
	
	
		void Start()
		{
			
			bool correct = false;
			
			
			GenerateSeqeuence();
			std::cout<<"Test sequence: "<<m_Sequence<<std::endl;
			if (m_Display==0)
			{
				std::cout<<"Display is null\n";
				return;
			}
			m_Display->DisplayMenu();
			
			
			while(1)
			{			
				
				
				correct = true;
				for (int i = 0; i < LED_SIZE; i++)
				{
					char currInput = m_Display->GetInput();
					if (currInput == m_Sequence[i])
					{
						m_LEDs[i] = GREEN;
					}
					else
					{
						bool found = false;
						for (int j = 0 ; j < LED_SIZE; j++)
						{
							if (i!=j)
							{
								if (currInput == m_Sequence[j])
								{
									m_LEDs[i] = ORANGE;
									found = true;
									correct = false;
								}
							}
						}
						if (!found)
						{
							m_LEDs[i] = RED;
							correct = false;
						}
					}
				}
				
				
				m_Display->DisplayLEDColour(m_LEDs[0], m_LEDs[1], m_LEDs[2]);
				if (correct)
				{
					m_Display->PrintSuccess();
					GenerateSeqeuence();
					m_Display->DisplayMenu();
				}
			}
			
			
		}
	
};