#sound_vortex 풀이

문제 분류 : 트리 (dp?), bruteforce?
```c++

#include <bits/stdc++.h>
#define endl '\n'
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 

using namespace std;
using vi = vector<int>;
//솔루션. 트리(dp?), bruteforce
#define MAX 100003
int N, W;
vi edge[MAX];
bool visited[MAX] {};
vi v;

int dfs(int node, int w) { //트리를 순회하면서 각 정점에서 시작하였을 때의 소리가 나는 정점의 수를 구한다
    visited[node] = 1; //기본 visited 
    int mxVertex = 1; //자신의 서브트리에서 돌아다닐 수 있는 최대 정점 수
    if(w-v[node]<=0) return mxVertex; //만약 자신에서 다른노드로 넘어갈 때 진동이 모두 다 감쇠되면 자신만 리턴
    for(auto next : edge[node]) {
        if(visited[next]) continue; //visited한적 있으면 넘어감
        mxVertex += dfs(next, w-v[node]); //서브트리의 노드 합산
    }
    return mxVertex;
}
void Solve() {
    cin >> N;
    v.resize(N+1);
    rep(i,1,N) cin >> v[i]; //1부터 N까지 정점의 재질을 받음

    rep(i,1,N-1) { //트리 입력받음
        int a, b; cin >> a >> b;
        edge[a].pbk(b);
        edge[b].pbk(a);
    }

    cin >> W;
    int mx = 0;
    rep(i,1,N) {
        memset(visited, 0, sizeof(visited));
        mx = max(mx, dfs(i, W)); //i에서 시작하였을 때의 소리나는 정점 수
    }
    
    cout << mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
```

N에 bruteforce로 풀 수 있을 만큼이라고 적혀있어서 bruteforce로 풀어봤습니다. 이게 의도한 바인지는 잘 모르겠습니다...
