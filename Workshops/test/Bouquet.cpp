#include <iostream>
#include <string>

using namespace std;

class Bouquet
{
	string* nameOfFlowers;
	unsigned int noOfFlowers;
	int noOfRoses=0;

public:

	Bouquet();

	Bouquet(unsigned int index, const string* names = nullptr)
	{
		if (names == nullptr && index != 0)
		{
			throw "Bad Parameters";
		}
	};

	bool operator==(const Bouquet& src)
	{
		if (this->nameOfFlowers == src.nameOfFlowers)
		{
			if (this->noOfFlowers == src.noOfFlowers)
			{
				for (int i = 0; i < noOfFlowers; i++)
				{
					if(nameOfFlowers[i] == src[i].nameOfFlowers) 	return true;


					if (this->nameOfFlowers->compare("Rose") == 0)
					{
							noOfRoses++;
					}

				}


				
			}
			
		}
		else if (this->nameOfFlowers->compare("Poison Ivy") == 0)
		{
			throw 1;
		}
		else if (src.nameOfFlowers->compare("Poisong Ivy") == 0)
		{
			throw 2;
		}
		else if (this->noOfFlowers == 0 || src.noOfFlowers == 0)
		{
			return false;
			exit(20);
		}
		

	}




};