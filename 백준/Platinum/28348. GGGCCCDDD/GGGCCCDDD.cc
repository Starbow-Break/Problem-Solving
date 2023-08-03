#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using int128 = __int128_t;

const int MAX = 1'000;
const int MOD = 1'000'000'007;

vector<int> primes; //소수
//w[1] == 0, w[i] == -1 (if p^2|i for some prime p)
//w[i] == k (if i == p_1 * ... * p_k for some distinct primes p_1, ..., p_k)
int w[MAX+1] = {0, };
//modPow[i][j] == i^j (mod MOD)
ll modPow[MAX+1][MAX+1];

//소수 구하기
void getPrimes() {
    bool isPrime[MAX+1];
    fill(isPrime+2, isPrime+MAX+1, true);
    for(int i = 2; i <= MAX; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

//modPow 전처리
void getModPow() {
    for(int i = 1; i <= MAX; i++) {
        modPow[i][0] = 1;
    }
    for(int i = 1; i <= MAX; i++) {
        for(int j = 1; j <= MAX; j++) {
            modPow[i][j] = (modPow[i][j-1]*i)%MOD;
        }
    }
}

//N, M이 주어질 때 gcd(a1, .., aM) == 1을 만족하는 순서쌍 (a1, ..., aM)의 갯수 
ll f(int N, int M) {
    ll ret = 0;
    for(int i = 1; i <= N; i++) {
        if(w[i] != -1) {
            ret += (w[i]%2 ? MOD-modPow[N/i][M] : modPow[N/i][M]);
            ret %= MOD;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes(); //소수 구하기
    getModPow(); //modPow 전처리
    
    //w[i] 전처리
    for(auto &p: primes) {
        for(int i = p; i <= MAX; i += p) {
            if(w[i] != -1) w[i]++;
        }
        for(int i = p*p; i <= MAX; i += p*p) {
            w[i] = -1;
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        //우리가 구하고자하는 답은 sum(k = 1 to N) k*f(N/k, M)이다.
        ll ans = 0;
        for(int k = 1; k <= N; k++) {
            ans += k*f(N/k, M);
            ans %= MOD;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}