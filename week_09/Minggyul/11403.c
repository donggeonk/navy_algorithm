#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
vector<int> v[MAX];
bool visited[MAX];
int arr[MAX][MAX];
int n;
bool flag; 

void dfs(int start, int x){
    visited[x] = true;
    
    for (int i = 0; i < v[x].size(); i++){
        int nx = v[x][i];
        if (nx == start) flag = true;
        if (!visited[nx]) dfs(start, nx);
    }
}

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int num; cin >> num;
            if (num == 1) v[i].push_back(j);
        }
    }
    
    for (int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        flag = false;
        dfs(i, i);
        for (int j = 0; j < n; j++)
            if (visited[j]) arr[i][j] = 1;
        if (!flag) arr[i][i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
