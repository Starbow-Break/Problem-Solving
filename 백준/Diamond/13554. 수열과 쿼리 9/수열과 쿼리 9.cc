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

int N, M;
int sqN;

struct query {
    int i, j, k, num;
    
    bool operator<(query &Q) {
        if(i/sqN != Q.i/sqN)
            return i/sqN < Q.i/sqN;
        else
            return j < Q.j;
    }
};

int seq[2][100001];
int cnt[2][100001] = {0, };
int segTree[2][200000] = {0, };
vector<query> queries;
ll ans[100001] = {0, };

void update(int val, int delta, char c) {
    int idx = val-1;
    cnt[c-'A'][val] += delta;
    segTree[c-'A'][idx+100000] += delta;
    for(int i = idx+100000; i > 1; i >>=1) {
        segTree[c-'A'][i>>1] = segTree[c-'A'][i]+segTree[c-'A'][i^1];
    }
}

int query(int i, int j, char c) {
    int ret = 0;
    
    i--; j--;
    for(int l = i+100000, r = j+100001; l < r; l >>= 1, r >>= 1) {
        if(l & 1) ret += segTree[c-'A'][l++];
        if(r & 1) ret += segTree[c-'A'][--r];
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; sqN = floor(sqrt(N));
    for(int a = 1; a <= N; a++) { cin >> seq[0][a]; }
    for(int a = 1; a <= N; a++) { cin >> seq[1][a]; }
    
    cin >> M;
    for(int a = 1; a <= M; a++) {
        int i, j, k; cin >> i >> j >> k;
        queries.push_back({i, j, k, a});
    }
    
    sort(queries.begin(), queries.end());
    
    int bi = -1; int bj = -1;
    for(int a = 0; a < M; a++) {
        int i = queries[a].i;
        int j = queries[a].j;
        int k = queries[a].k; int sqk = floor(sqrt(k));
        int num = queries[a].num;
        
        if(bi == -1) {
            bi = i; bj = j;
            for(int b = i; b <= j; b++) {
                update(seq[0][b], 1, 'A');
                update(seq[1][b], 1, 'B');
            }
            
            for(int b = 1; b <= sqk; b++) {
                ans[num] += 1LL*cnt[0][b]*query(b, k/b, 'B');
                ans[num] += 1LL*cnt[1][b]*query(b, k/b, 'A');
                ans[num] -= 1LL*cnt[0][b]*cnt[1][b];
            }
        }
        else {
            while(bi < i) {
                update(seq[0][bi], -1, 'A');
                update(seq[1][bi], -1, 'B');
                bi++;
            }
            while(bi > i) {
                bi--;
                update(seq[0][bi], 1, 'A');
                update(seq[1][bi], 1, 'B');
            }
            while(bj < j) {
                bj++;
                update(seq[0][bj], 1, 'A');
                update(seq[1][bj], 1, 'B');
            }
            while(bj > j) {
                update(seq[0][bj], -1, 'A');
                update(seq[1][bj], -1, 'B');
                bj--;
            }
            
            for(int b = 1; b <= sqk; b++) {
                ans[num] += 1LL*cnt[0][b]*query(b, k/b, 'B');
                ans[num] += 1LL*cnt[1][b]*query(b, k/b, 'A');
                ans[num] -= 1LL*cnt[0][b]*cnt[1][b];
            }
        }
    }
    
    for(int i = 1; i <= M; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}