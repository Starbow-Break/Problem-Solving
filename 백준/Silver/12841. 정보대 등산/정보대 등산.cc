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

int crosswalk[100'000];
ll sum[100'000][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> crosswalk[i];
    sum[0][0] = sum[0][1] = 0;
    for(int i = 1; i < N; i++) { cin >> sum[i][0]; sum[i][0] += sum[i-1][0]; }
    for(int i = 1; i < N; i++) { cin >> sum[i][1]; sum[i][1] += sum[i-1][1]; }
    
    int num = 1; ll minLen = crosswalk[0]+sum[N-1][1];
    for(int i = 2; i < N; i++) {
        if(sum[i-1][0]+crosswalk[i-1]+sum[N-1][1]-sum[i-1][1] < minLen) {
            num = i; minLen = sum[i-1][0]+crosswalk[i-1]+sum[N-1][1]-sum[i-1][1];
        }
    }
    
    cout << num << ' ' << minLen;

    return 0;
}