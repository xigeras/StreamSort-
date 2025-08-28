#include "queue_manager.h"
#include <iostream>

int main() {
    vector<Show> queue;
    const string filename = "queue.txt";
    string choice;

    cout << "Load queue from file? (y/n): ";
    getline(cin, choice);
    if (choice == "y" || choice == "Y") {
        loadQueue(queue, filename); 
    }

    while (true) {
        cout << "\n--- Streaming Queue Manager ---\n";
        cout << "1. Add Show\n";
        cout << "2. Remove Show\n";
        cout << "3. Display Queue (Recursive)\n";
        cout << "4. Sort Queue\n";
        cout << "5. Search Show\n";
        cout << "6. Save Queue\n";
        cout << "7. Load Queue\n";
        cout << "8. Exit\n";

        cout << "Choose an option (1-8): ";
        getline(cin, choice);

        switch (choice[0]) {
            case '1':
                addShow(queue);
                break;
            case '2':
                removeShow(queue);
                break;
            case '3':
                displayRecursiveQueue(queue);
                break;
            case '4':
                sortQueue(queue);
                break;
            case '5':
                searchShow(queue);
                break;
            case '6':
                saveQueue(queue, filename);
                break;
            case '7':
                loadQueue(queue, filename);
                break;
            case '8':
                cout << "Goodbye!";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        
            }
    }
        cout << "Goodbye!";
        return 0;    
}