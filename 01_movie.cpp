#ifndef MOVIE_CPP
#define MOVIE_CPP
#include <string>
using namespace std;

// Encapsulation -- data is private, only readable through getters
class Movie {
private:
    string title;
    string language;
    int durationMinutes;
public :

    Movie() {} // default constructor;
    
    Movie(string title, string language, int durationMinutes) {
        this->title           = title;   // 'this->' separates member from parameter
        this->language        = language;
        this->durationMinutes = durationMinutes;
    }
    string getTitle()    const { return title; }
    string getLanguage() const { return language; }
    int    getDuration() const { return durationMinutes; }
};
#endif