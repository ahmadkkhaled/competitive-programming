const int S = 2e7+1;
bool prime[S];

void sieve(){
    fill(prime, prime+S, true);
    prime[1] = prime[0] =  false;

    for(int i=2; i*i<=S; ++i){
        if(prime[i]){
            for(int j = i + i; j < MXN; j += i) {
                prime[j] = false;
            }
        }
    }
}
