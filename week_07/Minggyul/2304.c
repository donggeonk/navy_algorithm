#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n, h = 0, x = 0, y = 0;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        if (h < v[i].second){
            h = v[i].second;
            x = y = i;
        }
        else if (h == v[i].second) y = i;
    }
    int res = (v[y].first - v[x].first + 1) * h;
    int idx, value;
    idx = v[0].first;
    value = v[0].second;
    for (int i = 1; i <= x; i++){
        if (value < v[i].second){
            res += value * (v[i].first - idx);
            idx = v[i].first;
            value = v[i].second;
        }
    }
    idx = v[n - 1].first;
    value = v[n - 1].second;
    for (int i = n - 2; i >= y; i--){
         if (value < v[i].second){
            res += value * (idx - v[i].first);
            idx = v[i].first;
            value = v[i].second;
        }       
    }
    cout << res;
    return 0;
}

/* 2304 창고다각형 '2'
1. 왼쪽 최댓값 수열의 인덱스 (기존)
2. 오른쪽 최댓값 수열의 인덱스 ( + 1)
3. 최댓값의 영역 
*/
