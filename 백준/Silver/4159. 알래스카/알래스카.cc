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
    
    int N;
    while(cin >> N) {
        if(!N) break;
        vector<int> vec;
        for(int i = 1; i <= N; i++) {
            int v; cin >> v;
            vec.push_back(v); vec.push_back(2844-v);
        }
        vec.push_back(0); vec.push_back(2844);
        
        sort(vec.begin(), vec.end());
        
        bool isPos = true;
        for(int i = 0; i < vec.size()-1; i++) {
            if(vec[i+1]-vec[i] > 200) {
                isPos = false;
                continue;
            }
        }
        
        cout << (isPos ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }

    return 0;
}