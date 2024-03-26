#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 33;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;

int dfs(int x, int y){
    int node = 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            if (arr[nx][ny] == '1' && !visited[nx][ny]){
                node += dfs(nx, ny);
            }
        }
    }
    return node;
}

int main(){
    FASTIO;
    
    int temp; cin >> n;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == '1' && !visited[i][j]){
                temp = dfs(i, j);
                pq.push(temp);
            }
        }
    }
    
    cout << pq.size() << '\n';
    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}
