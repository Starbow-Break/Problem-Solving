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
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int caseNum = pow(3, N-1);
        vector<string> formula;
        
        for(int i = 0; i < caseNum; i++) {
            int v = i;
            char op[N];
            for(int i = 1; i < N; i++) {
                int opNum = v%3;
                if(opNum == 0) op[i] = ' ';
                else if(opNum == 1) op[i] = '+';
                else op[i] = '-';
                v /= 3;
            }
            
            int result = 0, cur = 0; char oper = '+';
            for(int i = 1; i <= N; i++) {
                cur = cur*10+i;
                if(i < N) {
                    if(op[i] != ' ') {
                        if(oper == '+') result += cur;
                        if(oper == '-') result -= cur;
                        cur = 0;
                        oper = op[i];
                    }
                }
            }
            if(oper == '+') result += cur;
            if(oper == '-') result -= cur;
            
            if(!result) {
                string f;
                for(int i = 1; i <= N; i++) {
                    f += '0'+i;
                    if(i < N) f += op[i];
                }
                formula.pb(f);
            }
        }
        
        sort(all(formula));
        for(auto &f: formula) cout << f << '\n';
        cout << '\n';
    }
    
    return 0;
}
