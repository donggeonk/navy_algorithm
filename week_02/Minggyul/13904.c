#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
bool visited[MAX];

int main(){
    FASTIO;

    int N, d, w;
    vector<pair<int, int>> v;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> d >> w;
        v.push_back({w, d});
    }
    sort(v.rbegin(), v.rend());

    int res = 0;
    for (int i = 0; i < N; i++){
        int day = v[i].second;
        int score = v[i].first;
        for (int j = day; j >= 1; j--){
            if (!visited[j]){
                visited[j] = true;
                res += score;
                break;
            }
        }
    }

    cout << res;
    return 0;
}
