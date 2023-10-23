#include <iostream>
#include <fstream>

const int MATRIX_SIZE = 3; // Define the matrix size

// Function prototypes
void readMatrixFromFile(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE], const std::string& filename);
void printMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void addMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);
void multiplyMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);
void subtractMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);

int main() {
    int matrix1[MATRIX_SIZE][MATRIX_SIZE];
    int matrix2[MATRIX_SIZE][MATRIX_SIZE];
    int result[MATRIX_SIZE][MATRIX_SIZE];

    // Read 3x3 matrices from a file
    readMatrixFromFile(matrix1, matrix2, "matrix_input.txt");

    // Display Matrix 1 & name
    std::cout << "Jackson Yanek, Lab 6 Matrix Manipulation" << std::endl;   
    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);

    // Display Matrix 2
    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2);

    // Add two 3x3 matrices and display the result
    addMatrices(matrix1, matrix2, result);
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    printMatrix(result);

    // Multiply two 3x3 matrices and display the result
    multiplyMatrices(matrix1, matrix2, result);
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    printMatrix(result);

    // Subtract the second 3x3 matrix from the first 3x3 matrix and display the result
    subtractMatrices(matrix1, matrix2, result);
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    printMatrix(result);

    return 0;
}

// Function to read two 3x3 matrices from a file
void readMatrixFromFile(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE], const std::string& filename) {
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        exit(1);
    }

    int size;
    file >> size; // Read the size of the square matrix

    if (size != MATRIX_SIZE) {
        std::cerr << "Error: Matrix size in the file does not match the expected size." << std::endl;
        exit(1);
    }

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (file.eof()) {
                std::cerr << "Error: Insufficient data in the file." << std::endl;
                exit(1);
            }
            file >> matrix1[i][j];
        }
    }

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (file.eof()) {
                std::cerr << "Error: Insufficient data in the file." << std::endl;
                exit(1);
            }
            file >> matrix2[i][j];
        }
    }
    file.close();
}

// Function to print a 3x3 matrix
void printMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Functions for adding, multiplying, and subtracting 3x3 matrices
void addMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[MATRIX_SIZE][MATRIX_SIZE], const int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
