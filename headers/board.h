#pragma once
#include "kings.h"
class chessboard{
    public:
    int turn = 1;
    map<vector<int>, bool> checker;
    vector<vector<int>> result;
    vector<vector<int>> results;
    vector<vector<int>> possiblemoves;
    vector<string> finalresults;
    int u = 0;
    int we = 0;
    int flag = 0;
    string board[8][8];
    piece interboard[8][8];
    king kings[2];
    void fill_board();
    void show_board();
    bool move(string type,int startx,int starty,int endx,int endy,piece interboard[8][8],string boarde[8][8]);
    bool find_dangerw(int color,int step,piece boarde[8][8],string board[8][8]);
    bool find_dangerd(int color,int step,piece boarde[8][8],string board[8][8]);
    
};
