#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
    int ranNum = rand() % 100 + 1;
    int guess = 0;
    int count = 0;

    cout << "***************Random Number Guessing Game!***************** \n" << endl;
    cout << " A random number between 1 and 100 has been selected.\n ******Try to guess it.******" << endl;

    do 
    {
        cout << "Enter your guessed number: ";
        cin >> guess;
        count++;

        if (guess < ranNum) 
        {
            cout << "Guess larger (Try again!)" << endl;
        }
        else if (guess > ranNum) 
        {
            cout << "Guess smaller (Try again!)" << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number (" << ranNum << ") in " << count << " attempts!" << endl;
        }
    } 
    while (guess != ranNum);

    return 0;
}
