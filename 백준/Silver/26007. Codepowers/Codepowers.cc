#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MAX 100000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M, K, X;
int A[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K >> X;
    
    A[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i]; A[i] += A[i-1];
    }
    
    for(int i = 1; i <= N; i++) { A[i] = (A[i] < K-X); }
    for(int i = 1; i <= N; i++) { A[i] += A[i-1]; }
    
    while(M--) {
        int s, f; cin >> s >> f;
        cout << A[f-1]-A[s-1] << '\n';
    }

    return 0;
}