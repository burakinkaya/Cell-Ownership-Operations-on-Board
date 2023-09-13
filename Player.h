
#ifndef Player_h
#define Player_h

#include "Board.h"

template <typename T>
class Player {
    private:
        static int playerCount;
        int playerID;
        Board<T> &board;
    public:
        Player(Board<T> &);
        bool updateCell(int row, int column, T value);
        void updateMyCells(T value);
        bool unclaimOwnership(int row, int column);
        void unclaimOwnerships();
};

/*template <typename T>
int Player<T>::playerCount = 1;*/

#include "Player.cpp"
#endif /* Player_h */
