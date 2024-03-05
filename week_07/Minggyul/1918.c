#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    string s; cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if(isalpha(c)){
            cout << c;
        }
        else {
            if (c == '*' || c == '/'){
                while(!st.empty()){
                    if (st.top() == '*' || st.top() == '/'){
                        cout << st.top();
                        st.pop();
                    }
                    else break;
                }
                st.push(c);
            }
            else if (c == '+' || c == '-'){
                while(!st.empty()){
                    if (st.top() != '('){
                        cout << st.top();
                        st.pop();
                    }
                    else break;
                }
                st.push(c);
            }
            else if (c == '(') st.push(c);
            else {
                while(st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}

/* 후위 표기식 '2'
1. 피연산자는 출력한다.
2. 연산자는 스택에 넣는다
2-1 ) 기존에 있는 연산자의 우선 순위가 넣는 것보다 높거나 같다면 계속 pop한다.
2-2 ) 괄호의 경우 괄호를 끝마칠 때 다 출력한다.
3. 마지막 남은 연산자를 모두 출력한다.
*/
