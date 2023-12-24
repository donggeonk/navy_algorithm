#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long

int main(){
    FASTIO;

    ll L, N, rf, rb, x, c;
    cin >> L >> N >> rf >> rb;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < N; i++){
        cin >> x >> c;
        v.push_back({x, c});
    }

    int p = v.size();
    vector<pair<ll, ll>> m;
    ll pre = v[p - 1].second;
    m.push_back({v[p - 1].first, v[p - 1].second});
    for (int i = p - 2; i >= 0; i--){
        if (pre <= v[i].second){
            m.push_back({v[i].first, v[i].second});
            pre = v[i].second;
        }
    }
    sort(m.begin(), m.end());

    ll res = 0;
    pre = 0;
    for (auto it : m){
        res += (rf - rb) * (it.first - pre) * it.second;
        pre = it.first;
    }
    cout << res;
    return 0;
}
