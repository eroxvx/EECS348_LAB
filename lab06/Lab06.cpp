#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

using namespace std;

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, ifstream& file) {
    file >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix[i][j];
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    
    ifstream file("matrix_input.txt");
    if (!file) {
        cerr << "Error: Unable to open file matrix_input.txt" << endl;
        return 1;
    }

    readMatrix(matrixA, size, file);
    readMatrix(matrixB, size, file);


    cout << "Lab #6: Matrix manipulation\n\n";

    cout << "Matrix A:\n";
    printMatrix(matrixA, size);


    cout << "\nMatrix B:\n";
    printMatrix(matrixB, size);


    addMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Sum (A + B):\n";
    printMatrix(result, size);

    
    multiplyMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Product (A * B):\n";
    printMatrix(result, size);

    
    subtractMatrices(matrixA, matrixB, result, size);
    cout << "\nMatrix Difference (A - B):\n";
    printMatrix(result, size);

    return 0;
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}


