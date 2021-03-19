#include <iostream>
#include <fstream>
#include <algorithm>

#define MaxK 40 
using namespace std;

struct Cars
{
    char carDealer[30];
    char brand[30];
    int carNumber;
    int manufactureYear;
    int price;
};

int K;
Cars car[MaxK];

void Insert() {
    bool full = false;
    char sum[32];
    if (K < MaxK)
    {
        cout << endl << "Car dealer: "; cin.ignore();
        cin.getline(car[K].carDealer, 30);

        cout << "Brand: ";
        cin.getline(car[K].brand, 30);


        cout << "Car number: "; cin >> sum; car[K].carNumber = atoi(sum);
        cout << "Manufacture year: "; cin >> sum; car[K].manufactureYear = atoi(sum);
        cout << "Price: "; cin >> sum; car[K].price = atoi(sum);


        ofstream ofs("Cars.txt", ofstream::app);
        if (K > 0) ofs << endl;
        ofs << car[K].carDealer << endl;
        ofs << car[K].brand << endl;
        ofs << car[K].carNumber << endl;
        ofs << car[K].manufactureYear << endl;
        ofs << car[K].price;

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
        cout << "Car: " << i + 1 << endl;
        cout << "Car dealer: " << car[i].carDealer << endl;
        cout << "Captain last name: " << car[i].brand << endl;
        cout << "Date: " << car[i].carNumber << endl;
        cout << "Bus number: " << car[i].manufactureYear << endl;
        cout << "Passengers amonunt: " << car[i].price << endl;
        cout << "-------------------------------" << endl;
    }

}

void OutputFromGivenCarDealer() {
    char dealer[30];
    int i, j;
    bool eq;

    cin.ignore();
    cout << "Car dealer: "; cin.getline(dealer, 30);


    for (i = 0; i < K; i++)
    {
        eq = true;
        for (j = 0; j < 30 && dealer[j] != '\0' && car[i].carDealer[j] != '\0'; j++)
        {
            if (dealer[j] != car[i].carDealer[j])
            {
                eq = false;
                break;
            }
            if (j < 30) if (dealer[j] != car[i].carDealer[j]) eq = false;
            if (eq)
            {
                cout << "Car: " << i + 1 << endl;
                cout << "Car dealer: " << car[i].carDealer << endl;
                cout << "Captain last name: " << car[i].brand << endl;
                cout << "Date: " << car[i].carNumber << endl;
                cout << "Bus number: " << car[i].manufactureYear << endl;
                cout << "Passengers amonunt: " << car[i].price << endl;
                cout << "-------------------------------" << endl;
                break;
            }
        }

    }
}

void Sorting() {

    int i;

    int temp = car[0].price;
    for (int i = 0; i < K; i++) {
        if (temp > car[i].price) {
            temp = car[i].price;
        }
    }

    for (i = 0; i < K; i++)
    {
        if (car[i].price == temp) {
            cout << "The cheapest car" << endl;
            cout << "Car dealer: " << car[i].carDealer << endl;
            cout << "Captain last name: " << car[i].brand << endl;
            cout << "Date: " << car[i].carNumber << endl;
            cout << "Bus number: " << car[i].manufactureYear << endl;
            cout << "Passengers amonunt: " << car[i].price << endl;
            cout << "-------------------------------" << endl;
        }
    }
}

void OutputFromGivenBrandAndYear() {
    char brand[30];
    int year, i, j;
    bool eq;

    cout << endl << "Brand: "; cin.ignore();
    cin.getline(brand, 30);

    cout << "Manufacture year: "; cin >> year;


    for (i = 0; i < K; i++)
    {
        eq = true;
        for (j = 0; j < 30 && brand[j] != '\0' && car[i].brand[j] != '\0'; j++)
        {
            if (brand[j] != car[i].brand[j] && year != car[i].manufactureYear)
            {
                eq = false;
                break;
            }
            if (j < 30) if (brand[j] != car[i].brand[j] && year != car[i].manufactureYear) eq = false;
            if (eq && brand[j] == car[i].brand[j] && car[i].manufactureYear == year)
            {
                Sorting();
                break;
            }
        }
    }
}

int main()
{
    ifstream ifs("Cars.txt", ifstream::in); // Отваря файла за прочитане.
    if (ifs.is_open()) // Проверка дали файла е отворен.
    {
        K = 0; // Занулява брояча 
        while (!ifs.eof()) // Докано файла не достигне края.
        {
            if (K > 0) ifs.ignore();
            // Прочита телефонния номер и импулса от файла.
            ifs.getline(car[K].carDealer, 30);
            ifs.getline(car[K].brand, 30);
            ifs >> car[K].carNumber;
            ifs >> car[K].manufactureYear;
            ifs >> car[K].price;

            K++; // Брояча се увеличава с 1.
        }
        ifs.close(); // Затваря се файла.
    }
    // Ако файла не се отвори(или възнинка проблем или не съществува), ако не съществува създава файла.
    else
    {
        ofstream ofs("Cars.txt", ofstream::out);
        ofs.close();
    }

    char ch[256]; // Масив за избор
    int choice; // Избор.


    do
    {
        cout << endl << "Current amount of Cars: " << K << endl;
        cout << "1) Insert data" << endl;
        cout << "2) Display all data" << endl;
        cout << "3) Dislpay data from given car dealer." << endl;
        cout << "4) Display display data for the cheapest car from gven brand and manufacture year." << endl;
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
            OutputFromGivenCarDealer();
            break;
        case 4:
            OutputFromGivenBrandAndYear();
            break;
        case 0:
            break;
        }
    } while (choice != 0);
    return 0;
}