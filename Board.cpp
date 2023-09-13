

#include "Board.h"
#include <iostream>
#include <string>
using namespace std;


template <typename T>
Board<T>::Board(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    matrix = new cell<T>*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new cell<T>[columns];
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j].owner = 0;
        }
    }
}

template <typename T>
Board<T>::Board(const Board & other) {
    this->rows = other.rows;
    this->columns = other.columns;
    matrix = new cell<T>*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new cell<T>[columns];
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

template <typename T>
Board<T>::~Board() {
    delete [] matrix;
}

template <typename T>
void Board<T>::displayBoard() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << "(" << matrix[i][j].owner << ", " << matrix[i][j].value << ") ";
        }
        cout << endl;
    }
}

template <typename T>
void Board<T>::updateBoardCells(int player, T value) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j].owner == player) {
                matrix[i][j].value = value;
            }
        }
    }
}

template <typename T>
int Board<T>::getPlayerCellsCount(int player) {
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j].owner == player) {
                count++;
            }
        }
    }
    return count;
}

template <typename T>
int Board<T>::knowTheOwner(int row, int column) {
    int intown = matrix[row][column].owner;
    return intown;
}



template <typename T>
void Board<T>::setValue(int row, int column, T value2){
    matrix[row][column].value = value2;
}

template <typename T>
void Board<T>::setOwner(int row, int column, int owner2){
    matrix[row][column].owner = owner2;
}

template <typename T>
int Board<T>::getRows(){
    return rows;
}

template <typename T>
int Board<T>::getCols(){
    return columns;
}

