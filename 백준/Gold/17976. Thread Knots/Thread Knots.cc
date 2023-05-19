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

vector<pii> threads;

bool check(int len) {
    ll cur = -len;
    for(auto &thread: threads) {
        if((ll)thread.first+thread.second < cur+len) return false;
        cur = max(cur+len, (ll)thread.first);
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x, d; cin >> x >> d;
        threads.push_back({x, d});
    }
    
    sort(threads.begin(), threads.end());
    
    ll i = 0, j = 2'000'000'000;
    while(i <= j) {
        ll mid = (i+j)>>1;
        if(check(mid)) i = mid+1;
        else j = mid-1;
    }
    
    cout << j;

    return 0;
}