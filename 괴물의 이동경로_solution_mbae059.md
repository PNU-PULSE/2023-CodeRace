# 풀이

```
#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, a, b) for (int i=a; i<=b; i++) 
using namespace std;
using pii = pair<int, int>;
int N, M;
int dir[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};
#define MAX 1001
int matrix[MAX][MAX] {};
int building[MAX][MAX] {};
int wall[MAX][MAX] {};
bool inRange(int y, int x){
    return 1<=y && y<=N && 1<=x && x<=M;
}

pii monster;
void SearchFrom(queue<pii> &q, int memo[MAX][MAX]) { // bfs from the building and wall
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if(y==monster.first && x==monster.second) {
            cout << memo[y][x]; //when monster is found. print answer
            exit(0);
        }
        rep(i,0,3) {
            int nexty = y+dir[i][0];
            int nextx = x+dir[i][1];
            if(!inRange(nexty, nextx)) continue;

            if((matrix[nexty][nextx]==3 || matrix[nexty][nextx]==0) && memo[nexty][nextx]!=-1) {
                memo[nexty][nextx] = memo[y][x] + 1;
                q.push({nexty,nextx});
            }
        }
    }
}

void Solve() {
    cin >> N >> M;

    rep(i,1,N) {
        rep(j,1,M) {
            building[i][j] = -1;
            wall[i][j] = -1;
        }
    }
    queue<pii> qBuilding, qWall;
    rep(i,1,N) {
        rep(j,1,M) {
            cin >> matrix[i][j];
            if(matrix[i][j]==2) {
                qBuilding.push({i,j});
                building[i][j] = 0;
            }
            else if(matrix[i][j]==1) {
                qWall.push({i,j});
                wall[i][j] = 0;
            }
            else if(matrix[i][j]==3) {
                monster = make_pair(i,j);
            }
        }
    }
    SearchFrom(qBuilding, building); //bfs from building
    SearchFrom(qWall, wall); //if not found from building, find it from wall

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
```

빌딩에서 bfs.
안되면 벽에서 bfs로 괴물의 위치를 찾아 리턴하였습니다
