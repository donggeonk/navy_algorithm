#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
ll a, b, c;

ll solved(ll x, ll y){
    if (y == 0) return 1;
    
    if (y % 2 == 0) return (solved(x, y/2)%c * solved(x, y/2)%c)%c;
    return (solved(x, y/2)%c * solved(x, y/2)%c * x%c)%c;
}

int main(){
    FASTIO;

    cin >> a >> b >> c;
    cout << solved(a, b);
    return 0;
}
