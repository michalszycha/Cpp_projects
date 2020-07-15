//POP_2015_12_14_projekt_1_Szyszkowski_Michał_EIT_4_160317.cpp Code::Blocks 13.12, GNU GCC Complier
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct historia{
    char q,w;
    int e;
};
void wypelnianie (char tab[8][8]){
    for (int i = 0; i < 1; i++){
        for( int j = 0; j < 8; j+=2){
            tab[i][j] = 'x';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = '.';
        }
    }
    for (int i = 1; i < 2; i++){
        for( int j = 0; j < 8; j+=2){
            tab[i][j] = '.';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = 'x';
        }
    }
    for (int i = 2; i < 5; i+=2){
        for (int j = 0; j < 8; j+=2){
            tab[i][j] = ' ';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = '.';
        }
    }
    for (int i = 3 ; i < 6; i+=2){
        for (int j = 0; j < 8; j+=2){
            tab[i][j] = '.';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = ' ';
        }
    }
    for (int i = 6; i < 7; i++){
        for( int j = 0; j < 8; j+=2){
            tab[i][j] = 'o';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = '.';
        }
    }
    for (int i = 7; i < 8; i++){
        for( int j = 0; j < 8; j+=2){
            tab[i][j] = '.';
        }
        for (int j = 1; j < 8; j+=2){
            tab[i][j] = 'o';
        }
    }
}
void generowanie (char tab[8][8]){
    int g = 65;
    cout << "  " << "+--------+" << endl;
    for (int i = 0; i < 8; i++){
        cout << static_cast<char>(g) << setw(2) << "|";
        for (int j = 0; j < 8; j++){
            cout << tab[i][j];
        }
        cout << "|";
        cout << endl;
        g++;
    }
    cout << "  " << "+--------+" << endl;
    cout << setw(4);
    for (int j = 0; j < 8; j++)
        cout << j+1;
    cout << endl;
}
void ruch_1(char tab[8][8], int n, int a){      //Ruch dó³, lewo
    char buf;
    buf = tab[n][a-1];
    tab[n][a-1] = tab[n+1][a-2];
    tab[n+1][a-2] = buf;
}
void ruch_2(char tab[8][8], int n, int a){      //Ruch dó³, prawo
    char buf;
    buf = tab[n][a-1];
    tab[n][a-1] = tab[n+1][a];
    tab[n+1][a] = buf;
}
void ruch_3(char tab[8][8], int n, int a){      //Ruch góra, lewo
    char buf;
    buf = tab[n][a-1];
    tab[n][a-1] = tab[n-1][a-2];
    tab[n-1][a-2] = buf;
}
void ruch_4(char tab[8][8], int n, int a){      //Ruch góra, prawo
    char buf;
    buf = tab[n][a-1];
    tab[n][a-1] = tab[n-1][a];
    tab[n-1][a] = buf;
}
bool mozliwosc_bicia_x(char tab[8][8], int n, int a){
    if (((tab[n+1][a] == 'o' || tab[n+1][a] == 'O') && tab[n+2][a+1] == ' ') || ((tab[n+1][a-2] == 'o' || tab[n+1][a-2] == 'O') && tab[n+2][a-3] == ' '))
        return true;
    else return false;
}
bool mozliwosc_bicia_X(char tab[8][8], int n, int a){
    if ((((tab[n+1][a] == 'o' || tab[n+1][a] == 'O') && tab[n+2][a+1]) == ' ') || ((tab[n+1][a-2] == 'o' || tab[n+1][a-2] == 'O') && tab[n+2][a-3] == ' ') || ((tab[n-1][a-2] == 'o' || tab[n-1][a-2] == 'O') && tab[n-2][a-3] == ' ') || ((tab[n-1][a] == 'o' || tab[n-1][a] == 'O') && tab[n-2][a+1] == ' '))
        return true;
    else return false;
}
bool mozliwosc_bicia_X_3(char tab[8][8], int n, int a){
    if((tab[n-1][a-2] == 'o' || tab[n-1][a-2] == 'O') && tab[n-2][a-3] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_X_4(char tab[8][8], int n, int a){
    if((tab[n-1][a] == 'o' || tab[n-1][a] == 'O') && tab[n-2][a+1] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_x_1(char tab[8][8], int n, int a){
    if((tab[n+1][a-2] == 'o' || tab[n+1][a-2] == 'O') && tab[n+2][a-3] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_x_2(char tab[8][8], int n, int a){
    if((tab[n+1][a] == 'o' || tab[n+1][a] == 'O') && tab[n+2][a+1] == ' ')
        return true;
    else return false;
}
void bicie_x_1(char tab[8][8], int n, int a){
    //lewo
    char buf;
    buf = tab[n][a-1];
    tab[n+2][a-3] = buf;
    tab[n+1][a-2] = ' ';
    tab[n][a-1] = ' ';
}
void bicie_x_2(char tab[8][8], int n, int a){
    //prawo
    int buf;
    buf = tab[n][a-1];
    tab[n+2][a+1] = buf;
    tab[n+1][a] = ' ';
    tab[n][a-1] = ' ';
}
bool mozliwosc_bicia_o(char tab[8][8], int n, int a){
    if(((tab[n-1][a-2] == 'x' || tab[n-1][a-2] == 'X') && tab[n-2][a-3] == ' ') || ((tab[n-1][a] == 'x' || tab[n-1][a] == 'X') && tab[n-2][a+1] == ' '))
        return true;
    else return false;
}
bool mozliwosc_bicia_O(char tab[8][8], int n, int a){
    if (((tab[n+1][a] == 'x' || tab[n+1][a] == 'X') && tab[n+2][a+1] == ' ') || ((tab[n+1][a-2] == 'x' || tab[n+1][a-2] == 'X') && tab[n+2][a-3] == ' ') || ((tab[n-1][a-2] == 'x' || tab[n-1][a-2] == 'X') && tab[n-2][a-3] == ' ') || ((tab[n-1][a] == 'x' || tab[n-1][a] == 'X') && tab[n-2][a+1] == ' '))
        return true;
    else return false;
}
bool mozliwosc_bicia_O_1(char tab[8][8], int n, int a){
    if((tab[n+1][a-2] == 'x' || tab[n+1][a-2] == 'X') && tab[n+2][a-3] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_O_2(char tab[8][8], int n, int a){
    if((tab[n+1][a] == 'x' || tab[n+1][a] == 'X') && tab[n+2][a+1] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_o_3(char tab[8][8], int n, int a){
    if((tab[n-1][a-2] == 'x' || tab[n-1][a-2] == 'X') && tab[n-2][a-3] == ' ')
        return true;
    else return false;
}
bool mozliwosc_bicia_o_4(char tab[8][8], int n, int a){
    if((tab[n-1][a] == 'x' || tab[n-1][a] == 'X') && tab[n-2][a+1] == ' ')
        return true;
    else return false;
}
void bicie_o_3(char tab[8][8], int n, int a){
    //lewo
    int buf;
    buf = tab[n][a-1];
    tab[n-2][a-3] = buf;
    tab[n-1][a-2] = ' ';
    tab[n][a-1] = ' ';
}
void bicie_o_4(char tab[8][8], int n, int a){
    //prawo
    int buf;
    buf = tab[n][a-1];
    tab[n-2][a+1] = buf;
    tab[n-1][a] = ' ';
    tab[n][a-1] = ' ';
}
bool wygrana_x(char tab[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (tab[i][j] == 'x' || tab[i][j] == 'X')
            return true;
        }
    }
    return false;
}
bool wygrana_o(char tab[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (tab[i][j] == 'o' || tab[i][j] == 'O')
            return true;
        }
    }
    return false;
}
bool mozliwosc_ruchu_x(char tab[8][8], int n, int a, int b){
    if (b == 1){
        if (tab[n+1][a-2] == ' ')
            return true;
        else return false;
    }
    if (b == 2){
        if (tab[n+1][a] == ' ')
            return true;
        else return false;
    }
}
bool mozliwosc_ruchu_o(char tab[8][8], int n, int a, int b){
    if (b == 3){
        if (tab[n-1][a-2] == ' ')
            return true;
        else return false;
    }
    if (b == 4){
        if (tab[n-1][a] == ' ')
            return true;
        else return false;
    }
}
void pomoc();
void gracz_x(char tab[8][8], int r, historia tab2[]);
void bicie_x(char tab[8][8], int n, int a, int r, historia tab2[]);
void bicie_X(char tab[8][8], int n, int a, int r, historia tab2[]);
void ruch_X(char tab[8][8], int n, int a, int r, historia tab2[]);
void ruch_x(char tab[8][8], int n, int a, int r, historia tab2[]);
void gracz_o(char tab[8][8], int r, historia tab3[]);
void bicie_O(char tab[8][8], int n, int a, int r, historia tab3[]);
void ruch_O(char tab[8][8], int n, int a, int r, historia tab3[]);
void bicie_o(char tab[8][8], int n, int a, int r, historia tab3[]);
void ruch_o(char tab[8][8], int n, int a, int r, historia tab3[]);
void damka_x(char tab[8][8], int n, int a, int r, historia tab2[]);
void damka_o(char tab[8][8], int n, int a, int r, historia tab3[]);
void zamiana_damka_x(char tab[8][8]);
void zamiana_damka_o(char tab[8][8]);
void historia_ruchow_x(int r, historia tab2[]);
void historia_ruchow_o(int r, historia tab3[]);
int main()
{
    char tab[8][8];
    historia tab2[250];
    historia tab3[250];
    int r = 0;
    int m;
    do{
    cout << "Witaj w grze w warcaby!" << endl;
    cout << "Wybierz co chcesz zrobic." << endl;
    cout << "Wybierz 1, aby rozpoczac gre." << endl;
    cout << "Wybierz 2, a by wyswietlic pomoc." << endl;
    cin >> m;
    switch (m){
    case(1): break;
    case(2):
        { pomoc();
          break;}
    default: cout << "Zle dane" << endl;
    }
    }while (m != 1 && m != 2);
    wypelnianie(tab);
    system("cls");
    generowanie(tab);
    do{
    cout << endl;
    cout << "Gracz nr1" << endl;
    gracz_x(tab, r, tab2);
    zamiana_damka_x(tab);
    system("cls");
    generowanie(tab);
    historia_ruchow_x(r, tab2);
    cout << endl;
    if(wygrana_o(tab))
    {
    cout << "Gracz nr2" << endl;
    gracz_o(tab, r, tab3);
    zamiana_damka_o(tab);
    system("cls");
    generowanie(tab);
    historia_ruchow_o(r, tab3);
    r++;
    }
    else break;
    }while(wygrana_o(tab) && wygrana_x(tab));
    if(wygrana_x(tab)){
        cout << endl;
        cout << "Gracz nr1 wygral" << endl;
    }
    if(wygrana_o(tab)){
        cout << endl;
        cout << "Gracz nr2 wygral" << endl;
    }
    system("PAUSE");
    return 0;
}
void pomoc(){
    system("cls");
    cout << "Ruch pionkiem odbywa sie poprzez podanie jego wspolrzednych i wybranie kierunku ruchu.\nPodanie wspolrzednych odbywa sie w kolejnosci litera-cyfra, na przyklad 'B2'.\nJesli po wybraniu pionka jest mozliwosc bicia nalezy podac jego kierunek." << endl;
    cout << "1- ruch/bicie lewo, dol.\n2- ruch/bicie prawo, dol.\n3- ruch/bicie lewo, gora.\n4- ruch/bicie prawo gora.\nIstnieje mozliwosc cofniecia sie do wyboru pionka,\naby to zrobic nalezy wpisac '0' w momencie, gry program zapyta o kierunek ruchu." << endl << endl;
    main();
}
void gracz_x(char tab[8][8], int r, historia tab2[]){
    char n;
    char a;
    do{
        cout << "Podaj wspolrzedne pionka: ";
        cin >> n >> a;
        tab2[r].q = n;
        tab2[r].w = a;
        n = static_cast<int>(n) - 65;
        a = static_cast<int>(a) - 48;
        if((n < 0 || n > 7) || (tab[n][a-1] != 'x' && tab[n][a-1] != 'X') || (a > 8))
            cout << "Bledne wspolrzedne." << endl;
    }while((n < 0 || n > 7) || (tab[n][a-1] != 'x' && tab[n][a-1] != 'X') || (a > 8));
    if(tab[n][a-1] == 'X')
        damka_x(tab, n, a, r, tab2);
    else{
    if(mozliwosc_bicia_x(tab, n, a)){
        bicie_x(tab, n, a, r, tab2);
    }
    else {
        ruch_x(tab, n, a, r, tab2);
    }
    }
}
void damka_x(char tab[8][8], int n, int a, int r, historia tab2[]){
    if(mozliwosc_bicia_X(tab, n, a)){
        bicie_X(tab, n, a, r, tab2);
    }
    else{
        ruch_X(tab, n, a, r, tab2);
    }
}
void bicie_X(char tab[8][8], int n, int a, int r, historia tab2[]){
    int c;
    cout << "Wybierz kierunek bicia: ";
    cin >> c;
    tab2[r].e = c;
    switch (c){
        case(1): {
            if(mozliwosc_bicia_x_1(tab, n, a))
                bicie_x_1(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_X(tab, n, a, r, tab2);
            }
            break;
        }
        case(2): {
            if(mozliwosc_bicia_x_2(tab, n, a))
                bicie_x_2(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_X(tab, n, a, r, tab2);
            }
            break;
        }
        case (3): {
            if(mozliwosc_bicia_X_3(tab, n, a))
                bicie_o_3(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_X(tab, n, a, r, tab2);
            }
            break;
        }
        case (4): {
            if(mozliwosc_bicia_X_4(tab, n, a))
                bicie_o_4(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_X(tab, n, a, r, tab2);
            }
            break;
        }
        default: {
            cout << "Niepoprawne dane" << endl;
            bicie_X(tab, n, a, r, tab2);
        }
    }
}
void ruch_X(char tab[8][8], int n, int a, int r, historia tab2[]){
    int b;
    do{
    cout << "Wybierz kierunek ruchu: ";
    cin >> b;
    tab2[r].e = b;
    switch (b){
    case (1):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_1(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_X(tab, n, a, r, tab2);
        }
        break;
    }
    case (2):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_2(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_X(tab, n, a, r, tab2);
        }
        break;
    }
    case (0): gracz_x(tab, r, tab2);
    default: cout << "Niepoprawne dane" << endl;
    case (3):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_3(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_X(tab, n, a, r, tab2);
        }
        break;
    }
    case (4):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_4(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_X(tab, n, a, r, tab2);
        }
        break;
    }
    }
    }while(b != 1 && b != 2 && b != 0 && b != 3 && b != 4);
}
void bicie_x(char tab[8][8], int n, int a, int r, historia tab2[]){
    int c;
    cout << "Wybierz kierunek bicia: ";
    cin >> c;
    tab2[r].e = c;
    switch (c){
        case(1): {
            if(mozliwosc_bicia_x_1(tab, n, a))
                bicie_x_1(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_x(tab, n, a, r, tab2);
            }
            break;
        }
        case(2): {
            if(mozliwosc_bicia_x_2(tab, n, a))
                bicie_x_2(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_x(tab, n, a, r, tab2);
            }
            break;
        }
        default: {
            cout << "Niepoprawne dane" << endl;
            bicie_x(tab, n, a, r, tab2);
        }
    }
}
void ruch_x(char tab[8][8], int n, int a, int r, historia tab2[]){
    int b;
    do{
    cout << "Wybierz kierunek ruchu: ";
    cin >> b;
    tab2[r].e = b;
    switch (b){
    case (1):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_1(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_x(tab, n, a, r, tab2);
        }
        break;
    }
    case (2):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_2(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_x(tab, n, a, r, tab2);
        }
        break;
    }
    case (0): gracz_x(tab, r, tab2);
    default: cout << "Niepoprawne dane" << endl;
    }
    }while(b != 1 && b != 2 && b != 0);
}
void gracz_o(char tab[8][8], int r, historia tab3[]){
    char n;
    char a;
    do{
        cout << "Podaj wspolrzedne pionka: ";
        cin >> n >> a;
        tab3[r].q = n;
        tab3[r].w = a;
        n = static_cast<int>(n) - 65;
        a = static_cast<int>(a) - 48;
        if((n < 0 || n > 7) || (tab[n][a-1] != 'o' && tab[n][a-1] != 'O') || (a > 8))
            cout << "Bledne wspolrzedne." << endl;
    }while((n < 0 || n > 7) || (tab[n][a-1] != 'o' && tab[n][a-1] != 'O') || (a > 8));
    if(tab[n][a-1] == 'O')
        damka_o(tab, n, a, r, tab3);
    else{
    if(mozliwosc_bicia_o(tab, n, a))
        bicie_o(tab, n, a, r, tab3);
    else ruch_o(tab, n, a, r, tab3);
    }
}
void damka_o(char tab[8][8], int n, int a, int r, historia tab3[]){
    if(mozliwosc_bicia_O(tab, n, a))
        bicie_O(tab, n, a, r, tab3);
    else ruch_O(tab, n, a, r, tab3);
}
void bicie_O(char tab[8][8], int n, int a, int r, historia tab3[]){
    int c;
    cout << "Wybierz kierunek bicia: ";
    cin >> c;
    tab3[r].e = c;
    switch (c){
        case(1): {
            if(mozliwosc_bicia_O_1(tab, n, a))
                bicie_x_1(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_O(tab, n, a, r, tab3);
            }
            break;
        }
        case(2): {
            if(mozliwosc_bicia_O_2(tab, n, a))
                bicie_x_2(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_O(tab, n, a, r, tab3);
            }
            break;
        }
        case (3): {
            if(mozliwosc_bicia_o_3(tab, n, a))
                bicie_o_3(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_O(tab, n, a, r, tab3);
            }
            break;
        }
        case (4): {
            if(mozliwosc_bicia_o_4(tab, n, a))
                bicie_o_4(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_O(tab, n, a, r, tab3);
            }
            break;
        }
        default: {
            cout << "Niepoprawne dane" << endl;
            bicie_O(tab, n, a, r, tab3);
        }
    }
}
void ruch_O(char tab[8][8], int n, int a, int r, historia tab3[]){
    int b;
    do{
    cout << "Wybierz kierunek ruchu: ";
    cin >> b;
    tab3[r].e = b;
    switch (b){
    case (1):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_1(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_O(tab, n, a, r, tab3);
        }
        break;
    }
    case (2):{
        if (mozliwosc_ruchu_x(tab, n, a, b))
            ruch_2(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_O(tab, n, a, r, tab3);
        }
        break;
    }
    case (0): gracz_o(tab, r, tab3);
    default: cout << "zle dane" << endl;
    case (3):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_3(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_O(tab, n, a, r, tab3);
        }
        break;
    }
    case (4):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_4(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_O(tab, n, a, r, tab3);
        }
        break;
    }
    }
    }while(b != 1 && b != 2 && b != 0 && b != 3 && b != 4);
}
void bicie_o(char tab[8][8], int n, int a, int r, historia tab3[]){
    int c;
    cout << "Wybierz kierunek bicia: ";
    cin >> c;
    tab3[r].e = c;
    switch (c){
        case (3): {
            if(mozliwosc_bicia_o_3(tab, n, a))
                bicie_o_3(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_o(tab, n, a, r, tab3);
            }
            break;
        }
        case (4): {
            if(mozliwosc_bicia_o_4(tab, n, a))
                bicie_o_4(tab, n, a);
            else {
                cout << "Nie mozna wykonac takiego bicia." << endl;
                bicie_o(tab, n, a, r, tab3);
            }
            break;
        }
        default: {
            cout << "Niepoprawne dane" << endl;
            bicie_o(tab, n, a, r, tab3);
        }
        }
}
void ruch_o(char tab[8][8], int n, int a, int r, historia tab3[]){
    int b;
    do{
    cout << "Wybierz kierunek ruchu: ";
    cin >> b;
    tab3[r].e = b;
    switch (b){
    case (3):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_3(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_o(tab, n, a, r, tab3);
        }
        break;
    }
    case (4):{
        if (mozliwosc_ruchu_o(tab, n, a, b))
            ruch_4(tab, n, a);
        else {
            cout << "Nie mozna wykonac tego ruchu." << endl;
            ruch_o(tab, n, a, r, tab3);
        }
        break;
    }
    case (0): gracz_o(tab, r, tab3);
    default: cout << "Niepoprawne dane" << endl;
    }
    }while(b != 3 && b != 4 && b != 0);
}
void zamiana_damka_x(char tab[8][8]){
    for (int i = 7; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(tab[i][j] == 'x')
                tab[i][j] = 'X';
        }
    }
}
void zamiana_damka_o(char tab[8][8]){
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 8; j++){
            if(tab[i][j] == 'o')
                tab[i][j] = 'O';
        }
    }
}
void historia_ruchow_x(int r, historia tab2[]){
    cout << "Historia ruchow gracza nr1: ";
    for (int i = 0; i < r+1; i++){
        cout << tab2[i].q << tab2[i].w << "." << tab2[i].e << ",";
    }
}
void historia_ruchow_o(int r, historia tab3[]){
    cout << "Historia ruchow gracza nr2: ";
    for (int i = 0; i < r+1; i++){
        cout << tab3[i].q << tab3[i].w << "." << tab3[i].e << ",";
    }
}
