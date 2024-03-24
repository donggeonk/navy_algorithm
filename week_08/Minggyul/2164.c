#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n;
    cin >> n;
    
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    
    while(q.size() != 1){
        q.pop();
        int k = q.front();
        q.pop();
        q.push(k);
    }
    
    cout << q.front();
    return 0;
}
