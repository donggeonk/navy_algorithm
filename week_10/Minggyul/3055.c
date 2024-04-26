#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 55;
bool wv[MAX][MAX], sv[MAX][MAX];
queue<pair<int,int>> wq, sq, tmp;
char arr[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int r, c, rx, ry;

void solved(){
    while(!sq.empty()){
        while(!wq.empty()){
            int wcx = wq.front().first;
            int wcy = wq.front().second;
            wq.pop();
            
            for (int i = 0; i < 4; i++){
                int wnx = wcx + dx[i];
                int wny = wcy + dy[i];
                
                if (wnx >= 0 && wnx < r && wny >= 0 && wny < c){
                    if (arr[wnx][wny] != 'X' && arr[wnx][wny] != 'D' && !wv[wnx][wny]){
                        wv[wnx][wny] = true;
                        tmp.push({wnx, wny});
                        arr[wnx][wny] = '*';
                    }
                }
            }
        }
        
        while(!tmp.empty()) {
            wq.push({tmp.front().first, tmp.front().second});
            tmp.pop();
        }
        
        while(!sq.empty()){
            int scx = sq.front().first;
            int scy = sq.front().second;
            sq.pop();
            
            for (int i = 0; i < 4; i++){
                int snx = scx + dx[i];
                int sny = scy + dy[i];
                
                if (snx == rx && sny == ry){
                    cout << dist[scx][scy] + 1;
                    return ;
                }
                if (snx >= 0 && snx < r && sny >= 0 && sny < c){
                    if (arr[snx][sny] == '.' && !sv[snx][sny]){
                        sv[snx][sny] = true;
                        tmp.push({snx, sny});
                        dist[snx][sny] = dist[scx][scy] + 1;
                    }
                }
            }            
        }
        
        while(!tmp.empty()) {
            sq.push({tmp.front().first, tmp.front().second});
            tmp.pop();
        }        
    }

    cout << "KAKTUS";
}

int main(){
    FASTIO;
    
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'D') rx = i, ry = j;
            else if (arr[i][j] == 'S') sq.push({i, j}), sv[i][j] = true;
            else if (arr[i][j] == '*') wq.push({i, j}), wv[i][j] = true;
        }
    }
    solved();
    return 0;
}
