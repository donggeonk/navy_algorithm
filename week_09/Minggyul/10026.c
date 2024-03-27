#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, a, b;

void dfs(int x, int y){
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            if (arr[nx][ny] == arr[x][y] && !visited[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!visited[i][j]) {
                dfs(i, j);
                a ++;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 'G') arr[i][j] = 'R';
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!visited[i][j]) {
                dfs(i, j);
                b ++;
            }
        }
    }
    
    cout << a << ' ' << b << '\n';
    return 0;
}
