
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <algorithm>

#define MaxK 50

using namespace std;

struct Vlozhitel
{
    char Ime[64];
    double BLV, USD, EURO;
};

int K;

Vlozhitel vlozh[MaxK];

void Input()
{
    bool full = false;
    char sum[32];
    int i;
    if (K < MaxK)
    {
        cout << endl << "Name: "; cin.ignore();
        cin.getline(vlozh[K].Ime, 64);
        cout << "Bulgarian leva: "; cin >> sum; vlozh[K].BLV = atof(sum);
        cout << "American dollar: "; cin >> sum; vlozh[K].USD = atof(sum);
        cout << "EURO: "; cin >> sum; vlozh[K].EURO = atof(sum);

        ofstream ofs("depositors.txt", ofstream::app);
        if (K > 0) ofs << endl;
        ofs << vlozh[K].Ime << endl;
        ofs << vlozh[K].BLV << endl;
        ofs << vlozh[K].USD << endl;
        ofs << vlozh[K].EURO;
        K++;
        ofs.close();
    }
    else
        full = true;
    for (i = 0; i < K; i++)
    {
        cout << endl << vlozh[i].Ime << endl;
        cout << "BLV: " << vlozh[i].BLV << endl;
        cout << "USD: " << vlozh[i].USD << endl;
        cout << "EURO: " << vlozh[i].EURO << endl;
    }
    if (full)
        cout << endl << "The list is full!" << endl;
}

void Reference()
{
    char Ime[64];
    char ch[16], sum[32];
    int choice, secchoice, i, j;
    bool eq;
    double LV_USD, LV_EURO, minSum;

    cout << endl << "1) Information for depositor by entered name." << endl;
    cout << "2) Depositors with a total amount (in BGN) over set\n- according to current courses" << endl;
    do
    {
        cout << "(1,2): ";
        cin >> ch;
        choice = atoi(ch);
    } while (choice < 1 || choice > 2);

    switch (choice)
    {
    case 1:
        do
        {
            cout << endl << "Name of the depositor: "; cin.ignore();
            cin.getline(Ime, 64);
            for (i = 0; i < K; i++)
            {
                eq = true;
                for (j = 0; j < 64 && Ime[j] != '\0' && vlozh[i].Ime[j] != '\0'; j++)
                    if (Ime[j] != vlozh[i].Ime[j])
                    {
                        eq = false; break;
                    }
                if (j < 64) if (Ime[j] != vlozh[i].Ime[j]) eq = false;
                if (eq)
                {
                    cout << endl << vlozh[i].Ime << endl;
                    cout << "BLV: " << vlozh[i].BLV << endl;
                    cout << "USD: " << vlozh[i].USD << endl;
                    cout << "EURO: " << vlozh[i].EURO << endl;
                    break;
                }
            }
            if (!eq)
                cout << endl << "The depositor doesn't exist." << endl;
            do
            {
                cout << endl << "More references (1 - yes, 2 - no): ";
                cin >> ch;
                secchoice = atoi(ch);
            } while (secchoice < 1 || secchoice > 2);
        } while (secchoice == 1);
        break;
    case 2:
        cout << endl << "Exchange rate - BLV for EURO: ";
        cin >> sum;
        LV_EURO = atof(sum);
        cout << "Exchange rate - BLV for Dollar: ";
        cin >> sum;
        LV_USD = atof(sum);
        cout << "Set a minimum amount (in BGN): ";
        cin >> sum;
        minSum = atof(sum);
        eq = false;
        for (i = 0; i < K; i++)
            if (vlozh[i].BLV + LV_USD * vlozh[i].USD + LV_EURO * vlozh[i].EURO >= minSum)
            {
                cout << endl << vlozh[i].Ime << endl;
                cout << "BLV: " << vlozh[i].BLV << endl;
                cout << "USD: " << vlozh[i].USD << endl;
                cout << "EURO: " << vlozh[i].EURO << endl;
                eq = true;
            }
        if (!eq)
            cout << endl << "The depositors doesn't exist." << endl;
        break;
    default:
        break;
    }
}

bool VlozhitelCompareByBLV(Vlozhitel vlozhLeft, Vlozhitel vlozhRight)
{
    return vlozhLeft.BLV < vlozhRight.BLV;
}

bool VlozhitelCompareByUSD(Vlozhitel vlozhLeft, Vlozhitel vlozhRight)
{
    return vlozhLeft.USD < vlozhRight.USD;
}

bool VlozhitelCompareByEURO(Vlozhitel vlozhLeft, Vlozhitel vlozhRight)
{
    return vlozhLeft.EURO < vlozhRight.EURO;
}

void Rearrangement()
{
    char ch[16];
    int choice;

    cout << endl << "1) Sort by deposit in Bulgarian levs" << endl;
    cout << "2) Sort by US dollar deposit" << endl;
    cout << "3) Sort by deposit in EURO" << endl;

    do
    {
        cout << "(1,2,3): ";
        cin >> ch;
        choice = atoi(ch);
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        sort(vlozh, vlozh + K, VlozhitelCompareByBLV);
        break;
    case 2:
        sort(vlozh, vlozh + K, VlozhitelCompareByUSD);
        break;
    case 3:
        sort(vlozh, vlozh + K, VlozhitelCompareByEURO);
        break;
    default:
        break;
    }
    for (int i = 0; i < K; i++)
    {
        cout << endl << vlozh[i].Ime << endl;
        cout << "BLV: " << vlozh[i].BLV << endl;
        cout << "USD: " << vlozh[i].USD << endl;
        cout << "EURO: " << vlozh[i].EURO << endl;
    }
}

int main()
{
    ifstream ifs("depositors.txt", ifstream::in);

    if (ifs.is_open())
    {
        K = 0;
        while (!ifs.eof())
        {
            if (K > 0) ifs.ignore();
            ifs.getline(vlozh[K].Ime, 64);
            ifs >> vlozh[K].BLV;
            ifs >> vlozh[K].USD;
            ifs >> vlozh[K].EURO;
            K++;
        }
        ifs.close();
    }
    else
    {
        ofstream ofs("depositors.txt", ofstream::out);
        ofs.close();
    }

    char ch[256];
    int choice;

    SetConsoleCP(1251); SetConsoleOutputCP(1251);



    cout << "Depositors in a bank" << endl;

    do
    {
        cout << endl << "Current number of depositors: " << K << endl;
        cout << "1) Data input" << endl;
        cout << "2) Output of reports" << endl;
        cout << "3) Reordering of deposits in ascending order\naccording to the amount of currency of a given type" << endl;
        cout << "4) Exit" << endl;
        do
        {
            cout << "(1,2,3,4): ";
            cin >> ch;
            choice = atoi(ch);
        } while (choice < 1 || choice > 4);
        switch (choice)
        {
        case 1:
            Input();
            break;
        case 2:
            Reference();
            break;
        case 3:
            Rearrangement();
            break;
        default:
            break;
        }
    } while (choice < 4);
    return 0;
}