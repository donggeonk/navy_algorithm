#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
vector<int> v[MAX];
bool visited[MAX];
int n, m, V;

void dfs(int x){
    visited[x] = true;
    cout << x << ' ';
    
    for (int i = 0; i < v[x].size(); i++){
        int next = v[x][i];
        if (!visited[next]) dfs(next);
    }
}

void bfs(){
    visited[V] = true;
    queue<int> q;
    q.push(V);
    
    while(!q.empty()){
        int x = q.front();
        cout << x << ' ';
        q.pop();
        
        for (int i = 0; i < v[x].size(); i++){
            int next = v[x][i];
            
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    FASTIO;
    
    cin >> n >> m >> V;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < MAX; i++)
        sort(v[i].begin(), v[i].end());
        
    dfs(V);
    cout << '\n';
    
    memset(visited, false, sizeof(visited));
    bfs();
    
    return 0;
}
