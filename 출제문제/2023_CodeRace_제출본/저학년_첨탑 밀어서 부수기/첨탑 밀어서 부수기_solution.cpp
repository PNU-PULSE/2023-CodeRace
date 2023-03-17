#include <iostream>

using namespace std;

void fastio();
void solve();

void fastio(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int n, val, h = 0, result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        if(val >= h) result += 1;
        h = val;
    }
    cout << result;
}

int main(){
    fastio();
    solve();
}
