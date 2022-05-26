#pragma once
#include "kings.h"
#include "cells.h"
class chessboard{
    public:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text status;
    chessboard(sf::RenderWindow* _window){
        window = _window;
        window->setFramerateLimit(60);
    }
    int turn = 1;
    map<vector<int>, bool> checker;
    vector<vector<int>> result;
    vector<vector<int>> results;
    vector<vector<int>> possiblemoves;
    vector<string> finalresults;
    sf::Texture textures[8][8];
    //map<piece, sf::Texture> textures;
    int u = 0;
    int we = 0;
    int flag = 0;
    string board[8][8];
    piece interboard[8][8];
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
};
