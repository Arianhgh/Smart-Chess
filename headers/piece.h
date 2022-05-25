#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class piece{
    public :
    string type;
    string color;
    int position_x,position_y;
    piece(string _type="",string _color="",int position_x_=0,int position_y_=0){
        this -> color = _color;
        this -> position_x = position_x_;
        this ->position_y = position_y_;
        this -> type = _type;
    }
    bool is_valid_pawn(int startx,int starty, int endx, int endy,piece board[8][8]);
    bool is_valid_rook(int startx,int starty, int endx, int endy,piece board[8][8]);
    bool is_valid_knight(int startx,int starty, int endx, int endy,piece board[8][8]);
    bool is_valid_bishop(int startx,int starty, int endx, int endy,piece board[8][8]);
    bool is_valid_queen(int startx,int starty, int endx, int endy,piece board[8][8]);
    bool is_valid_king(int startx,int starty, int endx, int endy,piece board[8][8]);
};