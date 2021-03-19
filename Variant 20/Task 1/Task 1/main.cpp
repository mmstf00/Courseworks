#include <iostream>
void menu();
void Insert();
void Scores();
void References();
void Output();
unsigned int MAS[25][7]; // За ред 0-Факултетен номер, 1-MAT, 2-VVS, 3-ETM, 4-BP,5-CE,6-UP.
unsigned int MAS2[25][6]; // Масив с оценки
int br; // Брой студенти (до 25), при -1 спира програмата.

using namespace std;

int main()
{
    do
    {
        menu(); // Извиква функцията menu(), докато броя не е -1.
    } while (br != -1);
}

void menu()
{
    int ch; // Избор.
    cout << "\n\t MENU";
    cout << "\n--------------------";
    cout << "\n\t1 - Enter points";
    cout << "\n\t2 - Convert points to score";
    cout << "\n\t3 - References";
    cout << "\n\t4 - Array content";
    cout << "\n--------------------";
    cout << "\n\t0 - EXIT" << endl;
    do
    {
        cin >> ch;      // Докато изборът е между 0 и 4 се въвежда избор.
    } while (ch < 0 || ch > 4);

    switch (ch)
    {
    case 1: Insert(); break; // Извиква фунцията Insert() за въвеждане на данни.
    case 2: Scores(); break; // Извиква фунцията Scores() за извеждане на оценки.
    case 3: References(); break; // Извиква фунцията References() за извеждане на справки.
    case 4: Output(); break; // Извиква фунцията Output() за извеждане на всички данни.
    case 0: br = -1; break; // Ако се натисне 0 прграмата прикючва.
    }
}
void Insert()
{
    do
    {
        cout << "\nEnter the number of students in the group (to 25): ";
        cin >> br;
    } while (br < 0 || br > 25); // Проверка дали студентите не са повече от 25.
    unsigned int x;
    for (int i = 0; i < br; i++)
    {
        cout << "\nEnter Faculty number of " << i + 1 << " -student: ";
        do
        {
            cin >> x;
        } while (x < 0 || x > 999999); // Проверка дали е валиден.
        MAS[i][0] = x;
        for (int k = 1; k < 7; k++)
        {
            cout << "\n\tFor " << MAS[i][0] << " Points on ";
            switch (k)
            {
            case 1: cout << "MAT: "; break;     // Математика.
            case 2: cout << "VVS: "; break;    // Въведение в специалността.
            case 3: cout << "ETM: "; break;   // Електротехнически материали.
            case 4: cout << "BP: "; break;   // Базово програмиране .
            case 5: cout << "CE: "; break;  // Чужд език.
            case 6: cout << "UP: "; break; // Учебна практика.
            }
            do
            {
                cin >> x;
            } while (x < 30 || x > 100);
            MAS[i][k] = x;
            if (MAS[i][k] >= 89) MAS2[i][k - 1] = 6; // Ако точките са над 89 оценка 6.
            else if (MAS[i][k] >= 75) MAS2[i][k - 1] = 5; // Ако точките са от 75 до 88 оценка 5.
            else if (MAS[i][k] >= 62) MAS2[i][k - 1] = 4; // Ако точките са от 62 до 74 оценка 4.
            else if (MAS[i][k] >= 55) MAS2[i][k - 1] = 3; // Ако точките са от 55 до 61 оценка 3.
            else  MAS2[i][k - 1] = 2; // Ако точките са от 30 до 49 оценка 2.
        }
    }
    cout << "\nFN\tMAT\tVVS\tETM\tBP\tCE\tUP";
    for (int i = 0; i < br; i++)
    {
        cout << endl;
        for (int k = 0; k < 7; k++)
        {
            cout << MAS[i][k] << "\t";
        }
    }
}
void Scores()
{
    if (MAS[0][0] > 0)
    {
        cout << "\nFN\tMAT\tVVS\tETM\tBP\tCE\tUP" << endl;
        for (int i = 0; i < br; i++)
        {
            cout << "\n" << MAS[i][0] << "\t";
            for (int k = 0; k < 6; k++)
            {
                cout << MAS2[i][k] << "\t";
            }
        }
    }
}
void References()
{
    if (MAS[0][0] > 0)
    {
        int x;
        cout << "\n 1 - Exellent students \n 2 - On Faculty number \n Enter choise: ";
        do
        { // Проверка на избора
            cin >> x;
        } while (x < 1 || x > 2);
        switch (x)
        {
        case 1:
        {
            int bro = 0; // Брой отличници
            if (MAS2[0][0] < 2) Scores();  // Изчислява Оценките, записва k+6 в MAS
            float OTL[25][2]; // Масив с отличници, първото е Факултетен номер, второто средна оценка.
            for (int i = 0; i < br; i++)
            {
                float S = 0; // Сума от всички Оценки.
                for (int k = 0; k < 6; k++)
                {
                    S += MAS2[i][k];
                }
                S = S / 6.0; // Прави S да е средно-аритметично на Оценките.
                if (S > 5.5)
                {
                    OTL[i][0] = MAS[i][0];
                    OTL[i][1] = S;
                    bro++;
                }
                else { cout << "There is no exlellent students.";  return; }
            } // na for (i)
            for (int i = 0; i < bro; i++)
            {  // izvejda F-nomer s ocenka
                cout << "\n" << i + 1 << ". " << OTL[i][0] << " with average score: " << OTL[i][1];
            }
            break;
        }// na case 1
        case 2:
        {
            cout << "\n Enter faculty number: ";
            unsigned int fn; // Факултетен номер
            bool real = false; // За проверка дали има такъв номер.
            int poziciq; // Позицията на която е студента в масива MAS**.
            do
            {
                cin >> fn; // Въежда се ФН
            } while (fn < 0 || fn > 999999); //Проверка дали е валиден факултетният номер.
            for (int i = 0; i < br; i++)
            {
                if (fn == MAS[i][0]) { real = true; poziciq = i; break; }
            }
            if (real) // Проверка дали съществува такъв ФН.
            {
                cout << "\nFN\tMAT\tVVS\tETM\tBP\tCE\tUP\t";
                cout << "\n" << MAS[poziciq][0];
                for (int k = 1; k < 7; k++)
                {
                    cout << "\t " << MAS[poziciq][k] << "(" << MAS2[poziciq][k - 1] << ")";
                }
            }
            else { cout << "\nThere is no student with such a number!!!"; } // Ако не съществува се извежда съобщение.
            break;
        }
        }
    }
}
void Output()
{
    if (MAS[0][0] > 0)
    {
        cout << "\nFN\tMAT\tVVS\tETM\tBP\tCE\tUP\t";
        for (int i = 0; i < br; i++)
        {
            cout << "\n" << MAS[i][0];
            for (int k = 1; k < 7; k++)
            {
                cout << "\t " << MAS[i][k] << "(" << MAS2[i][k - 1] << ")";
            }
        }
    }
}