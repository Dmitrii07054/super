#include "Game.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <windows.h>

const int Game::MAP_HEIGHT;
const int Game::MAP_WIDTH;

Game::Game() 
    : mario(nullptr), bricks(nullptr), brickCount(0), 
      movingObjects(nullptr), movingCount(0), score(0), level(1), maxLevel(3) {
    createLevel();
}

Game::~Game() {
    delete mario;
    delete[] bricks;
    delete[] movingObjects;
}

void Game::clearMap() {
    for (int i = 0; i < MAP_WIDTH; i++)
        map[0][i] = ' ';
    map[0][MAP_WIDTH] = '\0';
    for (int j = 1; j < MAP_HEIGHT; j++)
        sprintf(map[j], map[0]);
}

void Game::showMap() {
    for (int j = 0; j < MAP_HEIGHT; j++)
        printf("%.80s\n", map[j]);
}

void Game::setCur(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool Game::isPosInMap(int x, int y) {
    return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT);
}

void Game::putObjectOnMap(GameObject& obj) {
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);

    for (int i = ix; i < ix + iWidth; i++) {
        for (int j = iy; j < iy + iHeight; j++) {
            if (isPosInMap(i, j))
                map[j][i] = (char)obj.cType;
        }
    }
}

void Game::putBrickOnMap(Brick& obj) {
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);

    for (int i = ix; i < ix + iWidth; i++) {
        for (int j = iy; j < iy + iHeight; j++) {
            if (isPosInMap(i, j))
                map[j][i] = (char)obj.cType;
        }
    }
}

void Game::putScoreOnMap() {
    char c[30];
    sprintf(c, "Score: %d", score);
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        map[1][i + 5] = c[i];
    }
}

static bool isCollisionMovingBrick(MovingObject& o1, Brick& o2) {
    return (o1.x + o1.width > o2.x) && (o1.x < o2.x + o2.width) &&
           (o1.y + o1.height > o2.y) && (o1.y < o2.y + o2.height);
}

static bool isCollisionMovingMoving(MovingObject& o1, MovingObject& o2) {
    return (o1.x + o1.width > o2.x) && (o1.x < o2.x + o2.width) &&
           (o1.y + o1.height > o2.y) && (o1.y < o2.y + o2.height);
}

void Game::horizonMoveMap(float dx) {
    mario->x -= dx;
    for (int i = 0; i < brickCount; i++) {
        if (isCollisionMovingBrick(*mario, bricks[i])) {
            mario->x += dx;
            return;
        }
    }
    mario->x += dx;

    for (int i = 0; i < brickCount; i++)
        bricks[i].x += dx;
    for (int i = 0; i < movingCount; i++)
        movingObjects[i].x += dx;
}

void Game::playerDead() {
    system("color 4F");
    Sleep(500);
    createLevel();
}

