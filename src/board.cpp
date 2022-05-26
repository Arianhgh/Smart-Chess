#include "board.h"
void chessboard::clickmanager(sf::Vector2i position){
    int row = position.y / 100;
    int col = position.x / 100;
    if (row > 7 || col > 7) return;
    if (board[row][col] != "--"){
    //uichess[row][col].cellul.setFillColor(sf::Color::Yellow);

    }

}
void chessboard::drawboard(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            window->draw(uichess[i][j].cellul);
            if (board[i][j] != "--"){
                window->draw(interboard[i][j].spirite);
            }
        }
    }
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
    }
    e *= -1;
    }
    font.loadFromFile("textures/arial.ttf");
    status.setFont(font);
    status.setCharacterSize(30);
    status.setStyle(sf::Text::Regular);
    status.setFillColor(sf::Color::Black);
    status.setPosition(sf::Vector2f(320,320));
    update_status();
}
void chessboard::update_status(){
    status.setString("HELLO");
}
void chessboard::fill_board(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
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
        window->clear(sf::Color::Red);
        drawboard();
        update_status();
        window->display();

    }
}
bool chessboard::move(string type,int startx,int starty,int endx,int endy,piece interboard[8][8],string boarde[8][8]){
        piece empty;
        if (type == "P"){
            if (interboard[startx][starty].is_valid_pawn(startx,starty,endx,endy,interboard)){
                interboard[endx][endy] = interboard[startx][starty];
                interboard[startx][starty] = empty;
                boarde[endx][endy] = boarde[startx][starty];
                boarde[startx][starty] = "--";
                interboard[endx][endy].position_x = endx;
                interboard[endx][endy].position_y = endy;
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
                                if (step == 1){
                        result.clear();
                        flag = 0;
                    }           
                                bool tmp = move(boarde[i][j].type,i,j,k,r,boarde,board);
                                if (tmp && !kings[colores].is_check(boarde)){
                                    if (step == 1){
                                    vector<int> teremp = {i,j,k,r};
                                    possiblemoves.push_back(teremp);
                                    checker.insert(pair<vector<int>,bool>({i,j},true));
                                }
                                    result.push_back({i,j,k,r});
                                    turn = (-1) * turn;
                                    bool res =  find_dangerw(-color,step+1,boarde,board);
                                    
                                    if (res && result.size() >= 1 && step == 1 && flag == 1){
                                       //for (int s = 0; s < 4; s++){
                                          // cout << result[0][s] << " ";
                                     // }
                                      results.push_back(result[0]);
                                       // cout << endl;
                                    }
                                    else if (!res && step == 1){
                                        checker.at({i,j}) = false;
                                    }
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
        vector<int> ae = {0,4,0,5};
        vector<int> be = {1,5,2,5};
        
        if (result.size() > 23456 && u >= 1910 && u <= 1916){
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
                                if (step == 1){
                        result.clear();
                        flag = 0;
                    }           
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
                                    if (res && result.size() >= 1 && step == 1 && flag == 1){
                                        //for (int s = 0; s < 4; s++){
                                           //cout << result[0][s] << " ";
                                     // }
                                        //cout << endl;
                                        results.push_back(result[0]);
                                    }
                                    else if (!res && step == 1){
                                        checker.at({i,j}) = false;
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