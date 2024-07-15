//NUMBER GUESSING GAME

#include <iostream>  
#include <cstdlib>   
#include <ctime>     

using namespace std; 

int main() {
    
    srand(time(0));

    // Generate a random number 
    int secretNumber = rand() % 100 + 1;
    int guess;

    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "\nI've picked a number between 1 and 100.\nTry to guess it!" << endl;

    
    do {
        // Ask the user to enter a guess
        cout << "\nEnter your guess: ";
        cin >> guess;

        
        if (guess < secretNumber) {
            cout << "\nToo low! Try a higher number." << endl;
        } else if (guess > secretNumber) {
            cout << "\nToo high! Try a lower number." << endl;
        } else {
            
            cout << "\nCongratulations! You guessed the correct number." << endl;
        }
	} while (guess != secretNumber); 

    
}
