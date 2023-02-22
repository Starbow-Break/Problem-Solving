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

bool check(int N) {
    int v = 0;
    
    int cur = N;
    while(cur > 0) {
        v += cur%10; cur /= 10;
    }
    
    return N%v == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; int ans = 0;
    for(int i = 1; i <= N; i++) ans += check(i);
    cout << ans;
    
    return 0;
}