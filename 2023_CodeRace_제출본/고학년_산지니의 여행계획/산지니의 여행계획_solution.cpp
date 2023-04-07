#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int getParent(int num);
void unionParent(int a, int b);
bool isSameParent(int a, int b);

void dfs(int node);

void fastio();
void input();
void solution();
void output();

class Edge {
public:
    int node[2];
    int dis;
    Edge(int a, int b, int _dis) {
        node[0] = a;
        node[1] = b;
        dis = _dis;
    }
    bool operator < (const Edge& edge) {
        return dis > edge.dis;
    }
};



int N, M, S, answer = 0;

vector<Edge> edge;
vector<pair<int, int>> kruskalEdge[MAX];
int parent[MAX];

bool visited[MAX];
int v[MAX];



int getParent(int num){
    if (parent[num] == num) return num;
    return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool isSameParent(int a, int b){
    return getParent(a) == getParent(b);
}

void Kruskal(){
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < edge.size() ; i++){
        int nodeA = edge[i].node[0];
        int nodeB = edge[i].node[1];
        int dis = edge[i].dis;
        if (!isSameParent(nodeA, nodeB)){
            kruskalEdge[nodeA].push_back({nodeB, dis});
            kruskalEdge[nodeB].push_back({nodeA, dis});
            unionParent(nodeA, nodeB);
            answer += dis;
        }
    }
}

void dfs(int node){
    visited[node] = 1;
    for(auto next : kruskalEdge[node]){
        int nextNode = next.first;
        int nextDis = next.second;
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
    for (int i = 0; i < M; i++) {
        int s, e, dis;
        cin >> s >> e >> dis;
        edge.push_back(Edge(s, e, dis));
    }
    cin >> S;
}

void solution() {
    Kruskal();
    answer *= 2;
    dfs(S);
    int lastTraverse = *max_element(v+1, v+N+1);
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
