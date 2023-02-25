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
    
    int N, X; cin >> N >> X;
    int arr[101]; for(int i = 1; i <= N; i++) cin >> arr[i];
    
    int cur = 1;
    while(1) {
        if(arr[cur] < X) { cout << cur; break; }
        
        X++; cur = cur%N+1;
    }

    return 0;
}