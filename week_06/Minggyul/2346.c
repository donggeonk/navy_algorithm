#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
int arr[MAX];

int main(){
    FASTIO;
    
    int N;
    deque<int> dq;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dq.push_back(i);
    }
    
    while(!dq.empty()){
        int a = dq.front();
        int b = arr[a];
        cout << a << ' ';
        dq.pop_front();
        if(dq.empty()) break;
        
        if (b > 0){
            for (int i = 1; i < b; i++){
                int c = dq.front();
                dq.pop_front();
                dq.push_back(c);
            }
        }
        else {
            for (int i = 0; i < -b; i++){
                int c = dq.back();
                dq.pop_back();
                dq.push_front(c);
            }
        }
    }
    return 0;
}
