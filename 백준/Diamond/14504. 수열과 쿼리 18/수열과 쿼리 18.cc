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

int N; int sqrtN;
int A[100001];
vector<int> part[340];

void init() {
    for(int i = 0; i <= (N-1)/sqrtN; i++) {
        for(int j = 0; j < sqrtN; j++) {
            if(i*sqrtN+j >= N) break;
            part[i].push_back(A[i*sqrtN+j]);
        }
        sort(part[i].begin(), part[i].end());
    }
}

int query(int i, int j, int k) {
    int iPart = i/sqrtN; int iIdx = i%sqrtN;
    int jPart = j/sqrtN; int jIdx = j%sqrtN;
    
    int ret = 0;
    if(iPart == jPart) {
        for(int a = iIdx; a <= jIdx; a++) {
            if(A[iPart*sqrtN+a] > k) ret++;
        }
        return ret;
    }
    
    for(int a = iPart; a <= jPart; a++) {
        if(a == iPart) {
            for(int b = iIdx; b < sqrtN; b++) {
                if(A[a*sqrtN+b] > k) ret++;
            }
        }
        else if(a == jPart) {
            for(int b = 0; b <= jIdx; b++) {
                if(A[a*sqrtN+b] > k) ret++;
            }
        }
        else {
            int t = upper_bound(part[a].begin(), part[a].end(), k)-part[a].begin();
            ret += sqrtN-t;
        }
    }
    
    return ret;
}

void update(int i, int k) {
    int iPart = i/sqrtN;
    int t = lower_bound(part[iPart].begin(), part[iPart].end(), A[i])-part[iPart].begin();
    part[iPart][t] = k;
    sort(part[iPart].begin(), part[iPart].end());
    
    A[i] = k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; sqrtN = floor(sqrt(N));
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    
    init();
    
    int M; cin >> M;
    while(M--) {
        int q; cin >> q;
        if(q == 1) {
            int i, j, k; cin >> i >> j >> k;
            cout << query(i-1, j-1, k) << '\n';
        }
        else {
            int i, k; cin >> i >> k;
            update(i-1, k);
            /*for(int i = 0; i < N; i++) { cout << A[i] << " "; } cout << '\n';
            for(int i = 0; i <= (N-1)/sqrtN; i++) {
                for(int j = 0; j < part[i].size(); j++) {
                    cout << part[i][j] << " ";
                }
                cout << '\n';
            }
            cout << "-----------------------------" << '\n';*/
        }
    }

    return 0;
}