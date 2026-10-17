// Cpp_MusicManager_Personal.cpp 

#include <iostream>
#include <vector>
#include <string>
#include "Song.h"
using namespace std;


void displaySongs(const vector<Song>& songs)
{
	for (int i = 0; i < songs.size(); i++)
	{
		cout << songs[i].toString() << endl;
	}
}

bool findSong(const vector<Song>& songs, string& key) //pass our Vector and our key to find a match.
{
	bool match = false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (songs[i].getTrack() == key)
		{
			match = true;
			return true;

		}
	}

	return false;

}


int main()
{
    cout << "Welcome to the music hub! Find a song! \n" << endl;

	cout << "Would you like to add a track to your playlist? Enter Y/Yes to continue or any key to exit! " << endl;
	
	string song;
	string artist;
	string answer;
	string answer2;
	string searchTitle;

	vector<Song> songs;

	getline(cin, answer);
	
	 while (answer == "Yes" || answer == "yes" || answer == "YES" || answer == "Y" || answer == "y")
	{
	

		 cout << "Please enter your track and artist. "<< endl;
		 getline(cin, song);
		 cout << "Please enter your artist with that track." << endl ;
		 getline(cin, artist);

		 songs.emplace_back(song, artist); //When accepting multiple parameters, this is ideal.

		 cout << songs.back().toString() << endl;

		 cout << "Add another track? " << endl;
		 getline(cin, answer);

		
	}
	 cout << endl;
	 cout << "All songs in your database: \n" << endl;
	 displaySongs(songs);

	 cout << "Would you like to confirm the existence for an existing song in the database? ";
	 getline(cin, answer2);
		 
	 while (answer2 == "Yes" || answer2 == "yes" || answer2 == "YES" || answer2 == "Y" || answer2 == "y")
	 {
		 cout << "Enter the song title: " << endl;
		 getline(cin, searchTitle);
		 if (findSong(songs, searchTitle))
		 {
			 cout << "Song found! " << endl;

		 }
		 else
		 {
			 cout << "Requested song was not found! " << endl;

		 }
		 cout << "Find another song? " << endl;
		 getline(cin, answer2);

	
	 }


	  cout << "Music Manager 2026. \n";
}
