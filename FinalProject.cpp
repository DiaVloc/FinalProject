#include <iostream>
#include <fstream>
#include <string>
#include "hotel.h"
using namespace std;

int main()
{
    int options = 0, i = 0;
    Hotel A[1000];
    while (options != 5) {
        cout << "HOTEL ROOM BOOKING MANAGEMENT SYSTEM" << endl;
        cout << "Menu options:" << endl;
        cout << "1. Check-In" << endl;
        cout << "2. Check-Out" << endl;
        cout << "3. Booking records" << endl;
        cout << "4. Rooms allocated" << endl;
        cout << "5. Delete record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter option: ";
        cin >> options;
        cout << endl;
        switch (options)
        {
        case 1:
        {
            A[i].checkin();
            A[i].print();
            A[i].save();
            ofstream C;
            C.open("Hotel_bin.txt", ios::out | ios::app);
            C.write((char*)&A[i], sizeof(A[i]));
            C.close();
            i++;
            break;
        }
        case 2:
            A[i].checkout();
            break;
        case 3:
            { 
            ifstream B;
            B.open("Hotel.txt", ios::in);
            string line;
            while (!B.eof()) {
                getline(B, line);
                cout << line << endl;
            }
            B.close();       
            break;
            }
        case 4:
        {
            ifstream B;
            B.open("Hotel.txt", ios::in);
            string line;
            while (!B.eof()) {
                B.ignore(256, '*');
                getline(B, line);
                cout << line << endl;
            }
            B.close();
            break;
        }
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}