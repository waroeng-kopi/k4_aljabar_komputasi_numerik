#include <iostream>
#include <string>

// Definisikan struktur untuk merepresentasikan tipe data spasial
struct Point {
    float x;
    float y;
    float z;
};

// handle 
// error: no match for ‘operator<<’ (operand types are ‘std::ostream’ 
// {aka ‘std::basic_ostream<char>’} and ‘Point’)
//   74 |             std::cout << spatialMatrix[i][j] << "\t";
//      |             ~~~~~~~~~ ^~ ~~~~~~~~~~~~~~~~~~~
//      |                  |                         |
//      |                  |                         Point
//      |                  std::ostream {aka std::basic_ostream<char>}
// In file included from /usr/include/c++/10/iostream:39,
//                  from program.cpp:1:
//
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}


int main(void) {
    const int ROWS = 3; // Jumlah baris
    const int COLS = 4; // Jumlah kolom

    // Deklarasi matriks dengan tipe data string
    std::string stringMatrix[ROWS][COLS] = {
        {"Aku", "Kamu", "Kita", "Mereka"},
        {"HP", "Laptop", "Motor", "Uang"},
        {"Kucing", "Macan", "Anjing", "Monyet"}
    };

    // Deklarasi matriks dengan tipe data float
    float floatMatrix[ROWS][COLS] = {
        {1.2, 3.4, 5.6, 7.8},
        {2.3, 4.5, 6.7, 8.9},
        {3.4, 5.6, 7.8, 9.1}
    };

    // Deklarasi matriks dengan tipe data bool
    bool booleanMatrix[ROWS][COLS] = {
        {true, false, true, false},
        {false, true, false, true},
        {true, false, true, false}
    };

    // Deklarasi matriks dengan tipe data Point (spasial)
    struct Point spatialMatrix[ROWS][COLS] = {
        {{0.1, 0.2, 0.3}, {1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}},
        {{0.2, 0.3, 0.4}, {1.2, 1.3, 1.4}, {2.2, 2.3, 2.4}, {3.2, 3.3, 3.4}},
        {{0.3, 0.4, 0.5}, {1.3, 1.4, 1.5}, {2.3, 2.4, 2.5}, {3.3, 3.4, 3.5}}
    };

    // Print isi dari matriks dengan tipe data string
    std::cout << "String Matrix:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << stringMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print isi dari matriks dengan tipe data float
    std::cout << std::endl << "Float Matrix:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << floatMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print isi dari matriks dengan tipe data bool
    std::cout << std::endl << "Boolean Matrix:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << booleanMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print isi dari matriks dengan tipe data spatial
    std::cout << std::endl << "Spatial Matrix:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << spatialMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
