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
		counter++;
		bool ok = false;

		if (!pending.empty())
		{
			int temp = 0;
			for (size_t i=0;i< activeLine.size();i++)
			{
				temp = i;
				for (size_t j = 0; j < activeLine.size(); j++)
				{
					if (activeLine[j]->getNextStation() != nullptr && activeLine[i]->getItemName().compare(activeLine[j]->getNextStation()->getItemName()) == 0)
					{
						temp = ok;
					}
				}
				if (temp != ok) break;
			}
			*activeLine[temp] += move(pending.front());
			pending.pop_front();
		}
		for(size_t i = 0; i < activeLine.size(); i++) activeLine[i]->run(os);

		for(size_t i = 0; i < activeLine.size(); i++)
		{
			if (activeLine[i]->getNextStation() == nullptr)
			{
				CustomerOrder obj;
				bool check = false;
				
				if (m_orders.front().isOrderFilled())
				{
					obj = move(m_orders.front());
					m_oroders.pop_front();
					check = true;
				}

				if (check)
				{
					completed.push_back(move(obj));
				}
			}
			else
			{
				activeLine[i]
			}

		}

	}
	void LineManager::display() const
	{
		for (size_t i=0;i<activeLine.size();i++)
		{
			activeLine{ i }->display(cout);
		}
	}
}

