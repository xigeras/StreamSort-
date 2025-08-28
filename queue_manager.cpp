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

void displayRecursiveQueue(const vector<Show>& queue, size_t index) {
    if (index >= queue.size()) return;
    const Show& s = queue[index];
    cout << index + 1 << ". " << s.title << " | " << s.genre << " | " << s.episodes << " | " << s.rating << endl;
    displayRecursiveQueue(queue, index + 1);
}

void sortQueue(vector<Show>& queue) {
    cout << "Sort by (1) Title or (2) Rating?: ";
    string choice;
    getline(cin, choice);
    if (choice == "1") {
        sort(queue.begin(), queue.end(), [](const Show& a, const Show& b) {
            return a.title < b.title;
        });
        cout << "Sorted by title.\n";
    } else if (choice == "2") {
        sort(queue.begin(), queue.end(), [](const Show& a, const Show& b) {
            return a.rating > b.rating;
        });
        cout << "Sorted by rating.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void searchShow(const vector<Show>& queue) {
    cout << "Enter title to search: ";
    string title;
    getline(cin, title);
    auto it = find_if(queue.begin(), queue.end(), [&](const Show& s) {
        return s.title == title;
    });
    if (it != queue.end()) {
        const Show& s = *it;
        cout << "Found: " << s.title << " | " << s.genre << " | " << s.episodes << " | " << s.rating << endl;
    } else {
        cout << "Show not found.\n";
    }
}

void saveQueue(const vector<Show>& queue, const string& filename) {
    ofstream out(filename);
    for (const Show& s : queue) {
        out << s.title << "|" << s.genre << "|" << s.episodes << "|" << s.rating << endl;
    }
    out.close();
    cout << "Queue saved to " << filename << endl;
}

void loadQueue(vector<Show>& queue, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "No saved queue found.\n";
        return;
    }
    queue.clear();
    string line;
    while (getline(in, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;
        Show s;
        s.title = line.substr(0, p1);
        s.genre = line.substr(p1 + 1, p2 - p1 - 1);
        s.episodes = stoi(line.substr(p2 + 1, p3 - p2 - 1));
        s.rating = stod(line.substr(p3 + 1));
        queue.push_back(s);
    }
    in.close();
    cout << "Queue loaded from " << filename << endl;
}