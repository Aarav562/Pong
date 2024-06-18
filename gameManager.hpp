#include<iostream>
#include<conio.h>
#include<time.h>
#include"Ball.hpp"
#include"Paddle.hpp"
using namespace std;
class gameManager{
    private:
    int width, height;
    int score1,score2;
    bool quit;
    char up1,down1,up2,down2;
    Ball *ball;
    Paddle *player1;
    Paddle *player2;
    public:
    gameManager(int w, int h){
        srand(time(NULL));
        quit = false;
        up1 ='w';
        down1 = 's';
        up2 = 'i';
        down2 = 'k';
        width = w;
        height = h;
        score1=score2=0;
        ball = new Ball(w/2,h/2);
        player1 = new Paddle(1,h/2-3);
        player2 = new Paddle(w-2,h/2-3);
    }
    ~gameManager(){
        delete ball,player1,player2;
    }
    void scoreUP(Paddle *player){
        if(player==player1)
            score1++;
        else if(player==player2)
            score2++;

        ball->reset();
        player1->reset();
        player2->reset();
    }
    void draw(){
        system("cls");
        for(int i=0;i<width +2 ;i++){
            cout<<"\xB2";
        }
        cout<<endl;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player1y = player1->getY();
                int player2x = player2->getX();
                int player2y = player2->getY();

                if(j==0)
                    cout<<"\xB2";
                
                if(ballx==j && bally==i)
                    cout<<"O";
                else if(player1x==j && player1y == i)
                    cout<<"\xDB";
                else if(player2x == j && player2y == i)
                    cout<<"\xDB";
                else if(player1x == j && player1y +1 ==i)
                    cout<<"\xDB";
                else if(player1x == j && player1y +2 ==i)
                    cout<<"\xDB";
                else if(player1x == j && player1y +3 ==i)
                    cout<<"\xDB";
                else if(player2x==j && player2y+ 1 ==i)
                    cout<<"\xDB";
                else if(player2x==j && player2y+ 2 ==i)
                    cout<<"\xDB";
                else if(player2x==j && player2y+ 3 ==i)
                    cout<<"\xDB";
                else
                    cout<<" ";

                if(j==width-1){
                    cout<<"\xB2";
                }
                cout<<endl;
            }
        }
        for(int i=0;i<width+2;i++){
            cout<<"\xB2";
        }
        cout<<endl;

        cout<<"Score1: "<<score1<<"  "<<"Score2:  "<<score2<<endl;
    }
    void input(){
        ball->Move();
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player1y = player1->getY();
        int player2x = player2->getX();
        int player2y = player2->getY();

        if(_kbhit()){
            char current = _getch();
            if(current == up1 && player1y>0){
                player1->moveUp();
            }
            else if(current == down1 && player1y + 4 < height){
                player1->moveDown();
            }
            else if(current == up2 && player2y>0){
                player2->moveUp();
            }
            else if(current==down2 && player2y + 4 < height){
                player2->moveDown();
            }
            else if(current = 'q'){
                quit = true;
            }
        }
    }
    void game(){
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player1y = player1->getY();
        int player2x = player2->getX();
        int player2y = player2->getY();

        for(int i=0;i<4;i++){
            if(ballx == player1x +1 && bally == player1y + i)
                ball->changeDirection((Dir)((rand()% 3)+4));
        }
        for(int i=0;i<4;i++){
            if(ballx == player2x -1 && bally ==player2y + i)
                ball->changeDirection((Dir)((rand()%3)+1));
        }

        if(bally == height -1)
            ball->changeDirection(ball->getDirection()==DOWNRIGHT ? UPRIGHT : UPLEFT);
        if(bally == 0)
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

        if(ballx == width-1){
            scoreUP(player1);
        }
        if(ballx == 0){
            scoreUp(player2);
        }
    }

    void run(){
        while(!quit){
            draw();
            input();
            game();
        }
    }

};