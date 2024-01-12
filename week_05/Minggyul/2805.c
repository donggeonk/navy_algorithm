#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1000005;
ll n, m, lo, hi, mid, tmp;
ll tree[MAX];

ll cal (ll h){
    ll res = 0;
    for (int i = 0; i < n; i++){
        if (tree[i] > h) res += tree[i] - h;
    }
    return res;
}

int main(){
	FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        hi = max(hi, tree[i]);
    }

    while(lo + 1 < hi){
        mid = (lo + hi) / 2;
        tmp = cal(mid);
        if (tmp >= m) lo = mid;
        else hi = mid;
    }

    cout << lo;
	return 0;
}
