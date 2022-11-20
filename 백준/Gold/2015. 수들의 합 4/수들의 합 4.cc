#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
#define MAX 200000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N; ll K;
ll S[MAX+1];
map<ll, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    S[0] = 0;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> S[i]; S[i] += S[i-1];
    }
    
    for(int i = 0; i < N; i++) {
        auto t = mp.find(S[i]);
        
        if(t == mp.end()) {
            mp.insert({S[i], 1});
        }
        else {
            (t->second)++;
        }
    }
    
    ll ans = 0;
    for(int i = N; i >= 1; i--) {
        auto t = mp.find(S[i]-K);
        
        if(t != mp.end()) {
            ans += t->second;
        }
        
        t = mp.find(S[i-1]);
        (t->second)--;
    }
    
    cout << ans;

    return 0;
}
