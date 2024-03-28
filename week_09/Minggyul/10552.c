#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int arr[MAX];
bool visited[MAX], finished[MAX];
int n, m, p;

int dfs(int x){
    visited[x] = true;
    int nx = arr[x];
    int temp = 1;
    
    if (nx == 0) return 0;
    if (visited[nx]){
        if (!finished[nx]){
            cout << -1;
            exit(0);
        }
    }
    else temp += dfs(nx);
    
    finished[x] = true;
    return temp;
}

int main(){
    FASTIO;
    
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if (arr[b] == 0) arr[b] = a;
    }
    
    int res = dfs(p);
    cout << res;
    return 0;
}
