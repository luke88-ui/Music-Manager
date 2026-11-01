
// Cpp_MusicManager_Personal.cpp 

#include <iostream>
#include <vector>
#include <string>
#include "Song.h"
#include <fstream>
#include <map>
#include "List.h"
#include "Node.h"
using namespace std;



// Shorthand type aliases -------------------------------------------------------
typedef map<string, size_t> DBmap;

//utility functions
void displaySongs(const vector<Song>& songs)
{
    for (int i = 0; i < songs.size(); i++)
    {
        cout << songs[i] << endl;
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
            cout << songs[i] << endl;
            return true;
        }
    }

    return false;

}

bool deleteSong(vector<Song>& songs, string& key)
{
    bool match = false;
    for (auto it = songs.begin(); it != songs.end(); it++)
    {
        if ((*it).getTrack() == key)
        {
            it = songs.erase(it);
            match = true;
            return true;

        }
    }
    return false;



}
/////////////////////////////////////////////////////////////////

void editPersonalSongs(vector<Song>& db, DBmap& idMap, List<Song>& myPlaylist) {
    int answer = 2;
    string idEntry;

    cout << "Would you like to add or delete track to your playlist? 1 to add, 0 to delete [-1 to end]\n";
    cin >> answer;
    cin.ignore();

    while (answer != -1)
    {
        if (answer == 1)
        {
            cout << "Enter the song ID you wish to add: ";
            getline(cin, idEntry);

            if (idMap.find(idEntry) != idMap.end()) {
                size_t position = idMap[idEntry];

                myPlaylist.push_back(db[position]);

                cout << "Added to your playlist!\n";
                cout << "Add another? [1 to add, 0 to delete, -1 to end]: ";
                cin >> answer;
                cin.ignore();
            }
            else
            {
                cout << " Song ID doesn't exist.\n";
                cout << "Try again? [1 to try adding again, 0 to delete, -1 to end]: ";
                cin >> answer;
                cin.ignore();
            }
        }
        else if (answer == 0)
        {
            if (myPlaylist.empty())
            {
                cout << "Action denied. Empty playlist. " << endl;
                cout << "Try again? [1 to add, 0 to delete, -1 to end]: ";
                cin >> answer;
                cin.ignore();
            }
            else
            {
                cout << "Enter the song ID you wish to delete: ";
                getline(cin, idEntry);
                int targetID = stoi(idEntry);

                bool found = false;

                     if (myPlaylist.findAndEraseByID(targetID)) {
                        cout << "Removed from your playlist!\n";
                    }
                    else {
                        cout << " That ID does not exist in your personal playlist." << endl;
                    }

              cout << "Do the operation again? [-1 to end] ";
              cin >> answer;
              cin.ignore();
            }
        }
        else
        {
            // Safeguard case if they enter something weird like 5 or 9
            cout << "Invalid selection. [1 to add, 0 to delete, -1 to end]: ";
            cin >> answer;
            cin.ignore();
        }
    }
}


void searchPersonal(DBmap& idMap, List<Song>& myPlaylist) {
    int answer = 2;
    string idEntry;
    do
    {
        cout << "Enter the ID of the song you wish to display [-1 to end]: \n";
        getline(cin, idEntry);
        int targetID = stoi(idEntry);

        bool found = false;

        if (myPlaylist.entryExist(targetID)) {
            cout << "Successfully found! " << endl;
        }
        else {
            cout << " That ID you're trying to find does not exist." << endl;
        }



    } while (answer != -1);

}

void searchGlobal() {
    cout << "Test" << endl;
}

void displayPersonalSongs(List<Song>& myPlaylist) {

    cout << myPlaylist;

}

void displaySongDatabase(vector<Song>& db, string caption = "") {
    cout << endl << caption << "  Size: " << db.size() << endl;
    cout << string(50, '-') << endl;
    for (const auto& s : db)
        cout << s << endl;

}

//------------------------------------------------------

void mainHub(vector<Song>& db, DBmap& idMap, List<Song>& myPlaylist) {
    int answer = 0;

    while (answer != -1) {
        cout << "\nSelect an action." << endl;
        cout << "1. Add/Remove from your personal playlist " << endl;
        cout << "2. Search for a song in your playlist " << endl;
        cout << "3. Search for a song in the inputted file " << endl;
        cout << "4. Display all songs in your playlist " << endl;
        cout << "5. Display all songs in the inputted file " << endl;
        cout << "-1 to exit the application " << endl;

        cin >> answer;
        cin.ignore(); // Clears the newline from the buffer

        if (answer == -1) {
            break;
        }
        else if (answer == 1) {
            editPersonalSongs(db, idMap, myPlaylist);
        }
        else if (answer == 2) {
            searchPersonal(idMap, myPlaylist);
        }
        else if (answer == 3) {
            searchGlobal();
        }
        else if (answer == 4) {
            displayPersonalSongs(myPlaylist);
        }
        else if (answer == 5) {
            displaySongDatabase(db, " Song Database ");
        }
        else {
            cout << "Not a valid number entry. Try again\n";
        }
    }
}

//----------------------------------------------------------------------------
int main() {
    cout << "Enter a song.txt file to begin! With valid id's and comma separation. ";
    vector<Song> db;
    DBmap idMap;
    List<Song> myPlaylist;

    string txtFile;
    getline(cin, txtFile);
    string fullPath = "C:/temp/" + txtFile;

    ifstream infile(fullPath);
    if (!infile) { cout << "Fatal error - file not found\n"; return 101; }

    string t, a, i;
    Song s;
    while (getline(infile, i, ',') && getline(infile, t, ',') && getline(infile, a)) {
        s.setID(stoi(i));
        s.setTrack(t);
        s.setArtist(a);
        db.push_back(s);
        idMap[i] = db.size() - 1;
    }
    infile.close();

    // Calls mainHub successfully because mainHub is written ABOVE this line!
    mainHub(db, idMap, myPlaylist);

    cout << "\nMusic Manager 2026. \n";
    return 0;
}

