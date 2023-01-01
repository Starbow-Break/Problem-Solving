#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, K, sqN;

struct query {
    int l, r, idx;
    
    bool operator<(query &q) {
        if(l/sqN != q.l/sqN) return l/sqN < q.l/sqN;
        else return r < q.r;
    }
};

vector<query> queries;
list<int> indexList[1000000];
int cnt[1000][1000] = {0, };
int rowCnt[1000] = {0, };
int ans[100001];

int S[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K; 
    S[0] = 0; indexList[0].push_back(0);
    sqN = floor(sqrt(N));
    for(int i = 1; i <= N; i++) { cin >> S[i]; S[i] += S[i-1]; S[i] %= K; }
    
    int M; cin >> M;
    for(int i = 1; i <= M; i++) {
        int l, r; cin >> l >> r;
        queries.push_back({l, r, i});
    }
    
    sort(queries.begin(), queries.end());
    
    int bl = 1; int br = 0;
    for(int i = 0; i < M; i++) {
        int l = queries[i].l; int r = queries[i].r;
        int idx = queries[i].idx;
        
        while(br < r) {
            br++;
            
            if(indexList[S[br]].size() >= 2) {
                int len = indexList[S[br]].back()-indexList[S[br]].front();
                cnt[len/1000][len%1000]--; rowCnt[len/1000]--;
            }
            
            indexList[S[br]].push_back(br);
            
            if(indexList[S[br]].size() >= 2) {
                int len = indexList[S[br]].back()-indexList[S[br]].front();
                cnt[len/1000][len%1000]++; rowCnt[len/1000]++;
            }
        }
        while(br > r) {
            if(indexList[S[br]].size() >= 2) {
                int len = indexList[S[br]].back()-indexList[S[br]].front();
                cnt[len/1000][len%1000]--; rowCnt[len/1000]--;
            }
            
            indexList[S[br]].pop_back();
            
            if(indexList[S[br]].size() >= 2) {
                int len = indexList[S[br]].back()-indexList[S[br]].front();
                cnt[len/1000][len%1000]++; rowCnt[len/1000]++;
            }
            
            br--;
        }
        while(bl > l) {
            bl--;
            
            if(indexList[S[bl-1]].size() >= 2) {
                int len = indexList[S[bl-1]].back()-indexList[S[bl-1]].front();
                cnt[len/1000][len%1000]--; rowCnt[len/1000]--;
            }
            
            indexList[S[bl-1]].push_front(bl-1);
            
            if(indexList[S[bl-1]].size() >= 2) {
                int len = indexList[S[bl-1]].back()-indexList[S[bl-1]].front();
                cnt[len/1000][len%1000]++; rowCnt[len/1000]++;
            }
        }
        while(bl < l) {
            if(indexList[S[bl-1]].size() >= 2) {
                int len = indexList[S[bl-1]].back()-indexList[S[bl-1]].front();
                cnt[len/1000][len%1000]--; rowCnt[len/1000]--;
            }
            
            indexList[S[bl-1]].pop_front();
            
            if(indexList[S[bl-1]].size() >= 2) {
                int len = indexList[S[bl-1]].back()-indexList[S[bl-1]].front();
                cnt[len/1000][len%1000]++; rowCnt[len/1000]++;
            }
            
            bl++;
        }
        
        int a, b;
        for(a = 999; a >= 0; a--) {
            if(rowCnt[a]) break;
        }
        
        if(a < 0) ans[idx] = 0;
        else {
            for(b = 999; b >= 0; b--) {
                if(cnt[a][b]) break;
            }
            
            ans[idx] = 1000*a+b;
        }
    }
    
    for(int i = 1; i <= M; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}