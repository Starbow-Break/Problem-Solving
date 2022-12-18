#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
deque<int> dodo;
deque<int> suyun;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while(N--) {
        int a, b; cin >> a >> b;
        dodo.push_front(a);
        suyun.push_front(b);
    }
    
    int turn = 0;
    queue<int> doGround, suGround;
    while(M--) {
        if(turn) { suGround.push(suyun.front()); suyun.pop_front(); }
        if(!turn) { doGround.push(dodo.front()); dodo.pop_front(); }
        
        if(dodo.size() == 0 || suyun.size() == 0) break;
        
        if(!doGround.empty() && !suGround.empty() && doGround.back()+suGround.back() == 5) {
            while(!doGround.empty()) {
                suyun.push_back(doGround.front()); doGround.pop();
            }
            while(!suGround.empty()) {
                suyun.push_back(suGround.front()); suGround.pop();
            }
        }
        if((!doGround.empty() && doGround.back() == 5) || (!suGround.empty() && suGround.back() == 5)) {
            while(!suGround.empty()) {
                dodo.push_back(suGround.front()); suGround.pop();
            }
            while(!doGround.empty()) {
                dodo.push_back(doGround.front()); doGround.pop();
            }
            
        }
        
        turn++; turn %= 2;
    }
    
    if(dodo.size() > suyun.size()) cout << "do";
    else if(dodo.size() < suyun.size()) cout << "su";
    else cout << "dosu";

    return 0;
}