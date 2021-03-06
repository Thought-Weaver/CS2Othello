#ifndef __COMMON_H__
#define __COMMON_H__
#include <algorithm>

#define BOARDSIZE 8
#define AVGMOVES 25.0
#define TOURNEYTIME 300000.0
#define TIMELIMIT TOURNEYTIME / AVGMOVES

enum Side { 
    WHITE, BLACK
};

class Move {
   
public:
    int x, y;
    int flipped[50];
    int num_flipped;
    Move(int x, int y) {
        this->x = x;
        this->y = y; 
        this->num_flipped = 0;
    }
    ~Move() {

    }

    int getX() { return x; }
    int getY() { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    Move *copy()
    {
        Move *move = new Move(this->x, this->y);
        std::copy(std::begin(this->flipped), std::end(this->flipped), std::begin(move->flipped));
        move->num_flipped = this->num_flipped;
        return move;
    }
};

#endif
