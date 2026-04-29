// CSCI-40 Final Project
// Author: [Saul Lopez]

/* Description:
 * This program to build their own music library, with functions such as:
 * adding, removing, viewing, searching for, and sorting songs.
 *
 * Each song includes: artist, song, and genre.
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


int capacity = 2;
int currCount = 0;
Song* songs = new Song[capacity];

void console();
void userInputSongs();
void viewAll();
void resizeLibrary();

int main() {

    console();

    delete[] songs;

    return 0;
}

void Song::Print() const {
    cout << artist << " | " << name << " | " << genre << endl;
}

void console() {
    string consoleCommand;

    while (true) {
        cout << "Options: " << endl;
        cout << "   Type '0' to import songs from a file." << endl;
        cout << "   Type '1' to add a song." << endl;
        cout << "   Type '2' to remove a song." << endl;
        cout << "   Type '3' to view your songs." << endl;
        cout << "   Type '4' to search for a song." << endl;
        cout << "   Type '5' to sort songs." << endl;
        cout << "   Type '6' to exit." << endl << endl;

        cout << "Enter an option: ";
        getline(cin, consoleCommand);

        if (consoleCommand == "1") {
            userInputSongs();
        }
        else if (consoleCommand == "3") {
            viewAll();
        }
        else if (consoleCommand == "6") {
            break;
        }
    }
}

void userInputSongs() {
    string artistName;
    string songName;
    string genreName;
    const string SENTINEL = "Exit";

    while (true) {
        /*
        if (currCount >= capacity) {
            cout << "Your library is full!" << endl;
            break;
        }
        */
        cout << "Enter the artist's name (type 'Exit' to stop): " << endl;
        getline(cin, artistName);

        if (artistName == SENTINEL) {
            break;
        }

        if (currCount >= capacity) {
            resizeLibrary();
        }

        songs[currCount].SetArtist(artistName);

        cout << "Enter the song's name: " << endl;
        getline(cin, songName);
        songs[currCount].SetName(songName);

        cout << "Enter the genre: " << endl;
        getline(cin, genreName);
        songs[currCount].SetGenre(genreName);

        cout << "Here is your song: " << endl;
        songs[currCount].Print();
        cout << endl;

        currCount++;
    }
    cout << endl;
}

void viewAll() {
    if (currCount == 0) {
        cout << "There aren't any songs in your library!" << endl << endl;
        return;
    }
    cout << "Here are all your songs!" << endl << endl;
    for (int i = 0; i < currCount; i++) {
        songs[i].Print();
        cout << endl;
    }
    cout << endl;
}

void resizeLibrary() {
    int newCapacity = capacity + 100;

    Song* newSongs = new Song[newCapacity];

    for (int i = 0; i < currCount; i++) {
        newSongs[i] = songs[i];
    }

    delete[] songs;

    songs = newSongs;
    capacity = newCapacity;
}