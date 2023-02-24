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

int need[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    need[0] = 0;
    for(int i = 1; i <= 10000; i++) {
        need[i] = need[i-1]+(2*i-1)*(2*i-1);
    }
    
    for(int i = 0; i <= 10000; i++) {
        if(N < need[i]) { cout << i-1; break; }
    }

    return 0;
}