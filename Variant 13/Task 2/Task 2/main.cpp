#include <iostream>
#include <fstream>

#define MaxK 25 
using namespace std;

struct Travels
{
    char route[30];
    char shipName[30];
    char captainName[30];
    float price_1;
    float price_2;
    int passengers_1;
    int passengers_2;
    int soldTickets;
};

int K;
Travels travel[MaxK];

void Insert() {
    bool full = false;
    char sum[32];
    if (K < MaxK)
    {
        cout << endl << "Route: "; cin.ignore();
        cin.getline(travel[K].route, 30);

        cout << "Ship name: ";
        cin.getline(travel[K].shipName, 30);

        cout << "Captain name: ";
        cin.getline(travel[K].captainName, 30);


        cout << "Price 1st class: "; cin >> sum; travel[K].price_1 = atof(sum);
        cout << "Price 2nd class: "; cin >> sum; travel[K].price_2 = atof(sum);
        cout << "Passengers 1st class: "; cin >> sum; travel[K].passengers_1 = atoi(sum);
        cout << "Passengers 2nd class: "; cin >> sum; travel[K].passengers_2 = atoi(sum);
        cout << "Total selled ticket: "; cin >> sum; travel[K].soldTickets = atoi(sum);


        ofstream ofs("travelers.txt", ofstream::app);
        if (K > 0) ofs << endl;
        ofs << travel[K].route << endl;
        ofs << travel[K].shipName << endl;
        ofs << travel[K].captainName << endl;
        ofs << travel[K].price_1 << endl;
        ofs << travel[K].price_2 << endl;
        ofs << travel[K].passengers_1 << endl;
        ofs << travel[K].passengers_2 << endl;
        ofs << travel[K].soldTickets;

        K++;
        ofs.close();
    }
    else
        full = true;

    if (full)
        cout << endl << "The list is full!" << endl;
}

void Output()
{

    for (int i = 0; i < K; i++)
    {
        cout << "Travel: " << i + 1 << endl;
        cout << "Route: " << travel[i].route << endl;
        cout << "Ship name: " << travel[i].shipName << endl;
        cout << "Captain name: " << travel[i].captainName << endl;
        cout << "Price 1st class: " << travel[i].price_1 << endl;
        cout << "Price 2nd class: " << travel[i].price_2 << endl;
        cout << "Passengers 1st class: " << travel[i].passengers_1 << endl;
        cout << "Passengers 2nd class: " << travel[i].passengers_2 << endl;
        cout << "Selled tickets tickets: " << travel[i].soldTickets << endl;
        cout << "-------------------------------" << endl;
    }

}

void OutputFromGivenShipName() {
    char ship[30];
    int i, j;
    bool eq;

    cin.ignore();
    cout << "Enter ship name: "; cin.getline(ship, 30);


    for (i = 0; i < K; i++)
    {
        eq = true;
        for (j = 0; j < 30 && ship[j] != '\0' && travel[i].shipName[j] != '\0'; j++)
        {
            if (ship[j] != travel[i].shipName[j])
            {
                eq = false;
                break;
            }
            if (j < 30) if (ship[j] != travel[i].shipName[j]) eq = false;
            if (eq)
            {
                cout << "Travel: " << i << endl;
                cout << "Route: " << travel[i].route << endl;
                cout << "Ship name: " << travel[i].shipName << endl;
                cout << "Captain name: " << travel[i].captainName << endl;
                cout << "Price 1st class: " << travel[i].price_1 << endl;
                cout << "Price 2nd class: " << travel[i].price_2 << endl;
                cout << "Passengers 1st class: " << travel[i].passengers_1 << endl;
                cout << "Passengers 2nd class: " << travel[i].passengers_2 << endl;
                cout << "Selled tickets tickets: " << travel[i].soldTickets << endl;
                break;
            }
        }

    }

}

void BiggestSum() {

    int i, largest;
    largest = travel[0].soldTickets;
    for (i = 1; i < K; i++)
    {
        if (largest < travel[i].soldTickets) {
            largest = travel[i].soldTickets;
        }
    }

    cout << "Biggest sum is: " << largest << endl;

    for (i = 0; i < K; i++)
    {
        if (travel[i].soldTickets == largest) {
            cout << "Travel: " << i << endl; cout << endl;
            cout << "Route: " << travel[i].route << endl;
            cout << "Ship name: " << travel[i].shipName << endl;
            cout << "Captain name: " << travel[i].captainName << endl;
            cout << "Price 1st class: " << travel[i].price_1 << endl;
            cout << "Price 2nd class: " << travel[i].price_2 << endl;
            cout << "Passengers 1st class: " << travel[i].passengers_1 << endl;
            cout << "Passengers 2nd class: " << travel[i].passengers_2 << endl;
            cout << "Selled tickets tickets: " << travel[i].soldTickets << endl;
            cout << "-------------------------------" << endl;
        }
    }

}

int main()
{
    ifstream ifs("travelers.txt", ifstream::in); // Отваря файла за прочитане.
    if (ifs.is_open()) // Проверка дали файла е отворен.
    {
        K = 0; // Занулява брояча 
        while (!ifs.eof()) // Докано файла не достигне края.
        {
            if (K > 0) ifs.ignore();
            // Прочита телефонния номер и импулса от файла.
            ifs.getline(travel[K].route, 30);
            ifs.getline(travel[K].shipName, 30);
            ifs.getline(travel[K].captainName, 30);
            ifs >> travel[K].price_1;
            ifs >> travel[K].price_2;
            ifs >> travel[K].passengers_1;
            ifs >> travel[K].passengers_2;
            ifs >> travel[K].soldTickets;

            K++; // Брояча се увеличава с 1.
        }
        ifs.close(); // Затваря се файла.
    }
    // Ако файла не се отвори(или възнинка проблем или не съществува), ако не съществува създава файла.
    else
    {
        ofstream ofs("travelers.txt", ofstream::out);
        ofs.close();
    }

    char ch[256]; // Масив за избор
    int choice; // Избор.


    do
    {
        cout << endl << "Current amount of Travels: " << K << endl;
        cout << "1) Insert data" << endl;
        cout << "2) Display all data" << endl;
        cout << "3) Dislpay data from given name of the ship." << endl;
        cout << "4) Display the data with the largest total amount of tickets sold ." << endl;
        cout << "0) Exit." << endl;
        do
        {
            cout << "Choise: "; cin >> ch;
            cout << endl;
            choice = atoi(ch);

            if (choice == 0)
            {
                break;
            }
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Output();
            break;
        case 3:
            OutputFromGivenShipName();
            break;
        case 4:
            BiggestSum();
            break;
        case 0:
            break;
        }
    } while (choice > 5);
    return 0;
}