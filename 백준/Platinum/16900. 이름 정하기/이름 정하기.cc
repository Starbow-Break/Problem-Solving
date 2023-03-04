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
#define MAX 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int solve(string &s) {
    int fail[MAX] = {0, };
    
    for(int i = 1; i < s.length(); i++) {
        int j = fail[i-1];
        while(j > 0 && s[j] != s[i]) j = fail[j-1];
        if(s[i] == s[j]) fail[i] = j+1;
    }
    
    return fail[s.length()-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; int k; cin >> s >> k;
    cout << 1LL*s.length()*k-1LL*solve(s)*(k-1);

    return 0;
}