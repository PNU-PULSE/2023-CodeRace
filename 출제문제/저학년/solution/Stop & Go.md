# 풀이

사용 알고리즘 : priority queue<br>
백준 예상티어 : 실버 1~2

```c++
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

using pii = pair<int, int>;

struct Data{
    int a, b, c;
    Data(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend bool operator<(Data d1, Data d2) {
        if (d1.c > d2.c) {
            return true;
        }
        return false;
    }
};
int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //ifstream in("generate_random.inp");

    int N, t;
    cin >> N >> t;
    //in >> N >> t;

    priority_queue<Data> pq;
    priority_queue<int, vector<int>, greater<int>> res; // 값 저장

    char a;
    int b, c;

    for(int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        //in >> a >> b >> c;
        pq.push({a, b, c});
    }

    Data top = pq.top();
    int pre_road = top.a;
    int pre_time = top.c;
    pq.pop();

    while(!pq.empty()) {
        top = pq.top();
        if (top.c - pre_time < t) {
            res.push(top.b);
        }
        else if (top.c - pre_time == t && pre_road == top.a) {
            res.push(top.b);
        }
        pre_road = top.a;
        pre_time = top.c;
        pq.pop();
    }
    if(res.empty()) cout << -1;                 // 없으면 -1 출력
    while(!res.empty()){                        // 오름차순으로 출력
        cout << res.top() << "\n";
        res.pop();
    }
    return 0;
}

```
