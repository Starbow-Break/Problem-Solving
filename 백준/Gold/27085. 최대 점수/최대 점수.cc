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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, s;
ll A[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> s;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    for(int i = s-1; i >= 1; i--) { A[i] += A[i+1]; }
    for(int i = s+1; i <= N; i++) { A[i] += A[i-1]; }
    
    ll lmax = 0, rmax = 0;
    int i = s; int j = s;
    while(1) {
        bool flag = false;
        
        while(i > 1) {
            if(rmax+A[i-1] < 0) break;
            
            i--;
            if(lmax < A[i]) { lmax = A[i]; flag = true; }
        }
        while(j < N){
            if(lmax+A[j+1] < 0) break;
            
            j++;
            if(rmax < A[j]) { rmax = A[j]; flag = true; }
        }
        
        if(!flag) break;
    }
    
    cout << lmax+rmax;

    return 0;
}