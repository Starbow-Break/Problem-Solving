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

bool check(string pattern, string fileName) {
    int i = 0; int j = fileName.length()-1;
    
    int idx = 0;
    while(pattern[idx] != '*') {
        if(fileName[i] != pattern[idx]) return false;
        i++; idx++;
    }
    idx = pattern.length()-1;
    while(pattern[idx] != '*') {
        if(fileName[j] != pattern[idx]) return false;
        j--; idx--;
    }
    
    return (i-1 < j+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string p; cin >> p;
    
    while(N--) {
        string s; cin >> s;
        cout << (check(p, s) ? "DA" : "NE") << '\n';
    }
    
    return 0;
}