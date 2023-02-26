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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    int r = 1, c; cin >> c; int d; cin >> d;
    
    int rr, cc; cin >> rr >> cc;
    
    while(1) {
        if(r == N && c == M) {cout << "YES!"; break;}
        if(r == rr && c == cc) {cout << "NO..."; break;}
        
        if(d == 0) {
            if(c == 1) {r++; d = 1;}
            else c--;
        }
        else {
            if(c == M) {r++; d = 0;}
            else c++;
        }
    }
    
    return 0;
}