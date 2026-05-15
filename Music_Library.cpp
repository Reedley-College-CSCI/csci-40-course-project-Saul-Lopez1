// CSCI-40 Final Project
// Author: [Saul Lopez]

/* Description:
 * This program is for users to build their own music library, with functions such as:
 * adding, removing, viewing, searching for, and sorting songs.
 *
 * Each song includes: artist, song, and genre.
 *
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Song {
public:
    void SetArtist(string artistName) {
        artist = artistName;
    }
    string GetArtist() const {
        return artist;
    }
    void SetName(string songName) {
        name = songName;
    }
    string GetName() const {
        return name;
    }
    void SetGenre(string genreName) {
        genre = genreName;
    }
    string GetGenre() const {
        return genre;
    }
    void Print() const;

private:
    string artist;
    string name;
    string genre;
};


int capacity = 100;
int currCount = 0;
Song* songs = new Song[capacity];

void console();
void importSongs();
void userInputSongs();
void removeSong();
void viewAll();
void resizeLibrary();
void searchSong();
void sortSongs();
void save();
void saveToStorage();
void saveToLibrary();

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
        cout << "   Type '6' to save your library." << endl;
        cout << "   Type '7' to exit." << endl << endl;

        cout << "Enter an option: ";
        getline(cin, consoleCommand);
        if (consoleCommand == "0") {
            importSongs();
        }
        else if (consoleCommand == "1") {
            userInputSongs();
        }
        else if (consoleCommand == "2") {
            removeSong();
        }
        else if (consoleCommand == "3") {
            viewAll();
        }
        else if (consoleCommand == "4") {
            searchSong();
        }
        else if (consoleCommand == "5") {
            sortSongs();
        }
        else if (consoleCommand == "6") {
            save();
        }
        else if (consoleCommand == "7") {
            break;
        }
        else {
            cout << "Invalid option, please try again." << endl << endl;
        }
    }
}

void importSongs() {
    ifstream inFile("Library_Storage.txt");
    string documentInput;
    string userInput;

    cout << "Would you like to import song from a file into the console? "
        << "Anything you have input into the console will be overwritten (Type 'Yes' to proceed or 'No' to cancel): ";
    
    while (getline(cin, userInput)) {
        if (userInput == "Yes") {
            cout << "Reading the file..." << endl;
            currCount = 0;
            break;
        }
        else if (userInput == "No") {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid input. Try again: ";
        }
    }
    cout << endl;
    

    while (getline(inFile, documentInput)) {
        if (userInput == "No") {
            break;
        }
        if (currCount >= capacity) {
            resizeLibrary();
        }

        string fileName;
        string fileGenre;

        songs[currCount].SetArtist(documentInput);
        getline(inFile, fileName);
        songs[currCount].SetName(fileName);
        getline(inFile, fileGenre);
        songs[currCount].SetGenre(fileGenre);

        currCount++;
    }
    if (userInput == "Yes" && currCount != 0) {
        cout << "The file was read and songs were imported!" << endl;
    }
    inFile.close();
    cout << endl;
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
        cout << currCount + 1 << " | ";
        songs[currCount].Print();
        cout << endl;

        currCount++;
    }
    cout << endl;
}

void removeSong() {
    int songToRemove;
    const int SENTINEL = -1;

    while (true) {
        cout << "Enter a song number to remove (Type '-1' to cancel): ";
        cin >> songToRemove;
        cin.ignore();

        if (songToRemove == SENTINEL) {
            break;
        }

        if ((songToRemove > 0) && (songToRemove <= currCount)) {
            for (int i = songToRemove - 1; i < currCount; i++) {
                songs[i] = songs[i + 1];
            }
            cout << "Song removed." << endl;
            currCount--;
        }
        else {
            cout << "Invalid song number." << endl;
        }
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
        cout << i + 1 << " | ";
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

void searchSong() {
    string searchSelection = "";
    string userSearch;
    const string SENTINEL = "Exit";
    
    
    while (searchSelection != SENTINEL) {
        bool found = false;

        cout << "Type '1' to search for an artist, '2' for a song, '3' for genre, or 'Exit' to cancel: ";
        getline(cin, searchSelection);



        if (searchSelection == "1") {
            cout << "Enter the name of the artist you would like to search for: ";
            getline(cin, userSearch);
            cout << endl << endl;

            for (int i = 0; i < currCount; i++) {
                if (strstr(songs[i].GetArtist().c_str(), userSearch.c_str()) != nullptr) {
                    cout << i + 1 << " | ";
                    songs[i].Print();
                    cout << endl << endl;
                    found = true;
                }
            }
        }
        else if (searchSelection == "2") {
            cout << "Enter the name of the song you would like to search for: ";
            getline(cin, userSearch);
            cout << endl << endl;

            for (int i = 0; i < currCount; i++) {
                if (strstr(songs[i].GetName().c_str(), userSearch.c_str()) != nullptr) {
                    cout << i + 1 << " | ";
                    songs[i].Print();
                    cout << endl << endl;
                    found = true;
                }
            }
        }
        else if (searchSelection == "3") {
            cout << "Enter the genre you would like to search for: ";
            getline(cin, userSearch);
            cout << endl << endl;

            for (int i = 0; i < currCount; i++) {
                if (strstr(songs[i].GetGenre().c_str(), userSearch.c_str()) != nullptr) {
                    cout << i + 1 << " | ";
                    songs[i].Print();
                    cout << endl << endl;
                    found = true;
                }
            }
        }
        else if (searchSelection == "Exit") {
            break;
        }
        if (!found) {
            cout << "Search target not found." << endl;
        }
        cout << endl;
    }
}

void sortSongs() {
    string sortSelection = "";
    const string SENTINEL = "Exit";

    while (sortSelection != SENTINEL) {
        cout << "Type '1' to sort by artist, '2' by song, '3' by genre, or 'Exit' to cancel: ";
        getline(cin, sortSelection);

        if (sortSelection == SENTINEL) {
            cout << endl;
            break;
        }

        for (int i = 0; i < currCount - 1; i++) {
            for (int j = 0; j < currCount - i - 1; j++) {
                if (sortSelection == "1") {
                    if (songs[j].GetArtist() > songs[j + 1].GetArtist()) {
                        Song temp = songs[j];
                        songs[j] = songs[j + 1];
                        songs[j + 1] = temp;
                    }
                }
                else if (sortSelection == "2") {
                    if (songs[j].GetName() > songs[j + 1].GetName()) {
                        Song temp = songs[j];
                        songs[j] = songs[j + 1];
                        songs[j + 1] = temp;
                    }
                }
                else if (sortSelection == "3") {
                    if (songs[j].GetGenre() > songs[j + 1].GetGenre()) {
                        Song temp = songs[j];
                        songs[j] = songs[j + 1];
                        songs[j + 1] = temp;
                    }
                }
            }
        }
        if (sortSelection != "1" && sortSelection != "2" && sortSelection != "3") {
            cout << "Invalid input" << endl << endl;
        }
        else {
            cout << "Sorted!" << endl << endl;
        }
    }
    cout << endl;
}

void save() {
    string userInput;
    string SENTINEL = "No";

    while (userInput != SENTINEL) {
        cout << "Would you like to save your library to your device? ('Yes' to save, 'No' to cancel): ";
        getline(cin, userInput);

        if (userInput == SENTINEL) {
            break;
        }

        if (userInput == "Yes") {
            saveToStorage();
            saveToLibrary();
        }
        
        if (userInput != "Yes" && userInput != "No") {
            cout << "Invalid input!" << endl << endl;
        }
        else if (userInput == "Yes") {
            cout << "File saved!" << endl << endl;
            break;
        }
    }
    cout << endl;
}

void saveToStorage() {
    ofstream outFile("Library_Storage.txt");

    for (int i = 0; i < currCount; i++) {
        outFile << songs[i].GetArtist() << endl
            << songs[i].GetName() << endl
            << songs[i].GetGenre() << endl;
    }
    outFile.close();
}

void saveToLibrary() {
    ofstream outFile("Music_Library.txt");

    for (int i = 0; i < currCount; i++) {
        outFile << i + 1
            << " | " << songs[i].GetArtist()
            << " | " << songs[i].GetName()
            << " | " << songs[i].GetGenre()
            << endl << endl;
    }
    outFile.close();
}