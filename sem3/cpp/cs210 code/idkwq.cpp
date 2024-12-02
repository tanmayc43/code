#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double strip_closest(vector<pair<int,int>> &strip, double overall_min){
    double min_dist = overall_min;
    int n = strip.size();
    sort(strip.begin(), strip.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].second - strip[i].second) < min_dist; ++j) {
            double d = dist(strip[i], strip[j]);
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }

    return min_dist;
}

double closestdist(vector<pair<int,int>> &v, int l, int r){
    if(r - l <= 3){
        double min_dist = DBL_MAX;
        for(int i = l; i < r; i++){
            for(int j = i + 1; j < r; j++){
                min_dist = min(min_dist, dist(v[i], v[j]));
            }
        }
        return min_dist;
    }

    int mid = l + (r - l) / 2;
    pair<int,int> midpoint = v[mid];
    
    double min_dist_l = closestdist(v, l, mid);
    double min_dist_r = closestdist(v, mid, r); 
    double overall_min = min(min_dist_l, min_dist_r);
    vector<pair<int,int>> strip;

    for(int i = l; i < r; i++){
        if(abs(v[i].first - midpoint.first) < overall_min){
            strip.push_back(v[i]);
        }
    }

    return min(overall_min, strip_closest(strip, overall_min));
}

double closest(vector<pair<int, int>>& v) {
    sort(v.begin(), v.end());
    return closestdist(v, 0, v.size());
}

int main(){
    fast;
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    // for(int i=0;i<n;i++){
    //     cout << v[i].first << "," << v[i].second << endl;
    // }

    cout << fixed << setprecision(6) << closest(v) << endl;

    return 0;
}
