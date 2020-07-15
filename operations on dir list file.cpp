//POP_2016_01_18_projekt_2_Szyszkowski_Micha³_EIT_4_160317.cpp Code::Blocks 13.12, GNU GCC Complier
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

void liczenie_linii(fstream &plik, int &m, string tekst);
void przesuniecie(fstream &plik, int &n, string tekst);
void menu(fstream &plik, int &n, int m, string tekst);
void wypisanie_katalogow(fstream &plik, int &n, int m, string tekst);
void wypisanie_plikow(fstream &plik, int &n, int m, string tekst);
void wypisanie_wielkosc(fstream &plik, int &n, int m, string tekst);
void wypisanie_data(fstream &plik, int &n, int m, string tekst);
void wypisanie_data_starsze(fstream &plik, int &n, int m, string tekst);
void wypisanie_data_mlodsze(fstream &plik, int &n, int m, string tekst);
void wartosci(fstream &plik, int &r2, int &m2, int &d2, int &h2, int &min2);
void wypisanie_fraza(fstream &plik, int &n, int m, string tekst);

int main()
{
    int n = 0;
    int m = 0;
    fstream plik;
    string nazwa;
    cout << "Podaj nazwe pliku: ";
    cin >> nazwa;
    plik.open(nazwa.c_str(), ios::in);

    if(plik.good() == false)
    {
        cout << "Nie znaleziono pliku" << endl;
        exit(0);
    }

    string tekst;

    liczenie_linii(plik, m, tekst);

    plik.clear();
    plik.seekg(0);
    przesuniecie(plik, n, tekst);

    menu(plik, n, m, tekst);

    plik.close();
    return 0;
}

void liczenie_linii(fstream &plik, int &m, string tekst)
{
    while(plik)
    {
        getline(plik, tekst);
        m++;
    }
}

void przesuniecie(fstream &plik, int &n, string tekst)
{
    while(plik)
    {
        if(n >= 5)
            break;
        getline(plik, tekst);
        n++;
    }
}

void menu(fstream &plik, int &n, int m, string tekst)
{
    int o;
    cout << "1. Wypisanie wszystkich katalogow." << endl;
    cout << "2. Wypisanie wszystkich plikow." << endl;
    cout << "3. Wypisanie wedlug wielkosci." << endl;
    cout << "4. Wypisanie wedlug daty." << endl;
    cout << "5. Wypisanie po frazie." << endl;
    cout << "0. Wyjscie z programu" << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch (o)
    {
        case 1:
            {
                wypisanie_katalogow(plik, n, m, tekst);
                break;
            }
        case 2:
            {
                wypisanie_plikow(plik, n, m, tekst);
                break;
            }
        case 3:
            {
                wypisanie_wielkosc(plik, n, m, tekst);
                break;
            }
        case 4:
            {
                wypisanie_data(plik, n, m, tekst);
                break;
            }
        case 5:
            {
                wypisanie_fraza(plik, n, m, tekst);
                break;
            }
        case 0:
            {
                plik.close();
                exit(0);
            }
    }
}


