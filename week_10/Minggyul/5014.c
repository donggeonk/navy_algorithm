#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1000005;
bool visited[MAX];
int dist[MAX];
int F, S, G, U, D;

int bfs(){
    visited[S] = true;
    queue<int> q;
    q.push(S);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        int nx = x + U;
        if (nx <= F && !visited[nx]) {
            visited[nx] = true;
            q.push(nx);
            dist[nx] = dist[x] + 1;
            if (nx == G) return dist[nx];
        }
        
        nx = x - D;
        if (nx > 0 && !visited[nx]){
            visited[nx] = true;
            q.push(nx);
            dist[nx] = dist[x] + 1;
            if (nx == G) return dist[nx];
        }
    }
    return -1;
}

int main(){
    FASTIO;
    
    cin >> F >> S >> G >> U >> D;
    int temp = bfs();
    if (S == G) cout << 0;
    else if (temp == -1) cout << "use the stairs\n";
    else cout << temp;
    return 0;
}
