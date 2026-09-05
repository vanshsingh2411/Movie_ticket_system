#ifndef CINEMA_CPP
#define CINEMA_CPP
#include <vector>
#include <string>
#include "03_screen.cpp"
using namespace std;

// Composition -- Cinema owns its Screens
class Cinema {
private:
    string name;
    vector<Screen> screens;
public:
   
    Cinema() {}
    Cinema(string name) { this->name = name; }

    void addScreen(const Screen& screen) { screens.push_back(screen); }
    vector<Screen>& getScreens()         { return screens; }
    string getName() const               { return name; }

    Screen* findScreen(int screenNumber) {
        for (size_t i = 0; i < screens.size(); i++) {
            if (screens[i].getScreenNumber() == screenNumber)
                return &screens[i];
        }
        return nullptr;
    }
};
#endif