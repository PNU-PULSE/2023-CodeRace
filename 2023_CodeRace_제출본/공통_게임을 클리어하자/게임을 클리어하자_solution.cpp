#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 987654321

using namespace std;

void fastio();
void input();
void solution();
void output();

int N,M;

int matrix[MAX][MAX];
int dp[MAX][MAX];

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> matrix[i][j];
        }
    }
}

void solution(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = INF;
            for(int k = 1; k <= M; k++){
                if(j == k) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k]+matrix[i][j]);
            }
        }
    }
}

void output(){
    cout << *min_element(dp[N]+1, dp[N]+M+1);
}

int main(){

    fastio();
    input();
    solution();
    output();

    return 0;
}
