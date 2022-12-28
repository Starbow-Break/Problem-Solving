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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; string s;
    cin >> N >> s;
    
    int cnt[2] = {0, };
    for(int i = 0; i < N; i++) {
        cnt[s[i]-'A']++;
    }
    
    if(cnt[0] > cnt[1]) cout << "A";
    else if(cnt[0] < cnt[1]) cout << "B";
    else cout << "Tie";

    return 0;
}