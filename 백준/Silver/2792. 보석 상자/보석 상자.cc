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
    
    int N, M; cin >> N >> M;
    vector<int> vec;
    for(int i = 0; i < M; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    int i = 1, j = 1'000'000'000;
    while(i <= j) {
        int mid = i+j >> 1;
        int cur = 0;
        for(int i = 0; i < M; i++) {
            cur += vec[i]/mid+(vec[i]%mid > 0);
        }
        
        if(cur <= N) j = mid-1;
        else i = mid+1;
    }
    
    cout << i;

    return 0;
}