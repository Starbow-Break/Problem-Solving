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

int arr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    for(int i = 1; i <= N; i++) arr[i] = i;
    
    while(M--) {
        int i, j, k; cin >> i >> j >> k;
        
        int temp[101];
        for(int a = 1; a <= N; a++) {
            if(k <= a && a <= j) temp[i+(a-k)] = arr[a];
            else if(i <= a && a < k) temp[j-k+a+1] = arr[a];
            else temp[a] = arr[a];
        }
        
        for(int a = 1; a <= N; a++) arr[a] = temp[a];
    }
    
    for(int i = 1; i <= N; i++) cout << arr[i] << ' ';

    return 0;
}