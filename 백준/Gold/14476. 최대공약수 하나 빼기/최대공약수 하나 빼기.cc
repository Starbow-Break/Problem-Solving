#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 1000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int A[MAX+1], L[MAX+1], R[MAX+1];

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    
    for(int i = 1; i <= N; i++) {
        if(i == 1) L[i] = A[i];
        else L[i] = gcd(L[i-1], A[i]);
    }
    for(int i = N; i >= 1; i--) {
        if(i == N) R[i] = A[i];
        else R[i] = gcd(R[i+1], A[i]);
    }
    
    int ans = -1; int idx = -1;
    for(int i = 1; i <= N; i++) {
        int ret;
        if(i == 1) ret = R[i+1];
        else if(i == N) ret = L[i-1];
        else ret = gcd(L[i-1], R[i+1]);
        
        if(A[i]%ret && ans < ret) { 
            ans = ret; idx = i;
        }
    }
    
    cout << ans;
    if(ans != -1) cout << " " << A[idx];

    return 0;
}