// 소수판정법

// 0. 단순 숫자 1개 판별 (O(sqrt(n)))
/*
bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) { //2~n의 제곱근까지
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}
*/

// 1. 에라토스테네스의 체 O(Nlog(logN))
/*
for(int i = 2; i<n; i++){
    if(!primes[i]) continue;
    for(int j = i*i; j<n; j+=i){
        primes[j] = false;
    }
}
*/
