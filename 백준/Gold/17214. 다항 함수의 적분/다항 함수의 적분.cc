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

int coef[2] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    
    int v = 0; bool isMinus = false;
    for(int i = 0; i < s.length(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            v *= 10; v += s[i]-'0';
        }
        else if(s[i] == 'x') {
            if(isMinus) {
                v = -v; isMinus = false;
            }
            coef[1] += v; v = 0;
        }
        else {
            if(isMinus) {
                v = -v; isMinus = false;
            }
            coef[0] += v; v = 0;
            if(s[i] == '-') isMinus = true;
        }
    }
    if(isMinus) v = -v; coef[0] += v;
    
    if(coef[1] != 0) {
        if(coef[1] < 0) cout << "-";
        
        if(abs(coef[1]) > 2) cout << abs(coef[1])/2;
        cout << "xx";
    }
    if(coef[0] != 0) {
        if(coef[0] < 0) cout << "-";
        else if(coef[1] != 0) cout << "+";
        
        if(abs(coef[0]) > 1) cout << abs(coef[0]);
        cout << "x";
    }
    if(coef[0] != 0 || coef[1] != 0) cout << "+";
    cout << "W";

    return 0;
}