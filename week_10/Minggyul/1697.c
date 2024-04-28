#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100001;
int visited[MAX];
int n, k;

int bfs(){
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if (x == k) return visited[x] - 1;
        
        if (x - 1 >= 0 && x - 1 < MAX){
            if (!visited[x - 1]){
                q.push(x - 1);
                visited[x - 1] = visited[x] + 1;
            }
        }
        
        if (x + 1 >= 0 && x + 1 < MAX){
            if (!visited[x + 1]){
                q.push(x + 1);
                visited[x + 1] = visited[x] + 1;
            }
        }
        
        if (2 * x >= 0 && 2 * x < MAX){
            if (!visited[2 * x]){
                q.push(2 * x);
                visited[2 * x] = visited[x] + 1;
            }
        }        
    }
}

int main(){
    FASTIO;
    
    cin >> n >> k;
    if (n == k) cout << 0;
    else cout << bfs();
    return 0;
}
