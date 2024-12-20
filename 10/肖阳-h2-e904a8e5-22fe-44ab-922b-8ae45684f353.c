#define MAX 1000000007

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp ) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int countGoodNumbers(long long n) {
    // 使用快速幂算法计算 (4^((n+1)/2)) * (5^(n/2)) % MAX
    long long even_power = (n) / 2;
    long long odd_power = (n+1) / 2;
    long long four_pow = mod_pow(4, even_power, MAX);
    long long five_pow = mod_pow(5, odd_power, MAX);
    return (four_pow * five_pow) % MAX;
}