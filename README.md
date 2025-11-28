
# 🎵 Music Playlist Manager (C++ – Doubly Linked List)

This project is a **Music Playlist Manager** implemented in **C++** using a **doubly linked list**.
It allows users to create and manage their own playlist with operations like adding songs, deleting songs, viewing the playlist, shuffling songs, and clearing the entire playlist.

This program is interactive and menu-driven, making it easy for users to navigate and perform playlist operations.

---

## 📌 Features

### ✔ Add a Song

Add a new song (title + artist) to the end of the playlist.

### ✔ Delete a Song

Remove a song from the playlist using its title.

### ✔ Display Playlist

Show all songs currently stored in the playlist in order.

### ✔ Shuffle Playlist

Randomly reorder the songs using C++ `<shuffle>` and a vector snapshot of the nodes.

### ✔ Clear Playlist

Delete all songs and free memory safely.

### ✔ Doubly Linked List Implementation

Each song is stored in a `Node` containing:

* Song information (`title`, `artist`)
* Pointer to next and previous nodes.

### ✔ Menu-Driven UI

Simple console-based interface allowing users to choose actions.

---

## 🧱 Data Structures Used

### **Song Structure**

```cpp
struct Song {
    std::string title;
    std::string artist;
};
```

### **Node Class**

Represents a single element in the doubly linked list.

```cpp
class Node {
public:
    Song song;
    Node *next;
    Node *prev;
};
```

### **Playlist Class**

Holds the full playlist and provides all related operations.

---

## 🛠 Playlist Functions (Explained Clearly)

### `addSong(const Song &song)`

* Adds a new song to the end of the playlist.
* Handles the case when the playlist is empty.
* Updates head, tail, and count.

### `deleteSong(const std::string &title)`

* Searches for a song by title.
* Removes the node if found.
* Properly reconnects the previous and next nodes.
* Handles deleting from beginning, end, or middle.

### `shuffle()`

* Creates a temporary vector of all songs.
* Uses `std::shuffle` with random seed.
* Writes shuffled data back into the linked list.

### `clear()`

* Deletes every node one by one.
* Resets head, tail, and count to zero.

### `display() const`

* Shows all songs in the playlist.
* Displays song number, title, and artist.

### `showMenu()`

* Prints all available user choices.

---

## ▶ How the Program Works

When the program starts:

1. A default playlist with 3 pre-added songs is created:

   * Chand Sifarish
   * Malang Sajna
   * Tu Mileya

2. A loop displays the playlist and menu options.

3. The user can choose:

   ```
   1. Add a song
   2. Delete a song
   3. Show playlist
   4. Shuffle playlist
   5. Clear playlist
   6. Exit
   ```

4. All input/output is handled through the console.

---

## 🚀 How to Run the Program

1. Copy the code into a `.cpp` file (e.g., `playlist.cpp`).
2. Compile using any C++ compiler:

---

## 📚 What This Project Demonstrates

✔ Understanding of **doubly linked lists**
✔ Dynamic memory management (`new` / `delete`)
✔ Object-oriented programming (classes, constructors, destructors)
✔ Use of STL features like `vector`, `shuffle`, and random engines
✔ Clean menu-driven console UI
✔ Practical application of data structures to a real-world system

---

