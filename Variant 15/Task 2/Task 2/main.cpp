#include <iostream>
#include <fstream>
#include <algorithm>

#define MaxK 35 
using namespace std;

struct Transportation
{
    char route[30];
    char captainLastName[30];
    int date; // 1 - 31
    int busNumber;
    int passengers;
    double ticketPrice;
    double totalSum;
};

int K;
Transportation trans[MaxK];
Transportation sortTrans[MaxK];

void Insert() {
    bool full = false;
    char sum[32];
    if (K < MaxK)
    {
        cout << endl << "Route: "; cin.ignore();
        cin.getline(trans[K].route, 30);

        cout << "Captain last name: ";
        cin.getline(trans[K].captainLastName, 30);


        cout << "Date (from 1 to 31): "; cin >> sum; trans[K].date = atoi(sum);
        cout << "Bus number: "; cin >> sum; trans[K].busNumber = atoi(sum);
        cout << "Passengers amount: "; cin >> sum; trans[K].passengers = atoi(sum);
        cout << "Ticket price: "; cin >> sum; trans[K].ticketPrice = atof(sum);
        trans[K].totalSum = trans[K].passengers * trans[K].ticketPrice;


        ofstream ofs("transportation.txt", ofstream::app);
        if (K > 0) ofs << endl;
        ofs << trans[K].route << endl;
        ofs << trans[K].captainLastName << endl;
        ofs << trans[K].date << endl;
        ofs << trans[K].busNumber << endl;
        ofs << trans[K].passengers << endl;
        ofs << trans[K].ticketPrice << endl;
        ofs << trans[K].totalSum;

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
        cout << "Trancportation: " << i + 1 << endl;
        cout << "Route: " << trans[i].route << endl;
        cout << "Captain last name: " << trans[i].captainLastName << endl;
        cout << "Date: " << trans[i].date << endl;
        cout << "Bus number: " << trans[i].busNumber << endl;
        cout << "Passengers amonunt: " << trans[i].passengers << endl;
        cout << "Ticket price: " << trans[i].ticketPrice << endl;
        cout << "Total cost of tickets: " << trans[i].totalSum << endl;
        cout << "-------------------------------" << endl;
    }

}

void OutputFromGivenDate() {
    int date;
    int i, j;
    bool eq;

    cout << "Enter date: "; cin >> date;


    for (i = 0; i < K; i++)
    {
        eq = true;
        for (j = 0; j < 30 && date != '\0' && trans[i].date != '\0'; j++)
        {
            if (date != trans[i].date)
            {
                eq = false;
                break;
            }
            if (j < 30) if (date != trans[i].date) eq = false;
            if (eq)
            {
                cout << "Transportation: " << i << endl;
                cout << "Route: " << trans[i].route << endl;
                cout << "Captain last name: " << trans[i].captainLastName << endl;
                cout << "Date: " << trans[i].date << endl;
                cout << "Bus number: " << trans[i].busNumber << endl;
                cout << "Passengers amount: " << trans[i].passengers << endl;
                cout << "Ticket price: " << trans[i].ticketPrice << endl;
                cout << "Total cost of tickets: " << trans[i].totalSum << endl;
                break;
            }
        }

    }

}

bool comprareSum(Transportation transLeft, Transportation transRight)
{
    return transLeft.totalSum < transRight.totalSum;
}

void Sorting() {

    int i;

    for (i = 0; i < K; i++)
    {
        sortTrans[i] = trans[i];
    }

    sort(sortTrans, sortTrans + K, comprareSum);

    for (i = 0; i < K; i++)
    {
        cout << "Bus number: " << sortTrans[i].busNumber << endl;
        cout << "Total cost of tickets: " << sortTrans[i].totalSum << endl;
    }
}

int main()
{
    ifstream ifs("transportation.txt", ifstream::in); // Отваря файла за прочитане.
    if (ifs.is_open()) // Проверка дали файла е отворен.
    {
        K = 0; // Занулява брояча 
        while (!ifs.eof()) // Докано файла не достигне края.
        {
            if (K > 0) ifs.ignore();
            // Прочита телефонния номер и импулса от файла.
            ifs.getline(trans[K].route, 30);
            ifs.getline(trans[K].captainLastName, 30);
            ifs >> trans[K].date;
            ifs >> trans[K].busNumber;
            ifs >> trans[K].passengers;
            ifs >> trans[K].ticketPrice;
            ifs >> trans[K].totalSum;

            K++; // Брояча се увеличава с 1.
        }
        ifs.close(); // Затваря се файла.
    }
    // Ако файла не се отвори(или възнинка проблем или не съществува), ако не съществува създава файла.
    else
    {
        ofstream ofs("transportation.txt", ofstream::out);
        ofs.close();
    }

    char ch[256]; // Масив за избор
    int choice; // Избор.


    do
    {
        cout << endl << "Current amount of Transportations: " << K << endl;
        cout << "1) Insert data" << endl;
        cout << "2) Display all data" << endl;
        cout << "3) Dislpay data on a selected day of the month." << endl;
        cout << "4) Display bus numbers and total cost sorted in descending order by total cost." << endl;
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
            OutputFromGivenDate();
            break;
        case 4:
            Sorting();
            break;
        case 0:
            break;
        }
    } while (choice != 0);
    return 0;
}