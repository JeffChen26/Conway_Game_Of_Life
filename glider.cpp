#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int height = 40;
const int width = 40;
bool matrix[height][width] = { 0 };

void setup() {
    matrix[0][1] = true;
    matrix[1][2] = true;
    matrix[2][0] = true;
    matrix[2][1] = true;
    matrix[2][2] = true;
}
void draw() {
    system("cls");
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (matrix[row][col]) {
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
int count_neighbors(int row, int col) {
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if ((i == row && j == col) || (i < 0 || j < 0)
                || (i >= height || j >= width)) {
                continue;
            }
            else if (matrix[i][j] == true) {
                count++;
            }
        }
    }
    return count;
}
void update() {
    bool new_matrix[height][width] = { 0 };
    int live_neighbors;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            live_neighbors = count_neighbors(row, col);
            if (matrix[row][col] == true
                && (live_neighbors == 2
                    || live_neighbors == 3)) {
                new_matrix[row][col] = true;
            }
 
            else if (matrix[row][col] == false
                     && live_neighbors == 3) {
                new_matrix[row][col] = true;
            }
        }
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (new_matrix[row][col]) {
                matrix[row][col] = true;
            } else {
                matrix[row][col] = false;
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    system("MODE con cols=40 lines=40");
    setup();

    while (true)
    {
        draw();
        Sleep(100);
        update();
    }
    return 0;
}
