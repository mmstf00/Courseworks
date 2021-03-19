#include <iostream>
#include <windows.h>

using namespace std;

int N = 0;
struct StudentStruct
{
    unsigned int FakNomer;
    unsigned int Vazrast;
    unsigned short int Pol;
}Student[25];

void Vavezhdane(void)
{
    char Otgovor;
    if (N < 25)
    {
        cout << "\nEnter new student " << 1 + N << ":" << endl;
        cout << "Faculty number: "; cin >> Student[N].FakNomer;
        cout << "Age(years): "; cin >> Student[N].Vazrast;
        cout << "Gender (1-man, 2- woman): "; cin >> Student[N].Pol;
        cout << endl; N++;
        do
        {
            cout << "One more student? ('y'-yes, 'n'-no): ";
            cin >> Otgovor;
        } while (Otgovor != 'y' && Otgovor != 'n');
        if (Otgovor == 'y') Vavezhdane();
    }
    cout << endl << endl;
}

void MazheIZheni(void)
{
    int c, BrMazhe = 0, BrZheni = 0;
    unsigned int Mazhe[25][2], Zheni[25][2];
    for (c = 0; c < N; c++)
    {
        if (Student[c].Pol)
        {
            Mazhe[BrMazhe][0] = Student[c].FakNomer;
            Mazhe[BrMazhe][1] = Student[c].Vazrast;
            BrMazhe++;
        }
        else
        {
            Zheni[BrZheni][0] = Student[c].FakNomer;
            Zheni[BrZheni][1] = Student[c].Vazrast;
            BrZheni++;
        }
    }
    float SumVazrM = 0.0f, SumVazrZh = 0.0f;
    for (c = 0; c < BrMazhe; c++) SumVazrM += (float)Mazhe[c][1];
    for (c = 0; c < BrZheni; c++) SumVazrZh += (float)Zheni[c][1];
    cout << "Men:" << endl;
    cout << "Faculty number:\tAge:" << endl;
    for (c = 0; c < BrMazhe; c++) cout << Mazhe[c][0] << "\t\t\t" << Mazhe[c][1] << endl;
    cout << "Average age: " << SumVazrM / (float)BrMazhe;
    cout << endl << endl;
    cout << "Women:" << endl;
    cout << "Faculty number:\tAge:" << endl;
    for (c = 0; c < BrZheni; c++) cout << Zheni[c][0] << "\t\t\t" << Zheni[c][1] << endl;
    cout << "Average age: " << SumVazrZh / (float)BrZheni;
    cout << endl << endl;
}

void Tarsene(void)
{
    bool Exist;
    char Otgovor;
    unsigned int TarsenFakNomer;
    int c;
    do
    {
        cout << "\n\nFaculty to search: "; cin >> TarsenFakNomer;
        Exist = false;
        for (c = 0; c < N; c++)
            if (Student[c].FakNomer == TarsenFakNomer)
            {
                Exist = true;
                cout << "\nNumber in row: " << 1 + c << endl;
                cout << "Age(years): " << Student[c].Vazrast << endl;
                cout << "Gender: ";
                if (Student[c].Pol)  cout << "man" << endl;
                else                cout << "woman" << endl;
            }
        if (!Exist)  cout << "Student with faculty number " << TarsenFakNomer
            << " doesn't exist in array." << endl;
        cout << endl;
        do
        {
            cout << "One more student? ('y'-yes, 'n'-no): ";
            cin >> Otgovor;
        } while (Otgovor != 'y' && Otgovor != 'n');
    } while (Otgovor != 'n');
    cout << endl << endl;
}

void NayMlStka()
{
    unsigned int MinVazr;
    int cMinVazr, c, cc;
    c = 0;
    while (Student[c].Pol && c < N) c++;
    if (c < N)
    {
        cMinVazr = c;
        MinVazr = Student[c].Vazrast;
        for (cc = c + 1; cc < N; cc++)
            if (!Student[cc].Pol && Student[cc].Vazrast < MinVazr)
            {
                MinVazr = Student[cc].Vazrast;
                cMinVazr = cc;
            }
        cout << endl << "The youngest student "
            << Student[cMinVazr].FakNomer << endl << "and is " << Student[cMinVazr].Vazrast
            << " years old." << endl << endl;
    }
    else
        cout << endl << "Student doesn't exist." << endl << endl;
}

void PodrVazhVazr()
{
    int i, j;
    for (i = 0; i < N - 1; i++)
        for (j = 1; j < N; j++)
            if (Student[i].Vazrast > Student[j].Vazrast)
                swap(Student[i], Student[j]);
    for (i = 0; i < N; i++)
        cout << endl << "Student #" << 1 + i << ":" << endl
        << "Faculty number: " << Student[i].FakNomer << endl
        << "Age: " << Student[i].Vazrast << endl
        << "Gender: " << ((Student[i].Pol) ? "man." : "woman.") << endl << endl;
}

int main()
{
    int Izbor;
    do
    {
        do
        {
            cout << "\n\n1. Add students\n"
                << "2. Men,women - average age\n"
                << "3. Search with faculty number\n"
                << "4. Find the youngest student\n"
                << "5. Arrange students in ascending order by age\n\n"
                << "0. End\n\n\n";
            cout << "> "; cin >> Izbor;
        } while (Izbor < 0 || Izbor>5);
        switch (Izbor)
        {
        case 1:
            Vavezhdane();
            break;

        case 2:
            MazheIZheni();
            break;

        case 3:
            Tarsene();
            break;

        case 4:
            NayMlStka();
            break;

        case 5:
            PodrVazhVazr();
            break;
        }
    } while (Izbor != 0);

    return 0;
}
