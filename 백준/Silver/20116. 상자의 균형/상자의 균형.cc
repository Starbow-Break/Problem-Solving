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

ll posX[200'001];
ll sumX[200'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sumX[0] = 0;
    int n, L; cin >> n >> L;
    for(int i = 1; i <= n; i++) {
        cin >> posX[i];
        sumX[i] = posX[i]; sumX[i] += sumX[i-1];
    }
    
    int i;
    for(i = n-1; i >= 1; i--) {
        ll cx = sumX[n]-sumX[i];
        if(!(1LL*(n-i)*(posX[i]-L) < cx && cx < 1LL*(n-i)*(posX[i]+L))) break;
    }
    
    cout << (i == 0 ? "stable" : "unstable");

    return 0;
}