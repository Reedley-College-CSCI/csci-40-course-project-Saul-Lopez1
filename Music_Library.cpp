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


int main() {

    Song songs;
    string userInArtist;
    string userInName;
    string userInGenre;

    cout << "Enter the artist's name: " << endl;
    getline(cin, userInArtist);
    songs.SetArtist(userInArtist);
    cout << "Enter the song name: " << endl;
    getline(cin, userInName);
    songs.SetName(userInName);
    cout << "Enter the genre: " << endl;
    getline(cin, userInGenre);
    songs.SetGenre(userInGenre);

    cout << "Here is your song: " << endl;
    songs.Print();





    return 0;
}

void Song::Print() const {
    cout << artist << "     " << name << "     " << genre << endl;
}