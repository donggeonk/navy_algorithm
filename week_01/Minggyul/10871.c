#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n, x, num;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (num < x) cout << num << ' ';
    }
    
}
