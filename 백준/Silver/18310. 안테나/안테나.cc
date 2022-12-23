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

int cnt[100001] = {0, };
int ans = 0; ll minV;
ll cur = 0; int delta;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        cur += v;
        cnt[v]++;
    }
    
    delta = -N; minV = cur;
    for(int i = 1; i <= 100000; i++) {
        cur += delta;
        if(cur < minV) { ans = i; minV = cur; }
        delta += 2*cnt[i];
    }
    
    cout << ans;

    return 0;
}