#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int arr[100001];
int S[100001];

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    S[0] = 0;
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; S[i] = S[i-1]+arr[i]; }
    
    int A, B, C; A = B = C = 0;
    
    for(int i = 2; i < N; i++) {
        A = max(A, (S[i]-S[1])+(S[N-1]-S[i-1]));
    }
    
    for(int i = 2; i < N; i++) {
        B = max(B, (S[N]-S[1]-arr[i])+(S[N]-S[i]));
    }
    
    for(int i = 2; i < N; i++) {
        C = max(C, (S[N-1]-S[0]-arr[i])+(S[i-1]-S[0]));
    }
    
    cout << max(A, B, C);

    return 0;
}