#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

char map[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct POINT {
    int y;
    int x;
}Point;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    queue<Point> q;
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1c", &map[i][j]);
            if (map[i][j] == '.') map[i][j] = 'D';
            else if (map[i][j] == 'W') q.push({ i,j });
        }
    }
    while (q.empty() == false) {
        Point t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (map[ny][nx] == 'S') {
                printf("0\n");
                return 0;
            }
        }
    }
    printf("1\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
