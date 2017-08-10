#include <iostream>
#include <cassert>

#define CHARACTER '*'
#define WALL 'W'
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

char map[MAP_WIDTH][MAP_HEIGHT] = {{}};

using namespace std;


int x = 0;
int y = 0;


void ShowMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void SpawnHero(void) {
    x = rand() % 9 + 1;
    y = rand() % 9 + 1;
    map[x][y] = CHARACTER;
}

void MoveHero(char *a, char *b) {

    if (*b == WALL) {
        //assert(false);
        return;
    } else {
        char tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }


}

//memset( n2dArray[ hi ], 0, sizeof( int ) * m_width );
//[출처] memset()을 이용한 다차원(2차, 3차, ...) 배열 초기화|작성자 guntae01
void initWall() {
    for (int i = 0; i < 10; i++)
        memset(map[i], '.', sizeof(char) * 10);
}

void WallIdx() {
    int r = rand() % 10 + 1;
    for (int i = 0; i < r; i++) {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        map[x][y] = WALL;
    }

}

int main() {
    std::cout << CHARACTER << std::endl;
    initWall();
    srand(time(0));
    WallIdx();
    SpawnHero();


    while (true) {
        ShowMap();
        char command;
        cin >> command;

        cout << command << endl;

        switch (command) {
            case 'a':
                MoveHero(&(map[abs(x)%10][abs(y)%10]), &(map[abs(x)%10][abs(y-1)%10]));
                y--;
                break;
            case 's':
                MoveHero(&(map[abs(x)%10][abs(y)%10]), &(map[abs(x+1)%10][abs(y)%10]));
                x++;
                break;
            case 'd':
                MoveHero(&(map[abs(x)%10][abs(y)%10]), &(map[x][abs(y)%10+1]));
                y++;
                break;
            case 'w':
                MoveHero(&(map[abs(x)%10][abs(y)%10]), &(map[abs(x-1)%10][abs(y)%10]));
                x--;
                break;
            case 'x':
                return 0;

            default:
                break;
        }
    }
}