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
    
    int arr[50001];
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    int M; cin >> M;
    while(M--) {
        int q, l, r; cin >> q >> l >> r;
        if(q == 1) {
            for(int i = l; i <= r; i++) arr[i] = (arr[i]*arr[i])%2010;
        }
        else {
            int sum = 0;
            for(int i = l; i <= r; i++) sum += arr[i];
            cout << sum << '\n';
        }
    }

    return 0;
}