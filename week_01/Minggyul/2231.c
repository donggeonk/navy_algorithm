#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int N; cin >> N;
    for (int k = 1; k < N; k++){
        int tmp = k, sum = k;
        while(tmp){
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N){
            cout << k;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
