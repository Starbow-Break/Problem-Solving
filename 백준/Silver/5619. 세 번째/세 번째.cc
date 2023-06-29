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

int merge(int a, int b) {
    int ret = a, w = 10000;
    while(b < w) w /= 10;
    while(w > 0) {
        ret = ret*10+(b/w);
        b -= (b/w)*w; w /= 10;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt[10001] = {0, };
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        cnt[v]++;
    }
    
    int t = min(n, 4);
    vector<int> vec, vec1;
    for(int i = 1; i <= 10000; i++) {
        while(t > 0 && cnt[i] > 0) { vec.push_back(i); t--; cnt[i]--; }
        if(t == 0) break;
    }
    
    for(int i = 0; i < min(n, 4); i++) {
        for(int j = i+1; j < min(n, 4); j++) {
            vec1.push_back(merge(vec[i], vec[j]));
            vec1.push_back(merge(vec[j], vec[i]));
        }
    }
    
    sort(vec1.begin(), vec1.end());
    
    cout << vec1[2];

    return 0;
}