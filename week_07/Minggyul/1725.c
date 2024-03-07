#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int arr[MAX];

int main(){
    FASTIO;
    
    int n, res = 0;
    stack<pair<int, int>> st; // (value, index)
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++){
        if(st.empty() || st.top().first < arr[i]) st.push({arr[i], i});
        else {
            while(!st.empty() && st.top().first >= arr[i]){
                int v = st.top().first;
                int idx = st.top().second;
                st.pop();
                //cout << "i : " << i << '\n';
                if(st.empty()) {
                    res = max(res, v * (i - 1));
                    //cout << v * (i - 1) << '\n';
                }
                else {
                    int c = st.top().second;
                    res = max(res, v * (i - c - 1));
                    //cout << v * (i - c - 1) << '\n';
                }
            }
            st.push({arr[i], i});
        }
    }
    
    while(!st.empty()){
        int a = st.top().first;
        int b = st.top().second;
        st.pop();
        if (st.empty()) {
            res = max(res, a * n);
            //cout << a * n << '\n';
        }
        else {
            int c = st.top().second;
            res = max(res, a * (n - c));
            //cout << a * (n - c) << '\n';
        }
    }
    
    cout << res << '\n';
    return 0;
}

/* 1725 히스토그램 '3'
1. st.top() < cur H - push
2. st.top() >= cur H - pop
2-1. 전 후의 인덱스를 파악해서 최대 넓이를 구한다.
3. 남은 stack에 오른쪽 끝까지로 지정하고 계산한다. (내림차순이기 때문)
*/
