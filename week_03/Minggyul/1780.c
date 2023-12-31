#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 2222;
int arr[MAX][MAX];
int color[3];

bool check(int row, int col, int size){
    int tmp = arr[row][col];
    for (int i = row; i < row + size; i++){
        for (int j = col; j < col + size; j++){
            if (arr[i][j] != tmp) return false;
        }
    }
    return true;
}

void solved(int row, int col, int size){
    if (check(row, col, size)) color[arr[row][col] + 1] ++;
    else {
        size /= 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                solved(row + size * i, col + size * j, size);
            }
        }
    }
}

int main(){
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    solved(0, 0, N);
    for (int i = 0; i < 3; i++)
        cout << color[i] << '\n';
    return 0;
}
