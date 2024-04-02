#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

void bfs(int x, int y){
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (arr[nx][ny] == '1' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                    if (nx == n - 1 && ny == m - 1){
                        return;
                    }
                }
            }
        }
    }
}
int main(){
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    bfs(0, 0);
    cout << dist[n - 1][m - 1];
    return 0;
}
