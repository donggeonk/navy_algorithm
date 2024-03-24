#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int N, M;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        cin >> N >> M;
        for (int i = 0; i < N; i++){
            int num; cin >> num;
            q.push({i, num});
            pq.push(num);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if (y == pq.top()){
                pq.pop();
                cnt ++;
                if (M == x) break;
            }
            else q.push({x, y});
        }
        
        cout << cnt << '\n';
    }
    return 0;
}
