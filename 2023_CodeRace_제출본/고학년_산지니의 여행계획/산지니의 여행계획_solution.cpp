#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

long long getParent(long long num);
void unionParent(long long a, long long b);
bool isSameParent(long long a, long long b);

void dfs(long long node);

void fastio();
void input();
void solution();
void output();

class Edge {
public:
    long long node[2];
    long long dis;
    Edge(long long a, long long b, long long _dis) {
        node[0] = a;
        node[1] = b;
        dis = _dis;
    }
    bool operator < (const Edge& edge) {
        return dis > edge.dis;
    }
};



long long N, M, S, answer = 0;

vector<Edge> edge;
vector<pair<long long, long long>> kruskalEdge[MAX];
long long parent[MAX];

bool visited[MAX];
long long v[MAX];



long long getParent(long long num){
    if (parent[num] == num) return num;
    return parent[num] = getParent(parent[num]);
}

void unionParent(long long a, long long b){
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool isSameParent(long long a, long long b){
    return getParent(a) == getParent(b);
}

void Kruskal(){
    sort(edge.begin(), edge.end());
    for (long long i = 1; i <= N; i++) {
        parent[i] = i;
    }
    long long sum = 0;
    for (long long i = 0; i < edge.size() ; i++){
        long long nodeA = edge[i].node[0];
        long long nodeB = edge[i].node[1];
        long long dis = edge[i].dis;
        if (!isSameParent(nodeA, nodeB)){
            kruskalEdge[nodeA].push_back({nodeB, dis});
            kruskalEdge[nodeB].push_back({nodeA, dis});
            unionParent(nodeA, nodeB);
            answer += dis;
        }
    }
}

void dfs(long long node){
    visited[node] = 1;
    for(auto next : kruskalEdge[node]){
        long long nextNode = next.first;
        long long nextDis = next.second;
        if(visited[nextNode]) continue;
        v[nextNode] += nextDis + v[node];
        dfs(nextNode);
    }
}

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    cin >> N >> M;
    for (long long i = 0; i < M; i++) {
        long long s, e, dis;
        cin >> s >> e >> dis;
        edge.push_back(Edge(s, e, dis));
    }
    cin >> S;
}

void solution() {
    Kruskal();
    answer *= 2;
    dfs(S);
    long long lastTraverse = *max_element(v+1, v+N+1);
    answer -= lastTraverse;
}

void output(){
    cout << answer;
}

int main() {

    fastio();
    input();
    solution();
    output();

    return 0;
}
