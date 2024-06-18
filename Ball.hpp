#include<iostream>
using namespace std;
enum Dir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
class Ball {
private:
    int x, y;
    int originalX, originalY;
    Dir direction;
public:
    Ball(int posX, int posY) {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }
    void reset() {
        x = originalX;
        y = originalY;
        direction = STOP;
    }
    void changeDirection(Dir d) {
        direction = d;
    }
    void random() {
        direction = (Dir)((rand() % 6) + 1);
    }
    inline int getX() {
        return x;
    }
    inline int getY() {
        return y;
    }
    inline Dir getDirection() {
        return direction;
    }
    void Move() {
        switch (direction) {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            y--;
            x--;
            break;
        case UPRIGHT:
            y--;
            x++;
            break;
        case DOWNRIGHT:
            y++;
            x++;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        default:
            break;
        }
    }
    friend ostream& operator <<(ostream & o, Ball c);
};

ostream& operator<<(ostream& o, Ball c)
{
    o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
    return o;
}
