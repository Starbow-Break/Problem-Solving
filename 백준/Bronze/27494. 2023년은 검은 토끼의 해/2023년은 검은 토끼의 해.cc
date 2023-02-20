#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_V 50'000
#define MAX_E 200'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, ans = 0;
    cin >> N;
    
    int arr[4] = {2, 0, 2, 3};
    
    for(int i = 1; i <= N; i++) {
        int idx = 3; int cur = i;
        
        while(cur > 0 && idx >= 0) {
            if(cur%10 == arr[idx]) idx--;
            cur /= 10;
        }
        
        ans += (idx == -1);
    }
    
    cout << ans;

    return 0;
}