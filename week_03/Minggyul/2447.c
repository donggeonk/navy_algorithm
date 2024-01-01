#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void solved(int row, int col, int size){
    if ((row / size) % 3 == 1 && (col / size) % 3 == 1) cout << ' ';
    else {
        if (size == 1) cout << '*';
        else solved(row, col, size / 3);
    }
}

int main(){
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            solved(i, j, N);
        }
        cout << '\n';
    }
    return 0;
}
