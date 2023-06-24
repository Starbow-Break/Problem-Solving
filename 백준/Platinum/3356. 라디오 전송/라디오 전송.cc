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

vector<int> getFail(string &s) {
    vector<int> fail;
    fail.push_back(0);
    
    for(int i = 1, j = 0; i < s.length(); i++) {
        while(j > 0 && s[i] != s[j]) j = fail[j-1];
        if(s[i] == s[j]) j++;
        fail.push_back(j);
    }
    
    return fail;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int L; cin >> L;
    string s; cin >> s;
    vector<int> fail = getFail(s);
    cout << L-fail.back();
    
    return 0;
}