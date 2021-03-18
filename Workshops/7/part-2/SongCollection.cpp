//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NAA
// Workshop:       7 
// Date:           18/03/2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "SongCollection.h"

namespace sdds
{
	SongCollection::SongCollection(const char* file)
	{
		if (file == nullptr)
		{
			throw "Bad File Name";
		}
		else
		{
			string temp = "";
			ifstream f(file);
			if (!f)
			{
				cout << "ERROR: Cannot open file [" << file << "]." << endl;
				return;
			}

			while (f && f.peek() != EOF)
			{
				string tYear;
				Song sTemp;
				getline(f,temp);

				sTemp.title = temp.substr(0, 25);
				temp.erase(0, 25);

				sTemp.artist = temp.substr(0, 25);
				temp.erase(0, 25);

				sTemp.album = temp.substr(0, 25);
				temp.erase(0, 25);

				tYear = temp.substr(0, 5);
				auto pos = tYear.find_first_not_of(' ');
				if (pos != 0) sTemp.year = 0;
				else sTemp.year = stoi(tYear);
				temp.erase(0, 5);

				sTemp.length = stoul(temp.substr(0, 5));
				temp.erase(0, 5);

				sTemp.m_price = stod(temp);

				//Removing Spaces
				auto pos1 = sTemp.title.find_first_not_of(' ');
				auto pos2 = sTemp.title.find_last_not_of(' ');
				sTemp.title = sTemp.title.substr(pos1, (pos2 - pos1) + 1);

				pos1 = sTemp.artist.find_first_not_of(' ');
				pos2 = sTemp.artist.find_last_not_of(' ');
				sTemp.artist = sTemp.artist.substr(pos1, (pos2 - pos1) + 1);

				pos1 = sTemp.album.find_first_not_of(' ');
				pos2 = sTemp.album.find_last_not_of(' ');
				sTemp.album = sTemp.album.substr(pos1, (pos2 - pos1) + 1);

				sCollection.push_back(sTemp);
			}
			f.close();
		}
	}
	void SongCollection::display(ostream& out) const
	{
		int hour = 0;
		int min = 0;
		int sec = 0;

		int total = accumulate(sCollection.begin(), sCollection.end(), 0u, [](const size_t& res, const Song theSong) { return res + theSong.length; });

		hour = total / 3600;
		min = (total % 3600) / 60;
		sec = total % 60;

		for_each(sCollection.begin(), sCollection.end(), [&](const Song& theSong) {
			out << theSong << endl;
		});

		out << "----------------------------------------------------------------------------------------" << endl;
		out << "| " << right << setw(77) << "Total Listening Time: " << hour << ":" << min << ":" << sec << " |" << endl;
	}

	void SongCollection::sort(string name)
	{
		if (name == "title") std::sort(sCollection.begin(), sCollection.end(), [](Song& songA, Song& songB) {return songA.title < songB.title; });
		else if (name == "album") std::sort(sCollection.begin(), sCollection.end(), [](Song& songA, Song& songB) {return songA.album < songB.album; });
		else if (name == "length") std::sort(sCollection.begin(), sCollection.end(), [](Song& songA, Song& songB) {return songA.length < songB.length; });
	}

	void SongCollection::cleanAlbum()
	{
		for_each(sCollection.begin(), sCollection.end(), [](Song& theSong) { if (theSong.album == "[None]") theSong.album = ""; });
	}

	bool SongCollection::inCollection(const char* name) const
	{
		return any_of(sCollection.begin(), sCollection.end(), [=](const Song& theSong) {return name == theSong.artist;});
	}

	list<Song> SongCollection::getSongsForArtist(string artist) const
	{
		auto iterator = count_if(sCollection.begin(), sCollection.end(), [&artist](const Song& theSong) {return artist == theSong.artist; });

		list<Song> theSongs(iterator);

		copy_if(sCollection.begin(), sCollection.end(), theSongs.begin(), [&artist](const Song& theSong) {return artist == theSong.artist; });

		return theSongs;
	}

	ostream& operator<<(ostream& out, const Song& theSong)
	{
		int min = 0;
		min = theSong.length / 60;

		int sec = 0;
		sec = theSong.length % 60;

			out << "| " << left << setw(20) << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album;
			if (theSong.year != 0) out << " | " << setw(6) << right << theSong.year << " | " << min << ":";
			else out << setw(12) << " | " << min << ":";
			if ((sec < 10)) out << "0" << sec;
			else out << sec;
			out << " | " << theSong.m_price << " |";

			return out;
	}
}


