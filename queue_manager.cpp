#include "queue_manager.h"
#include <iostream>
#include <fstream>


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