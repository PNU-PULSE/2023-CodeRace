#include <iostream>
#include <vector>

using namespace std;

void fastio();
void solve();

class Tree{

private:
    vector<long long> sums;

public:
    Tree(int n){
        this -> sums = vector<long long>(n + 1, 0);
    }

    void update(int i, int delta){
        while(i < int(this->sums.size())){
            this->sums[i] += delta;
            i += i & (-i);
        }
    }

    long long query(int i){
        long long res = 0;
        while (i > 0){
            res += this->sums[i];
            i -= i & (-i);
        }
        return res;
    }
};

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int n;
    cin >> n;

    vector<int> vec1(n);
    vector<int> vec2(n);

    for(auto& v : vec1){
        cin >> v;
    }
    for(auto& v : vec2){
        cin >> v;
    }

    vector<int> temp(n);
    for(int i = 0; i < n; ++i){
        temp[vec1[i]] = i;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = temp[vec2[i]];
    }

    Tree t1 = Tree(n);
    Tree t2 = Tree(n);

    int answer = 0; int lessVal;

    for(auto a : arr){
        answer += t2.query(a);
        t1.update(a + 1, 1);
        lessVal = t1.query(a);
        t2.update(a + 1, lessVal);
    }

    if(answer != 0) cout << "³» ¸¾Àº ¿ÂÅë paradise\n" << answer;
    else cout << "Attention is what I want";
}

int main(void){

    fastio();
    solve();

    return 0;
}
