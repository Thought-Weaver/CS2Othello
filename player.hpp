#ifndef __PLAYER_H__
#define __PLAYER_H__
#define NDEBUG

#include "common.hpp"
#include "board.hpp"
#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <algorithm>
#include <fstream>

using namespace std;

class Player {
public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    Move *doNaiveMove();
    Move *doABMinimaxMove();

    double getABScore(Board b, int depth, double alpha, double beta);

    void LoadOpeningMoves();

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;

    int depth;

    Side side;
    Board board;

    vector<string> opening_moves;
    string made_moves;
};

#endif