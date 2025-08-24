#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include <string>
#include <vector>

using namespace std;

struct Show {
    string title;
    string genre;
    int episodes;
    double rating; // between 1.0 and 5.0
};

void addShow(vector<Show> &queue);
void removeShow(vector<Show> &queue);
void displayRecursiveQueue(const vector<Show> &queue, size index = 0);
void sortQueue(vector<Show>& queue);
void searchShow(const vector<Show>& queue);
void saveQueue(const vector<Show>& queue, const string& filename);
void loadQueue(vector<Show>& queue, const string& filename);

#endif