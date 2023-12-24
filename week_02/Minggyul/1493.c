#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long

int main(){
    FASTIO;

    ll l, w, h, n, a, b, tmp, res;
    vector<pair<ll, ll>> v;
    cin >> l >> w >> h >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.rbegin(), v.rend());

    tmp = res = 0;
    for (int i = 0; i < n; i++){
        a = pow(2, v[i].first);
        tmp = tmp << 3;
        b = min(v[i].second, (l / a) * (w / a) * (h / a) - tmp);
        tmp += b, res += b;
    }
    
    if (tmp == l * w * h) cout << res;
    else cout << -1;
    return 0;
}
