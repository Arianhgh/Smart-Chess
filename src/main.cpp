#include "board.h"
int main(){
    string colormode;
    cin >> colormode;
    string converted[8]={"a", "b", "c", "d", "e", "f","g","h"};
    chessboard A;
    A.fill_board();
    int color = (colormode[0] == 'B')? -1: 1;
    if (colormode[1] == 'M'){
    A.find_dangerw(color,1,A.interboard,A.board);}
    else{
        A.find_dangerd(color,1,A.interboard,A.board);
    }
    if (A.results.size()>0) {
    int flagx = 0;
    vector<int> tmp = A.results[0];
    for (int i=0; i<A.results.size(); i++){
        int a = A.results[i][0];
        int b = A.results[i][1];
        int c = A.results[i][2];
        int d = A.results[i][3];
        if (A.checker.at({a, b}) == 1){
            A.finalresults.push_back(converted[b]+to_string(abs(a-8))+A.board[a][b]);
            flagx =1;
            int j = i+1;
            while (j < A.results.size() && A.results[j][0] == a && A.results[j][1] == b){
                j++;
            }
            i = j-1;
        }
        else if (A.checker.at({a, b}) == 0){
            A.finalresults.push_back(converted[b]+to_string(abs(a-8))+A.board[a][b] +converted[d]+to_string(abs(c-8)));
        }
    }
    for (int i = 0; i < A.finalresults.size()-1; i++){
        for (int j = i; j < A.finalresults.size(); j++){
            if (A.finalresults[i] > A.finalresults[j]){
                string tmpe = A.finalresults[j];
                A.finalresults[j] = A.finalresults[i];
                A.finalresults[i]=tmpe;
            }
        }
    }
    for (int i = 0; i < A.finalresults.size(); i++){
        cout << A.finalresults[i] << endl;
    }
    }
    else{
        cout <<"No Answer!";
    }
    return 0;
}