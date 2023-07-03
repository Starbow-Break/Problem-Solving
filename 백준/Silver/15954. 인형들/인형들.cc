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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    ll A[N+1]; A[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i]; A[i] += A[i-1];
    }
    
    double ans = 1'000'000'000;
    for(int i = 0; i <= N-K; i++) {
        for(int j = i+K; j <= N; j++) {
            double avg = (double)(A[j]-A[i])/(j-i);
            
            double var = 0;
            for(int k = i+1; k <= j; k++) {
                var += (avg-A[k]+A[k-1])*(avg-A[k]+A[k-1]);
            }
            var /= (j-i);
            
            ans = min(ans, sqrt(var));
        }
    }
    
    cout << fixed << setprecision(12) << ans;

    return 0;
}