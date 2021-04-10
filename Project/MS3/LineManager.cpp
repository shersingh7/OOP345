// Name: Davinder Verma
// Seneca Student ID: 121802201
// Seneca email: dverma22@myseneca.ca
// Date of completion: 05/04/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		ifstream f(file);

		if (!(f.is_open())) throw "Error";
		else
		{

			while (!f.eof())
			{
				Utilities temp;
				size_t a = 0;
				bool ok = false;
				string str;
				string stationStr;
				string nextStationStr;

				temp.setDelimiter('|');

				getline(f, str);

				stationStr = temp.extractToken(str, a, ok);

				if (ok) 
				{
					nextStationStr = temp.extractToken(str, a, ok);
				}
				else 
				{
					nextStationStr = "";
				}

				for (auto iterator : stations) 
				{
					if (stationStr == iterator->getItemName())
					{
						for (auto iterator2 : stations)
						{
							if (iterator2->getItemName() == nextStationStr)
							{
								iterator->setNextStation(iterator2);
							}
						}
						activeLine.push_back(iterator);
					}
				}
			}
			f.close();
			m_firstStation = activeLine.front();
			m_cntCustomerOrder = pending.size();

		}

	}
	void LineManager::linkStations()
	{
		for (size_t i = 0; i < activeLine.size(); i++) 
		{
			if (!activeLine[i]->getNextStation()) 
			{
				swap(activeLine[activeLine.size() - 1], activeLine[i]);
				break;
			}
		}

		for (size_t i = activeLine.size() - 1; i > 0; i--) 
		{
			Workstation* temp = activeLine[i];
			for (size_t x = 0; x < i; x++) 
			{
				if (temp == activeLine[x]->getNextStation()) 
				{
					swap(activeLine[i - 1], activeLine[x]);
				}
			}
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t count = 1;
		os << "Line Manager Iteration: " << count << endl;

		if (!pending.empty()) 
		{
			*activeLine.front() += move(pending.front());
			pending.pop_front();
		}

		for (size_t i = 0; i < activeLine.size(); i++) 
		{
			activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->attemptToMoveOrder();
		}
		count++;
		return completed.size() == m_cntCustomerOrder;
	}
	void LineManager::display(ostream& os) const
	{
		for (size_t i=0;i<activeLine.size();i++)
		{
			activeLine[i]->display(os);
		}
	}
}
