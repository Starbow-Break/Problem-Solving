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

deque<pii> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        dq.push_back({i, v});
        
    }
    
    while(!dq.empty()) {
        pii m = dq.front(); cout << m.first << " ";
        
        int t = m.second;
        dq.pop_front(); if(t > 0) t--;
        
        while(t > 0) {
            t--;
            dq.push_back(dq.front()); dq.pop_front(); 
        }
        while(t < 0) {
            t++;
            dq.push_front(dq.back()); dq.pop_back(); 
        }
    }

    return 0;
}
