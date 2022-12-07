#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct node {
    int pow3, pow2, index;
    
    bool operator<(node &N) {
        if(pow3 != N.pow3) return pow3 > N.pow3;
        return pow2 < N.pow2;
    }
};

int N;
ll A[101];
node B[101];

node getNode(ll value, int index) {
    int pow3 = 0; int pow2 = 0;
    
    while(!(value%3)) { pow3++; value /= 3; }
    while(!(value%2)) { pow2++; value /= 2; }
    
    return {pow3, pow2, index};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = getNode(A[i], i);
    }
    
    sort(B+1, B+N+1);
    
    for(int i = 1; i <= N; i++) { cout << A[B[i].index] << " "; }

    return 0;
}