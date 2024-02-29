#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int N, K;
    list<int> L;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) L.push_back(i);
    
    list<int>::iterator cur = L.begin();
    int k = 0;
    cout << '<';
    while(true){
        if (L.size() == 1) {
            cout << L.front() << ">";
            break;
        }
        k++;
        int tmp = L.front();
        cur = L.erase(cur);
        if (k == K) {
            cout << tmp << ", ";
            k = 0;
        }
        else L.push_back(tmp);
    }
    return 0;
}
// STL List를 이용한 풀이 
