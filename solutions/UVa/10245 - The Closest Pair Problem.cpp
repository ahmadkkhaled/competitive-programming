#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

double getDistance(pair<double,double> &p1, pair<double,double> &p2){
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;

    double d1 = x1-x2;
    d1*=d1;

    double d2 = y1-y2;
    d2*=d2;

    return sqrt(d1 + d2);
}

double bruteForce(vector<pair<double,double>> &p, int l, int r){
    double minimum_distance = 1e4;
    for(int i = l; i<=r; i++){
        for(int j = i+1; j<=r; ++j){
            minimum_distance = min(minimum_distance, getDistance(p[i], p[j]));
        }
    }
    return minimum_distance;
}

double join(vector<pair<double,double>> &p, int l, int r, double min_l, double min_r){
    double segma = min(min_l, min_r);
    int mid = (l + r) / 2;
    double mid_line = (p[mid].first + p[mid+1].first)/2;

    vector<pair<double,double>> strip;
    for(int i = l; i<=r; i++){
        if(abs(p[i].first - mid_line) < segma)
            strip.push_back(p[i]);
    }
    double strip_minimum = bruteForce(strip, 0, (int)strip.size() - 1); /// O(c) because strip.size is estimated at MAX 8 points
    return min(strip_minimum, segma);
}

double divide(vector<pair<double,double>> &p, int l, int r){
    if(r-l + 1 <= 3){
        return bruteForce(p, l, r);
    }

    int mid = (l+r)/2;
    double min_l = divide(p, l, mid);
    double min_r = divide(p, mid+1, r);

    return join(p, l, r, min_l, min_r);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    while(cin >> n && n){

        vector<pair<double,double>> p(n);
        for(int i = 0; i<n; i++){
            cin >> p[i].first >> p[i].second;
        }

        sort(p.begin(), p.end());

        double minimum_distance = divide(p, 0, n-1);
        if(minimum_distance < 1e4)
            cout << fixed << setprecision(4) << minimum_distance << '\n';
        else
            cout << "INFINITY" << '\n';
    }
}

