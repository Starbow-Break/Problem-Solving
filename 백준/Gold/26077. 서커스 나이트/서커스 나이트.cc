#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int parent[1'000'001] = {0, };
int sz[1'000'001] = {0, };

bool isPrime[1'000'001];
vector<int> primes;
void getPrime() {
    fill(isPrime+2, isPrime+1'000'001, true);
    
    for(int i = 2; i <= 1'000'000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            
            for(int j = i*2; j <= 1'000'000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void unionSet(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    
    if(ra == rb) return;
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra; sz[ra] += sz[rb];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int id; cin >> id;
        parent[id] = id; sz[id]++;
    }
    
    getPrime();
    
    for(auto &p: primes) {
        int minId = 0;
        for(int i = p; i <= 1'000'000; i += p) {
            if(parent[i] == 0) continue;
            
            if(minId == 0) minId = i;
            else unionSet(minId, i);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 1'000'000; i++) ans = max(ans, sz[i]);
    cout << ans;

    return 0;
}