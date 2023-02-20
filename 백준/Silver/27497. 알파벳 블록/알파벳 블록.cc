#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    stack<int> s; deque<char> dq;
    int N; cin >> N;
    
    while(N--) {
        int q; char c; cin >> q;
        switch(q) {
            case 1:
                cin >> c;
                dq.push_back(c); s.push(1);
                break;
            case 2:
                cin >> c;
                dq.push_front(c); s.push(2);
                break;
            default:
                if(!s.empty()) {
                    if(s.top() == 1) dq.pop_back();
                    else dq.pop_front();
                    
                    s.pop();
                }
        }
    }

    if(dq.empty()) cout << 0;
    else {
        for(auto &c: dq) cout << c;
    }
    return 0;
}