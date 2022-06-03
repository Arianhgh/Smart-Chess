#include "piece.h"
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