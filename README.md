[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ay551EX-)
# CS1 Final Project - [Music Library]

## 1. Overview
- This program was created to give people a way to store and organize their music library.  
- It has functions to add, remove, view, search for, sort, and save songs to enable library management and organization.   

---

## 2. Design Decisions
- The program uses a class to store all the songs. Each song includes the artist, song name, and genre. They are held by an array that stores all the information as strings. Strings are used throughout the program, such as for taking user input, for convenience and simplicity.   
- I used a class to group the information for the names of the artists, songs and genres instead of having separate arrays for each field.  
- I used cstring and the strstr command to search for substrings for the searching function of the program. Sorting was done through a bubble sort, which repeatedly compares neighboring songs and switches them if they’re out of order until the list is fully sorted, as it would be fine to use for personal libraries.  
- The program can save songs entered into a text file, Library_Storage.txt, and includes an import function using the same text file to ensure data persistence between program runs.   
- A few alternatives I had considered was using selection sort, a fixed array, and a different method to remove songs. Bubble sort was used for simplicity, while I switched to using a dynamic array for user friendliness. I was planning to let the user remove either single or multiple songs through searching for index numbers or a category, such as removing all the songs from one artist, but switched it to only remove singles by index due to complications.  

---

## 3. Testing Summary
- **Structured Testing Log:**
  Included as file due to formatting.
- I tested by making different sets of songs and running them through the program, using the different functions several times.  
- Inputting something other than one of the listed numbers to control the menu makes it loop until a valid input is entered. An invalid input to import, search, or save songs also causes the program to loop until a valid input is entered.  

---

## 4. Technical Walkthrough
- Walking through the program, it starts off with the menu displayed to the user. From there, they can either import their songs from the text file or manually add them into the console. With some songs now in the console, the user has several ways they can manipulate them. They can use the view option to see everything they have, they can remove songs by index number, sort songs alphabetically by the artist, song name, or genre, and search for songs. After editing their library, the user has the option to save it to the text file, or they can exit without saving to discard the changes.  
- https://youtu.be/ZZNwg-lexDI

---

## 5. Challenges and Lessons Learned
- I had some challenges learning cstring for the search function and implementing it with my class with .c_str(). Swapping entire objects in the class for the sort function also gave me some trouble.  
- I’ve learned a lot about strings, file and memory management, and classes from working on this project. Having so many bugs to fix also taught me to make sure to validate inputs to ensure the program runs properly.   

---

## 6. Future Improvements
- If I had more time, I would like to improve the function to remove songs and give users a way to edit songs without having to remove them and add them back in. I would also add more fields to songs, such as albums, and case insensitive searching.  
