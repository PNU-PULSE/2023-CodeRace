#풀이

```c++

#include <bits/stdc++.h>
#define endl '\n'
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 

using namespace std;
int T, N, K, M, S, H, W, Q; // S is for MCMF, network flow

void make_adequate_value(int& idx) { //make index in range
    if(idx==0) idx = N;
    else if(idx==-1) idx = N-1;
    else if(idx==N+1) idx = 1;
    else if(idx==N+2) idx = 2;
}

void Solve() { 
    cin >> N >> M;
    map<string, int> mp;
    rep(i,1,N) {
        string str; cin >> str;
        mp[str] = i;
    }

    string starter; cin >> starter;
    int idx = mp[starter];
    [&] () {
        while(M--) {
            cin >> K;
            
            switch(K) {
                case 1:
                idx -= 2;
                make_adequate_value(idx);
                break;
                case 2:
                idx-=1;
                make_adequate_value(idx);
                break;
                
                case 3:
                for(auto p : mp) {
                    if(p.second==idx) {
                        cout << p.first;
                        return;
                    }
                }
                break;

                case 4:
                idx+=1;
                make_adequate_value(idx);
                break;

                case 5:
                idx+=2;
                make_adequate_value(idx);
                break;

                default :
                cerr << "error";
                break;
            }
        }
        cout << starter;
    } ();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}
```

