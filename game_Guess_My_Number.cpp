#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
  srand(static_cast<unsigned int>(time(0)));
  int secretNumber = rand() % 100 + 1;
  int tries = 0;
  int guess;

  do {
  tries++;
  cout << "Enter Number: ";
  cin >> guess;
    if (guess > secretNumber) {
      cout << "Too high!\n\n" << endl;
    } else if (guess < secretNumber) {
      cout << "Too low!\n\n" << endl;
    }
    else {
      cout << "\nYou got it in " << tries << " guesses!" << endl;
    }
  } while(guess != secretNumber);
  return 0;
}
