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

int S[200001]; int ans = 0;
int T[200001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    S[0] = 0;
    for(int i = 1; i <= N; i++) { cin >> S[i]; }
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        ans += S[i]*v;
        S[i] *= (v ? -1 : 1);
    }
    for(int i = 1; i <= N; i++) { S[i] += S[i-1]; T[i] = min(T[i-1], S[i]); }
    
    int delta = S[1];
    for(int i = 2; i <= N; i++) {
        delta = max(delta, S[i]-T[i-1]);
    }
    ans += delta;
    
    cout << ans;

    return 0;
}