#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
bool visited[MAX][MAX];
int arr[MAX][MAX];
queue<pair<pair<int, int>, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, res;

int bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (arr[nx][ny] != -1 && !visited[nx][ny]){
                    q.push({{nx, ny}, z + 1});
                    visited[nx][ny] = true;
                    arr[nx][ny] = 1;
                    res --;
                    if (res == 0) return z + 1;
                }
            }
        }

    }
    
    return -1;
}

int main(){
    FASTIO;
    
    cin >> m >> n;
    bool flag = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (!flag && arr[i][j] == 0) flag = true;
            if (arr[i][j] == 1) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
            else if (arr[i][j] == -1) {
                visited[i][j] = true;
            }
            else res++;
        }
    }
    if (flag) cout << bfs();
    else cout << 0;
    
    return 0;
}
