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
    
    int N; cin >> N;
    if(N == 0) cout << 0;
    else {
        vector<int> values(N);
        for(int i = 0; i < N; i++) cin >> values[i];
        
        sort(values.begin(), values.end());
        
        int t = N*15/100+(N*15%100 >= 50), sum = 0;
        for(int i = t; i < N-t; i++) sum += values[i];
        
        cout << sum/(N-2*t)+(sum%(N-2*t) >= (N/2-t+N%2));
    }

    return 0;
}