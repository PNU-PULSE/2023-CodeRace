#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

void init_arr(int tx, int ty, int x, int y, int isHalf);
void bfs(int bx, int by);
int max_prob_loc();

void fastio();
void input();
void solution();
void output();

int N, M;
int arr[MAX][MAX];

int B;
int prob[MAX][MAX][MAX];
queue<pair<int, int>> Q;
bool isEnd = false;

int result = -1;

void init_arr(int tx, int ty, int x, int y, int isHalf){

    if(arr[tx][ty] == 0){
        Q.push({tx, ty});
        arr[tx][ty] = 2;
    }

    for(int i = MAX - 1; i >= 0 + isHalf; i--){
        prob[tx][ty][i] += prob[x][y][i - isHalf];

        if(i > 0){
            prob[tx][ty][i - 1] += prob[tx][ty][i] / 2;
            prob[tx][ty][i] %= 2;
        }
    }
}

void bfs(int bx, int by){
    Q.push({bx, by});
    prob[bx][by][0] = 1;

    while (!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if(x == N - 1){
            if (!isEnd) isEnd = 1;
            continue;
        }

        if(arr[x + 1][y] != 1) init_arr(x + 1, y, x, y, 0);

        else{

            if(arr[x][y - 1] == 0 && arr[x + 1][y - 1] != 1){
                init_arr(x + 1, y - 1, x, y, 1);
            }


            if(arr[x][y + 1] == 0 && arr[x + 1][y + 1] != 1){
                init_arr(x + 1, y + 1, x, y, 1);
            }
        }
    }
}

int max_prob_loc(){
    int ans = 0;

    for(int i = 1; i < M; i++){
        for(int j = 0; j < MAX; j++){
            if(prob[N - 1][ans][j] != prob[N - 1][i][j]){
                if(prob[N - 1][ans][j] < prob[N - 1][i][j]) ans = i;
                break;
            }
        }
    }
    return ans;
}

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 2) B = j;
        }
    }
}

void solution(){
    bfs(0, B);
    if(isEnd) result = max_prob_loc();
}

void output(){
    cout << result;
}

int main(){

    fastio();
    input();
    solution();
    output();

    return 0;
}
