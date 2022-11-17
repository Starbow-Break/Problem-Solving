#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, K; 
vector<int> A; //파인애플 토핑 수 (a_1, a_2, .., a_n, a_1, .., a_(n-1))
vector<int> B; //손님의 나이

//좌표 압축을 수행하기 위한 벡터
vector<int> vecA; vector<int> vecB; 

int segTree[270000] = {0, }; //A에서 값의 순위를 얻기위한 SegTree

void treeClear() {
    for(int i = 0; i < 270000; i++) {
        segTree[i] = 0;
    }
}

void update(int s, int f, int idx, int t, int delta) {
    if(f < t || t < s)
        return;
    
    if(s == f) {
        segTree[idx] += delta;
        return;
    }
    
    int mid = (s+f)/2;
    update(s, mid, 2*idx, t, delta);
    update(mid+1, f, 2*idx+1, t, delta);
    segTree[idx] = segTree[2*idx]+segTree[2*idx+1];
}

int query(int s, int f, int idx, int i, int j) {
    if(i > j)
        return 0;
        
    if(f < i || j < s)
        return 0;
    
    if(i <= s && f <= j) {
        return segTree[idx];
    }
    
    int mid = (s+f)/2;
    int L = query(s, mid, 2*idx, i, j);
    int R = query(mid+1, f, 2*idx+1, i, j);
    return L+R;
}

int fail[100000] = {0, };
int smaller[100000] = {0, };
int bigger[100000] = {0, };

bool isSameRank(int target, int cur, int size) {
    bool l = (smaller[target] == query(1, size, 1, 1, cur-1));
    bool r = (bigger[target] == query(1, size, 1, cur+1, size));
    return l && r;
}

void getFail() {
    for(int i = 0; i < K; i++) {
        smaller[i] = query(1, K, 1, 1, B[i]-1);
        bigger[i] = query(1, K, 1, B[i]+1, K);
        update(1, K, 1, B[i], 1);
    }
    
    treeClear();
    
    int j = 0;
    for(int i = 1; i < K; i++) {
        while(j > 0 && !isSameRank(j, B[i], K)) {
            for(int k = i-j; k < i-fail[j-1]; k++) {
                update(1, K, 1, B[k], -1);
            }
            
            j = fail[j-1];
        }
        if(isSameRank(j, B[i], K)) { fail[i] = j+1; update(1, K, 1, B[i], 1); j++; }
    }
    
}

int solve() {
    treeClear();
    
    int ans = 0;
    
    int a = 0; int cur = 0; int idx = 0;
    while(a < N) {
        if(isSameRank(idx, A[cur], N)) {
            if(idx == K-1) {
                ans++;
                idx = fail[K-1]-1;
                
                if(cur-idx >= N)
                    break;

                while(a < cur-idx) {
                    update(1, N, 1, A[a], -1);
                    a++;
                }
            }
            update(1, N, 1, A[cur], 1);
            cur++; idx++;
        }
        else {
            if(idx == 0) {
                update(1, N, 1, A[cur], 1);
                cur++;
                
                update(1, N, 1, A[a], -1);        
                a++;
            }
            else {
                idx = fail[idx-1];
                
                if(cur-idx >= N)
                    break;
    
                while(a < cur-idx) {
                    update(1, N, 1, A[a], -1);
                    a++;
                }
            }
        }
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        int value; cin >> value;
        A.push_back(value); vecA.push_back(value);
    }
    for(int i = 0; i < N-1; i++) {
        A.push_back(A[i]);
    }
    for(int i = 0; i < K; i++) {
        int value; cin >> value;
        B.push_back(value); vecB.push_back(value);
    }
    
    //좌표 압축
    sort(vecA.begin(), vecA.end());
    vecA.erase(unique(vecA.begin(), vecA.end()), vecA.end());
    for(int i = 0; i < A.size(); i++) {
        A[i] = lower_bound(vecA.begin(), vecA.end(), A[i])-vecA.begin()+1;
    }
    sort(vecB.begin(), vecB.end());
    vecB.erase(unique(vecB.begin(), vecB.end()), vecB.end());
    for(int i = 0; i < B.size(); i++) {
        B[i] = lower_bound(vecB.begin(), vecB.end(), B[i])-vecB.begin()+1;
    }
    
    getFail();
    
    cout << solve();

    return 0;
}