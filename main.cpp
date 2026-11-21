#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Step 1: Create Ticket Class
class Ticket
{
public:
    int pnr;
    string passengerName;
    string source;
    string destination;
    int seatnumber;

    // Step 2: Input Function
    void input()
    {
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName);

        cout << "Enter Source Station: ";
        getline(cin, source);

        cout << "Enter Destination Station: ";
        getline(cin, destination);

        cout << "Enter Seat Number: ";
        cin >> seatnumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Step 3: Display Function
    void display()
    {
        cout << "\n----- Ticket Details -----\n";
        cout << "PNR: " << pnr;
        cout << "\nName: " << passengerName;
        cout << "\nFrom: " << source;
        cout << "\nTo: " << destination;
        cout << "\nSeat Number: " << seatnumber;
        cout << "\n--------------------------\n";
    }
};

// Step 4: Main Function
int main()
{
    const int MAX_TICKET = 5;

    Ticket ticket[MAX_TICKET];

    int count = 0;
    int pnr_counter = 1001;
cout<<"\n===== WELCOME TO RAILWAY TICKET BOOKING SYSTEM =====\n";
    // Step 5: Infinite Loop (Menu Driven Program)
    while (true)
    {
        cout << "\n===== RAILWAY TICKET BOOKING SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Show Ticket\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice: ";

        int choice;
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Step 6: Booking Option
        if (choice == 1)
        {
            if (count == MAX_TICKET)
            {
                cout << "Sorry, Booking is Full!\n";
                continue;
            }

            ticket[count].pnr = pnr_counter++;

            ticket[count].input();

            cout << "\nTicket Booked Successfully!\n";
            cout << "Your PNR Number is: "
                 << ticket[count].pnr << "\n";

            count++;
        }

        // Step 7: Show Ticket Option
        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "No Ticket Booked Yet!\n";
            }
            else
            {
                cout << "\n===== ALL BOOKED TICKETS =====\n";

                for (int i = 0; i < count; i++)
                {
                    ticket[i].display();
                }
            }
        }

        // Step 8: Exit Option
        else if (choice == 3)
        {
            cout << "Thank You for Using Railway Booking System!\n";
            break;
        }

        // Step 9: Invalid Choice
        else
        {
            cout << "Invalid Choice! Please Try Again.\n";
        }
    }

    return 0;
}
