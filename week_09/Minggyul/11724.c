#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
vector<int> v[MAX];
bool visited[MAX];

void dfs(int cur){
    visited[cur] = true;
    
    for (int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if (!visited[next]) dfs(next);
    }
}

int main(){
    FASTIO;
    
    int n, m, x, y, res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            res ++;
        }
    }
    
    cout << res;
    return 0;
}
