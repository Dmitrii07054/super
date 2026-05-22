#ifndef GAME_HPP
#define GAME_HPP

#include "MovingObject.hpp"

class Game {
private:
    static const int MAP_HEIGHT = 25;
    static const int MAP_WIDTH = 80;
    
    char map[MAP_HEIGHT][MAP_WIDTH + 1];
    
    MovingObject* mario;
    Brick* bricks;
    int brickCount;
    MovingObject* movingObjects;
    int movingCount;
    
    int score;
    int level;
    int maxLevel;
    
    void clearMap();
    void showMap();
    void setCur(int x, int y);
    void putScoreOnMap();
    void putObjectOnMap(GameObject& obj);
    void putBrickOnMap(Brick& obj);
    bool isPosInMap(int x, int y);
    
    void horizonMoveMap(float dx);
    void createLevel();
    void playerDead();
    
public:
    Game();
    ~Game();
    void run();
};

#endif
