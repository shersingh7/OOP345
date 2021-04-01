#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities util;
		ifstream f(file);

		if (!(f.is_open())) throw "Error";

		string currentStation = "";
		string nextStation = "";
		string temp = "";

		size_t a = 0;

		bool ok = false;

		while (!(f.eof()))
		{
			getline(f, temp);

			currentStation = util.extractToken(temp, a, ok);

			if (ok) nextStation = util.extractToken(temp, a, ok);
			
			for (int i = 0; i < stations.size(); i++)
			{
				if (stations[i]->getItemName() == currentStation)
				{
					for (int a = 0; a < stations.size(); a++)
					{
						if (stations[a]->getItemName() == nextStation) stations[i]->setNextStation(*stations[a]);
					}

					if (m_firstStation == nullptr) m_firstStation = stations[i];
				}
			}
		}

		f.close();

		
	}
	void LineManager::linkStations()
	{
		if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation) {
			*m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
	}
	bool LineManager::run(std::ostream& os)
	{
		static int counter = 1;

		os << "Line Manager Iteration: " << counter << endl;

		if ();
		counter++;
	}
	void LineManager::display() const
	{
	}
}

