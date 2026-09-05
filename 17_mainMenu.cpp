#ifndef MAINMENU_CPP
#define MAINMENU_CPP
#include <iostream>
#include <vector>
#include <limits>
#include "04_cinema.cpp"
#include "01_movie.cpp"
#include "05_show.cpp"
#include "07_customer.cpp"
#include "13_bookingService.cpp"
#include "10_paymentTypes.cpp"



using namespace std;

// MainMenu displays the console menu, reads input, validates it (NFR3),
// and delegates real work to Cinema / BookingService. It contains NO
// booking, payment, pricing, or ticket-printing logic itself.

class MainMenu {
 
 private:

    Cinema cinema;
    vector<Movie> movies;
    vector<Show> shows;
    vector<Booking*> bookings;
    BookingService bookingService;

  int readIntChoice() {

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
          return choice ;
    }


  void setupData() {
        
        cinema = Cinema("PVR cinema");
        Screen screen1(1);
        

       for ( int i = 1; i <= 10 ; i++ ) {
    
            SeatType type = (i <= 2) ? PLATINUM : (i <= 6) ? GOLD : SILVER;
      
            screen1.addSeat(Seat(i, type));
      
       }
       
       
        cinema.addScreen(screen1);

        movies.push_back(Movie("spiderman BrandNew day", "English", 169));
        movies.push_back(Movie("social network", "English", 161));
        movies.push_back(Movie("sherlock holmes", "English", 172));
        movies.push_back(Movie("avatar 2", "English", 180));

        shows.push_back(Show(&movies[0], cinema.findScreen(1), "6:00 PM"));
        shows.push_back(Show(&movies[1], cinema.findScreen(1), "9:00 PM"));
        shows.push_back(Show(&movies[2], cinema.findScreen(1), "8:00 AM"));
        shows.push_back(Show(&movies[3], cinema.findScreen(1), "11:00 AM"));
    
   }


  void listMovies() {

        cout << "\n--- Movies ---" << endl;
    
        for( size_t i = 0 ; i < movies.size() ; i++) {
            cout << (i + 1) << ". " << movies[i].getTitle()
                 << " (" << movies[i].getLanguage() << ", "
                 << movies[i].getDuration() << " min)" << endl;
        }
    
    }

    void listShowsForMovie(Movie* movie) {
        cout << "\n--- Shows ---" << endl;
        for (size_t i = 0; i < shows.size(); i++) {
            if (shows[i].getMovie() == movie) {
                cout << "Show ID " << shows[i].getShowId() << " -> Screen "
                     << shows[i].getScreen()->getScreenNumber()
                     << " at " << shows[i].getStartTime() << endl;
            }
        }
    }

    Show* findShowById(int showId) {
        for (size_t i = 0; i < shows.size(); i++) {
            if (shows[i].getShowId() == showId) return &shows[i];
        }
        return nullptr;
    }

    Booking* findBookingById(int bookingId) {
        for (size_t i = 0; i < bookings.size(); i++) {
            if (bookings[i]->getBookingId() == bookingId) return bookings[i];
        }
        return nullptr;
    }

    // F1
    void handleListMovies() {
        listMovies();
    }

    // F2
    void handleListShows() {
        listMovies();
        cout << "Select a movie number: ";
        int choice = readIntChoice();
        if (choice < 1 || choice > (int)movies.size()) {
            cout << "Invalid movie selection." << endl;
            return;
        }
        listShowsForMovie(&movies[choice - 1]);
    }

    // F3
    void handleDisplaySeats() {
        cout << "Enter show ID: ";
        int showId = readIntChoice();
        Show* show = findShowById(showId);
        if (show == nullptr) {
            cout << "Invalid show selection." << endl;
            return;
        }
        cout << "\n--- Seats for show " << showId << " ---" << endl;
        show->displaySeats();
    }

    // F4 + F5 + F6 + F7
    void handleBookSeats() {
        cout << "Enter show ID: ";
        int showId = readIntChoice();
        Show* show = findShowById(showId);
        if (show == nullptr) {
            cout << "Invalid show selection." << endl;
            return;
        }

        cout << "Enter number of seats to book: ";
        int count = readIntChoice();
        if (count <= 0) {
            cout << "Invalid seat count." << endl;
            return;
        }

        vector<int> seatNumbers;
        for (int i = 0; i < count; i++) {
            cout << "Enter seat number " << (i + 1) << ": ";
            int seatNumber = readIntChoice();
            if (seatNumber < 0) {
                cout << "Invalid seat number." << endl;
                return;
            }
            seatNumbers.push_back(seatNumber);
        }

        cin.ignore();
        cout << "Enter customer name: ";
        string name;
        getline(cin, name);
        Customer customer(name, "0000000000");

        cout << "Select payment method (1-UPI, 2-Card, 3-Cash): ";
        int paymentChoice = readIntChoice();
        PaymentMethod method;
        if (paymentChoice == 1) method = UPI;
        else if (paymentChoice == 2) method = CARD;
        else if (paymentChoice == 3) method = CASH;
        else {
            cout << "Invalid payment method." << endl;
            return;
        }
        Payment* payment = createPayment(method);

        Booking* booking = bookingService.bookTicket(*show, customer, seatNumbers, payment);
        if (booking != nullptr) {
            bookings.push_back(booking);
        }
    }

    // F8
    void handleCancelBooking() {
        cout << "Enter booking ID to cancel: ";
        int bookingId = readIntChoice();
        Booking* booking = findBookingById(bookingId);
        if (booking == nullptr) {
            cout << "Invalid booking ID." << endl;
            return;
        }
        bookingService.cancelBooking(*booking);
    }

    void displayMenu() {
        cout << "\n===== Movie Ticket Booking System =====" << endl;
        cout << "1. List Movies" << endl;
        cout << "2. List Shows for a Movie" << endl;
        cout << "3. Display Seats for a Show" << endl;
        cout << "4. Book Seats" << endl;
        cout << "5. Cancel Booking" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
    }

public :

  MainMenu() {
         setupData();
    }

void run() {
  
    bool running = true;
        while (running) {
            displayMenu();
            int choice = readIntChoice();
            switch (choice) {
                case 1: handleListMovies(); break;
                case 2: handleListShows(); break;
                case 3: handleDisplaySeats(); break;
                case 4: handleBookSeats(); break;
                case 5: handleCancelBooking(); break;
                case 6: running = false; break;
                default: cout << "Invalid choice. Please try again." << endl;
            }
        }

      cout << "Thank you for using the Movie Ticket Booking System." << endl;

   }

 };

#endif
