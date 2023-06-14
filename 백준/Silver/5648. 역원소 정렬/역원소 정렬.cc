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

void reverseNumber(ll &v) {
    vector<int> temp;
    while(v > 0) {
        temp.push_back(v%10);
        v /= 10;
    }
    
    temp.begin(), temp.end();
    
    for(auto &t: temp) v = v*10+t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<ll> vec;
    
    while(N--) {
        ll v; cin >> v;
        vec.push_back(v);
    }
    
    for(auto &v: vec) reverseNumber(v);
    
    sort(vec.begin(), vec.end());
    
    for(auto &v: vec) cout << v << '\n';

    return 0;
}