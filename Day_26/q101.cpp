#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int input;
    
        cout << "\nNUMBER GUESSING GAME\n";
        cout << "Enter input: 1- Play Game  2- Exit\n";
        cin >> input;
        
        if (input == 1)
        {
            int secretNumber = (rand() % 100) + 1;
            int guess = 0;
            int attempts = 0;
            
            cout << "I have thought of a number between 1 and 100\n";
            cout << "Can you guess it?\n\n";
            
            while (guess != secretNumber)
            {
                cout << "Enter your guess: ";
                cin >> guess;
                attempts++;
                
                if (guess > secretNumber)
                {
                    cout << "Too high! Try again.\n";
                }
                else if (guess < secretNumber)
                {
                    cout << "Too low! Try again.\n";
                }
                else
                {
                    cout << "\nCongratulations! You guessed it correctly!\n";
                    cout << "The number was: " << secretNumber << endl;
                    cout << "Total attempts: " << attempts << endl;
                }
            }
        }
        else if (input == 2)
        {
            cout << "Thank you for playing!\n";
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }

}
