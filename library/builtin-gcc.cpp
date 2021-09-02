/// returns the index of the MSB if the 0-based indexing started from the LSB
/// e.g. 0 0 0 1 -> returns 0
/// e.g. 0 1 0 0 -> returns 2

int msb(int x){
    return 31 - __builtin_clz(x);
}

int msb(long long x){
    return 63 -__builtin_clzll(x);
}

__builtin_popcountll() /// popcount for long long

__builtin_popcount() /// popcount for int

