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
    
    bool reversed = false;
    int N, M, K; cin >> N >> M >> K;
    
    if(1+N-K < M) { cout << -1; return 0; }
    
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        ans.push_back(i);
    }
    
    int q = 0;
    while(1+N-K >= M && M > 0) {
        reverse(ans.begin()+q, ans.begin()+q+K);
        q += K; N -= K; M--;
    }
    
    if(!M && N) { cout << -1; return 0; }
    reverse(ans.begin()+q, ans.begin()+q+N-M+1);
    
    for(auto &v: ans) cout << v << ' ';

    return 0;
}