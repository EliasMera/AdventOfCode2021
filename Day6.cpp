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

long long solve(int days) {
    string line;
    long long fish[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (getline(cin, line, ','))
        fish[atoi(line.c_str()) + 1]++;

    for (int d = 0; d <= days; d++)
        fish[(d + 7) % 9] += fish[d % 9];

    long long ans = 0;
    for(auto f : fish) ans += f;
    return ans;
}

int main() {
    cout << solve(256) << endl;
    return 0;
}