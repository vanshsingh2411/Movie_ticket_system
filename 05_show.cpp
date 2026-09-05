#ifndef SHOW_CPP
#define SHOW_CPP
#include <vector>
#include <string>
#include <iostream>
#include "01_movie.cpp"
#include "03_screen.cpp"
#include "06_showseat.cpp"
using namespace std;

// Aggregation -- Show uses an existing Movie and Screen (does not own them)
// Composition -- Show owns its ShowSeats (they are created here and die with the show)
class Show {
private:
    static int nextShowId;
    int showId;
    Movie*  movie;   // pointer -- Movie can exist without this Show
    Screen* screen;  // pointer -- Screen can exist without this Show
    string startTime;
    vector<ShowSeat> showSeats;

 public : 
   
    Show() : showId(0), movie(nullptr), screen(nullptr) {}

    Show( Movie* movie, Screen* screen, string startTime) {
        
        this->showId    = nextShowId++ ;
        this->movie     = movie;
        this->screen    = screen;
        this->startTime = startTime;
        
        // create one ShowSeat per physical seat in the screen
        vector<Seat>& physicalSeats = screen->getSeats();
    
        for( size_t i = 0; i < physicalSeats.size() ; i++ ) {

            showSeats.push_back( ShowSeat(physicalSeats[i]) );
  
        }
    
      }


    int     getShowId()    const { return showId; }
    Movie*  getMovie()     const { return movie; }
    Screen* getScreen()    const { return screen; }
    string  getStartTime() const { return startTime; }

    ShowSeat* findShowSeat(int seatNumber) {
        for (size_t i = 0; i < showSeats.size(); i++) {
            if (showSeats[i].getSeatNumber() == seatNumber)
                return &showSeats[i];
        }
        return nullptr;
    }

    void displaySeats() {
        for (size_t i = 0; i < showSeats.size(); i++) {
            cout << "Seat " << showSeats[i].getSeatNumber()
                 << " [" << seatTypeToString(showSeats[i].getSeatType()) << "] - "
                 << (showSeats[i].isAvailable() ? "AVAILABLE" : "BOOKED") << endl;
        }
    }
};
int Show::nextShowId = 1;
#endif