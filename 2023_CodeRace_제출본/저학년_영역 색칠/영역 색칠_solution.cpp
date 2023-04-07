#include <iostream>
#define MAX 101

using namespace std;

void fastio();
void input();
void solution();
void output();

int N, M, pic[MAX][MAX], result;

void fastio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> pic[i][j];
        }
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        int cnt[2] = {pic[i][0] == 1, pic[i][0] == 2};

        for (int j = 1; j < M; j++) {
            if (pic[i][j - 1] != pic[i][j]) {
                if (pic[i][j] != 0) {
                    cnt[pic[i][j] - 1]++;
                }
                else {
                    result += min(cnt[0], cnt[1]) + 1;
                    cnt[0] = 0;
                    cnt[1] = 0;
                }
            }
        }
        if (max(cnt[0], cnt[1]) != 0) {
            result += min(cnt[0], cnt[1]) + 1;
        }
    }
}

void output() {
    cout << result;
}

int main() {

    fastio();
    input();
    solution();
    output();

    return 0;
}
