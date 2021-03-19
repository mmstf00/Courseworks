#include <iostream>
#include <string>

using namespace std;

// Клас Туристи.
class Tourists
{
public:
    char name[30]{}; // Име.
    string gender; // Пол.
    string country; // Държава.
    int daysInHotel{}; // Брой дни престой.
    double price{}; // Цена за нощувка.

public:
    void getData(); // Функция за въвеждане на данни.
    void display(); // Функция за извеждане на данни.
    string getCountry() { return country; } // Функция която връща като стойност държавата.
    double calculate(); // Фунция за пресмятане на туриста заплатил най-голямата обща съма.
};

void Tourists::getData()
{
    // Въвеждат се име,пол,държава,брой дни престой и цена за нощувка.
    cin.ignore();
    cout << "Enter name: "; cin.getline(name, 30);
    cout << "Enter gender: "; cin >> gender;
    cout << "Enter counrty: "; cin >> country;
    cout << "Enter days in hotel: "; cin >> daysInHotel;
    cout << "Enter price per night: "; cin >> price;
    cout << "------------------------" << endl;
}

void Tourists::display()
{
    //Извеждат се име, пол, държава, брой дни престой и цена за нощувка.
    cout << "------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << country << endl;
    cout << "Country: " << country << endl;
    cout << "Days in hotel: " << daysInHotel << endl;
    cout << "Price: " << price << endl;
    cout << "------------------------" << endl;
}

double Tourists::calculate()
{
    return daysInHotel * price; // Умножава се броя дни престой по цената за нощувка.
}

int main()
{
    Tourists tourist[50];
    int i, amount = 0;
    char choise;
    string country;

    do
    {
        cout << " 1 - Enter information for tourists." << endl;
        cout << " 2 - Display all data." << endl;
        cout << " 3 - Display tourist from given country." << endl;
        cout << " 4 - Display tourist who paid the most price." << endl;
        cout << " 0 - To exit" << endl;
        cout << "Enter choise: "; cin >> choise;

        switch (choise)
        {
        case'1': {
            tourist[amount++].getData(); // Въваежда се информация за туриста и броя се увеличава с 1.
            break;
        }
        case'2': {
            for (i = 0; i < amount; i++)
            {
                tourist[i].display(); // извежда се информация за всички турсти.
            }
            break;
        }
        case'3':
            cout << "Enter country: "; cin >> country; // Въвежда се държава.
            for (i = 0; i < amount; i++)
            {
                if (tourist[i].getCountry() == country) // Ако държавата на туриста съвпада с въведената държава,се извежда информацията за туриста.
                {
                    tourist[i].display();
                }
            }
            break;

        case'4':
            for (i = 0; i < amount; i++)
            {
                if (tourist[0].calculate() < tourist[i].calculate()) // Ако първият турист е заплатил по-малко от следващият.
                {
                    tourist[0] = tourist[i]; // Следващият турист става първи.
                }
            }
            tourist[0].display(); // извежда се информацията за първият турист.
            break;
        }

    } while (choise != '0');
}

