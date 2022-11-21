#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
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
    
    int N; string s;
    cin >> N >> s;
    
    string hiarc = "HIARC";
    
    int cnt[26] = {0, };
    for(int i = 0; i < N; i++) cnt[s[i]-'A']++;
    
    int ans = 10000000;
    for(int i = 0; i < 5; i++) ans = min(ans, cnt[hiarc[i]-'A']);
    
    cout << ans;

    return 0;
}