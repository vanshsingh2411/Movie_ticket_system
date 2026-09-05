# Movie Ticket Booking System

A console-based movie ticket booking system implemented in C++ designed to demonstrate system design principles and real-world applications of SOLID design principles.

## 📋 Project Overview

This project implements a complete movie ticket booking system that mimics real-world cinema operations. It showcases best practices in object-oriented design with a focus on SOLID principles (Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion).

### Key Features

- **Movie Management**: Browse and manage movies
- **Cinema & Screen Management**: Handle multiple cinemas with different screens
- **Show Scheduling**: Create and manage movie shows across different times
- **Seat Selection**: Interactive seat booking system with real-time availability
- **Customer Management**: Handle customer information and booking history
- **Booking System**: End-to-end booking workflow
- **Payment Processing**: Multiple payment methods support
  - UPI Payment
  - Card Payment
  - Cash Payment
- **Dynamic Price Calculation**: Calculate ticket prices based on seat type and timing
- **Ticket Printing**: Generate and display booking confirmations

## 🏗️ Project Architecture

The system is organized into modular components following object-oriented design:

### Core Components

| File | Purpose |
|------|---------|
| `01_movie.cpp` | Movie entity and operations |
| `02_seat.cpp` | Seat entity representing individual theater seats |
| `03_screen.cpp` | Cinema screen management |
| `04_cinema.cpp` | Cinema entity with multiple screens |
| `05_show.cpp` | Show scheduling and management |
| `06_showseat.cpp` | Show-specific seat mapping and availability |
| `07_customer.cpp` | Customer information management |
| `08_booking.cpp` | Booking entity and operations |
| `09_payment.cpp` | Payment base class and interface |
| `10_paymentTypes.cpp` | Payment type definitions |
| `11_priceCalculator.cpp` | Dynamic ticket price calculation |
| `12_ticketPrinter.cpp` | Ticket generation and formatting |
| `13_bookingService.cpp` | Core booking service orchestration |
| `14_upipayment.cpp` | UPI payment implementation |
| `15_cardpayment.cpp` | Card payment implementation |
| `16_cashpayment.cpp` | Cash payment implementation |
| `17_mainMenu.cpp` | User interface and menu system |
| `main.cpp` | Application entry point |

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: GCC, Clang, or MSVC (supporting C++11 or later)
- **Operating System**: Windows, macOS, or Linux
- **Git**: For cloning the repository

### Installation & Setup

#### 1. Clone the Repository

```bash
git clone https://github.com/vanshsingh2411/Movie_ticket_system.git
cd Movie_ticket_system
```

#### 2. Compile the Project

**On Linux/macOS:**

```bash
# Compile all source files and create executable
g++ -std=c++11 *.cpp -o movie_booking_system

# Or using clang
clang++ -std=c++11 *.cpp -o movie_booking_system
```

**On Windows (MinGW):**

```bash
g++ -std=c++11 *.cpp -o movie_booking_system.exe
```

**On Windows (MSVC):**

```bash
cl /std:c++latest *.cpp /Fe:movie_booking_system.exe
```

#### 3. Run the Application

**On Linux/macOS:**

```bash
./movie_booking_system
```

**On Windows:**

```bash
movie_booking_system.exe
```

## 💡 Usage Guide

Once the application starts, you'll see an interactive menu with the following options:

1. **Browse Movies** - View available movies
2. **Select Cinema** - Choose your preferred cinema
3. **Select Show** - Pick a show time
4. **Select Seats** - Choose your preferred seats with real-time availability
5. **Process Booking** - Complete the booking
6. **Choose Payment Method** - Select from UPI, Card, or Cash
7. **View Confirmation** - Get your ticket details

Follow the on-screen prompts to complete your booking.

## 🏛️ SOLID Principles Applied

This project demonstrates all five SOLID principles:

- **Single Responsibility**: Each class has one reason to change (e.g., `Movie` handles movies, `Payment` handles payment processing)
- **Open/Closed**: Classes are open for extension (payment types can be added) but closed for modification
- **Liskov Substitution**: Different payment types (`UPIPayment`, `CardPayment`, `CashPayment`) can substitute the base `Payment` class
- **Interface Segregation**: Clients depend on specific interfaces rather than large monolithic classes
- **Dependency Inversion**: High-level modules depend on abstractions, not concrete implementations

## 📁 Project Structure

```
Movie_ticket_system/
├── 01_movie.cpp
├── 02_seat.cpp
├── 03_screen.cpp
├── 04_cinema.cpp
├── 05_show.cpp
├── 06_showseat.cpp
├── 07_customer.cpp
├── 08_booking.cpp
├── 09_payment.cpp
├── 10_paymentTypes.cpp
├── 11_priceCalculator.cpp
├── 12_ticketPrinter.cpp
├── 13_bookingService.cpp
├── 14_upipayment.cpp
├── 15_cardpayment.cpp
├── 16_cashpayment.cpp
├── 17_mainMenu.cpp
├── main.cpp
├── images/
└── README.md
```

## 🔧 Building from Scratch

### Step-by-step Compilation

If you prefer to compile individual components and link them:

```bash
# Create object files
g++ -std=c++11 -c 01_movie.cpp -o movie.o
g++ -std=c++11 -c 02_seat.cpp -o seat.o
g++ -std=c++11 -c 03_screen.cpp -o screen.o
# ... compile all other files ...
g++ -std=c++11 -c main.cpp -o main.o

# Link all object files
g++ movie.o seat.o screen.o cinema.o show.o showseat.o customer.o \
    booking.o payment.o paymentTypes.o priceCalculator.o ticketPrinter.o \
    bookingService.o upipayment.o cardpayment.o cashpayment.o mainMenu.o main.o \
    -o movie_booking_system
```

## 📝 Notes

- The project includes pre-compiled executables (`main` and `a.out`) for quick testing
- All user interactions are handled through console input/output
- The system maintains in-memory data during runtime (data is not persisted to disk)
- Seat availability is tracked in real-time during the session

## 🎓 Learning Outcomes

By studying this project, you'll understand:

- System design for real-world applications
- Object-oriented programming principles in C++
- Design pattern implementation
- Building scalable and maintainable code
- Practical applications of SOLID principles
- Class relationships and composition

## 🤝 Contributing

Contributions are welcome! Feel free to:

- Report bugs or issues
- Suggest enhancements
- Submit pull requests with improvements
- Add new features (e.g., database persistence, graphical interface)

## 📄 License

This project is open source and available for educational and learning purposes.

## 👨‍💻 Author

**Vansh Singh** - [@vanshsingh2411](https://github.com/vanshsingh2411)

## 📞 Support

For issues, questions, or suggestions, please open an issue on the [GitHub repository](https://github.com/vanshsingh2411/Movie_ticket_system/issues).

---

**Happy Coding! 🎬🎫**
