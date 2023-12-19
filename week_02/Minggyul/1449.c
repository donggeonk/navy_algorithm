#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1000;
bool arr[MAX + 1];

int main(){
	FASTIO;

    int N, L, pos, res = 0;
    cin >> N >> L;
    for (int i = 0; i < N; i++){
        cin >> pos;
        arr[pos] = true;
    }

    for (int i = 1; i <= MAX; i++){
        if (arr[i]){
            res ++;
            for (int j = i; j < i + L && j <= MAX; j++) arr[j] = false;
        }
    }

    cout << res;
	return 0;
}
