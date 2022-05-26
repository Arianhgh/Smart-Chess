#include "board.h"
using namespace sf;
int main(){
    string colormode;
    RenderWindow window(VideoMode(800, 800), "Chess", Style::Titlebar | Style::Close);
    chessboard A(&window);
    A.run();
    int color = (colormode[0] == 'B')? -1: 1;
    return 0;
}