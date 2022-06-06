#pragma once
#include "kings.h"
#include "cells.h"
#include <SFML/Audio.hpp>
class chessboard{
    public:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text status;
    sf::Text selected_piece;
    sf::Text warning;
    sf::Text remove_piece;
    sf::Music music;
    sf::RectangleShape mutebutton;
    string inputs;
    int inputtype;
    int turncolor;
    int backupturncolor;
    chessboard(sf::RenderWindow* _window,int _inputtype = 1, int _turncolor = 1){
        window = _window;
        inputtype = _inputtype;
        turncolor = _turncolor;
        backupturncolor = _turncolor;
        window->setFramerateLimit(60);
    }
    int turn = 1;
    bool laststate = true;
    bool piece_selected = false;
    bool selectdone = false;
    bool sound = true;
    piece selectedpiece;
    map<vector<int>, bool> checker;
    vector<vector<int>> undo_moves;
    vector<string> undo_strs;
    vector<piece> undo_pieces;
    vector<vector<int>> result;
    vector<vector<int>> results;
    vector<vector<int>> results1;
    vector<vector<int>> possiblemoves;
    vector<string> finalresults;
    vector<int> moves;
    sf::Texture textures[8][8];
    sf::Texture uitextures[18];
    int selected[2] = {-1,-1};
    int checkkingx = -1;
    int checkkingy = -1;
    int checkmate = 0;
    int kingsi = 1;
    sf::Color lastcolor;
    int u = 0;
    int we = 0;
    int flag = 0;
    string board[8][8];
    piece interboard[8][8];
    string backupboard[8][8];
    piece backupinterboard[8][8];
    king kings[2];
    cell uichess[8][8];
    void fill_board();
    void show_board();
    bool move(string type,int startx,int starty,int endx,int endy,piece interboard[8][8],string boarde[8][8]);
    bool find_dangerw(int color,int step,piece boarde[8][8],string board[8][8]);
    bool find_dangerd(int color,int step,piece boarde[8][8],string board[8][8]);
    void run();
    void setup_board();
    void update_status();
    void clickmanager(sf::Vector2i position);
    void drawboard();
    void undo(int startx,int starty,int endx,int endy,string board[8][8],piece interboard[8][8]);
    void fill_board_manager(sf::Vector2i position);
    void draw_fill_board();
    void right_click_manager(sf::Vector2i position);
};

