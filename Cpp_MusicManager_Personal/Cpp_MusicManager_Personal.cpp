// Cpp_MusicManager_Personal.cpp 

#include <iostream>
#include <vector>
#include <string>
#include "Song.h"
using namespace std;


void displaySongs(const vector<Song>& songs)
{
	//TO-DO
	

}



int main()
{
    cout << "Welcome to the music hub! Find a song! \n" << endl;

	cout << "Would you like to add a track to your playlist? Enter Y/Yes to continue or any key to exit! " << endl;
	
	string song;
	string artist;
	string answer;
	vector<Song> songs;

	getline(cin, answer);
	
	 while (answer == "Yes")
	{
		
		
		 cout << "DEBUG: choice = [" << answer << "]\n";

		 cout << "Please enter your track and artist. "<< endl;
		 getline(cin, song);
		 cout << "Please enter your artist with that track." << endl ;
		 getline(cin, artist);

		 songs.emplace_back(song, artist); //When accepting multiple parameters, this is ideal.

		 cout << songs.back().toString() << endl;

		 cout << "Add another track? " << endl;
		 getline(cin, answer);


		 cout << "DEBUG #2: choice = [" << answer << "]\n";
		
	}

	  cout << "Music Manager 2026. \n";
}
