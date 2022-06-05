//https://github.com/Arianhgh
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class piece{
    public :
    string type;
    string color;
    int position_x,position_y;
    sf::Sprite spirite;
    vector<int> allmoves;
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
    void possiblemoves(int startx,int starty,piece board[8][8],int color);
};
class king : public piece{
    public:
    king(string _type="",string _color="",int position_x_=0,int position_y_=0){
        this -> color = _color;
        this->position_x = position_x_;
        this->position_y = position_y_;
        this ->type = _type;
    }
    bool is_check(piece board[8][8]);
    bool checkmate(piece board[8][8]);
    void update_pos(int endx, int endy);
};
using namespace std;
class cell{
    public:
    sf::RectangleShape cellul;
};
class chessboard{
    public:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text status;
    sf::Text selected_piece;
    sf::Text warning;
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
    
    bool piece_selected = false;
    bool selectdone = false;
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
    sf::Texture uitextures[16];
    int selected[2] = {-1,-1};
    int checkkingx = -1;
    int checkkingy = -1;
    int checkmate = 0;
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
int main(){
    cout << "how do you want to input the board?\n1.clipboard\n2.by hand\n";
    int input;
    cin >> input;
    int turncolor;
    cout << "which color do you want to start?\n1.white\n2.black\n";
    cin >> turncolor;
    if (turncolor == 2) turncolor = -1;
    else turncolor = 1;
    RenderWindow window(VideoMode(1200, 800), "Chess", Style::Titlebar | Style::Close);
    chessboard A(&window,input,turncolor);
    A.run();
    return 0;
}
bool piece::is_valid_pawn(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if (position_x == 1 || position_x == 6){
            if (starty == endy && (abs(endx - startx) == 1 || abs(endx - startx) == 2) && board[endx][endy].type == ""){
                if (board[startx][starty].color=="W" && endx - startx == -1 ){
                    return true;
                }
                else if (board[startx][starty].color=="W" && endx - startx == -2 && board[startx-1][endy].type == ""){
                    return true;
                }
                else if (board[startx][starty].color=="B" && endx - startx == 1){
                    return true;
                }
                else if (board[startx][starty].color=="B" && endx - startx == 2 && board[startx+1][endy].type == ""){
                    return true;
                }
                else
                    return false;
            }
            else if (abs(endx- startx) == 1 && abs(endy-starty) == 1 && board[endx][endy].type != "" && board[endx][endy].color != board[startx][starty].color){
                if (board[startx][starty].color == "W" && endx - startx == -1){
                    return true;
                }
                else if (board[startx][starty].color == "B" && endx - startx == 1){
                    return true;
                }
                else
                    return false;
            } else
                return false;
        }
        else{
            if (starty == endy && (abs(endx - startx) == 1) && board[endx][endy].type == ""){
                if (board[startx][starty].color=="W" && endx - startx == -1){
                    return true;
                }
                else if (board[startx][starty].color=="B" && endx - startx == 1){
                    return true;
                }
                else
                    return false;
            }
            else if (abs(endx- startx) == 1 && abs(endy-starty) == 1 && board[endx][endy].type != "" && board[endx][endy].color != board[startx][starty].color){
                if (board[startx][starty].color == "W" && endx - startx == -1){
                    return true;
                }
                else if (board[startx][starty].color == "B" && endx - startx == 1){
                    return true;
                }
                else
                    return false;
            } else
                return false;
        }
}
bool piece::is_valid_rook(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if ((starty == endy || endx == startx) && board[endx][endy].color != board[startx][starty].color){
            if (startx == endx && endy > starty){
                for (int i = starty+1; i <endy; i++ ) {
                    if (i != endy && board[startx][i].type != "")
                        return false;
                }
                return true;
            }
            if (startx == endx && endy < starty){
                for (int i = starty-1; i >endy; i-- ) {
                    if (i != endy && board[startx][i].type != "")
                        return false;
                }
                return true;
            }
            if (starty == endy && endx > startx){
                for (int i = startx+1; i <endx; i++ ) {
                    if (i != endx && board[i][starty].type != "")
                        return false;
                }
                return true;
            }
            if (starty == endy && endx < startx){
                for (int i = startx-1; i > endx; i-- ) {
                    if (i != endx && board[i][starty].type != "")
                        return false;
                }
                return true;
            }
        } else
            return false;
        return false;
}
bool piece::is_valid_bishop(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if (startx != endx && starty != endy && (abs(endx-startx)==abs(endy - starty)) && board[endx][endy].color != board[startx][starty].color){
            if (endx > startx && endy > starty){
                for (int i = startx+1 ,j = starty+1; i < endx && j < endy; i++,j++) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx > startx && endy < starty){
                for (int i = startx+1 ,j = starty-1; i < endx && j > endy; i++,j--) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx < startx && endy > starty){
                for (int i = startx-1 ,j = starty+1; i > endx && j < endy; i--,j++) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx < startx && endy < starty){
                for (int i = startx-1 ,j = starty-1; i > endx && j > endy; i--,j--) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }

        } else
            return false;
        return false;
}
bool piece::is_valid_knight(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if (((abs(endy - starty) == 2 && abs(endx - startx)==1) || (abs(endx - startx)==2 && abs(endy - starty)==1)) &&
            board[endx][endy].color != board[startx][starty].color){
            return true;
        } else
            return false;
}
bool piece::is_valid_queen(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if ((startx == endx || endy == starty) && board[endx][endy].color != board[startx][starty].color){
            if (startx == endx && endy > starty){
                for (int i = starty+1; i <endy; i++ ) {
                    if (i != endy && board[startx][i].type != "")
                        return false;
                }
                return true;
            }
            if (startx == endx && endy < starty){
                for (int i = starty-1; i >endy; i-- ) {
                    if (i != endy && board[startx][i].type != "")
                        return false;
                }
                return true;
            }
            if (starty == endy && endx > startx){
                for (int i = startx+1; i <endx; i++ ) {
                    if (i != endx && board[i][starty].type != "")
                        return false;
                }
                return true;
            }
            if (starty == endy && endx < startx){
                for (int i = startx-1; i > endx; i-- ) {
                    if (i != endx && board[i][starty].type != "")
                        return false;
                }
                return true;
            }
        }
        else if (startx != endx && starty != endy && (abs(endx-startx)==abs(endy - starty)) && board[endx][endy].color != board[startx][starty].color){
            if (endx > startx && endy > starty){
                for (int i = startx+1 ,j = starty+1; i < endx && j < endy; i++,j++) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx > startx && endy < starty){
                for (int i = startx+1 ,j = starty-1; i < endx && j > endy; i++,j--) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx < startx && endy > starty){
                for (int i = startx-1 ,j = starty+1; i > endx && j < endy; i--,j++) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }
            if (endx < startx && endy < starty){
                for (int i = startx-1 ,j = starty-1; i > endx && j > endy; i--,j--) {
                    if (i != endx && j != endy && board[i][j].type != "")
                        return false;
                }
                return true;
            }

        }
        else {
            return false;
        }
        return false;
}
bool piece::is_valid_king(int startx,int starty, int endx, int endy,piece board[8][8]){
    if (endx < 0 || endx > 7 && endy < 0 && endy > 7)
            return false;
        if ((startx == endx || endy == starty) && board[endx][endy].color != board[startx][starty].color){
            if (startx == endx){
                if(abs(endy-starty) == 1)
                    return true;
                return false;
            }
            if (starty == endy){
                if(abs(endx-startx) == 1)
                    return true;
                return false;
            }
        }
        else if (startx != endx && starty != endy && (abs(endx-startx)==abs(endy - starty)) && board[endx][endy].color != board[startx][starty].color) {
            if (abs(endx-startx)==1){
                return true;
            } else
                return false;
        }
        else {
            return false;
        }
        return false;
}
void piece::possiblemoves(int startx,int starty,piece board[8][8],int color){
    if(board[startx][starty].type == "P"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_pawn(startx,starty,i,j,board) && board[i][j].type != "K"){
                    //cout << i << j << endl;
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
    if(board[startx][starty].type == "R"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_rook(startx,starty,i,j,board) && board[i][j].type != "K"){
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
    if(board[startx][starty].type == "B"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_bishop(startx,starty,i,j,board) && board[i][j].type != "K"){
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
    if(board[startx][starty].type == "N"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_knight(startx,starty,i,j,board) && board[i][j].type != "K"){
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
    if(board[startx][starty].type == "Q"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_queen(startx,starty,i,j,board) && board[i][j].type != "K"){
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
    if(board[startx][starty].type == "K"){
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if((i != startx || j != starty) && is_valid_king(startx,starty,i,j,board) && board[i][j].type != "K"){
                    allmoves.push_back(i);
                    allmoves.push_back(j);
                }
            }
        }
    }
}
bool king::is_check(piece board[8][8]){
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j) {
                if (board[i][j].type != "" && board[i][j].color != color){
                    if (board[i][j].type == "Q"){
                        if(is_valid_queen(i,j,position_x,position_y,board))
                            return true;

                    }
                    if (board[i][j].type == "B"){
                        if(is_valid_bishop(i,j,position_x,position_y,board))
                            return true;

                    }
                    if (board[i][j].type == "R"){
                        if(is_valid_rook(i,j,position_x,position_y,board))
                            return true;

                    }
                    if (board[i][j].type == "N"){
                        if(is_valid_knight(i,j,position_x,position_y,board))
                            return true;

                    }
                    if (board[i][j].type == "P"){
                        if(is_valid_pawn(i,j,position_x,position_y,board))
                            return true;

                    }
                    if (board[i][j].type == "K"){
                        if(is_valid_king(i,j,position_x,position_y,board))
                            return true;

                    }
                }
            }
        }
        return false;
    }
bool king::checkmate(piece board[8][8]){
        
        bool result = true;
        int moves[8][2] = {{position_x+1,position_y},{position_x+1,position_y+1},{position_x,position_y+1},{position_x-1,position_y+1},{position_x-1,position_y},{position_x-1,position_y-1}
                ,{position_x,position_y-1},{position_x+1,position_y-1}};
         if (is_check(board)){
        for (int k = 0; k < 8; ++k) {
            if ((moves[k][0] < 8 && moves[k][0] >= 0 && moves[k][1] >= 0 && moves[k][1] < 8) && is_valid_king(this -> position_x,this ->position_y,moves[k][0],moves[k][1],board)){
                //cout << moves[k][0] << " " << moves[k][1] << endl;
                piece tmp2;
                piece tmp = board[moves[k][0]][moves[k][1]];
                int xtmp = this -> position_x;
                int ytmp = this ->position_y;
                board[moves[k][0]][moves[k][1]] = board[position_x][position_y];
                board[position_x][position_y] = tmp2;
                position_x = moves[k][0];
                position_y = moves[k][1];
                if (!is_check(board)){
                    
                    board[xtmp][ytmp] = board[position_x][position_y];
                    this -> position_x = xtmp;
                    this -> position_y = ytmp;
                    board[moves[k][0]][moves[k][1]] = tmp;
                    result = false;
                    break;
                }
                else{
                    board[xtmp][ytmp] = board[position_x][position_y];
                    this -> position_x = xtmp;
                    this -> position_y = ytmp;
                    board[moves[k][0]][moves[k][1]] = tmp;
                }
            }
        }
        
        if (result == false){
            return false;
        }
        else{
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    if (board[i][j].color == color && board[i][j].type != "K"){
                        if (board[i][j].type == "Q"){
                        for (int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){
                                if (board[i][j].is_valid_queen(i,j,k,r,board)){
                                    piece tmp,tmp1;
                                    int xtemp = board[i][j].position_x;
                                    int ytemp = board[i][j].position_y;
                                    tmp = board[k][r];
                                    board[k][r] = board[i][j];
                                    board[i][j].position_x = k;
                                    board[i][j].position_y = r;
                                    board[i][j] = tmp1;
                                    if (!is_check(board)){
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                        return false;
                                    }
                                    else{
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                    }
                                }
                            }
                        }

                    }
                    if (board[i][j].type == "B"){
                        for (int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){
                                if (board[i][j].is_valid_bishop(i,j,k,r,board)){
                                    piece tmp,tmp1;
                                    int xtemp = board[i][j].position_x;
                                    int ytemp = board[i][j].position_y;
                                    tmp = board[k][r];
                                    board[k][r] = board[i][j];
                                    board[i][j].position_x = k;
                                    board[i][j].position_y = r;
                                    board[i][j] = tmp1;
                                    if (!is_check(board)){
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                        return false;
                                    }
                                    else{
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                    }
                                }
                            }
                        }

                    }
                    if (board[i][j].type == "R"){
                        for (int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){
                                if (board[i][j].is_valid_rook(i,j,k,r,board)){
                                    piece tmp,tmp1;
                                    int xtemp = board[i][j].position_x;
                                    int ytemp = board[i][j].position_y;
                                    tmp = board[k][r];
                                    board[k][r] = board[i][j];
                                    board[i][j].position_x = k;
                                    board[i][j].position_y = r;
                                    board[i][j] = tmp1;
                                    if (!is_check(board)){
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                        return false;
                                    }
                                    else{
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                    }
                                }
                            }
                        }

                    }
                    if (board[i][j].type == "N"){
                        for (int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){
                                if (board[i][j].is_valid_knight(i,j,k,r,board)){
                                    piece tmp,tmp1;
                                    int xtemp = board[i][j].position_x;
                                    int ytemp = board[i][j].position_y;
                                    tmp = board[k][r];
                                    board[k][r] = board[i][j];
                                    board[i][j].position_x = k;
                                    board[i][j].position_y = r;
                                    board[i][j] = tmp1;
                                    if (!is_check(board)){
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                        return false;
                                    }
                                    else{
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                    }
                                }
                            }
                        }

                    }
                    if (board[i][j].type == "P"){
                        for (int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){
                                if (board[i][j].is_valid_pawn(i,j,k,r,board)){
                                    piece tmp,tmp1;
                                    int xtemp = board[i][j].position_x;
                                    int ytemp = board[i][j].position_y;
                                    tmp = board[k][r];
                                    board[k][r] = board[i][j];
                                    board[i][j].position_x = k;
                                    board[i][j].position_y = r;
                                    board[i][j] = tmp1;
                                    if (!is_check(board)){
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                        return false;
                                    }
                                    else{
                                        board[i][j] = board[k][r];
                                        board[i][j].position_x = xtemp;
                                        board[i][j].position_y = ytemp;
                                        board[k][r] = tmp;
                                    }
                                }
                            }
                        }

                    }
                    
                    }
                }
            }
            return true;
        }
    }
    else{
        return false;
    }
    }
