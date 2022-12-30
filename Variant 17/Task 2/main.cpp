#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

struct Car {
    string dealership;
    string brand;
    int year;
    int price;
};

Car cars[MAX_N];
int n;

void input() {
    ofstream out("cars.txt", ios::app);

    cout << "Enter the dealership name: ";
    cin >> cars[n].dealership;
    out << cars[n].dealership << " ";

    cout << "Enter the brand: ";
    cin >> cars[n].brand;
    out << cars[n].brand << " ";

    cout << "Enter the year of production: ";
    cin >> cars[n].year;
    out << cars[n].year << " ";

    cout << "Enter the price: ";
    cin >> cars[n].price;
    out << cars[n].price << endl;

    n++;

    out.close();
}

void print_all() {
    cout << "Dealership" << " " << "Brand" << " " << "Year" << " " << "Price" << endl;
    for (int i = 0; i < n; i++) {
        cout << cars[i].dealership << " " << cars[i].brand << " " << cars[i].year << " " << cars[i].price << endl;
    }
}

void print_by_brand() {
    string brand;
    cout << "Enter the brand: ";
    cin >> brand;

    cout << "Dealership" << " " << "Brand" << " " << "Year" << " " << "Price" << endl;
    for (int i = 0; i < n; i++) {
        if (cars[i].brand == brand) {
            cout << cars[i].dealership << " " << cars[i].brand << " " << cars[i].year << " " << cars[i].price << endl;
        }
    }
}

void print_by_brand_and_year() {
    string brand;
    cout << "Enter the brand: ";
    cin >> brand;

    int year;
    cout << "Enter the year of production: ";
    cin >> year;

    cout << "Dealership" << " " << "Brand" << " " << "Year" << " " << "Price" << endl;

    // Филтриране на масива
    Car filtered_cars[MAX_N];
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].brand == brand && cars[i].year == year) {
            filtered_cars[m] = cars[i];
            m++;
        }
    }

    // Сортиране на масива
    sort(filtered_cars, filtered_cars + m, [](const Car &a, const Car &b) {
        return a.price > b.price;
    });

    // Извеждане на резултата
    for (int i = 0; i < m; i++) {
        cout << filtered_cars[i].dealership << " " << filtered_cars[i].brand << " " << filtered_cars[i].year << " "
             << filtered_cars[i].price << endl;
    }
}

int main() {
    ifstream in("cars.txt");
    while (in >> cars[n].dealership >> cars[n].brand >> cars[n].year >> cars[n].price) {
        n++;
    }
    in.close();
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Input data" << endl;
        cout << "2. Print all data" << endl;
        cout << "3. Print data by brand" << endl;
        cout << "4. Print data by brand and year of production" << endl;
        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            input();
        } else if (choice == 2) {
            print_all();
        } else if (choice == 3) {
            print_by_brand();
        } else if (choice == 4) {
            print_by_brand_and_year();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
    }
}