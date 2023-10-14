#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    int cnt[4];
    for(int i = 0; i < 4; i++) cin >> cnt[i];
    
    int maxV = -1e9, minV = 1e9;
    for(int s = 0; s < 1<<(2*N-2); s++) {
        vector<char> op; op.pb('&');
        int curCnt[4] = {0, };
        
        int _s = s;
        bool check = true;
        for(int i = 0; i < N-1; i++) {
            int t = _s%4; _s /= 4;
            if(curCnt[t] == cnt[t]) {
                check = false;
                break;
            }
            curCnt[t]++;
            
            switch(t) {
                case 0:
                op.pb('+');
                break;
                case 1:
                op.pb('-');
                break;
                case 2:
                op.pb('*');
                break;
                case 3:
                op.pb('/');
            }
        }
        
        if(!check) continue;
        
        stack<int> stk; stk.push(A[0]);
        for(int i = 1; i < N; i++) {
            if(op[i] == '+') stk.push(A[i]);
            if(op[i] == '-') stk.push(-A[i]);
            if(op[i] == '*') stk.top() *= A[i];
            if(op[i] == '/') stk.top() /= A[i];
        }
        
        int cur = 0;
        while(!stk.empty()) {
            cur += stk.top();
            stk.pop();
        }
        
        minV = min(minV, cur);
        maxV = max(maxV, cur);
    }
    
    cout << maxV << '\n' << minV;
    
    return 0;
}