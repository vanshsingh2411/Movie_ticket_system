#include<iostream>
#include <cstdlib>
#include <ctime>
#include "17_mainMenu.cpp"

using namespace std;

int main() {

   srand(time(0));   // seed random for payment failure simulation
   MainMenu menu;
   menu.run();
   return 0;

}
