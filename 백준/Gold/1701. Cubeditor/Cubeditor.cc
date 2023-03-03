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
#define MAX 5000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int fail[MAX] = {0, }, ans = 0;
void getfail(string s, int start) {
    fill(fail, fail+MAX, 0);
    for(int i = 1; i < s.length()-start; i++) {
        int j = fail[i-1];
        while(j > 0 && s[start+j] != s[start+i]) { j = fail[j-1]; }
        if(s[start+j] == s[start+i]) {
            fail[i] = j+1;
            ans = max(ans, j+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++) getfail(s, i);
    
    cout << ans;

    return 0;
}