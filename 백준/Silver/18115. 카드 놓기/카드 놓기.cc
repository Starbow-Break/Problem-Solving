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

const int MAX = 1'000'000;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int ans[MAX+1] = {0, }; int f = 1, f2 = 2, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    b = N;
    
    for(int i = N; i >= 1; i--) {
        int v; cin >> v;
        if(v == 1) {
            ans[f] = i;
            while(f <= N && ans[f] > 0) f++;
            while(f >= f2 || (f2 <= N && ans[f2] > 0) ) f2++;
        }
        else if(v == 2) {
            ans[f2] = i;
            while(f2 <= N && ans[f2] > 0) f2++;
        }
        else {
            ans[b] = i; b--;
        }
    }
    
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';

    return 0;
}