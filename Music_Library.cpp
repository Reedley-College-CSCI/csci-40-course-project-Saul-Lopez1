// CSCI-40 Final Project
// Author: [Saul Lopez]

/* Description:
 * This program to build their own music library, with functions such as:
 * adding, removing, viewing, searching for, and sorting songs.
 *
 Each song includes: artist, song, and genre.
 *
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

class Song {
public:
    void SetArtist(string artistName) {
        artist = artistName;
    }
    void SetName(string songName) {
        name = songName;
    }
    void SetGenre(string genreName) {
        genre = genreName;
    }
    void Print() const;

private:
    string artist;
    string name;
    string genre;
};

Song songs;
int count = 0;

void console();
void userInputSongs();

int main() {

    console();

    return 0;
}

void Song::Print() const {
    cout << artist << "     " << name << "     " << genre << endl;
}

void console() {
    string consoleCommand;

    cout << "Options: " << endl;
    cout << "   Type '1' to add a song." << endl;
    cout << "   Type '2' to remove a song." << endl;
    cout << "   Type '3' to view your songs." << endl;
    cout << "   Type '4' to search for a song." << endl;
    cout << "   Type '5' to sort songs." << endl;
    cout << "Enter an option: " << endl;
    getline(cin, consoleCommand);

    if (consoleCommand == "1") {
        userInputSongs();
    }
}

void userInputSongs() {
    string artistName;
    string songName;
    string genreName;
    const string SENTINEL = "Exit";

    while (true) {
        cout << "Enter the artist's name (type 'Exit' to stop): " << endl;
        getline(cin, artistName);

        if (artistName == SENTINEL) {
            break;
        }
        songs.SetArtist(artistName);

        cout << "Enter the song's name: " << endl;
        getline(cin, songName);
        songs.SetName(songName);

        cout << "Enter the genre: " << endl;
        getline(cin, genreName);
        songs.SetGenre(genreName);

        cout << "Here is your song: " << endl;
        songs.Print();
        cout << endl;
    }
    console();
}