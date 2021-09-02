map<int, int> f; /// can use vector<int> of size sqrt(input)
for(int i=2; i*i <= n; i++){
    while(n%i == 0){
        f[i]++;
        n/=i;
    }
}
if(n != 1){ /// don't remove
    f[n]++;
}