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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s; cin >> s;
    int cnt = 0, numG = 0;
    
    for(auto &c: s) {
        if(c == '(') cnt--;
        else if(c == ')') cnt++;
        else numG++;
    }
    
    int open = (numG+cnt)/2;
    for(auto &c: s) {
        if(c == 'G') {
            if(open) {
                open--; cout << '(';
            }
            else cout << ')';
        }
        else cout << c;
    }

    return 0;
}