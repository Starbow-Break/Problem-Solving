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

bool check(int num, int L) {
    int A = num;
    while(A > 0) {
        if(A%10 == L) return false;
        A /= 10;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, L; cin >> N >> L;
    
    int ans = 0;
    while(N > 0) {
        ans++;
        
        N -= check(ans, L);
    }
    
    cout << ans;
    
    return 0;
}