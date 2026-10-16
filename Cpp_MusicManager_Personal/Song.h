#pragma once
#include <iostream>
#include <sstream>



using namespace std;


class Song
{
private:

	string track;
	string artist;


public:
	//mutators

	void setTrack(string trackValue)
	{
		track = trackValue;

	}
	void setArtist(string artistValue)
	{
		artist = artistValue;

	}

	//accessors
	string getTrack() const {
		return track; }
	string getArtist() const
	{
		return artist;}

	//Constructors
	Song(string trackValue = "na", string artistValue = "na")
	{
		setTrack(trackValue);
		setArtist(artistValue);

	}
	//Destructor
	~Song()
	{}

	//User Methods
	string toString() const
	{
		stringstream sout;
		sout << "Track details: " << endl;
		sout << " Song [Track title: " << track << ", Artist: " << artist << "]" << endl;
		sout << "Stored in:  " << this;


		return sout.str();
	}


	//experiments
};

