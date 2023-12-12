#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n, num, tmp = 0, res = -1005;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> num;
        if (tmp <= 0) tmp = num;
        else tmp += num;
        
        res = max(res, tmp);
    }
    
    cout << res;
}
