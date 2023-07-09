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
    
    int n, k; cin >> n >> k;
    vector<int> h;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        h.push_back(v);
    }
    
    int i = 0, j = 1'000'000'000;
    bool check[1'000'000] = {false, };
    while(i <= j) {
        fill(check, check+n, false);
        
        int mid = i+j >> 1;
        for(int i = 0; i < n-1; i++) {
            if(abs(h[i]-h[i+1]) > mid) {
                check[i] = check[i+1] = true;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += check[i];
        
        if(cnt <= k) j = mid-1;
        else i = mid+1;
    }
    
    cout << i;

    return 0;
}