void king::update_pos(int endx, int endy){
        this -> position_x = endx;
        this -> position_y = endy;
    }
void chessboard::fill_board_manager(sf::Vector2i position){
    int x = position.x;
    int y = position.y;
    if(x >= 860 && x <= 930 && y >= 100 && y <= 170){
        piece wpawn("P","W",0,0);
        string tmp = "White Pawn";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wpawn;
        piece_selected = true;
    }
    if(x>= 860 && x <= 930 && y >= 180 && y <= 250){
        piece wrook("R","W",0,0);
        string tmp = "White Rook";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wrook;
        piece_selected = true;
    }
    if(x>= 860 && x <= 930 && y >= 260 && y <= 330){
        piece wknight("N","W",0,0);
        string tmp = "White Knight";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wknight;
        piece_selected = true;
    }
    if(x>= 860 && x <= 930 && y >= 340 && y <= 410){
        piece wbishop("B","W",0,0);
        string tmp = "White Bishop";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wbishop;
        piece_selected = true;
    }
    if(x>= 860 && x <= 930 && y >= 420 && y <= 490){
        piece wqueen("Q","W",0,0);
        string tmp = "White Queen";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wqueen;
        piece_selected = true;
    }
    if(x>= 860 && x <= 930 && y >= 500 && y <= 570){
        piece wking("K","W",0,0);
        string tmp = "White King";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = wking;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 100 && y <= 170){
        piece bpawn("P","B",0,0);
        string tmp = "Black Pawn";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = bpawn;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 180 && y <= 250){
        piece brook("R","B",0,0);
        string tmp = "Black Rook";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = brook;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 260 && y <= 330){
        piece bknight("N","B",0,0);
        string tmp = "Black Knight";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = bknight;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 340 && y <= 410){
        piece bbishop("B","B",0,0);
        string tmp = "Black Bishop";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = bbishop;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 420 && y <= 490){
        piece bqueen("Q","B",0,0);
        string tmp = "Black Queen";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = bqueen;
        piece_selected = true;
    }
    if(x>= 1060 && x <= 1130 && y >= 500 && y <= 570){
        piece bking("K","B",0,0);
        string tmp = "Black King";
        selected_piece.setString("Selected piece: "+tmp);
        selectedpiece = bking;
        piece_selected = true;
    }
    if(piece_selected){
        if(x>=0 && x<= 800 && y>=0 && y<=800){
            int row = position.y / 100;
            int col = position.x / 100;
            int i = row;
            int j = col;
            if(kings[0].position_x == row && kings[0].position_y == col){
                kings[0] = king();
            }
            else if (kings[1].position_x == row && kings[0].position_y == col){
                kings[1] = king();
            }
            interboard[row][col] = selectedpiece;
            interboard[row][col].position_x = row;
            interboard[row][col].position_y = col;
            interboard[i][j].spirite.setOrigin(-35,-25);
            interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
            interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
            if(selectedpiece.type == "K" && selectedpiece.color == "W"){
                king kingw("K","W",row,col);
                kings[0] = kingw;
                textures[i][j].loadFromFile("textures/w_king.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "KW";
            }
            else if(selectedpiece.type == "K" && selectedpiece.color == "B"){
                king kingb("K","B",row,col);
                kings[1] = kingb;
                textures[i][j].loadFromFile("textures/b_king.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "KB";
            }
            else if(selectedpiece.type == "Q" && selectedpiece.color == "W"){
                textures[i][j].loadFromFile("textures/w_queen.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "QW";
            }
            else if(selectedpiece.type == "Q" && selectedpiece.color == "B"){
                textures[i][j].loadFromFile("textures/b_queen.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "QB";
            }
            else if(selectedpiece.type == "R" && selectedpiece.color == "W"){
                textures[i][j].loadFromFile("textures/w_rook.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "RW";
            }
            else if(selectedpiece.type == "R" && selectedpiece.color == "B"){
                textures[i][j].loadFromFile("textures/b_rook.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "RB";
            }
            else if(selectedpiece.type == "B" && selectedpiece.color == "W"){
                textures[i][j].loadFromFile("textures/w_bishop.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "BW";
            }
            else if(selectedpiece.type == "B" && selectedpiece.color == "B"){
                textures[i][j].loadFromFile("textures/b_bishop.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "BB";
            }
            else if(selectedpiece.type == "N" && selectedpiece.color == "W"){
                textures[i][j].loadFromFile("textures/w_knight.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "NW";
            }
            else if(selectedpiece.type == "N" && selectedpiece.color == "B"){
                textures[i][j].loadFromFile("textures/b_knight.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "NB";
            }
            else if(selectedpiece.type == "P" && selectedpiece.color == "W"){
                textures[i][j].loadFromFile("textures/w_pawn.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "PW";
            }
            else if(selectedpiece.type == "P" && selectedpiece.color == "B"){
                textures[i][j].loadFromFile("textures/b_pawn.png");
                interboard[i][j].spirite.setTexture(textures[i][j]);
                board[i][j] = "PB";
            }
            piece_selected = false;
            selectedpiece = piece();
            selected_piece.setString("Selected piece: ");
            warning.setString("");


        }


    }
    if(x>=1060 && x <= 1140 && y>= 630 && y <= 710){
        if(kings[0].type == "" || kings[1].type == ""){
            warning.setString("Two kings should be on the board");
        }
        else if(abs(kings[0].position_x - kings[1].position_x)<= 1 && abs(kings[0].position_y - kings[1].position_y)<= 1){
            warning.setString("Kings should be at least 2 squares apart");
        }
        else{
        warning.setString("");
        selectdone = true;
        for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board[i][j] == "") board[i][j] == "--";
            backupboard[i][j] = board[i][j];
            backupinterboard[i][j] = interboard[i][j];
        }
        }
    }
    }

}
void chessboard::right_click_manager(sf::Vector2i position){
    int row = position.y / 100;
    int col = position.x / 100;
    piece empty;
    if(interboard[row][col].type != ""){
        interboard[row][col] = empty;
        piece_selected = false;
        selectedpiece = piece();
        selected_piece.setString("Selected piece: ");
    }
}
void chessboard::undo(int startx,int starty,int endx,int endy,string board[8][8],piece interboard[8][8]){
    piece empty;
     interboard[endx][endy] = interboard[startx][starty];
     interboard[startx][starty] = empty;
     board[endx][endy] = board[startx][starty];
     board[startx][starty] = "--";
     interboard[endx][endy].position_x = endx;
     interboard[endx][endy].position_y = endy;
     if(interboard[endx][endy].type =="K"){
     if (interboard[endx][endy].color == "W"){
        kings[0].update_pos(endx,endy);
     }
     else if (interboard[endx][endy].color == "B"){
        kings[1].update_pos(endx,endy);
     }
     }
     interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
}
void chessboard::clickmanager(sf::Vector2i position){
    int x = position.x;
    int y = position.y;
    if((x>=860 && x <= 960)&&(y>=660 && y<= 710) && undo_moves.size()>0){
        cout << "undo" << endl;
        undo(undo_moves[undo_moves.size()-1][2],undo_moves[undo_moves.size()-1][3],undo_moves[undo_moves.size()-1][0],undo_moves[undo_moves.size()-1][1],board,interboard);
        board[undo_moves[undo_moves.size()-1][2]][undo_moves[undo_moves.size()-1][3]] = undo_strs[undo_strs.size()-1];
        interboard[undo_moves[undo_moves.size()-1][2]][undo_moves[undo_moves.size()-1][3]] = undo_pieces[undo_pieces.size()-1];
        undo_moves.pop_back();
        undo_pieces.pop_back();
        undo_strs.pop_back();
        turncolor = turncolor * -1;
        int colores = (turncolor==1)?0:1;
        if(kings[colores].is_check(interboard)){
                    uichess[kings[colores].position_x][kings[colores].position_y].cellul.setFillColor(sf::Color::Red);
                    checkkingx = kings[colores].position_x;
                    checkkingy = kings[colores].position_y;
                }
        else{
            if((checkkingx + checkkingy) % 2 == 1){
                    uichess[checkkingx][checkkingy].cellul.setFillColor(sf::Color::Black);
                }
                else{
                    uichess[checkkingx][checkkingy].cellul.setFillColor(sf::Color::White);
                }
                checkkingx = -1;
                checkkingy = -1;

        }
        if(checkmate != 0){
            checkmate = 0;
        }
        int e = -1;
        for(int i=0; i<8; i++){
            for (int j = 0; j < 8; j++){
            uichess[i][j].cellul.setSize(sf::Vector2f(100,100));
            if (e == 1)
                uichess[i][j].cellul.setFillColor(sf::Color::Black);
            else{
                uichess[i][j].cellul.setFillColor(sf::Color::White);
            }
            e *= -1;
            uichess[i][j].cellul.setPosition(sf::Vector2f(j*100,i*100));
            uichess[i][j].cellul.setOutlineThickness(-1);
            uichess[i][j].cellul.setOutlineColor(sf::Color::Black);
    }
    e *= -1;
    }
        if(turncolor == 1) status.setOutlineColor(sf::Color::Blue);
            else status.setOutlineColor(sf::Color::Red);
            string turn = (turncolor == 1 ? "White" : "Black");
            status.setString(turn + "'s turn");
        if(kings[colores].is_check(interboard)){
                    uichess[kings[colores].position_x][kings[colores].position_y].cellul.setFillColor(sf::Color::Red);
                    checkkingx = kings[colores].position_x;
                    checkkingy = kings[colores].position_y;
                }
    }
    if(x>=1030 && x <= 1130 && y>=660 && y<= 710){
        for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            board[i][j] = backupboard[i][j];
            interboard[i][j] = backupinterboard[i][j];
        }
    }
        cout << backupturncolor << "color" << endl;
        turncolor = backupturncolor;
        fill_board();
        setup_board();
        checkkingx = -1;
        checkkingy = -1;
        checkmate = 0;
        if(turncolor == 1){
        status.setOutlineColor(sf::Color::Blue);
        status.setString("White's turn");
        }
        else{
        status.setOutlineColor(sf::Color::Red);
        status.setString("Black's turn");
        }
        selected[0] = -1;
        selected[1] = -1;
    }
    int row = position.y / 100;
    int col = position.x / 100;
    string colors = (turncolor == 1) ? "W" : "B";
    int colores = (turncolor==1)?0:1;
    if(x>=860 && x <=1130 && y >= 600 && y <= 650){
        if(selected[0] != -1){
            cout << selected[0] << " " << selected[1] << endl;
            row = selected[0];
            col = selected[1];
            for(int i=0;i<interboard[selected[0]][selected[1]].allmoves.size()-1;i+=2){
            if(interboard[selected[0]][selected[1]].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            piece tmpboard[8][8];
            string tmpboards[8][8];
            for (int z = 0; z < 8; z++){
                for (int j = 0; j < 8; j++){
               tmpboard[z][j] = interboard[z][j];
               tmpboards[z][j] = board[z][j];
                                        }
                                    }
            piece tmp = tmpboard[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]];
            string temp = tmpboards[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]];
            undo(selected[0],selected[1],tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1],tmpboards,tmpboard);
            result.push_back({row,col,tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1]});
            bool res = find_dangerd(-turncolor,2,tmpboard,tmpboards);
            cout <<"bool"<< res << endl;
            if (result.size() >= 1 && flag == 1){
                    results.push_back(result[0]);
                                    }
            result.clear();
            flag = 0;
            undo(tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1],selected[0],selected[1],tmpboards,tmpboard);
            tmpboard[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]] = tmp;
            tmpboards[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]] = temp;
        }
        cout << results.size() << endl;
        for(int i=0;i<interboard[row][col].allmoves.size();i+=2){
            if(interboard[row][col].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color::Green);
            for(int j = 0;j<results.size();j++){
                if(results[j][2] == interboard[row][col].allmoves[i] && results[j][3] == interboard[row][col].allmoves[i+1]){
                    uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color{255,100,0});
                    cout << interboard[row][col].allmoves[i] << " " << interboard[row][col].allmoves[i+1] << endl;
                }

            }
        }
        }
        return;
    }
    if(x>=860 && x <= 1130 && y>= 540 && y <= 590){
        if(selected[0] != -1){
            int oldx = kings[0].position_x;
            int oldy = kings[0].position_y;
            int oldx1 = kings[1].position_x;
            int oldy1 = kings[1].position_y;
            cout << selected[0] << " " << selected[1] << endl;
            row = selected[0];
            col = selected[1];
            for(int i=0;i<interboard[selected[0]][selected[1]].allmoves.size()-1;i+=2){
            if(interboard[selected[0]][selected[1]].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            piece tmpboard[8][8];
            string tmpboards[8][8];
            for (int z = 0; z < 8; z++){
                for (int j = 0; j < 8; j++){
               tmpboard[z][j] = interboard[z][j];
               tmpboards[z][j] = board[z][j];
                                        }
                                    }
            piece tmp = tmpboard[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]];
            string temp = tmpboards[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]];
            undo(selected[0],selected[1],tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1],tmpboards,tmpboard);
            result.push_back({row,col,tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1]});
            bool res = find_dangerw(-turncolor,2,tmpboard,tmpboards);
            cout <<"bool"<< res << endl;
            if (result.size() >= 1 && flag == 1){
                    results1.push_back(result[0]);
                                    }
            result.clear();
            flag = 0;
            undo(tmpboard[row][col].allmoves[i],tmpboard[row][col].allmoves[i+1],selected[0],selected[1],tmpboards,tmpboard);
            tmpboard[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]] = tmp;
            tmpboards[tmpboard[row][col].allmoves[i]][tmpboard[row][col].allmoves[i+1]] = temp;
        }
        cout << 12345<<endl;
        cout << results1.size() << endl;
        cout << interboard[row][col].allmoves.size() << endl;
        for(int i=0;i<interboard[row][col].allmoves.size();i+=2){
            if(interboard[row][col].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color::Green);
            for(int j = 0;j<results1.size();j++){
                if(results1[j][2] == interboard[row][col].allmoves[i] && results1[j][3] == interboard[row][col].allmoves[i+1]){
                    uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color::Cyan);
                    cout << interboard[row][col].allmoves[i] << " " << interboard[row][col].allmoves[i+1] << endl;
                }

            }
        }
        kings[0].update_pos(oldx,oldy);
        kings[1].update_pos(oldx1,oldy1);
        }
        
        cout << "kings" << endl;
        cout << kings[0].position_x << " " << kings[0].position_y << endl;
        cout << kings[1].position_x << " " << kings[1].position_y << endl;
        return;
    }
    if (row > 7 || col > 7) return;
    if (board[row][col] != "--" && selected[0]==-1 && colors == interboard[row][col].color){
        selected[0] = row;
        selected[1] = col;
        lastcolor = uichess[row][col].cellul.getFillColor();
        uichess[row][col].cellul.setFillColor(sf::Color::Yellow);
        interboard[row][col].possiblemoves(row,col,interboard,colores);
        for(int i=0;i<interboard[row][col].allmoves.size()-1;i+=2){
             if(interboard[row][col].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
             piece tmp = interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]];
             string temp = board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]];
             undo(selected[0],selected[1],interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],board,interboard);
             if(kings[colores].is_check(interboard)){
                 undo(interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],selected[0],selected[1],board,interboard);
                 interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = tmp;
                 board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = temp;
                 interboard[row][col].allmoves.erase(interboard[row][col].allmoves.begin()+i,interboard[row][col].allmoves.begin()+i+2);
                 i -= 2;
             }
             else{
             undo(interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],selected[0],selected[1],board,interboard);
             interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = tmp;
             board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = temp;
             }
             cout << interboard[row][col].allmoves.size() << endl;
            
        }
        for(int i=0;i<interboard[row][col].allmoves.size();i+=2){
            if(interboard[row][col].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color::Green);

        }
    }
    else{
        bool want_to_move = false;
        if(selected[0]!= -1)
            uichess[selected[0]][selected[1]].cellul.setFillColor(lastcolor);
        for(int i=0;i<interboard[selected[0]][selected[1]].allmoves.size();i+=2){
            if(selected[0]==-1){
                break;
            }
            if(interboard[selected[0]][selected[1]].allmoves[i]==row && interboard[selected[0]][selected[1]].allmoves[i+1]==col){
                want_to_move = true;
            }
            if((interboard[selected[0]][selected[1]].allmoves[i]+interboard[selected[0]][selected[1]].allmoves[i+1])%2==1){
                uichess[interboard[selected[0]][selected[1]].allmoves[i]][interboard[selected[0]][selected[1]].allmoves[i+1]].cellul.setFillColor(sf::Color::Black);
            }
            else{
                uichess[interboard[selected[0]][selected[1]].allmoves[i]][interboard[selected[0]][selected[1]].allmoves[i+1]].cellul.setFillColor(sf::Color::White);
            }
        }
        if(want_to_move){
            cout << "moving" << endl;
            undo_pieces.push_back(interboard[row][col]);
            undo_strs.push_back(board[row][col]);
            //move(interboard[selected[0]][selected[1]].type,selected[0],selected[1],row,col,interboard,board);
            undo(selected[0],selected[1],row,col,board,interboard);
            undo_moves.push_back({selected[0],selected[1],row,col});
            want_to_move = false;
            if(checkkingx != -1){
            if (!kings[colores].is_check(interboard)){
                if((checkkingx + checkkingy) % 2 == 1){
                    uichess[checkkingx][checkkingy].cellul.setFillColor(sf::Color::Black);
                }
                else{
                    uichess[checkkingx][checkkingy].cellul.setFillColor(sf::Color::White);
                }
                checkkingx = -1;
                checkkingy = -1;
            }
            }
            turncolor *= -1;
            if(turncolor == 1) status.setOutlineColor(sf::Color::Blue);
            else status.setOutlineColor(sf::Color::Red);
            string turn = (turncolor == 1 ? "White" : "Black");
            status.setString(turn + "'s turn");
            int colores = (turncolor==1)?0:1;
            if(kings[colores].checkmate(interboard)){
                checkmate = colores + 1;
            }
            else{
                if(kings[colores].is_check(interboard)){
                    uichess[kings[colores].position_x][kings[colores].position_y].cellul.setFillColor(sf::Color::Red);
                    checkkingx = kings[colores].position_x;
                    checkkingy = kings[colores].position_y;
                }
            }
                
            selected[0] = -1;
            selected[1] = -1;
            interboard[row][col].allmoves.clear();
            results.clear();
            results1.clear();        
            }
        else{
            if(board[row][col] == "--"){
                selected[0] = -1;
                selected[1] = -1;
            }
            else{
                results.clear();
                interboard[row][col].allmoves.clear();
                results1.clear();
                if (colors == interboard[row][col].color){
                selected[0] = row;
                selected[1] = col;
                lastcolor = uichess[row][col].cellul.getFillColor();
                uichess[row][col].cellul.setFillColor(sf::Color::Yellow);
                interboard[row][col].possiblemoves(row,col,interboard,colores);
                for(int i=0;i<interboard[row][col].allmoves.size()-1;i+=2){
                    if(interboard[row][col].allmoves.size()==0){
                        cout << "no moves" << endl;
                        break;
                     }
                    piece tmp = interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]];
                    string temp = board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]];
                    undo(selected[0],selected[1],interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],board,interboard);
                    if(kings[colores].is_check(interboard)){
                        undo(interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],selected[0],selected[1],board,interboard);
                        interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = tmp;
                        board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = temp;
                        interboard[row][col].allmoves.erase(interboard[row][col].allmoves.begin()+i,interboard[row][col].allmoves.begin()+i+2);
                        i -= 2;
                    }
                    else{
                    undo(interboard[row][col].allmoves[i],interboard[row][col].allmoves[i+1],selected[0],selected[1],board,interboard);
                    interboard[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = tmp;
                    board[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]] = temp;}
                    
                }
        for(int i=0;i<interboard[row][col].allmoves.size();i+=2){
            if(interboard[row][col].allmoves.size()==0){
                 cout << "no moves" << endl;
                 break;
             }
            uichess[interboard[row][col].allmoves[i]][interboard[row][col].allmoves[i+1]].cellul.setFillColor(sf::Color::Green);
        }
        }
            }
        }
    }

}
void chessboard::drawboard(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            window->draw(uichess[i][j].cellul);
            if (interboard[i][j].type != ""){
                window->draw(interboard[i][j].spirite);
            }
        }
    }
    sf::RectangleShape background(sf::Vector2f(400,800));
    background.setPosition(800,0);
    sf::Texture bg;
    bg.loadFromFile("textures/background.jpg");
    uitextures[2] = bg;
    background.setTexture(&uitextures[2]);
    window->draw(background);
    sf::RectangleShape undobutton(sf::Vector2f(100,50));
    undobutton.setPosition(860,660);
    undobutton.setFillColor(sf::Color::Red);
    sf::Text undotext;
    undotext.setFont(font);
    undotext.setString("Undo");
    undotext.setCharacterSize(30);
    undotext.setPosition(870,670);
    window->draw(undobutton);
    window->draw(undotext);
    sf::RectangleShape resetbutton(sf::Vector2f(100,50));
    resetbutton.setPosition(1030,660);
    resetbutton.setFillColor(sf::Color::Blue);
    sf::Text resettext;
    resettext.setFont(font);
    resettext.setString("Reset");
    resettext.setCharacterSize(30);
    resettext.setPosition(1040,670);
    window->draw(resetbutton);
    window->draw(resettext);
    sf::RectangleShape hintbutton1(sf::Vector2f(270,50));
    hintbutton1.setPosition(860,600);
    hintbutton1.setFillColor(sf::Color::Green);
    sf::Text hinttext1;
    hinttext1.setFont(font);
    hinttext1.setString("Defensive Hint");
    hinttext1.setCharacterSize(30);
    hinttext1.setPosition(895,610);
    hinttext1.setFillColor(sf::Color::Black);
    window->draw(hintbutton1);
    window->draw(hinttext1);
    sf::RectangleShape hintbutton2(sf::Vector2f(270,50));
    hintbutton2.setPosition(860,540);
    hintbutton2.setFillColor(sf::Color::Green);
    sf::Text hinttext2;
    hinttext2.setFont(font);
    hinttext2.setString("Offensive Hint");
    hinttext2.setCharacterSize(30);
    hinttext2.setPosition(895,550);
    hinttext2.setFillColor(sf::Color::Black);
    window->draw(hintbutton2);
    window->draw(hinttext2);
    if(checkmate != 0){
        sf::RectangleShape rect(sf::Vector2f(280,280));
        rect.setOutlineThickness(1);
        rect.setOutlineColor(sf::Color::Blue);
        rect.setPosition(sf::Vector2f(860,85));
        sf::Texture texturei;
        if(checkmate==1){
            texturei.loadFromFile("textures/blackwin1.jpg");
            uitextures[0] = texturei;
        }
        else{
            texturei.loadFromFile("textures/whitewin.jpg");
            uitextures[1] = texturei;
        }
        rect.setTexture(&uitextures[checkmate-1]);
        status.setString("");
        window->draw(rect);

    }
}
void chessboard::draw_fill_board(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            window->draw(uichess[i][j].cellul);
            if (interboard[i][j].type != ""){
                window->draw(interboard[i][j].spirite);
            }
        }
    }
    sf::RectangleShape background(sf::Vector2f(400,800));
    background.setPosition(800,0);
    sf::Texture bg;
    bg.loadFromFile("textures/background.jpg");
    uitextures[2] = bg;
    background.setTexture(&uitextures[2]);
    window->draw(background);
    sf::RectangleShape fill_w_pawn(sf::Vector2f(70,70));
    fill_w_pawn.setPosition(860,100);
    sf::Texture pawnw;
    pawnw.loadFromFile("textures/w_pawn.png");
    uitextures[3] = pawnw;
    fill_w_pawn.setTexture(&uitextures[3]);
    window->draw(fill_w_pawn);
    sf::RectangleShape fill_b_pawn(sf::Vector2f(70,70));
    fill_b_pawn.setPosition(1060,100);
    sf::Texture pawnb;
    pawnb.loadFromFile("textures/b_pawn.png");
    uitextures[4] = pawnb;
    fill_b_pawn.setTexture(&uitextures[4]);
    window->draw(fill_b_pawn);
    sf::RectangleShape fill_w_rook(sf::Vector2f(70,70));
    fill_w_rook.setPosition(860,180);
    sf::Texture rookw;
    rookw.loadFromFile("textures/w_rook.png");
    uitextures[5] = rookw;
    fill_w_rook.setTexture(&uitextures[5]);
    window->draw(fill_w_rook);
    sf::RectangleShape fill_b_rook(sf::Vector2f(70,70));
    fill_b_rook.setPosition(1060,180);
    sf::Texture rookb;
    rookb.loadFromFile("textures/b_rook.png");
    uitextures[6] = rookb;
    fill_b_rook.setTexture(&uitextures[6]);
    window->draw(fill_b_rook);
    sf::RectangleShape fill_w_knight(sf::Vector2f(70,70));
    fill_w_knight.setPosition(860,260);
    sf::Texture knightw;
    knightw.loadFromFile("textures/w_knight.png");
    uitextures[7] = knightw;
    fill_w_knight.setTexture(&uitextures[7]);
    window->draw(fill_w_knight);
    sf::RectangleShape fill_b_knight(sf::Vector2f(70,70));
    fill_b_knight.setPosition(1060,260);
    sf::Texture knightb;
    knightb.loadFromFile("textures/b_knight.png");
    uitextures[8] = knightb;
    fill_b_knight.setTexture(&uitextures[8]);
    window->draw(fill_b_knight);
    sf::RectangleShape fill_w_bishop(sf::Vector2f(70,70));
    fill_w_bishop.setPosition(860,340);
    sf::Texture bishopw;
    bishopw.loadFromFile("textures/w_bishop.png");
    uitextures[9] = bishopw;
    fill_w_bishop.setTexture(&uitextures[9]);
    window->draw(fill_w_bishop);
    sf::RectangleShape fill_b_bishop(sf::Vector2f(70,70));
    fill_b_bishop.setPosition(1060,340);
    sf::Texture bishopb;
    bishopb.loadFromFile("textures/b_bishop.png");
    uitextures[10] = bishopb;
    fill_b_bishop.setTexture(&uitextures[10]);
    window->draw(fill_b_bishop);
    sf::RectangleShape fill_w_queen(sf::Vector2f(70,70));
    fill_w_queen.setPosition(860,420);
    sf::Texture queenw;
    queenw.loadFromFile("textures/w_queen.png");
    uitextures[11] = queenw;
    fill_w_queen.setTexture(&uitextures[11]);
    window->draw(fill_w_queen);
    sf::RectangleShape fill_b_queen(sf::Vector2f(70,70));
    fill_b_queen.setPosition(1060,420);
    sf::Texture queenb;
    queenb.loadFromFile("textures/b_queen.png");
    uitextures[12] = queenb;
    fill_b_queen.setTexture(&uitextures[12]);
    window->draw(fill_b_queen);
    sf::RectangleShape fill_w_king(sf::Vector2f(70,70));
    fill_w_king.setPosition(860,500);
    sf::Texture kingw;
    kingw.loadFromFile("textures/w_king.png");
    uitextures[13] = kingw;
    fill_w_king.setTexture(&uitextures[13]);
    window->draw(fill_w_king);
    sf::RectangleShape fill_b_king(sf::Vector2f(70,70));
    fill_b_king.setPosition(1060,500);
    sf::Texture kingb;
    kingb.loadFromFile("textures/b_king.png");
    uitextures[14] = kingb;
    fill_b_king.setTexture(&uitextures[14]);
    window->draw(fill_b_king);
    sf::RectangleShape confirm_piece(sf::Vector2f(80,80));
    confirm_piece.setPosition(1060,630);
    sf::Texture confirm_piece_texture;
    confirm_piece_texture.loadFromFile("textures/done.png");
    uitextures[15] = confirm_piece_texture;
    confirm_piece.setTexture(&uitextures[15]);
    window->draw(confirm_piece);
    
    

}
void chessboard::setup_board(){
    int e = -1;
    for(int i=0; i<8; i++){
        for (int j = 0; j < 8; j++){
            uichess[i][j].cellul.setSize(sf::Vector2f(100,100));
            if (e == 1)
                uichess[i][j].cellul.setFillColor(sf::Color::Black);
            else{
                uichess[i][j].cellul.setFillColor(sf::Color::White);
            }
            e *= -1;
            uichess[i][j].cellul.setPosition(sf::Vector2f(j*100,i*100));
            uichess[i][j].cellul.setOutlineThickness(-1);
            uichess[i][j].cellul.setOutlineColor(sf::Color::Black);
    }
    e *= -1;
    }
    font.loadFromFile("textures/arial.ttf");
    status.setFont(font);
    if(turncolor == 1){
        status.setString("White's turn");
    }
    else{
        status.setString("Black's turn");
    }
    status.setCharacterSize(40);
    status.setStyle(sf::Text::Regular);
    if(turncolor == 1){
        status.setOutlineColor(sf::Color::Blue);
    }
    else{
        status.setOutlineColor(sf::Color::Red);
    }
    status.setOutlineThickness(1);
    status.setFillColor(sf::Color::White);
    status.setPosition(sf::Vector2f(885,100));
    selected_piece.setFont(font);
    selected_piece.setString("Selected piece: ");
    selected_piece.setCharacterSize(20);
    selected_piece.setPosition(860,600);
    //a warning text indicating that there should be two kings
    warning.setFont(font);
    warning.setFillColor(sf::Color::Red);
    warning.setCharacterSize(15);
    warning.setPosition(860,630);

    
}
void chessboard::update_status(){
    status.setString("HELLO");
}
void chessboard::fill_board(){
    string s;
    if(inputs.length()==0) s = sf::Clipboard::getString();
    else s = inputs;
    int x = 0;
    for (int z = 0; z < s.length(); z+=3) {
            int i = x / 8;
            int j = x % 8;
            x += 1;
            board[i][j] = s[z];
            board[i][j] += s[z+1];
            if (board[i][j][0] == 'K' ) {
                if (board[i][j][1] == 'W') {
                    piece x("K","W",i,j);
                    king tmp("K","W",x.position_x,x.position_y);
                    kings[0]= tmp;
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_king.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));

                } else{
                    piece x("K","B",i,j);
                    king tmp("K","B",x.position_x,x.position_y);
                    kings[1] = tmp;
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_king.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
            if (board[i][j][0] == 'Q' ) {
                if (board[i][j][1] == 'W') {
                    piece x("Q","W",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_queen.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                } else{
                    piece x("Q","B",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_queen.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
            if (board[i][j][0] == 'B' ) {
                if (board[i][j][1] == 'W') {
                    piece x("B","W",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_bishop.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                } else{
                    piece x("B","B",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_bishop.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
            if (board[i][j][0] == 'N' ) {
                if (board[i][j][1] == 'W') {
                    piece x("N","W",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_knight.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                } else{
                    piece x("N","B",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_knight.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
            if (board[i][j][0] == 'R' ) {
                if (board[i][j][1] == 'W') {
                    piece x("R","W",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_rook.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                } else{
                    piece x("R","B",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_rook.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
            if (board[i][j][0] == 'P' ) {
                if (board[i][j][1] == 'W') {
                    piece x("P","W",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/w_pawn.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                } else{
                    piece x("P","B",i,j);
                    interboard[i][j] = x;
                    textures[i][j].loadFromFile("textures/b_pawn.png");
                    interboard[i][j].spirite.setTexture(textures[i][j]);
                    interboard[i][j].spirite.setOrigin(-35,-25);
                    interboard[i][j].spirite.setPosition(sf::Vector2f(j * 100,i * 100));
                    interboard[i][j].spirite.scale(sf::Vector2f(.5f, .5f));
                }
            }
        
    }
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            backupboard[i][j] = board[i][j];
            backupinterboard[i][j] = interboard[i][j];
        }
    }
}
void chessboard::show_board(){
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
}
void chessboard::run(){
    if(inputtype==1){
    fill_board();
    setup_board();
    window->display();
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                clickmanager(sf::Mouse::getPosition(*window));
            }
        }
        window->clear(sf::Color::White);
        drawboard();
        window->draw(status);
        window->display();
    }
    }
    if(inputtype==2){
        setup_board();
        window->display();
        while(window->isOpen()){
            sf::Event event;
            if(!selectdone){
            while(window->pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window->close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    fill_board_manager(sf::Mouse::getPosition(*window));
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    right_click_manager(sf::Mouse::getPosition(*window));
                }
            }
            window->clear(sf::Color::White);
            draw_fill_board();
            window->draw(selected_piece);
            window->draw(warning);
            window->display();
            }
            else{
                while(window->pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window->close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    clickmanager(sf::Mouse::getPosition(*window));
                }
            }
            window->clear(sf::Color::White);
            drawboard();
            window->draw(status);
            window->display();
            }
        }
    }
}
bool chessboard::move(string type,int startx,int starty,int endx,int endy,piece interboard[8][8],string boarde[8][8]){
        piece empty;
        if (type == "P"){
            //cout << startx << " " << starty << " " << endx << " " << endy << endl;
            if (interboard[startx][starty].is_valid_pawn(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                return true;
            }
        }
        else if (type == "R"){
            if (interboard[startx][starty].is_valid_rook(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                return true;
            }
        }
        else if (type == "B"){
           // if (u < 12){
            //cout << startx << starty << endx << endy << endl;}
            if (interboard[startx][starty].is_valid_bishop(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                return true;
            }
        }
        else if (type == "Q"){
            if (interboard[startx][starty].is_valid_queen(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                return true;
            }
        }
        else if (type == "N"){
            if (interboard[startx][starty].is_valid_knight(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                return true;
            }
        }
        else if (type == "K"){
            if (interboard[startx][starty].is_valid_king(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
                //interboard[endx][endy].spirite.setPosition(sf::Vector2f(endy * 100,endx * 100));
                if (interboard[endx][endy].color == "W"){
                    kings[0].update_pos(endx,endy);
                }
                else if (interboard[endx][endy].color == "B"){
                    kings[1].update_pos(endx,endy);
                }
                return true;
            }
        }
        return false;
    }
bool chessboard::find_dangerw(int color,int step,piece boarde[8][8],string board[8][8]){
        //cout << result.size() << endl;
        u++;
        vector<int> ae = {5,3,3,4};
        vector<int> be = {4,1,3,1};
        if (result.size() > 23456  && result[0] == ae && step == 3){
            cout << result.size() << endl;
            cout << "step = " << step << endl;
            //cout << kings[1].position_x << " " << kings[1].position_y << endl;
            cout << u << endl;
            for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int d = 0; d < result.size();d++){
            for (int e = 0; e < 4; e++){
                cout << result[d][e] << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------"<<endl;
        }
        
        string colors = (color == 1) ? "W" : "B";
        int colores = (color==1)?0:1;
        int oldx1 = kings[0].position_x;
        int oldy1 = kings[0].position_y;
        int oldx2 = kings[1].position_x;
        int oldy2 = kings[1].position_y;
        
        piece tmpboard[8][8];
        string tmpboards[8][8];
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
               tmpboard[i][j] = boarde[i][j];
               tmpboards[i][j] = board[i][j];
                                        }
                                    }
        if (step > 3){
            if(kings[colores].checkmate(boarde)){
                if(result.size()>0){
        result.pop_back();}
                return true;
            }
            if(result.size()>0){
        result.pop_back();}
            return false;
            
        }
        if(step == 2){
            //cout << step << endl;
            if(kings[colores].checkmate(boarde)){
                flag = 1;
                //cout << "done" << endl;
                return true;
            }
            
        }
        
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++) {
                    if (boarde[i][j].color == colors){
                        for(int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){          
                                bool tmp = move(boarde[i][j].type,i,j,k,r,boarde,board);
                                if (tmp && !kings[colores].is_check(boarde)){
                                    result.push_back({i,j,k,r});
                                    turn = (-1) * turn;
                                    bool res =  find_dangerw(-color,step+1,boarde,board);
                                    if (flag == 0 && !res && step == 2){
                                        kings[0].update_pos(oldx1,oldy1);
                                        kings[1].update_pos(oldx2,oldy2);
                                        
                                        return false;
                                    }
                                    if (res && step == 3){
                                        kings[0].update_pos(oldx1,oldy1);
                                        kings[1].update_pos(oldx2,oldy2);
                                        if (result.size() > 0){
                                            result.pop_back();
                                        }
                                        flag = 1;
                                        return true;
                                    }
                                    
                                    
                                }
                                
                                kings[0].update_pos(oldx1,oldy1);
                                        kings[1].update_pos(oldx2,oldy2);
                                for (int y = 0; y < 8; y++){
                                        for (int z = 0;z < 8; z++){
                                            boarde[y][z]=tmpboard[y][z];
                                            board[y][z]=tmpboards[y][z];
                                        }
                                    }
                                
                                
                            }
                        }
                    }
                }
            }
        
        if (step == 3){
            
            flag = 0;
            if(result.size()>0){
        result.pop_back();}
            return false;
        }
        if (step == 2){
            flag = 1;
            return true;
        }
        if(result.size()>0){
        result.pop_back();}
        return false;
    }
bool chessboard::find_dangerd(int color,int step,piece boarde[8][8],string board[8][8]){
        
        //cout << result.size() << endl;
        u++;
        vector<int> ae = {1,6,2,6};
        vector<int> be = {1,5,2,5};
        
        if (result.size() > 45654 && result[0] == ae){
            cout << result.size() << endl;
            cout << "step = " << step << endl;
            //cout << kings[1].position_x << " " << kings[1].position_y << endl;
            cout << u << endl;
            for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int d = 0; d < result.size();d++){
            for (int e = 0; e < 4; e++){
                cout << result[d][e] << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------"<<endl;
        }
        
        string colors = (color == 1) ? "W" : "B";
        int colores = (color==1)?0:1;
        int oldx1 = kings[0].position_x;
        int oldy1 = kings[0].position_y;
        int oldx2 = kings[1].position_x;
        int oldy2 = kings[1].position_y;
        
        piece tmpboard[8][8];
        string tmpboards[8][8];
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
               tmpboard[i][j] = boarde[i][j];
               tmpboards[i][j] = board[i][j];
                                        }
                                    }
        if (step > 4){
            if(kings[colores].checkmate(boarde)){
                if(result.size()>0){
        result.pop_back();}
                return true;
            }
            if(result.size()>0){
        result.pop_back();}
            return false;
            
        }
        if(step == 3){
            //cout << step << endl;
            if(kings[colores].checkmate(boarde)){
                flag = 1;
                //cout << "done" << endl;
                if(result.size()>0){
                    result.pop_back();}
                return true;
            }
            
        }
        
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++) {
                    if (boarde[i][j].color == colors){
                        for(int k =0; k < 8; k++){
                            for (int r=0; r < 8; r++){        
                                bool tmp = move(boarde[i][j].type,i,j,k,r,boarde,board);
                                if (tmp && !kings[colores].is_check(boarde)){
                                    vector<int> teremp = {i,j,k,r};
                                    possiblemoves.push_back(teremp);
                                    checker.insert(pair<vector<int>,bool>({i,j},true));
                                    result.push_back({i,j,k,r});
                                    turn = (-1) * turn;
                                    bool res =  find_dangerd(-color,step+1,boarde,board);
                                    if (flag == 1 && res && step == 2 ){
                                        kings[0].update_pos(oldx1,oldy1);
                                 kings[1].update_pos(oldx2,oldy2);
                                        //cout  << result.size() << endl;
                                        return true;
                                    }
                                    
                                    
                                    if (flag == 0 && !res && step == 3){
                                        kings[0].update_pos(oldx1,oldy1);
                                        kings[1].update_pos(oldx2,oldy2);
                                        
                                        if (result.size() > 0){
                                            result.pop_back();
                                        }
                                        return false;
                                    }
                                    if (res && step == 4){
                                        kings[0].update_pos(oldx1,oldy1);
                                 kings[1].update_pos(oldx2,oldy2);
                                        if (result.size() > 0){
                                            result.pop_back();
                                        }
                                        flag = 1;
                                        return true;
                                    }
                                    
                                    
                                }
                                
                                kings[0].update_pos(oldx1,oldy1);
                                 kings[1].update_pos(oldx2,oldy2);
                                for (int y = 0; y < 8; y++){
                                        for (int z = 0;z < 8; z++){
                                            boarde[y][z]=tmpboard[y][z];
                                            board[y][z]=tmpboards[y][z];
                                        }
                                    }
                                
                                
                            }
                        }
                    }
                }
            }
        //cout << "step" << step << endl;
        if (step == 4){
            
            flag = 0;
            if(result.size()>0){
        result.pop_back();}
            return false;
        }
        if (step == 3){
            flag = 1;
            if(result.size()>0){
        result.pop_back();}
            return true;
        }
        if (step == 2){
            flag = 0;
            
           return false;
        }
        if(result.size()>0){
        result.pop_back();}
        return false;
    }
