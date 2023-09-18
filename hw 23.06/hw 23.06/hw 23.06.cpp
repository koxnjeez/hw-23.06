#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    const int M = 10, L1 = 2000, L2 = 5000, L3 = 100000;
    int deposits[M], credits[M], choice, indMin = 0, indMax = 0, diff[M], indMaxDif = 0;
    float sumDeposits = 0, sumCredits = 0;
    bool isData = false;

    do {
        cout << "\t\tMenu:\n";
        cout << "1. data generation\n";
        cout << "2. data print\n";
        cout << "3. client with min credit value\n";
        cout << "4. client with max deposit value\n";
        cout << "5. client with highest difference between 2 accounts\n";
        cout << "6. average value of credits and deposits\n";
        cout << "0. exit\n";

        cout << "Select menu item #!";
        cin >> choice;

        switch (choice) {
        case 0: {
            cout << "See you!\n\n";
            break;
        }
        case 1: {
            for (int i = 0; i < M; i++) {
                deposits[i] = L2 + rand() % (L3 - L2);
                credits[i] = L1 + rand() % (L2 - L1);

                diff[i] = abs(deposits[i] - credits[i]);
                sumDeposits += deposits[i];
                sumCredits += credits[i];

                if (i != 0) {
                    if (deposits[i] > deposits[indMax]) {
                        indMax = i;
                    }
                    if (credits[i] < credits[indMin]) {
                        indMin = i;
                    }
                    if (diff[i] > diff[indMaxDif]) {
                        indMaxDif = i;
                    }
                }
            }
            isData = true;
            cout << endl;
            break;
        }
        case 2: {
            if (isData) {
                for (int i = 0; i < M; i++) {
                    cout << "Client #" << i + 1 << ". deposit value: " << deposits[i] << ", credit value: " << credits[i] << endl;
                }
                cout << endl;
            }
            else {
                cout << "Impossible operation!\n\n";
            }
            break;
        }
        case 3: {
            if (isData) {
                cout << "Client with min credit value " << credits[indMin] << " is #" << indMin + 1 << endl << endl;
            }
            else {
                cout << "Impossible operation!\n\n";
            }
            break;
        }
        case 4: {
            if (isData) {
                cout << "Client with max deposit value " << deposits[indMax] << " is #" << indMax + 1 << endl << endl;
            }
            else {
                cout << "Impossible operation!\n\n";
            }
            break;
        }
        case 5: {
            if (isData) {
                cout << "Client with the highest difference between 2 accounts " << diff[indMaxDif] << " is #" << indMaxDif + 1 << endl << endl;
            }
            else {
                cout << "Impossible operation!\n\n";
            }
            break;
        }
        case 6: {
            if (isData) {
                cout << "Average value of deposits = " << sumDeposits / M << ", of credits = " << sumCredits / M << endl << endl;
            }
            else {
                cout << "Impossible operation!\n\n";
            }
            break;
        }
        default: {
            cout << "Wrong menu item #! Try again!\n\n";
        }
        }
    } while (choice != 0);
}