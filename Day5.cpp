#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(it, cont) for(auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for(auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

#define sz(c) ((int)c.size())
#define print(v) cout << #v" = " << v << endl
#define printArr(arr, a, b) FOR(i, a, b) cout << #arr << "[" << i << "] = " << arr[i] << endl
#define zero(v) memset(v, 0, sizeof(v))
#define uno(v) memset(v, 1, sizeof(v))
#define unoneg(v) memset(v, -1, sizeof(v))
#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')
#define toCharA(i) (char)(i + 'a')
#define toChara(i) (char)(i + 'A')
#define toChar0(i) (char)(i + '0')


using namespace std;

typedef long long ll;

#define MAXN 10
#define MOD 1000000007

struct obj {
    ll x1, x2, y1, y2;
};
vector<obj> v;
int main() {
    ll x1,y1,x2,y2,mx = 0;
    while(scanf("%lld,%lld -> %lld,%lld", &x1,&y1,&x2,&y2) != EOF) {
        obj tmp;
        tmp.x1 = x1; tmp.y1 = y1; tmp.x2 = x2; tmp.y2 = y2;
        v.push_back(tmp);
        mx = max(mx, max(x1, max(y1, max(x2, y2))));
    }

    vector<vector<ll>> mat(mx + 5, vector<ll>(mx + 5, 0));
    for(obj o : v) {
        // vertical
        if(o.x1 == o.x2) {
            ll mini = min(o.y1, o.y2);
            ll maxi = max(o.y1, o.y2);
            for(ll i = mini; i <= maxi; i++) mat[o.x1][i]++;
        } else if(o.y1 == o.y2) {
            ll mini = min(o.x1, o.x2);
            ll maxi = max(o.x1, o.x2);
            for(ll i = mini; i <= maxi; i++) mat[i][o.y1]++;
        } else {
            ll minX = min(o.x1, o.x2), minY = min(o.y1, o.y2);
            ll maxX = max(o.x1, o.x2), maxY = max(o.y1, o.y2);
            ll slope = (o.y2 - o.y1) / (o.x2 - o.x1);
            if(slope > 0)
                for(ll i = minX, j = minY; i <= maxX && j <= maxY; i++, j++) {
                    mat[i][j]++;
                }
            else
                for(ll i = minX, j = maxY; i <= maxX && j >= minY; i++, j--) {
                    mat[i][j]++;
                }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < mx + 5; i++) {
        for(ll j = 0; j < mx + 5; j++) {
            if(mat[i][j] > 1) ans++;
        }
    }

    cout << ans << endl;
	
    return 0;
}