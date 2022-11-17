#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, K, M; 
struct query {
    int s, f, idx;
    
    bool operator<(query &Q) {
        int n = sqrt(N);
        int a = s/n;
        int b = Q.s/n;
        
        if(a != b)
            return a < b;
        else
            return f < Q.f;
    }
};

int arr[100001];
list<int> lis[100001];
int brr[100001] = {0, };
vector<query> queries;
int ans[100001];
int cnt[320][320] = {0, };
int rowCnt[320] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    int n = sqrt(N);
    cnt[0][0] = K; rowCnt[0] = K;
    
    int M; cin >> M;
    for(int i = 1; i <= M; i++) { int s, f; cin >> s >> f; queries.push_back({s, f, i}); }
    
    sort(queries.begin(), queries.end());
    
    int i = -1; int j = -1;
    for(auto &q: queries) {
        int s = q.s; int f = q.f;
        if(i == -1 && j == -1) {
            i = s; j = f;
            for(int l = s; l <= f; l++) {
                int v = arr[l];
                lis[v].push_back(l);

                cnt[brr[v]/n][brr[v]%n]--;
                rowCnt[brr[v]/n]--;
                    
                brr[v] = lis[v].back()-lis[v].front();
                
                cnt[brr[v]/n][brr[v]%n]++;
                rowCnt[brr[v]/n]++;
            }
        }
        else {
            while(j < f) {
                j++;
                int v = arr[j];
                lis[v].push_back(j);

                cnt[brr[v]/n][brr[v]%n]--;
                rowCnt[brr[v]/n]--;
                    
                brr[v] = lis[v].back()-lis[v].front();
                
                cnt[brr[v]/n][brr[v]%n]++;
                rowCnt[brr[v]/n]++;
            }
            while(i > s) {
                i--;
                int v = arr[i];
                lis[v].push_front(i);
                
                cnt[brr[v]/n][brr[v]%n]--;
                rowCnt[brr[v]/n]--;
                    
                brr[v] = lis[v].back()-lis[v].front();
                
                cnt[brr[v]/n][brr[v]%n]++;
                rowCnt[brr[v]/n]++;
            }
            while(j > f) {
                int v = arr[j];
                lis[v].pop_back();

                cnt[brr[v]/n][brr[v]%n]--;
                rowCnt[brr[v]/n]--;
                
                if(lis[v].empty())
                    brr[v] = 0;
                else
                    brr[v] = lis[v].back()-lis[v].front();
                    
                cnt[brr[v]/n][brr[v]%n]++;
                rowCnt[brr[v]/n]++;
                
                j--;
            }
            while(i < s) {
                int v = arr[i];
                lis[v].pop_front();

                cnt[brr[v]/n][brr[v]%n]--;
                rowCnt[brr[v]/n]--;
                
                if(lis[v].empty())
                    brr[v] = 0;
                else
                    brr[v] = lis[v].back()-lis[v].front();
                    
                cnt[brr[v]/n][brr[v]%n]++;
                rowCnt[brr[v]/n]++;
                
                i++;
            }
        }
        
        int r = N/n+1; int c = n-1;
        while(rowCnt[r] == 0) { r--; }
        while(cnt[r][c] == 0) { c--; }
        
        ans[q.idx] = r*n+c;
    }
    
    for(int i = 1; i <= M; i++) { cout << ans[i] << '\n'; }

    return 0;
}
