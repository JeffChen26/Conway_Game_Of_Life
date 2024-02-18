#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

const int height = 40;
const int width = 40;
bool matrix[height][width];

void setup() {
    string input;
    fstream file;
    while (true) {
        cout << "Enter name of file:" << endl;
        cin >> input;
        file.open(input, ios::in);
        if (file.is_open()) {
            break;
        } else {
            cout << "File does not exist, try again." << endl;
        }
    }
    string line;
    int row = 0;
    int col = 0;
    while (getline(file, line) && row < height) {
        for (char c : line) {
            if (c == '1') {
                matrix[row][col] = true;
            } else {
                matrix[row][col] = false;
            }
            col++;
        }
        row++;
        col = 0;
    }
    file.close();
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
    cout << "At any time, press 's' to store universe." << endl;
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
void store() {
    string input;
    system("cls");
    cout << "Enter name of file to store:" << endl;
    cin >> input;
    ofstream file(input);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (matrix[row][col]) {
                file << '1';
            } else {
                file << '0';
            }
        }
        file << '\n';
    }
    file.close();
}
void input() {
    if (_kbhit() && _getch() == 's') {
        store();
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    system("MODE con cols=41 lines=41");
    setup();

    while (true)
    {
        draw();
        Sleep(100);
        update();
        input();
    }
    return 0;
}
