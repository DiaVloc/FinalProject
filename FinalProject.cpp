#include <iostream>
#include "hotel.h"
using namespace std;

int main()
{
    int options = 0, i = 0;
    Hotel A[100];
    while (options != 5) {
        cout << "Hotel room booking management system" << endl;
        cout << "Menu options:" << endl;
        cout << "1. Book new room" << endl;
        cout << "2. Booking records" << endl;
        cout << "3. Rooms allocated" << endl;
        cout << "4. Delete record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option:";
        cin >> options;
        switch (options)
        {
        case 1:
            A[i].input();
            A[i].print();
            i++;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }


    
}