#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void fastio();
void input();
void solution();
void output();

struct Data{
    int a, b, c;
    Data(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend bool operator<(Data d1, Data d2){
        if (d1.c > d2.c) return true;
        return false;
    }
};

int N, T;
priority_queue<Data> pq;
priority_queue<int, vector<int>, greater<int>> answer;

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void input(){
    int a, b, c;
    cin >> N >> T;
    for(int i = 0; i < N; ++i){
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }
}

void solution(){
    Data top = pq.top();
    int pre_road = top.a;
    int pre_time = top.c;
    pq.pop();

    while(!pq.empty()){
        top = pq.top();

        if(top.c - pre_time < T) answer.push(top.b);
        else if (top.c - pre_time == T && pre_road == top.a) answer.push(top.b);

        pre_road = top.a;
        pre_time = top.c;
        pq.pop();
    }
}

void output(){
    if(answer.empty()) cout << -1;

    while(!answer.empty()){
        cout << answer.top() << "\n";
        answer.pop();
    }
}

int main(){

    fastio();
    input();
    solution();
    output();

    return 0;
}
