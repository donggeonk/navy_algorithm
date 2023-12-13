#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 55;
char arr[MAXN][MAXN];
int N, res;

void check(){
    for (int i = 0; i < N; i++){
        char pre = arr[i][0];
        int tmp = 1;
        for (int j = 1; j < N; j++){
            if (arr[i][j] == pre) tmp ++;
            else tmp = 1;
            pre = arr[i][j];
            
            res = max(res, tmp);
        }
    }
    
    for (int j = 0; j < N; j++){
        char pre = arr[0][j];
        int tmp = 1;
        for (int i = 1; i < N; i++){
            if (arr[i][j] == pre) tmp ++;
            else tmp = 1;
            pre = arr[i][j];
            
            res = max(res, tmp);
        }
    }
}

int main(){
    FASTIO;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int a = 0; a < N; a++){
        for (int b = 0; b < N - 1; b++){
            swap(arr[a][b], arr[a][b + 1]);
            check();
            swap(arr[a][b], arr[a][b + 1]);
        }
    }
    
    for (int b = 0; b < N; b++){
        for (int a = 0; a < N - 1; a++){
            swap(arr[a][b], arr[a + 1][b]);
            check();
            swap(arr[a][b], arr[a + 1][b]);
        }
    }
    
    cout << res;
    return 0;
}
