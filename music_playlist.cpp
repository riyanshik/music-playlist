#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

struct Song
{
    std::string title;
    std::string artist;
};

class Node
{
public:
    Song song;
    Node *next;
    Node *prev;

    Node(const Song &s) : song(s), next(nullptr), prev(nullptr) {}
};

class Playlist
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    Playlist() : head(nullptr), tail(nullptr), count(0) {}
    ~Playlist()
    {
        clear();
    }
    void addSong(const Song &song)
    {

        Node *newNode = new Node(song);
        std::cout << "-> Adding '" << song.title << "'..." << std::endl;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        std::cout << "-> Success." << std::endl;
    }

    bool deleteSong(const std::string &title)
    {
        Node *current = head;
        while (current != nullptr && current->song.title != title)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            std::cout << "-> Song '" << title << "' not found." << std::endl;
            return false;
        }

        std::cout << "-> Deleting '" << title << "'..." << std::endl;
        if (current == head)
        {
            head = current->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        else if (current == tail)
        {
            tail = current->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        count--;
        std::cout << "-> Success." << std::endl;
        return true;
    }

    void shuffle()
    {
        std::cout << "-> Shuffling playlist..." << std::endl;
        if (count < 2)
        {
            std::cout << "-> Not enough songs to shuffle." << std::endl;
            return;
        }

        std::vector<Song> songData;
        Node *current = head;
        while (current != nullptr)
        {
            songData.push_back(current->song);
            current = current->next;
        }

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(songData.begin(), songData.end(), std::default_random_engine(seed));

        current = head;
        int i = 0;
        while (current != nullptr)
        {
            current->song = songData[i];
            current = current->next;
            i++;
        }
        std::cout << "-> Success." << std::endl;
    }

    void clear()
    {
        if (head == nullptr)
            return;
        std::cout << "-> Clearing playlist..." << std::endl;
        Node *current = head;
        Node *nodeToDelete;
        while (current != nullptr)
        {
            nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
        head = tail = nullptr;
        count = 0;
        std::cout << "-> Success." << std::endl;
    }

    void display() const
    {
        std::cout << "\n--- My Playlist (" << count << " songs) ---" << std::endl;
        if (head == nullptr)
        {
            std::cout << "Playlist is empty." << std::endl;
        }
        else
        {
            Node *current = head;
            int songNum = 1;
            while (current != nullptr)
            {
                std::cout << songNum++ << ". " << current->song.title << " - " << current->song.artist << std::endl;
                current = current->next;
            }
        }
        std::cout << "--------------------------\n"
                  << std::endl;
    }
};

void showMenu()
{
    std::cout << "======= Music Playlist Menu =======" << std::endl;
    std::cout << "1. Add a song" << std::endl;
    std::cout << "2. Delete a song" << std::endl;
    std::cout << "3. Show playlist" << std::endl;
    std::cout << "4. Shuffle playlist" << std::endl;
    std::cout << "5. Clear playlist" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    Playlist myPlaylist;
    int choice;

    myPlaylist.addSong({"Chand Sifarish", "Shaan & Kailash Kher"});
    myPlaylist.addSong({"Malang Sajna", "Sachet Tandon & Parampara Tandon"});
    myPlaylist.addSong({"Tu Mileya", "Darshan Raval"});

    do
    {
        myPlaylist.display();
        showMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            Song newSong;
            std::cout << "Enter song title: ";
            std::getline(std::cin, newSong.title);
            std::cout << "Enter artist name: ";
            std::getline(std::cin, newSong.artist);
            myPlaylist.addSong(newSong);
            break;
        }
        case 2:
        {
            std::string titleToDelete;
            std::cout << "Enter title of song to delete: ";
            std::getline(std::cin, titleToDelete);
            myPlaylist.deleteSong(titleToDelete);
            break;
        }
        case 3:
        {
            std::cout << "Displaying current playlist..." << std::endl;
            break;
        }
        case 4:
        {
            myPlaylist.shuffle();
            break;
        }
        case 5:
        {
            myPlaylist.clear();
            break;
        }
        case 6:
        {
            std::cout << "Exiting application. Goodbye!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
