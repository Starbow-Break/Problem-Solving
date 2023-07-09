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

const double PI = 3.141592653589793;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

bool check[7] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; check[0] = true;
    while(N--) {
        int v; cin >> v;
        bool temp[7] = {false, };
        for(int i = 0; i < 7; i++) {
            if(check[i]) temp[(i+v)%7] = true;
        }
        for(int i = 0; i < 7; i++) {
            if(temp[i]) check[i] = true;
        }
    }
    
    cout << (check[4] ? "YES" : "NO");

    return 0;
}