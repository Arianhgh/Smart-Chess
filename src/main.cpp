#include "board.h"
using namespace sf;
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