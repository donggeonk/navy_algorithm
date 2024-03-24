#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int N, K;
    long long res = 0;
    cin >> N >> K;
    
    priority_queue<int,vector<int>,greater<int>> pq[25];
    for (int i = 0; i < N; i++){
        string s; cin >> s;
        int cur = s.length();
        while(!pq[cur].empty()){
            if(i - pq[cur].top() > K) pq[cur].pop();
            else break;
        }
        res += pq[cur].size();
        pq[cur].push(i);
    }
    
    cout << res;
    return 0;
}