void wypisanie_katalogow(fstream &plik, int &n, int m, string tekst)
{
    n = 0;
    plik.clear();
    plik.seekg(0);
    przesuniecie(plik, n, tekst);
    int o;
    int g;
    system("cls");
    while(plik)
    {
        getline(plik, tekst);
        g = tekst.find("<DIR>");
        if(g != -1)
            cout << tekst << endl;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}

void wypisanie_plikow(fstream &plik, int &n, int m, string tekst)
{
    n = 0;
    int x = 0;
    plik.clear();
    plik.seekg(0);
    przesuniecie(plik, n, tekst);
    int o;
    int g;
    system("cls");
    while(plik)
    {
        while(x < m-8)
        {
            getline(plik, tekst);
            g = tekst.find("<DIR>");
            if(g == -1)
                cout << tekst << endl;
            x++;
        }
        if(x == m-8)
            break;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}

void wypisanie_wielkosc(fstream &plik, int &n, int m, string tekst)
{
    system("cls");
    char z;
    int x = 0;
    int k = 0;
    int o, g;
    float a, b, c, d, f, w;
    float r;
    int q;
    cout << "1. Wypisanie plikow o rozmiarze wiekszym od podanego." << endl;
    cout << "2. Wypisanie plikow o rozmiarze mniejszym od podanego." << endl;
    cout << "3. Wypisanie plikow o rozmiarze rownym podanemu rozmiamarowi." << endl;
    cout << "Wybierz opcje: ";
    cin >> q;
    system("cls");
    cout << "Podaj rozmiar (w bajtach): ";
    cin >> r;

    while(x < m-8)
    {
        n = 0;
        plik.clear();
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        getline(plik, tekst);
        g = tekst.find("<DIR>");
        if(g == -1)
        {
        n = 0;
        plik.clear();
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        n = 0;
        while(n < 17)
        {
            plik.get(z);
            n++;
        }
        plik >> a;
        plik.get(z);
        f = static_cast<int>(z);
        if(f == -1)
        {
            plik >> b;
            plik.get(z);
            f = static_cast<int>(z);
            if(f == -1)
            {
                plik >> c;
                plik.get(z);
                f = static_cast<int>(z);
                if(f == -1)
                {
                    plik >> d;
                    w = (a * 1000000000) + (b * 1000000) + (c * 1000) + d;
                }
                else
                    w = (a * 1000000) + (b * 1000) + c;
            }
            else
                w = (a * 1000) + b;
        }
        else
            w = a;
        n = 0;
        plik.clear();
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        getline(plik, tekst);
        if(q == 1)
        {
            if(w > r)
            cout << tekst << endl;
        }
        if(q == 2)
        {
            if(w < r)
            cout << tekst << endl;
        }
        if(q == 3)
        {
            if(w == r)
            cout << tekst << endl;
        }
        }
    x++;
    k++;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}

void wartosci(fstream &plik, int &r2, int &m2, int &d2, int &h2, int &min2)
{
    char c;
    plik >> r2;
    plik.get(c);
    plik >> m2;
    plik.get(c);
    plik >> d2;
    plik.get(c);
    plik.get(c);
    plik >> h2;
    plik.get(c);
    plik >> min2;
}


void wypisanie_data(fstream &plik, int &n, int m, string tekst)
{
    system("cls");
    int o;
    cout << "1. Wypisanie plikow starszych niz wprowadzona data." << endl;
    cout << "2. Wypisanie plikow mlodszych niz wprowadzona data." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            wypisanie_data_starsze(plik, n, m, tekst);
            break;
        }
    case 2:
        {
            wypisanie_data_mlodsze(plik, n, m, tekst);
            break;
        }
    }

}

void wypisanie_data_starsze(fstream &plik, int &n, int m, string tekst)
{
    system("cls");
    int x = 0;
    int k = 0;
    int o, g;
    int r1, m1, d1, h1, min1;
    int r2, m2, d2, h2, min2;
    cout << "Podaj date." << endl;
    cout << "Rok: ";
    cin >> r1;
    do{
    cout << "Miesiac: ";
    cin >> m1;
    if(m1 >= 13)
        cout << "Bledne dane." << endl;
    }while(m1 >= 13);
    do{
    cout << "Dzien: ";
    cin >> d1;
    if(d1 >= 32)
        cout << "Bledne dane." << endl;
    }while(d1 >= 32);
    do{
    cout << "Godzina: ";
    cin >> h1;
    if(h1 >= 24)
        cout << "Bledne dane." << endl;
    }while(h1 >= 24);
    do{
    cout << "Minuta: ";
    cin >> min1;
    if(min1 >= 60)
        cout << "Bledne dane." << endl;
    }while(min1 >= 60);
    cout << endl;

    while(x < m-8)
    {
        n = 0;
        plik.clear();
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        wartosci(plik, r2, m2, d2, h2, min2);
        n = 0;
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        getline(plik, tekst);
        g = tekst.find("<DIR>");
        if(g == -1)
        {
            if(r1 < r2)
            {
            cout << tekst << endl;
            }
            if(r1 == r2)
            {
                if(m1 < m2)
                {
                cout << tekst << endl;
                }
                if(m1 == m2)
                {
                    if(d1 < d2)
                    {
                    cout << tekst << endl;
                    }
                    if(d1 == d2)
                    {
                        if(h1 < h2)
                        {
                        cout << tekst << endl;
                        }
                        if(h1 == h2)
                        {
                            if(min1 < min2)
                            {
                            cout << tekst << endl;
                            }
                        }
                    }
                }
            }
        }
        x++;
        k++;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}

void wypisanie_data_mlodsze(fstream &plik, int &n, int m, string tekst)
{
    system("cls");
    int x = 0;
    int k = 0;
    int o, g;
    int r1, m1, d1, h1, min1;
    int r2, m2, d2, h2, min2;
    cout << "Podaj date." << endl;
    cout << "Rok: ";
    cin >> r1;
    do{
    cout << "Miesiac: ";
    cin >> m1;
    if(m1 >= 13)
        cout << "Bledne dane." << endl;
    }while(m1 >= 13);
    do{
    cout << "Dzien: ";
    cin >> d1;
    if(d1 >= 32)
        cout << "Bledne dane." << endl;
    }while(d1 >= 32);
    do{
    cout << "Godzina: ";
    cin >> h1;
    if(h1 >= 25)
        cout << "Bledne dane." << endl;
    }while(h1 >= 25);
    do{
    cout << "Minuta: ";
    cin >> min1;
    if(min1 >= 61)
        cout << "Bledne dane." << endl;
    }while(min1 >= 61);
    cout << endl;

    while(x < m-8)
    {
        n = 0;
        plik.clear();
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        wartosci(plik, r2, m2, d2, h2, min2);
        n = 0;
        plik.seekg(0);
        while(plik)
        {
            if(n >= 5+k)
                break;
            getline(plik, tekst);
            n++;
        }
        getline(plik, tekst);
        g = tekst.find("<DIR>");
        if(g == -1)
        {
            if(r1 > r2)
            {
            cout << tekst << endl;
            }
            if(r1 == r2)
            {
                if(m1 > m2)
                {
                cout << tekst << endl;
                }
                if(m1 == m2)
                {
                    if(d1 > d2)
                    {
                    cout << tekst << endl;
                    }
                    if(d1 == d2)
                    {
                        if(h1 > h2)
                        {
                        cout << tekst << endl;
                        }
                        if(h1 == h2)
                        {
                            if(min1 > min2)
                            {
                            cout << tekst << endl;
                            }
                        }
                    }
                }
            }
        }
        x++;
        k++;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}

void wypisanie_fraza(fstream &plik, int &n, int m, string tekst) //???
{
    n = 0;
    int x = 0;
    plik.clear();
    plik.seekg(0);
    przesuniecie(plik, n, tekst);
    int o;
    int g;
    system("cls");
    string fraza;
    cout << "Podaj fraze: ";
    cin >> fraza;
    while(x < m-8)
    {
        getline(plik, tekst);
        g = tekst.find("<DIR>");
        if(g == -1)
        {
        g = tekst.find(fraza);
        if(g != -1)
            cout << tekst << endl;
        }
        x++;
    }
    cout << "1. Powrot do menu." << endl;
    cout << "0. Wyjscie z programu." << endl;
    cout << "Wybierz opcje: ";
    cin >> o;
    switch(o)
    {
    case 1:
        {
            system("cls");
            menu(plik, n, m, tekst);
        }
    case 0:
        {
            plik.close();
            exit(0);
        }
    }
}
