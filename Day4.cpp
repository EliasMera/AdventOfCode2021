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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef __int128 bigInt;

#define MAXN 10
#define MOD 1000000007

vector<int> split(string s) {
	vector<int> ans;
	int tmp = 0;
	for(char c : s) {
		if(c == ',') {
			ans.push_back(tmp);
			tmp = 0;
		} else {
			tmp *= 10;
			tmp += (c - '0');
		}
	}
	ans.push_back(tmp);
	
	return ans;
}

vector<vector<vector<int>>> boards;
vector<vector<vector<int>>> vis;

int markncheck(vector<vector<int>> &board, int x, vector<vector<int>> &vis) {
	int ren = -1, col = -1, sum = 0;
	int visH = 0, visV = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(board[i][j] == x) {
				ren = i;
				col = j;
				vis[i][j] = true;
			}
		}
	}
	
	if(ren == -1) return 0;
	
	// check horizontal
	for(int i = 0; i < 5; i++) {
		visH += vis[ren][i] == 1;
	}
	
	// vertical
	for(int i = 0; i < 5; i++) {
		visV += vis[i][col] == 1;
	}
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(!vis[i][j]) {
				sum += board[i][j];
			}
		}
	}
	
	if(visH == 5 || visV == 5) return sum;
	return 0;
}

int main() { _
	string s;
	cin >> s;
	vector<int> nums = split(s);
	map<int, int> haveWon;
	int howManyWon = 0;

	int first;
	while(cin >> first) {
		vector<vector<int>> board(5, vector<int>(5, 0));
		vis.push_back(board);
		board[0][0] = first;
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(i == 0 && j == 0) continue;
				cin >> board[i][j];
			}
		}
		boards.push_back(board);
	}
	
	for(int num : nums) {
		for(int i = 0; i < boards.size(); i++) {
			if(haveWon[i]) continue;
			int sum = markncheck(boards[i], num, vis[i]);
			if(sum > 0) {
				haveWon[i] = true;
				howManyWon++;
				if(howManyWon == (int) boards.size()) {
					cout << num << endl << sum << endl;
					cout << num * sum << endl;
					return 0;
				}
			}
		}
	}
	
	for(int i = 0; i < boards.size(); i++) {
		vector<vector<int>> v =  vis[i];
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

    return 0;
}