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

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int B[N+1]; B[0] = 0;
    for(int i = 1; i <= N; i++) cin >> B[i];
    
    for(int i = 1; i <= N; i++) {
        cout << 1LL*B[i]*i-1LL*B[i-1]*(i-1) << ' ';
    }

    return 0;
}