#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt[26] = {0, };
    string s;
    while(getline(cin, s)) {
        for(auto &c: s) {
            if('a' <= c && c <= 'z') cnt[c-'a']++;
        }
    }
    
    int maxV = 0;
    for(int i = 0; i < 26; i++) maxV = max(maxV, cnt[i]);
    
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == maxV) cout << (char)('a'+i);
    }
    
    return 0;
}