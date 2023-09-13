


#include "Player.h"


/*template <class T>
Player<T>::Player(Board<T> & b){
    playerID = playerCount;
    playerCount++;
}*/

template <typename T>
int Player<T>::playerCount = 1;

template<typename T>
Player<T>::Player(Board<T> &b){
	playerID=playerCount;
	board= b;
	playerCount++;
}






template <typename T>
bool Player<T>::updateCell(int row, int column, T value) {
    if(board.knowTheOwner(row, column) == 0) {
        board.setValue(row, column, value);
        board.setOwner(row, column, playerID);
        return true;
    }
    else if(board.knowTheOwner(row, column) == playerID) {
        board.setValue(row, column, value);
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Player<T>::updateMyCells(T value) {
    for(int i = 0; i < board.getRows(); i++) {
        for(int j = 0; j < board.getCols(); j++) {
            if(board.knowTheOwner(i, j) == playerID) {
                board.setValue(i, j, value);
            }
        }
    }
}

template <typename T>
bool Player<T>::unclaimOwnership(int row, int column) {
    if(board.knowTheOwner(row, column) == playerID) {
        board.setOwner(row, column, 0);
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Player<T>::unclaimOwnerships() {
    for(int i = 0; i < board.getRows(); i++) {
        for(int j = 0; j < board.getCols(); j++) {
            if(board.knowTheOwner(i, j) == playerID) {
                board.setOwner(i, j, 0);
            }
        }
    }
}
