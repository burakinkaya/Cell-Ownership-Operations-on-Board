

#ifndef Board_h
#define Board_h

template <typename T>
struct cell {
    T value;
    int owner;
};

template <typename T>
class Board {
    private:
        int rows;
        int columns;
        int count;
        cell<T> ** matrix;
    public:
        Board(int rows, int columns);
        Board(const Board & other);
        ~Board();
        void displayBoard();
        void updateBoardCells(int player, T value);
        int getPlayerCellsCount(int player);
        int knowTheOwner(int row, int column);
        void setValue(int row, int column, T value2);
        void setOwner(int row, int column, int owner2);
        int getRows();
        int getCols();
};

#include "Board.cpp"


#endif /* Board_h */
