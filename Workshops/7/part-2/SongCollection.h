//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       7 
// Date:           18/03/2021
//==============================================

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
//#include<fstream>
#include<algorithm>
#include<list>
#include<fstream>
//#include<sstream>
#include<numeric>

using namespace std;
namespace sdds
{
	struct Song
	{
		string artist;
		string title;
		string album;
		double m_price;
		size_t year;
		size_t length;
	};

	class SongCollection
	{
		vector<Song> sCollection;
	public:
		SongCollection(const char* file);
		void display(ostream& out)const;
		void sort(string);
		void cleanAlbum();
		bool inCollection(const char*)const;
		std::list<Song> getSongsForArtist(string) const;
	};
	ostream& operator<<(ostream& out, const Song& theSong);
}

#endif // !SDDS_SONGCOLLECTION_H

