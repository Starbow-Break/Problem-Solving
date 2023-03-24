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

int zrr[1'000'000];

//Z 알고리즘
void z(string s) {
    int l = 0, r = 0;
    reverse(s.begin(), s.end());
    
    zrr[0] = s.length();
    
    for(int i = 1; i < s.length(); i++) {
        if(r < i) {
            zrr[i] = 0;
            while(i+zrr[i] < s.length() && s[zrr[i]] == s[i+zrr[i]]) zrr[i]++;
            
            if(zrr[i] > 0) { l = i; r = i+zrr[i]-1; }
        }
        else {
            if(i+zrr[i-l]-1 < r) zrr[i] = zrr[i-l];
            else {
                zrr[i] = r-i+1;
                while(i+zrr[i] < s.length() && s[zrr[i]] == s[i+zrr[i]]) zrr[i]++;
                
                if(zrr[i] > 0) { l = i; r = i+zrr[i]-1; }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    z(s);
    
    int M; cin >> M;
    while(M--) {
        int v; cin >> v;
        cout << zrr[s.length()-v] << '\n';
    }

    return 0;
}