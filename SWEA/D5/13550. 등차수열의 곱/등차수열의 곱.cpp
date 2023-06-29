#include<iostream>

using namespace std;

const int MOD = 1'000'003;

long long fact[1'000'003]; //팩토리얼

long long modPow(int a, int e) {
    long long ret = 1, w = a;
    while(e > 0) {
        if(e%2) {
            ret = 1LL*ret*w%MOD;
        }
        w = 1LL*w*w%MOD;
        e /= 2;
    }
    return ret;
}

long long solve(int a, int d, int n) {
    if(d != 0 && n >= MOD) return 0;
    if(a == 0) return 0;
    if(d == 0) return 1LL*modPow(a, n)%MOD;
    long long k = 1LL*a*modPow(d, MOD-2)%MOD; //a = kd (mod MOD)
    if(k+n-1 >= MOD) return 0;
    return 1LL*modPow(d, n)*fact[k+n-1]%MOD*modPow(fact[k-1], MOD-2)%MOD;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int test_case;
	int T;
    cin>>T;
    
    //fact 전처리
    fact[0] = 1;
    for(int i = 1; i <= 1'000'002; i++) {
        fact[i] = 1LL*fact[i-1]*i%MOD;
    }
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, d, n; cin >> a >> d >> n;
		cout << '#' << test_case << ' ' << solve(a, d, n) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}