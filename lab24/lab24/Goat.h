
// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
#include <string>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public:
    Goat() : name(""), age(0), color("") {}
    Goat(string n) : name(n), age(0), color("") {}
    Goat(string n, int a, string c) : name(n), age(a), color(c) {
        cout << "Goat created: " << name << " (" << age << ", " << color << ")" << endl;
    }

    void set_name(string n) { name = n; }
    string get_name() const { return name; }

    void set_age(int a) { age = a; }
    int get_age() const { return age; }

    void set_color(string c) { color = c; }
    string get_color() const { return color; }

    bool operator<(const Goat& other) const {
        if (name != other.name) return name < other.name;
        if (age != other.age) return age < other.age;
        return color < other.color;
    }

    bool operator==(const Goat& other) const {
        return name == other.name && age == other.age && color == other.color;
    }
};

#endif
