#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int t, res = 0;
    cin >> t;
    while(t--){
        stack<char> st;
        string s;
        cin >> s;
        
        for (int i = 0; i < s.size(); i++){
            if (st.empty()) st.push(s[i]);
            else if (st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        if (st.empty()) res++;
    }
    
    cout << res;
    return 0;
}
/* 3986 좋은 단어 '1'
top과 같은 것이 들어오면 pop해버리는 전략
*/
