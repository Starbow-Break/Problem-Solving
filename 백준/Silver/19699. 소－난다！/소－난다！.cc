#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

vector<vector<int>> combination;
bool isPrime[9001];
void getPrimes() {
    isPrime[1] = false;
    fill(isPrime+2, isPrime+9001, true);
    
    for(int i = 2; i <= 9000; i++) {
        if(isPrime[i]) {
            for(int j = i*2; j <= 9000; j += i) isPrime[j] = false;
        }
    }
}

vector<int> temp;
void getCombination(int N, int M, int start = 0) {
    if(temp.size() == M) {
        combination.push_back(temp);
        return;
    }
    
    for(int i = start; i < N; i++) {
        temp.push_back(i);
        getCombination(N, M, i+1);
        temp.erase(temp.end()-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> weight, ans;
    for(int i = 0; i < N; i++) {
        int w; cin >> w;
        weight.push_back(w);
    }
    
    getCombination(N, M);
    getPrimes();
    
    for(auto &c: combination) {
        int cur = 0;
        for(auto &v: c) {
            cur += weight[v];
        }
        if(isPrime[cur]) ans.push_back(cur);
    }
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    if(ans.size() == 0) { cout << -1; return 0; }
    for(auto &a: ans) cout << a << ' ';

    return 0;
}