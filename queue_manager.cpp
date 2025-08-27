#include "queue_manager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>


void addShow(vector<Show> &queue) {
    Show s;
    cout << "Enter show title: ";
    getline(cin, s.title);
    cout << "Enter show genre: ";
    getline(cin, s.genre);

    try {
        cout << "Enter number of episodes: ";
        string epStr;
        getline(cin, epStr);
        s.episodes = stoi(epStr);
        if (s.episodes <= 0) throw invalid_argument("Episodes must be positive.");

        cout << "Enter rating (1.0 - 5.0): ";
        string ratingStr;
        getline(cin, ratingStr);
        s.rating = stod(ratingStr);
        if (s.rating < 1.0 || s.rating > 5.0) throw out_of_range("Rating must be between 1.0 and 5.0.");

    queue.push_back(s);
    cout << "Show added!\n";
    } catch (exception& e) {
        cout << "Error: " << e.what() << "\nShow not added.\n";
    }
}

void removeShow(vector<Show> &queue) {
    cout << "Enter title of the show to remove: ";
    string title;
    getline(cin, title);
    auto it = find_if(queue.begin(), queue.end(), [&title](const Show& s) {
        return s.title == title;
    });
    if (it != queue.end()) {
        queue.erase(it);
        cout << "Show removed!\n";
    } else {
        try {
            throw ShowNotFoundException(title);
        } catch (ShowNotFoundException& e) {
                cout << "Error: " << e.what() << "\n";
        }
    }
}

void displayRecursiveQueue(const vector<Show> &queue, size_t index = 0) {
    
}


void sortQueue(vector<Show>& queue);
void searchShow(const vector<Show>& queue);
void saveQueue(const vector<Show>& queue, const string& filename);
void loadQueue(vector<Show>& queue, const string& filename);
