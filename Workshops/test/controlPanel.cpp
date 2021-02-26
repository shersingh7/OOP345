#include <iostream>
#include <string>

using namespace std;

struct Indicator
{
	int id;
	char ledColour;
};

class ControlPanel: public Indicator
{

	string* Indicators;
	unsigned int noOfIndicators = 0;
	int noOfRed = 0;

public:
	ControlPanel();
	ControlPanel(const int* i,const char* c, unsigned int no =0)
	{
		
		if (i == nullptr || c == nullptr)
		{
			throw invalid_argument("WRONG");
		}
		else
		{
			noOfIndicators = no;

			for (int k = 0; k < no; k++)
			{
				Indicators[k] = (i[k], c[k]);
			}

		}
	}

	void changeLED(int id, char color)
	{
		int counter = 0;

		if (Indicators != nullptr)
		{
			for (int i = 0; i < noOfIndicators; i++)
			{
				if (Indicators[i][i] == (id))
				{
					Indicators[i][i] == color;
					counter++;
				}
				if (Indicators[i][i] == 'r')
				{
					noOfRed++;
				}
			}
			if (counter < 0)
			{
				throw "LED not found!";
			}
		}
		else
		{
			exit(40);
		}
	}

};



