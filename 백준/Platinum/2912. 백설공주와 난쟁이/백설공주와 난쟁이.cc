#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, C, n; 

struct query {
    int s, f, idx;
    
    bool operator<(query &Q) {
        int a = s/n; int b = Q.s/n;
        if(a != b)
            return a < b;
        else
            return f < Q.f;
    }
};

int color[300001];
int cnt[10001] = {0, };
vector<query> queries;
pair<bool, int> ans[10001];
int countArr[300001]; int idx = 0;

void update(int cur, bool isInsert) {
    int curCol = color[cur];
    if(isInsert) {
        countArr[cnt[curCol]] -= curCol;
        cnt[curCol]++;
        countArr[cnt[curCol]] += curCol;
        if(idx < cnt[curCol]) { idx = cnt[curCol]; }
    }
    else {
        countArr[cnt[curCol]] -= curCol;
        cnt[curCol]--;
        countArr[cnt[curCol]] += curCol;
        if(countArr[idx] == 0) { idx--; }
    }
}

void solve() {
    countArr[0] = C*(C+1)/2;
    sort(queries.begin(), queries.end());
    
    int i = -1; int j = -1;
    for(auto &q: queries) {
        int s = q.s; int f = q.f;
        if(i == -1 && j == -1) {
            i = s; j = f;
            for(int l = s; l <= f; l++) {
                update(l, true);
            }
        }
        else {
            while(j < f) {
                j++;
                update(j, true);
            }
            while(i > s) {
                i--;
                update(i, true);
            }
            while(j > f) {
                update(j, false);
                j--;
            }
            while(i < s) {
                update(i, false);
                i++;
            }
        }

        ans[q.idx] = {(idx > (f-s+1)/2), countArr[idx]};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C; n = sqrt(N);
    for(int i = 1; i <= N; i++) { cin >> color[i]; }
    
    int M; cin >> M;
    for(int i = 1; i <= M; i++) {
        int s, f; cin >> s >> f;
        queries.push_back({s, f, i});
    }
    
    solve();
    
    for(int i = 1; i <= M; i++) {
        if(ans[i].first)
            cout << "yes " << ans[i].second;
        else
            cout << "no";

        cout << '\n';
    }

    return 0;
}
