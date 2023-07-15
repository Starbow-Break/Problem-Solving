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

bool isPrime[10001];
void getPrime() {
    isPrime[1] = false;
    fill(isPrime+2, isPrime+10001, true);
    
    for(int i = 2; i <= 10000; i++) {
        if(isPrime[i]) {
            for(int j = i*2; j <= 10000; j += i) isPrime[j] = false;
        }
    }
}

bool visited[330];
bool isHappy(int v) {
    fill(visited, visited+330, false);
    if(v < 330) visited[v] = true;
    
    int cur = v;
    while(1) {
        int next = 0;
        while(cur > 0) {
            next += (cur%10)*(cur%10);
            cur /= 10;
        }
        if(next == 1) return true;
        if(visited[next]) return false;
        visited[next] = true;
        cur = next;
    }
}

bool isHappyPrime(int v) {
    return isPrime[v] && isHappy(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    int arr[N], cnt[N], t[N];
    for(int i = 0; i < N; i++) {
        arr[i] = cnt[i] = t[i] = 0;
    }
    
    for(int m = 1; m <= M; m++) {
        int v; cin >> v;
        
        int target = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] == 0) {
                arr[i] = v;
                cnt[i] = 1; t[i] = m;
                target = -1;
                break;
            }
            if(arr[i] == v) {
                cnt[i]++;
                target = -1;
                break;
            }
            if(cnt[i] < cnt[target]) target = i;
            if(cnt[i] == cnt[target] && t[i] < t[target]) target = i;
        }
        
        if(target >= 0) {
            arr[target] = v; cnt[target] = 1;
            t[target] = m;
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(arr[i] > 0) ans.push_back(arr[i]);
    }
    
    sort(ans.begin(), ans.end());
    
    for(auto &v: ans) cout << v << ' ';

    return 0;
}