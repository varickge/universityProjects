#include <stdio.h> 
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void pause() {
    for (double k = 1; k < 1e+8; k++);
}

void smallPause() {
    for (double k = 1; k < 1e+7; k++);
}

void clearEl() {
    printf("     ");
}

int main() {
    int m, n;
    printf("Input N (rows) & N (columns):\n");
    scanf_s("%d", &m);
    system("cls");
    srand(time(NULL));
    int matrix[10][10];
    n = m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 50 - rand() % 100;
        }
    }
    matrix[0][0] = 0;
    matrix[2][2] = 0;
    matrix[4][4] = 0;
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int startX = 0;
    int startY = 0;
    pos.X = startX;
    pos.Y = startY;

    for (int i = 0; i < m; i++) {
        SetConsoleCursorPosition(hConsole, pos);
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
            pos.X += 10;
            SetConsoleCursorPosition(hConsole, pos);
            pause();
        }
        SetConsoleCursorPosition(hConsole, pos);
        pos.X += 18;
        pause();
        pos.X = startX;
        pos.Y += 2;
    }

    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 100;
    SetConsoleCursorInfo(hConsole, &info);
    pos.Y = startY;
    int k = 0, cacheX, cacheY;
    for (int i = 0; i < m; i++) {

        pos.X = startX;
        if (matrix[i][i] == 0) {
            k++;
            SetConsoleCursorPosition(hConsole, pos);
            pause();
            pos.X = startX;

            for (int j = 0; j < n; j++) {
                pos.Y = startY + (2 * i);
                //Move right
                //if (k > 1 && j == 0) {

                //}
                //else
                for (int count = 0; count < 5; count++) {
                    smallPause();
                    pos.X -= 1;
                    SetConsoleCursorPosition(hConsole, pos);
                    clearEl();
                    pos.X += 2;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf("%4d", matrix[i][j]);
                }

                //Move bottom
                int bottom = startY + (m - 1) * 2 + 3 - pos.Y;
                if (i == 0) {
                    bottom = startY + (m - 1) * 2 + 6 - pos.Y;
                }

                for (int count = 0; count < bottom; count++) {
                    smallPause();
                    SetConsoleCursorPosition(hConsole, pos);
                    // smallPause();
                    clearEl();
                    pos.Y += 1;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf("%4d", matrix[i][j]);
                }
                cacheX = pos.X;
                cacheY = pos.Y;
                if (i != 0) {
                    for (int count = 0; count < (k - 1) * 50; count++) {
                        smallPause();
                        pos.X -= 1;
                        SetConsoleCursorPosition(hConsole, pos);
                        clearEl();
                        pos.X += 2;
                        SetConsoleCursorPosition(hConsole, pos);
                        printf("%4d", matrix[i][j]);
                    }
                    bottom = startY + (m - 1) * 2 + 6 - pos.Y;
                    for (int count = 0; count < bottom; count++) {
                        smallPause();
                        SetConsoleCursorPosition(hConsole, pos);
                        clearEl();
                        pos.Y += 1;
                        SetConsoleCursorPosition(hConsole, pos);
                        printf("%4d", matrix[i][j]);
                    }
                }
                pos.X = cacheX;
                pos.Y = cacheY;
                pos.X += 5;
                SetConsoleCursorPosition(hConsole, pos);
            }
        }
    }
    return 0;
}