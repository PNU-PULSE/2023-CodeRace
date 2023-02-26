```C++
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

class Tree{

private:
    vector<ll> sums;

public:
    Tree(int n) {
        this -> sums = vector<ll>(n + 1, 0);
    }
    void update(int i, int delta) {
        while(i < int(this->sums.size())) {
            this->sums[i] += delta;
            i += i & (-i);
        }
    }

    ll query(int i) {
        ll res = 0;
        while (i > 0) {
            res += this->sums[i];
            i -= i & (-i);
        }
        return res;
    }
};

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec1(n);
    vector<int> vec2(n);
    
    for(auto& v : vec1) {
        cin >> v;
    }
    for(auto& v : vec2) {
        cin >> v;
    }

    vector<int> temp(n);
    for(int i = 0; i< n; ++i) {
        temp[vec1[i]] = i;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        arr[i] = temp[vec2[i]];
    }

    Tree t1 = Tree(n); Tree t2 = Tree(n);
    int answer = 0; int less;
    
    for(auto a : arr) {
        answer += t2.query(a);
        t1.update(a + 1, 1);
        less = t1.query(a);
        t2.update(a + 1, less);
    }
    cout << answer;
    
    return 0;
}
```
