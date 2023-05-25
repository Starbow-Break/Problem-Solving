#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num, k; cin >> num >> k;
    ll ans = 0;
    if(num == 1 || num == 5) cout << 8LL*k+num-1;
    else cout << 8LL*(k/2)+(k%2 ? 9-num : num-1);

    return 0;
}