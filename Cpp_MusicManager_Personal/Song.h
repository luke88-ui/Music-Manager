#pragma once
#include <iostream>
#include <sstream>



using namespace std;


class Song
{
private:

	int id;
	string track;
	string artist;




public:
	//mutators
	void setID(int i)
	{
		id = i;

	}

	void setTrack(string t)
	{
		track = t;

	}
	void setArtist(string a)
	{
		artist = a;

	}

	//accessors
	int getID() const { return id;  }
	string getTrack() const { return track;}
	string getArtist() const
	{
		return artist;
	}

	//Constructors
	Song(int i = 000, string t = "na", string a = "na") : id(i), track(t), artist(a)
	{
	}
	//Destructor
	~Song()
	{
	}

	//User Methods


	void titleCase(string& artist)
	{

		if (artist.empty())
		{
			return;
		}
		artist.at(0) = toupper(artist.at(0));

		for (int i = 1; i < artist.length(); i++)
		{
			if (artist[i - 1] == ' ')
			{
				artist[i] = toupper(artist[i]);
			}
			else
			{
				artist[i] = tolower(artist[i]);
			}
		}

	}

	friend ostream& operator<<(ostream& sout, const Song& s) {

			//sout << endl;
			//sout << "Track details: " << endl;
			sout << "ID: " << s.id << ", Song[Track title : " << s.track << ", Artist : " << s.artist << "]" << endl;
			return sout;

		}

		//experiments
	};

