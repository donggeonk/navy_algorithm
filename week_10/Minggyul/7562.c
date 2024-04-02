#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 305;
bool visited[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l, sx, sy, ex, ey;

void bfs(){
    visited[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < l && ny >= 0 && ny < l){
                if (!visited[nx][ny]){
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                    
                    if (nx == ex && ny == ey) return;
                }
            }
        }
    }
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        cin >> l >> sx >> sy >> ex >> ey;
        
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));
        bfs();
        cout << dist[ex][ey] << '\n';
    }
    return 0;
}
