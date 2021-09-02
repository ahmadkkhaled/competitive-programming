/*
 * (A / B) % MOD = (A * mod_inv(B)) % MOD
 * mod_inv(B) = B^(MOD - 2), if MOD is prime
 *
 * modulo multiplicative inverse of N under MOD is X such that
 * (N * X) % MOD = 1
 * (5 * 3) % 7 = 1
 * */

ll mul(ll a, ll b){
    return (a * b) % MOD;
}
ll fastpow(ll base, ll power){
    assert(power >= 0);
    if(power == 0) return 1;
    if(power%2==0){
        ll ret = fastpow(base, power/2);
        return mul(ret, ret);
    }
    return mul(base, fastpow(base, power-1));
}

ll mod_inv(const ll &val){
    return fastpow(val, MOD - 2);
}