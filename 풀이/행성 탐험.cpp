# 풀이
```
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 
#define all(v) (v).begin(), (v).end()

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii> ;
int T, N, K, M, S, H, W, Q;


#define MAX 500001
vvi SCC;
int d[MAX];
bool finished[MAX];
vpii edge[MAX];
int id, SN; //mark sn[i]
stack<int> s;
int sn[MAX]; //sn[i] is SCC number to which it belongs to. If sn is big, then it is at the start of DAG. If small, it is at the end of DAG. If one wants to start from the beginning of DAG, start from the largest of sn.
int SCCnode[MAX] {}; //if SCCbfs is needed...
int nodeValue[MAX] {}; //if SCCbfs is needed...
int dfs(int x) {
    d[x] = ++id; //노드마다 고유한 아이디 부여
    s.push(x); //스택에 자기 자신을 삽입
    int parent = d[x];
    for (auto next : edge[x]) {
		int nextNode = next.first;
        if (d[nextNode] == 0) { //방문 안 한 이웃
            parent = min(parent, dfs(nextNode));
        }
        else if (finished[nextNode] == 0) { //처리 중인 이웃
            parent = min(parent, d[nextNode]);
        }
    }
    if (parent == d[x]) {
        vector<int> scc;
        while (true) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = 1;
            sn[t] = SN;
            //d[t] = x; //to make scc recognizable with d
            //SCCnode[SN] += nodeValue[t];
            if (t == x) break;
        }
        SN++;
        SCC.push_back(scc); //SCC의 SN번째 그래프랑 대응된다
    }
    return parent;
}

vpii SCCedge[MAX]; //index refers to SN. Could be replaced with set if you don't want to overlap
int inDegree[MAX]; //index refers to SN
void SCCtopology_sort() {
    for(int i=1;i<=N;i++) { //id starts with 1
        for(auto next : edge[i]) {
			int nextNode = next.first;
			int dist = next.second;
            if(sn[nextNode]!=sn[i]) {
                SCCedge[sn[i]].pbk({sn[nextNode], dist}); //SN could be overlapped. Could be solved with set but it is often not needed
            }
        }
    }
}
int d[MAX];
struct cmp {
    bool operator() (const pii& i, const pii& j) {
        return i.second > j.second;
    }
};
int SCCdp[MAX] {};
void SCCdijkstra(int x) { 
	p_q<pii, vpii, cmp> pq;
    pq.push({ x, 0 });
    fill(d + 1, d + 1 + N, INF); //INF could be larger, varying from problem to problem
    d[x] = 0;
    while (!pq.empty()) {
        int cur = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        if(d[cur] < dis) continue; //could be used if d[cur] has been updated more than once.
        for (auto next : SCCedge[cur]) {
            if(d[next.first] > d[cur] + next.second) {
                d[next.first] = d[cur]+next.second;
                pq.push({next.first, d[next.first]});
            }
        }
    }
}

void Solve() {
	cin >> N >> M;

	rep(i,1,M) {
		int a, b;
		cin >> a >> b >> T;
		edge[a].pbk({b,T});
	}
	cin >> S >> T;
	rep(i,1,N) {
		if(d[i]==0) dfs(i);
	}
	SCCtopology_sort();

	int SCCstart = sn[S];
	int SCCend = sn[T];

	SCCdijkstra(SCCstart);
	cout << d[SCCend];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
```

SCC + dijkstra

풀다가 union-find로 풀 수 있을 것 같긴한데 N 제한 때문에 안될 것 같기도 합니다.

