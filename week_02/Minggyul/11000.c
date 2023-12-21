#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
	FASTIO;

    int N; cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++){
        int S, T;
        cin >> S >> T;
        v.push_back({S, T});
    }
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    for(int i = 1; i < v.size(); i++){
        if (pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }

    cout << pq.size();
	return 0;
}
