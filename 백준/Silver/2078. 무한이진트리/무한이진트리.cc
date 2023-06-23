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

pii solve(int A, int B) {
    pii ret = {0, 0};
    while(A != 1 || B != 1) {
        if(A > B) {
            ret.first += (A-1)/B; A -= (A-1)/B*B;
        }
        else {
            ret.second += (B-1)/A; B -= (B-1)/A*A;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int A, B; cin >> A >> B;
    cout << solve(A, B);
    
    return 0;
}