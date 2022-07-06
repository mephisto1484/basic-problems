#include <iostream>
#include<queue>
#include<set>
#include<time.h>
using namespace std;

#define A_sum 500
#define B_sum 502
#define C_sum 1000
struct state {
	int a, b, c,level;
	state() {
		a = b = c = level = 0;
	}
	state(int A, int B, int C, int Level) {
		a = A; b = B; c = C; level = Level;
	}
};

int num[1010];
queue<state> area;
bool visit[502][505][1002];
int main(){
	time_t timeA,timeB ;
	time(&timeA);
	memset(num, -1, sizeof(num));
	memset(visit, 0, sizeof(num));
	visit[500][502][0] = 1;
	area.push(state(500, 502, 0, 0));
	state tmp; int a, b, c,level;
	while (!area.empty()) {
		tmp = area.front();
		area.pop();
		a = tmp.a; b = tmp.b; c = tmp.c; level = tmp.level;
		{
			//if (level == 1)cout << a << " " << b<<" " << c << endl;
			if (num[a] < 0)num[a] = level;
			if (num[b] < 0)num[b] = level;
			if (num[c] < 0)num[c] = level;
			if (num[a + b] < 0)num[a + b] = level;
			if (num[a + c] < 0)num[a + c] = level;
			if (num[b + c] < 0)num[b + c] = level;
		}
		{
			if (a > 0) {
				if (!visit[max(0, a + b - B_sum)][min(B_sum, a + b)][c]) {
					area.push(state(max(0, a + b - B_sum), min(B_sum, a + b), c, level + 1));
					visit[max(0, a + b - B_sum)][min(B_sum, a + b)][c] = 1;
				}
				if (!visit[max(0, a + c - C_sum)][b][min(a + c, C_sum)]) {
					area.push(state(max(0, a + c - C_sum), b, min(a + c, C_sum), level + 1));
					visit[max(0, a + c - C_sum)][b][min(a + c, C_sum)] = 1;
				}
			}
			if (b > 0) {
				if (!visit[min(A_sum, a + b)][max(0, a + b - A_sum)][c]) {
					area.push(state(min(A_sum, a + b), max(0, a + b - A_sum), c, level + 1));
					visit[min(A_sum, a + b)][max(0, a + b - A_sum)][c] = 1;
				}
				if (!visit[a][max(0, b + c - C_sum)][min(b + c, C_sum)]) {
					area.push(state(a, max(0, b + c - C_sum), min(b + c, C_sum), level + 1));
					visit[a][max(0, b + c - C_sum)][min(b + c, C_sum)] = 1;
				}
			}
			if (c > 0) {
				if (!visit[min(a + c, A_sum)][b][max(0, a + c - A_sum)]) {
					area.push(state(min(a + c, A_sum), b, max(0, a + c - A_sum), level + 1));
					visit[min(a + c, A_sum)][b][max(0, a + c - A_sum)] = 1;
				}
				if (!visit[a][min(b + c, B_sum)][max(b + c - B_sum, 0)]) {
					area.push(state(a, min(b + c, B_sum), max(b + c - B_sum, 0), level + 1));
					visit[a][min(b + c, B_sum)][max(b + c - B_sum, 0)] = 1;
				}
			}
		}

	}

Judge:
	cout << "input your number,or 0 to exit" << endl;
	int whichNum; cin >> whichNum;
	if (whichNum >= 500 && whichNum <= 1002) {
		if (num[whichNum] >= 0)
			cout << "This is" << num[whichNum] << "for you" << endl;
		else cout << "No!" << endl;
		goto Judge;
	}
	else {
		if (whichNum == 0);
		else {
			cout << "Wrong input!" << endl << endl;
			goto Judge;
		}
	}

	time(&timeB);
	cout << "Using time:" << timeB - timeA << endl;
	cout << "The all" << endl;

	for (int i = 500; i <= 1002; i++)
		cout << i << "  " << num[i] << endl;

}
