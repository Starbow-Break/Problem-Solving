#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int INF = 2'100'000'000;

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.fi > b.fi;
    }
};

int N;
vector<int> initNum, L, R, minCost; // 처음 수, 왼쪽 힙, 오른쪽 힙, 최소 Cost
vector<priority_queue<int, vector<int>, greater<int>>> pqs; // 최소 힙들의 모임
priority_queue<pii, vector<pii>, cmp> _pq;

// 초기화
void init() {
    initNum.clear(); L.clear(); R.clear(); minCost.clear();
    pqs.clear();
    while(!_pq.empty()) _pq.pop();
}

// 힙에서 두번째로 위에 있는 원소 반환
int secondTop(int idx) {
    int a = pqs[idx].top(); pqs[idx].pop();
    int ret = pqs[idx].top();
    pqs[idx].push(a);
    return ret; 
}

// 두 힙 합침
void merge(int a, int b) {
    if(pqs[a].size() < pqs[b].size()) swap(pqs[a], pqs[b]);
    while(pqs[b].size()) {
        pqs[a].push(pqs[b].top());
        pqs[b].pop();
    }
}

// 최소 비용 구하기
int getMinCost(int i) {
    int ret = INF;
    if(pqs[i].size() >= 2) {
        ret = min(ret, pqs[i].top()+secondTop(i));
    }
    if(initNum[i] != INF && pqs[i].size() >= 1) {
        ret = min(ret, pqs[i].top()+initNum[i]);
    }
    if(initNum[R[i]] != INF && pqs[i].size() >= 1) {
        ret = min(ret, pqs[i].top()+initNum[R[i]]);
    }
    if(initNum[i] != INF && initNum[R[i]] != INF) {
        ret = min(ret, initNum[i]+initNum[R[i]]);
    }
    return ret;
}

ll solve(vector<int> &vec) {
    ll ret = 0;
    
    //초기 세팅
    initNum.resize(N+2); L.resize(N+2); R.resize(N+2); minCost.resize(N+2);
    pqs.resize(N+2);
    FOR(i, 1, N+1) {
        initNum[i] = vec[i-1];
        L[i] = i-1; R[i] = i+1;
    }
        
    initNum[0] = initNum[N+1] = INF;
    R[0] = 1; L[N+1] = N;
    FOR(i, 1, N) {
        minCost[i] = initNum[i]+initNum[i+1];
        _pq.push({minCost[i], i});
    }
    
    // 파일이 하나 남을 때 까지
    int e = N;
    while(e > 1) {
        int c = _pq.top().fi;
        int i = _pq.top().se;
        _pq.pop();
        
        if(minCost[i] != c) continue; //최신 정보가 아니면 스킵
        
        //기존 값이 아닌 두 값에서 최소가 나올 경우
        if(pqs[i].size() >= 2 && pqs[i].top()+secondTop(i) == c) {
            pqs[i].pop(); pqs[i].pop();
        }
        // 현재 위치의 기존 값과 새로운 값에서 최소가 나올 경우
        else if(initNum[i] != INF && pqs[i].size() >= 1 && pqs[i].top()+initNum[i] == c) {
            minCost[i] = initNum[i] = INF; pqs[i].pop();
            L[R[i]] = L[i];
            R[L[i]] = R[i];
            merge(L[i], i);
            i = L[i];
        }
        // 현재 위치의 오른쪽의 기존 값과 새로운 값에서 최소가 나올 경우
        else if(initNum[R[i]] != INF && pqs[i].size() >= 1 && pqs[i].top()+initNum[R[i]] == c) {
            minCost[R[i]] = initNum[R[i]] = INF; pqs[i].pop();
            merge(i, R[i]);
            L[R[R[i]]] = i;
            R[i] = R[R[i]];
        }
        // 현재 위치의 기존 값과 오른쪽의 기존 값에서 최소가 나올 경우
        else if(initNum[i] != INF && initNum[R[i]] != INF && initNum[i]+initNum[R[i]] == c) {
            minCost[i] = minCost[R[i]] = initNum[i] = initNum[R[i]] = INF;
            R[L[i]] = R[R[i]];
            L[R[R[i]]] = L[i];
            merge(i, R[i]);
            merge(L[i], i);
            i = L[i];
        }
        
        pqs[i].push(c); minCost[i] = getMinCost(i);
        _pq.push({minCost[i], i});
        ret += c;
        e--;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init(); //초기화
        
        //파일의 크기 받기
        cin >> N;
        vector<int> sz(N);
        FOR(i, 0, N) cin >> sz[i];
        
        //최소 비용 출력
        cout << solve(sz) << '\n';
    }
    
    return 0;
}