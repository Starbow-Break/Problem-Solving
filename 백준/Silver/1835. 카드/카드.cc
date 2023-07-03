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

int card[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    queue<int> q;
    for(int i = 0; i < N; i++) q.push(i);
    
    for(int i = 1; i <= N; i++) {
        int j = i;
        while(j--) {
            q.push(q.front()); q.pop();
        }
        
        card[q.front()] = i; q.pop();
    }
    
    for(int i = 0; i < N; i++) cout << card[i] << ' ';

    return 0;
}