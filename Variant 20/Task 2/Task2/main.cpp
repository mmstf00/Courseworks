
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>

#define MaxK 100 // Максимум 100 телефона.
using namespace std;

struct Phones
{
    int phoneNumber; // Телефонен номер.
    int pulse; // Импулс.
};

int K; // Брояч на телефони в файла TEL1.txt
int K1; // Брояч на телефони в файла TEL2.txt

Phones phone[MaxK]; // Масив от телефони до 100. 
Phones phone2[MaxK]; // Масив2 от телефони до 100.
Phones merging[200]; // Масив за сортиране.

// Функция за проверка при сортиране.
bool PhonesCompareBypulse(Phones phoneLeft, Phones phoneRight)
{
    return phoneLeft.pulse > phoneRight.pulse; // Връща по-големия импулс.
}

void Sorting()
{
    int i, k;

    for (i = 0; i < K; i++)
    {
        merging[i] = phone[i]; // Прехвърля всичко от 1вия масив в масива за сортиране.
    }

    int size = K + K1; // Инициализира се променлива която е равна на двата брояча.

    for (i = 0, k = K; k < size && i < K1; i++, k++)
    {
        merging[k] = phone2[i]; // След като прехвърли всичко от 1вия масив прехвърля след него и втория.
    }

    cout << "Before merging:" << endl; // Извежда на екрана Масива за сортиране преди сортиране.
    for (i = 0; i < size; i++)
    {
        if (merging[i].phoneNumber && merging[i].pulse != 0) {
            cout << "Phone number: " << merging[i].phoneNumber << endl;
            cout << "Pulse: " << merging[i].pulse << endl;
        }
    }
    cout << endl;

    sort(merging, merging + size, PhonesCompareBypulse);

    cout << "After merging and sorting:" << endl; // Извежда на екрана Сортираният масив.
    for (i = 0; i < size; i++)
    {
        if (merging[i].phoneNumber && merging[i].pulse != 0) {
            cout << "Phone number:" << merging[i].phoneNumber << endl;
            cout << "Pulse: " << merging[i].pulse << endl;
        }
    }

}

// Извежда данните в 2вата файла.
void Output()
{
    int i;

    cout << "TEL1.dat" << endl;
    for (i = 0; i < K; i++)
    {
        // Ако телефонния номер и импулса не са 0ли изжвежда данните на конзолата.
        if (phone[i].phoneNumber && phone[i].pulse != 0)
        {
            cout << "Phone number: " << phone[i].phoneNumber << endl;
            cout << "Pulse: " << phone[i].pulse << endl;
        }
    }

    cout << endl << "TEL2.dat" << endl;
    for (i = 0; i < K1; i++)
    {
        if (phone2[i].phoneNumber && phone2[i].pulse != 0)
        {
            cout << "Phone number: " << phone2[i].phoneNumber << endl;
            cout << "Pulse: " << phone2[i].pulse << endl;
        }
    }
}

int main()
{
    ifstream ifs("TEL1.txt", ifstream::in); // Отваря файла за прочитане.
    if (ifs.is_open()) // Проверка дали файла е отворен.
    {
        K = 0; // Занулява брояча 
        while (!ifs.eof()) // Докано файла не достигне края.
        {
            if (K > 0) {
                // Прочита телефонния номер и импулса от файла.
                ifs >> phone[K].phoneNumber;
                ifs >> phone[K].pulse;
            }
            K++; // Брояча се увеличава с 1.
        }
        ifs.close(); // Затваря се файла.
    }
    // Ако файла не се отвори(или възнинка проблем или не съществува), ако не съществува създава файла.
    else
    {
        ofstream ofs("TEL1.txt", ofstream::out);
        ofs.close();
    }


    // Долу прави същото за 2рият файл TEL2 както горното.
    ifstream ifs1("TEL2.txt", ifstream::in);
    if (ifs1.is_open())
    {
        K1 = 0;
        while (!ifs1.eof())
        {
            if (K1 > 0) {
                ifs1 >> phone2[K1].phoneNumber;
                ifs1 >> phone2[K1].pulse;
            }
            K1++;
        }
        ifs1.close();
    }
    else
    {
        ofstream ofs1("TEL2.txt", ofstream::out);
        ofs1.close();
    }

    char ch[256]; // Масив за избор
    int choice; // Избор.


    cout << "Phone information" << endl;

    do
    {
        cout << endl << "Current number of phones: " << K << endl;
        cout << "1) Merge the arrays in new, and sort in descending order by current number of pulses" << endl;
        cout << "2) Output data" << endl;
        cout << "3) Exit" << endl;
        do
        {
            cout << "Choise: "; cin >> ch;
            choice = atoi(ch);
        } while (choice < 1 || choice > 4); // Докато изборът е между 1-4 се избира избор.
        switch (choice)
        {
        case 1:
            Sorting(); // Ако се избере 1 се изиква функцията за сортирне.
            break;
        case 2:
            Output(); // Ако се избере 2 се извиква функцията за извеждане на всички данни.
            break;
        default:
            break;
        }
    } while (choice < 4);
    return 0;
}