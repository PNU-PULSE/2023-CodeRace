#include <iostream>
#define MAX 1000001
#define QUERY_MAX 100001

using namespace std;

void fastio();
void input();
void solution();
void output();

int N, Q;

int imos[MAX];
int prefix[MAX];
int query[QUERY_MAX];

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N;
    for(int i = 0;i < N;i++){
        int a, b;
        cin >> a >> b;
        imos[a] += 1;
        imos[b+1] -= 1;
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> query[i];
    }
}

void solution() {
    for(int i = 1;i < MAX;i++) {
        prefix[i] = prefix[i-1]+imos[i];
    }
}

void output(){
    for(int i = 0; i < Q; i++){
        cout << prefix[query[i]] << "\n";
    }
}

int main() {

    fastio();
    input();
    solution();
    output();

    return 0 ;
}
