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

int getCode(string op) {
    string codes[24] = {
        "ADD", "ADDC", "SUB", "SUBC", "MOV", "MOVC", "AND", "ANDC", 
        "OR", "ORC", "NOT", "x", "MULT", "MULTC", "LSFTL", "LSFTLC",
        "LSFTR", "LSFTRC", "ASFTR", "ASFTRC", "RL", "RLC", "RR", "RRC"
    };
    
    for(int i = 0; i < 24; i++) {
        if(codes[i] == op) {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int bit[16] = {0, };
        string op; int rD, rA, rB;
        cin >> op >> rD >> rA >> rB;
        int opcode = getCode(op);
        
        for(int i = 4; i >= 0; i--) {
            bit[i] = opcode % 2;
            opcode /= 2;
        }
        
        for(int i = 8; i >= 6; i--) {
            bit[i] = rD % 2;
            rD /= 2;
        }
        
        for(int i = 11; i >= 9; i--) {
            bit[i] = rA % 2;
            rA /= 2;
        }
        
        if(bit[4] == 0) rB *= 2;
        for(int i = 15; i >= 12; i--) {
            bit[i] = rB % 2;
            rB /= 2;
        }
        
        for(int i = 0; i < 16; i++) cout << bit[i];
        cout << '\n';
    }
    
    return 0;
}
