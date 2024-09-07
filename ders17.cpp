#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

const int N = 8;
int board[N][N];
int moveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

//----------------------------------------------------------------1------------------------------------------------------------
void replaceDigitsWithSpaces() {
    char ch;
    cout << "Rəqəmləri boşluqla əvəz etmək üçün hərf və ya rəqəm daxil edin:" << endl;
    while (true) {
        ch = _getch();
        if (isdigit(ch)) {
            _putch(' ');
        }
        else {
            _putch(ch);
        }
    }
}

// -------------------------------------------------------------------2----------------------------------------------------
void swapCase() {
    char ch;
    cout << "Kiçik hərfləri böyük və əksinə çevirmək üçün hərf daxil edin:" << endl;
    while (true) {
        ch = _getch();
        if (islower(ch)) {
            _putch(toupper(ch));
        }
        else if (isupper(ch)) {
            _putch(tolower(ch));
        }
        else {
            _putch(ch);
        }
    }
}

// ---------------------------------------------------------------------------3----------------------------------------------
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

bool solveKnightTour(int x, int y, int moveCount) {
    if (moveCount == N * N) return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1)) return true;
            board[nextX][nextY] = -1;
        }
    }
    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void knightTour() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    int startX, startY;
    cout << "Atın yerləşdiriləcəyi başlanğıc koordinatlarını daxil edin (0-7 arası): ";
    cin >> startX >> startY;

    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1)) {
        printBoard();
    }
    else {
        cout << "At üçün həll yoxdur." << endl;
    }
}

int main() {
    int secim;
    while (true) {
        cout << "\nFunksiyanı seçin:\n";
        cout << "1. Rəqəmləri boşluqla əvəz et\n";
        cout << "2. Kiçik hərfləri böyük, böyük hərfləri kiçik hərflə əvəz et\n";
        cout << "3. Atın şahmat taxtasında hərəkəti\n";
        cout << "0. Çıxış\n";
        cout << "Seçim: ";
        cin >> secim;

        switch (secim) {
        case 1:
            replaceDigitsWithSpaces();
            break;
        case 2:
            swapCase();
            break;
        case 3:
            knightTour();
            break;
        case 0:
            return 0;
        default:
            cout << "Yanlış seçim. Yenidən cəhd edin." << endl;
        }
    }
}