#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
bool arr[MAX][MAX], visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

int dfs(int x, int y){
    int node = 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m){
            if (arr[nx][ny] && !visited[nx][ny]){
                node += dfs(nx, ny);
            }
        }
    }
    return node;
}

int main(){
    FASTIO;
    
    int k, r, c, temp, res = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        cin >> r >> c;
        arr[r - 1][c - 1] = true;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(arr[i][j] && !visited[i][j]) {
                temp = dfs(i, j);
                res = max(res, temp);
            }
        }
    }
    
    cout << res;
    return 0;
}
