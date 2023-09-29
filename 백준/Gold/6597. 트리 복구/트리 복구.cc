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

string postOrder(string &preOrd, string &inOrd) {
    if(preOrd.length() <= 1) return preOrd;
    
    int i = 1, t = 0;
    for(;;t++) {
        if(preOrd[0] == inOrd[t]) break;
    }
    
    string pl = "", pr = "", il = "", ir = "";
    for(int j = 0; j < t; j++) {
        pl += preOrd[i];
        il += inOrd[j];
        i++;
    }
    for(int j = t+1; j < inOrd.length(); j++) {
        pr += preOrd[i];
        ir += inOrd[j];
        i++;
    }
    
    return postOrder(pl, il)+postOrder(pr, ir)+preOrd[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string preOrd, inOrd;
    while(cin >> preOrd >> inOrd) {
        cout << postOrder(preOrd, inOrd) << '\n';
    }
    
    return 0;
}
