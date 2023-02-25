```c++

#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, a, b) for (int i=a; i<=b; i++) 

using namespace std;
int N, M;
#define MAX 1003
int matrix[MAX][MAX] {};
int memo[MAX][MAX] {};
void Solve() {
    cin >> N >> M;
    rep(i,1,N) {
        rep(j,1,M) {
            cin >> matrix[i][j];
            if(matrix[i][j]==2) memo[1][j] = 1;
        }
    }

    rep(i,1,N-1) {
        rep(j,1,M) {
            if(memo[i][j]==0) continue;

            if(matrix[i+1][j]) {
                if(matrix[i][j-1]==0 && matrix[i+1][j-1]==0) {
                    memo[i+1][j-1] += memo[i][j];
                }
                if(matrix[i][j+1]==0 && matrix[i+1][j+1]==0) {
                    memo[i+1][j+1] += memo[i][j];
                }
            }
            else {
                memo[i+1][j] = memo[i][j];
            }
        }
    }
    int mx = 0;
    int idx = -1;
    rep(i,1,M) {
        if(mx < memo[N][i]) {
            mx = memo[N][i];
            idx = i-1;
        }
    }
    cout << idx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
```
구현

