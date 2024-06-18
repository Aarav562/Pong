#include<iostream>
using namespace std;
class Paddle{
    private:
    int x,y;
    int originalX,originalY;
    public:
    Paddle(){
        x=0;
        y=0;
    }
    Paddle(int posx,int posy):Paddle(){
        originalX = posx;
        originalY = posy;
        x = posx;
        y = posy;
    }
    inline void reset(){
        x = originalX;
        y = originalY;
    }
    inline int getX(){
        return x;
    }
    inline int getY(){
        return y;
    }
    inline void moveUp(){
        y++;
    }
    inline void moveDown(){
        y--;
    }
    friend ostream & operator<<(ostream &o,const Paddle &c);
};
ostream & operator<<(ostream& o,const Paddle& c){
    o << "Paddle ["<< c.x <<","<<c.y<<"]";
    return o;
}
