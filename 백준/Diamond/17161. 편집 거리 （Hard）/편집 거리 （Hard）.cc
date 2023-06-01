#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define MAX_L 17'000

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pair<char, char> &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int n, m;
string s, t; vector<pair<char, char>> ans;

//히르쉬버그
int dp1[MAX_L+1], dp2[MAX_L+1], temp[MAX_L+1];
void hirschberg(int la, int lb, int ra, int rb) {
    if(rb <= lb) return;
    if(rb-lb == 1) {
        if(la == ra) { 
            ans.push_back({'a', t[lb]});
            return;
        }
        
        bool flag = false;
        for(int i = la; i < ra; i++) {
            if(s[i] == t[lb] && !flag) {
                ans.push_back({'c', t[lb]});
                flag = true;
            }
            else {
                if(!flag && i == ra-1) ans.push_back({'m', t[lb]});
                else ans.push_back({'d', s[i]});
            }
        }
        return;
    }
    
    int mid = (lb+rb)/2; 
    for(int i = lb; i <= mid; i++) {
        if(i == lb) {
            for(int i = la; i <= ra; i++) dp1[i] = i-la;
        }
        else {
            for(int j = la; j <= ra; j++) {
                temp[j] = dp1[j]+1;
                if(j > la) {
                    temp[j] = min({temp[j], temp[j-1]+1, dp1[j-1]+1});
                    if(s[j-1] == t[i-1])
                        temp[j] = min(temp[j], dp1[j-1]);
                }
            }
            
            for(int j = la; j <= ra; j++) {
                dp1[j] = temp[j];
            }
        }
    }

    for(int i = rb; i >= mid; i--) {
        if(i == rb) {
            for(int i = ra; i >= la; i--) dp2[i] = ra-i;
        }
        else {
            for(int j = ra; j >= la; j--) {
                temp[j] = dp2[j]+1;
                if(j < ra) {
                    temp[j] = min({temp[j], temp[j+1]+1, dp2[j+1]+1});
                    if(s[j] == t[i])
                        temp[j] = min(temp[j], dp2[j+1]);
                }
            }
            
            for(int j = la; j <= ra; j++) {
                dp2[j] = temp[j];
            }
        }
    }
    
    int i = la;
    for(int a = la; a <= ra; a++) {
        if(dp1[i]+dp2[i] > dp1[a]+dp2[a]) i = a;
    }
    
    hirschberg(la, lb, i, mid); hirschberg(i, mid, ra, rb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s >> t;
    int n = s.length(), m = t.length();
    
    hirschberg(0, 0, n, m);
    
    for(auto &a: ans) cout << a << '\n';

    return 0;
}