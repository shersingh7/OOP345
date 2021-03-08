#include"Utilities.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		string temp;
		stringstream str;
		string name;
		getline(in, temp);

		string::size_type a = temp.find(',');
		name = temp.substr(0, a);
		temp.erase(0, a + 1);

		auto a1 = name.find_first_not_of(' ');
		auto a2 = name.find_last_not_of(' ');
		name = name.substr(a1, (a2 - a1) + 1);

		str << temp;

		if (in.peek() == EOF + 1)
		{
			return nullptr;
		}
		if (name == "c" || name == "C")
		{
			Vehicle* car;
			car = new Car(str);
			return car;
		}

	}
}
	
