#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
bool apple[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    FASTIO;
    
    int N, K, L, times = 1, dir = 0, cx = 1, cy = 1;
    cin >> N >> K;
    deque<pair<int,int>> dq;
    dq.push_front({1, 1});
    for (int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        apple[a][b] = true;
    }
    
    map<int, char> m;
    cin >> L;
    for (int i = 0; i < L; i++){
        int a;
        char c;
        cin >> a >> c;
        m[++a] = c;
    }
    
    while(true){
        times ++;
        cx += dx[dir];
        cy += dy[dir];
        
        if (m.find(times) != m.end()){ // 방향 처리
            if (m[times] == 'D'){
                dir ++;
                if (dir == 4) dir = 0;
            }
            else {
                dir --;
                if (dir == -1) dir = 3;
            }
        }
        
        
        if (find(dq.begin(), dq.end(), make_pair(cx, cy)) != dq.end()){
            cout << --times;
            break;
        }
        dq.push_front({cx, cy}); // head가 앞으로 움직이는 것 구현
        if(apple[cx][cy]) apple[cx][cy] = false;
        else {
            dq.pop_back();
        }
        
        if(cx <= 0 || cx > N || cy <= 0 || cy > N) { // 죽는 것 구현
            cout << --times;
            break;
        }
    }
    return 0;
}

/* 3190번 - 뱀
dequeue를 이용
0. 앞으로 나가는 좌표가 벽이면 죽는다
1. 앞으로 나갈 때 deque front에 넣는다.
2. apple이 존재하지 않으면 deque back을 pop 한다
3. deque에 머리가 들어간 좌표가 있으면 죽는다.

시뮬레이션으로 시간 초가 흐르면서 진행한다.

(1,1) 이라는 좌표를 times = 1이라고 두고 방향이 한 박자 늦게 반영된다고 생각해야
예제 3이 맞는다.
*/
