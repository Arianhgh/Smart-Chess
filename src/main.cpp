#include "board.h"
using namespace sf;
int main(){
    cout << "how do you want to input the board?\n1.clipboard\n2.by hand\n";
    int input;
    cin >> input;
    RenderWindow window(VideoMode(1200, 800), "Chess", Style::Titlebar | Style::Close);
    chessboard A(&window,input);
    A.run();
    return 0;
}