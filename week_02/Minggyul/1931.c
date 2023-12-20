#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    FASTIO;

    int N; cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);

    int res = 1;
    int pre = v[0].second;
    for (int i = 1; i < N; i++){
        if (pre <= v[i].first) {
            pre = v[i].second;
            res ++;
        }
    }

    cout << res;
}
