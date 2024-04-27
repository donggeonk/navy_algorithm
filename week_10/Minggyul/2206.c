#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 1005;
const int INF = 1e9 + 5;
char arr[MAX][MAX];
int dist[MAX][MAX][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

int bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push({{1, 1}, 1});
    dist[1][1][1] = 1;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        
        if (x == n && y == m) return dist[x][y][z];
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                if (arr[nx][ny] == '1' && z ){
                    dist[x][y][z - 1] = dist[x][y][z];
                    q.push({{nx, ny}, z - 1});
                    dist[nx][ny][z - 1] = dist[x][y][z - 1] + 1;
                }
                else if (arr[nx][ny] == '0' && !dist[nx][ny][z]){
                    q.push({{nx, ny}, z});
                    dist[nx][ny][z] = dist[x][y][z] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    FASTIO;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    
    cout << bfs() << '\n';
    return 0;
}
