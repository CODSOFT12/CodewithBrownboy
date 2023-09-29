#include <iostream>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

char seats[NUM_ROWS][NUM_COLS] = {0};

void displayMovieListings()
{
    cout << "Movie Listings:" << endl;
    cout << "1. Movie A" << endl;
    cout << "2. Movie B" << endl;
    cout << "3. Movie C" << endl;
}

void displaySeatMap()
{
    cout << "Seat Map:" << endl;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            cout << (seats[i][j] ? 'B' : 'E') << " ";
        }
        cout << endl;
    }
}

bool isSeatAvailable(int row, int col) 
{
    return seats[row][col]== 0;
}

double calculateTotalCost(int numTickets) 
{
    return numTickets*TICKET_PRICE;
}

void bookSeats(int row, int col, int numTickets)
{
    for (int i = row; i < row + numTickets; i++) 
    {
        seats[i][col] = 1;
    }
}

int main() 
{
    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true)
    {
        int choice;
        cout << "Menu:" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. View Seat Map" << endl;
        cout << "3. Book Tickets" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayMovieListings();
            break;
        case 2:
            displaySeatMap();
            break;
        case 3: 
        {
            int row, col, numTickets;
            cout << "Enter the row and column of the first seat, and the number of tickets you want to book (e.g., 1 2 3): ";
            cin >> row >> col >> numTickets;

            if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) 
            {
                bool allAvailable = true;
                for (int i = row; i < row + numTickets; i++)
                {
                    if (!isSeatAvailable(i, col)) 
                    {
                        allAvailable = false;
                        break;
                    }
                }

                if (allAvailable)
                {
                    double totalCost = calculateTotalCost(numTickets);
                    cout << "Total Cost: $" << totalCost << endl;

                    char confirm;
                    cout << "Confirm booking (Y/N): ";
                    cin >> confirm;

                    if (confirm == 'Y' || confirm == 'y')
                    {
                        bookSeats(row, col, numTickets);
                        cout << "Booking successful!" << endl;
                    }
                    else
                    {
                        cout << "Booking canceled." << endl;
                    }
                }
                else
                {
                    cout << "Seats are not available. Please select other seats." << endl;
                }
            }
            else
            {
                cout << "Invalid seat selection. Please enter a valid row, column, and number of tickets." << endl;
            }
            break;
        }
        case 4:
            cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
