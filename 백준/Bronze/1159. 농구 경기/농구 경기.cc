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
    
    int N; cin >> N;
    while(N--) {
        string s; cin >> s;
        cnt[s[0]-'a']++;
    }
    
    string ans = "";
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) ans += 'a'+i;
    }
    
    cout << (ans == "" ? "PREDAJA" : ans);
    
    return 0;
}