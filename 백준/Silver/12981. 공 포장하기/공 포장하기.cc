#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int R, G, B; cin >> R >> G >> B;
    int ans = 0;
    ans += R/3+G/3+B/3;
    R %= 3; G %= 3; B %= 3;
    
    int c1 = (R > 0) + (G > 0) + (B > 0);
    int c2 = max({R, G, B});
    ans += min(c1, c2);
    
    cout << ans;

    return 0;
}