void Game::createLevel() {
    system("color 9F");
    
    delete mario;
    delete[] bricks;
    delete[] movingObjects;
    
    brickCount = 0;
    movingCount = 0;
    
    bricks = new Brick[100];
    movingObjects = new MovingObject[50];
    
    mario = new MovingObject(39, 10, 3, 3, ObjectType::MARIO);
    score = 0;
    
    switch (level) {
        case 1:
            bricks[brickCount++] = Brick(20, 20, 40, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(30, 10, 5, 3, ObjectType::BRICK_QUESTION);
            bricks[brickCount++] = Brick(50, 10, 5, 3, ObjectType::BRICK_QUESTION);
            bricks[brickCount++] = Brick(60, 15, 40, 10, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(60, 5, 10, 3, ObjectType::BRICK_EMPTY);
            bricks[brickCount++] = Brick(70, 5, 5, 3, ObjectType::BRICK_QUESTION);
            bricks[brickCount++] = Brick(75, 5, 5, 3, ObjectType::BRICK_EMPTY);
            bricks[brickCount++] = Brick(80, 5, 5, 3, ObjectType::BRICK_QUESTION);
            bricks[brickCount++] = Brick(85, 5, 10, 3, ObjectType::BRICK_EMPTY);bricks[brickCount++] = Brick(100, 20, 20, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(120, 15, 10, 10, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(150, 20, 40, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(210, 15, 10, 10, ObjectType::BRICK_FINISH);
            
            movingObjects[movingCount++] = MovingObject(25, 18, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(80, 18, 3, 2, ObjectType::ENEMY);
            break;
            
        case 2:
            bricks[brickCount++] = Brick(20, 20, 40, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(60, 15, 10, 10, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(80, 20, 20, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(120, 15, 10, 10, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(150, 20, 40, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(210, 15, 10, 10, ObjectType::BRICK_FINISH);
            
            movingObjects[movingCount++] = MovingObject(25, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(80, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(65, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(120, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(160, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(175, 10, 3, 2, ObjectType::ENEMY);
            break;
            
        case 3:
            bricks[brickCount++] = Brick(20, 20, 40, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(80, 15, 10, 10, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(120, 20, 20, 5, ObjectType::BRICK_NORMAL);
            bricks[brickCount++] = Brick(160, 15, 10, 10, ObjectType::BRICK_FINISH);
            
            movingObjects[movingCount++] = MovingObject(25, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(50, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(80, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(90, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(120, 10, 3, 2, ObjectType::ENEMY);
            movingObjects[movingCount++] = MovingObject(130, 10, 3, 2, ObjectType::ENEMY);
            break;
    }
}

void Game::run() {
    do {
        clearMap();
        
        if (!mario->IsFly && GetKeyState(VK_SPACE) < 0)
            mario->vertSpeed = -1.55f;
        if (GetKeyState('A') < 0)
            horizonMoveMap(2.5f);
        if (GetKeyState('D') < 0)
            horizonMoveMap(-2.5f);
        
        if (mario->y > MAP_HEIGHT)
            playerDead();
        
        mario->IsFly = TRUE;
        mario->vertSpeed += MovingObject::GRAVITY;
        mario->y += mario->vertSpeed;
        
        for (int i = 0; i < brickCount; i++) {
            if (isCollisionMovingBrick(*mario, bricks[i])) {
                if (mario->vertSpeed > 0)
                    mario->IsFly = FALSE;
                
                if (bricks[i].cType == ObjectType::BRICK_QUESTION && mario->vertSpeed < 0) {
                    bricks[i].cType = ObjectType::BRICK_EMPTY;
                    MovingObject* newMoving = new MovingObject[movingCount + 1];
                    for (int j = 0; j < movingCount; j++)
                        newMoving[j] = movingObjects[j];
                    delete[] movingObjects;
                    movingObjects = newMoving;
                    
                    movingObjects[movingCount] = MovingObject(bricks[i].x, bricks[i].y - 3, 3, 2, ObjectType::COIN);movingObjects[movingCount].vertSpeed = -0.7f;
                    movingCount++;
                }
                
                mario->y -= mario->vertSpeed;
                mario->vertSpeed = 0;
                
                if (bricks[i].cType == ObjectType::BRICK_FINISH) {
                    level++;
                    if (level > maxLevel) level = 1;
                    system("color 2F");
                    Sleep(500);
                    createLevel();
                }
                break;
            }
        }
        
        for (int i = 0; i < movingCount; i++) {
            if (isCollisionMovingMoving(*mario, movingObjects[i])) {
                if (movingObjects[i].cType == ObjectType::ENEMY) {
                    if (mario->IsFly && mario->vertSpeed > 0 &&
                        mario->y + mario->height < movingObjects[i].y + movingObjects[i].height * 0.5f) {
                        score += 50;
                        movingCount--;
                        movingObjects[i] = movingObjects[movingCount];
                        i--;
                        continue;
                    } else {
                        playerDead();
                    }
                }
                
                if (movingObjects[i].cType == ObjectType::COIN) {
                    score += 100;
                    movingCount--;
                    movingObjects[i] = movingObjects[movingCount];
                    i--;
                    continue;
                }
            }
        }
        
        for (int i = 0; i < brickCount; i++)
            putBrickOnMap(bricks[i]);
        
        for (int i = 0; i < movingCount; i++) {
			movingObjects[i].IsFly = TRUE;
			movingObjects[i].vertSpeed += MovingObject::GRAVITY;
			movingObjects[i].y += movingObjects[i].vertSpeed;
			
			for (int j = 0; j < brickCount; j++) {
				if (isCollisionMovingBrick(movingObjects[i], bricks[j])) {
					if (movingObjects[i].vertSpeed > 0) {
						movingObjects[i].y -= movingObjects[i].vertSpeed;
						movingObjects[i].vertSpeed = 0;
						movingObjects[i].IsFly = FALSE;
					}
					break;
				}
			}
			
			if (!movingObjects[i].IsFly) {
				float nextX = movingObjects[i].x + movingObjects[i].horizSpeed;
				float footY = movingObjects[i].y + movingObjects[i].height;
				bool hasGroundAhead = false;
				
				for (int j = 0; j < brickCount; j++) {
					if (nextX + movingObjects[i].width > bricks[j].x &&
						nextX < bricks[j].x + bricks[j].width &&
						footY + 1 > bricks[j].y && footY - 3 < bricks[j].y) {
						hasGroundAhead = true;
						break;
					}
				}
				
				if (!hasGroundAhead) {
					movingObjects[i].horizSpeed = -movingObjects[i].horizSpeed;
				} else {
					movingObjects[i].x = nextX;
				}
				
				for (int j = 0; j < brickCount; j++) {
					if (isCollisionMovingBrick(movingObjects[i], bricks[j])) {
						movingObjects[i].x -= movingObjects[i].horizSpeed;
						movingObjects[i].horizSpeed = -movingObjects[i].horizSpeed;
						break;
					}
				}
			}
			
			if (movingObjects[i].y > MAP_HEIGHT) {
				movingCount--;
				movingObjects[i] = movingObjects[movingCount];
				i--;
				continue;
			}
			putObjectOnMap(movingObjects[i]);
		}
        
        putObjectOnMap(*mario);
        putScoreOnMap();
        
        setCur(0, 0);
        showMap();
        
        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);
}
