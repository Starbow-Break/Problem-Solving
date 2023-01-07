#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int ip[1000][32];
int networkIP[32];
int networkMask[32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int cur[4]; int idx = 0;
        string s; int v = 0;
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == '.') {
                cur[idx] = v; v = 0;
                idx++;
            }
            else {
                v *= 10; v += (s[j]-'0');
            }
        }
        cur[idx] = v;
        
        for(int j = 3; j >= 0; j--) {
            for(int k = 0; k < 8; k++) {
                ip[i][(3-j)*8+k] = ((cur[j] & (1<<k)) != 0);
            }
        }
    }
    
    for(int i = 0; i < 32; i++) {
        int cur = ip[0][i]; int j;
        for(j = 1; j < N; j++) {
            if(cur != ip[j][i]) break;
        }
        
        if(j == N) {
            networkIP[i] = cur;
            networkMask[i] = 1;
        }
        else {
            networkIP[i] = 0;
            networkMask[i] = 0;
        }
    }
    
    int nip[4] = {0, }; int nmask[4] = {0, };
    bool flag = true;
    for(int i = 31; i >= 0; i--) {
        if(!networkMask[i]) flag = false;
        
        if(flag) {
            nmask[i/8] += (1<<(i%8));
            nip[i/8] += (1<<(i%8))*networkIP[i];
        }
    }
    
    for(int i = 3; i >= 0; i--) {
        cout << nip[i];
        if(i > 0) cout << '.';
    }
    cout << '\n';
    
    for(int i = 3; i >= 0; i--) {
        cout << nmask[i];
        if(i > 0) cout << '.';
    }

    return 0;
}