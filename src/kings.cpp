#include "kings.h"
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
