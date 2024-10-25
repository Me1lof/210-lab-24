//Melissa Ochoa Flores
// COMSC 210
// Convert Lab 23 to a std::set.

#include <iostream>
#include <fstream>
#include <set>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(const set<Goat>& trip);
void delete_goat(set<Goat>& trip);
void add_goat(set<Goat>& trip, string names[], string colors[]);
void display_trip(const set<Goat> trip);
int main_menu();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    bool again = true;


    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int name_count = 0;
    while (name_count < SZ_NAMES && fin >> names[name_count]) {
        name_count++;
    }
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    int color_count = 0;
    while (color_count < SZ_COLORS && fin1 >> colors[color_count]) {
        color_count++;
    }
    fin1.close();

    set<Goat>trip;

    while (again) {
        int choice = main_menu();
        switch (choice) {
        case 1:
            add_goat(trip, names, colors, name_count, color_count);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            display_trip(trip);
            break;
        case 4:
            again = false;
            cout << "Exiting Goat Manager 3001. Goodbye!" << endl;
            break;
        default:
            cout << "Invaild choice. Please try again" << endl;
        }
    }

    return 0;
}

int main_menu() {
    int choice;
        do {
            cout << "*** GOAT MANAGER 3001 ***" << endl;
            cout << "[1] Add a goat" << endl;
            cout << "[2] Delete a goat" << endl;
            cout << "[3] List goats" << endl;
            cout << "[4] Quit" << endl;
            cout << "Choice ----> ";
            cin >> choice;

            if (choice < 1 || choice > 4) {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
        } while (choice < 1 || choice > 4);
        return choice;
}

void add_goat(set<Goat>& trip, string names[], string colors[], int name_count, int color_count) {
    string name = names[rand() % name_count];
    string color = colors[rand() % color_count];

    int age = rand() % (MAX_AGE + 1);

    Goat new_goat(name, age, color);
    auto result = trip.insert(new_goat);

    if (result.second) { 
        cout << "Added goat: " << name << " (" << age << ", " << color << ")" << endl;
    } else {
        cout << "Duplicate goat: " << name << " (" << age << ", " << color << ") not added." << endl;
    }
}


void delete_goat(set<Goat>& trip) {
    if (trip.empty()) {
        cout << "No goats to delete." << endl;
        return;
    }

    int index = select_goat(trip);
    if (index < 1 || index > static_cast<int>(trip.size())) {
        cout << "Invalid selection." << endl;
        return;
    }
    auto it = trip.begin();
    advance(it, index - 1);

    cout << "Deleting goat: " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")" << endl;
    trip.erase(it);
}
int select_goat(const set<Goat>& trip) {
    int i = 1, choice;

    cout << "\nSelect a goat to delete:\n";
    for (const Goat& goat : trip) {
        cout << "[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }

    cout << "Choice ----> ";
    cin >> choice;
    return choice;
}

void display_trip(const set<Goat> trip) {
    if (trip.empty()) {
        cout << "No goats in the trip." << endl;
        return;
    }
    int i = 1;
    cout << "\nCurrent goats on the trip:\n";
    for (const Goat& goat : trip) {
        cout << "[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }
}