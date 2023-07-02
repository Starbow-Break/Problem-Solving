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
    
    int N; cin >> N;
    queue<int> buffer;
    int v;
    while(cin >> v) {
        if(v == -1) break;
        if(v) {
            if(buffer.size() >= N) {
                while(!buffer.empty()) buffer.pop();
            }
            buffer.push(v);
        }
        else if(!buffer.empty()) buffer.pop();
    }
    
    if(buffer.empty()) cout << "empty";
    else {
        while(!buffer.empty()) {
            cout << buffer.front() << ' ';
            buffer.pop();
        }
    }

    return 0;
}