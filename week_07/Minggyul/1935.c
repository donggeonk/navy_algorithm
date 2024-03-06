#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 55;
double arr[MAX];
int main(){
    FASTIO;
    
    int n; cin >> n;
    double res = 0;
    string s; cin >> s;
    stack<double> st;
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) st.push(arr[s[i] - 'A']);
        else {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            double c;
            if (s[i] == '*') c = a * b;
            else if (s[i] == '/') c = a / b;
            else if (s[i] == '+') c = a + b;
            else c = a - b;
            st.push(c);
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}

/* 1935 후위 표기식2 '1'
후위 표기식과 피연산자의 값 -> 계산 결과
피연산자는 스택에 넣고 연산자는 스택에서 2개의 수를 계산하고 다시 넣는다.
*/
