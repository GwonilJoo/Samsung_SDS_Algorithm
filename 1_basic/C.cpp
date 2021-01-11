#include<iostream>
#include<string>
using namespace std;

int N, K;
bool visited[26];
string words[50];
int selectedCount = 0;
int Max = 0;

void dfs(int index);
void check();

int main() {
	cin >> N >> K;

	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
	selectedCount = 5;

	for (int i = 0; i < N; i++)
		cin >> words[i];

	if (K < 5) {
		Max = 0;
	}
	else if (K == 26) {
		Max = N;
	}
	else if (K == 5) {
		check();
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
	}

	cout << Max;
}

void dfs(int index) {
	visited[index] = true;
	selectedCount++;

	if (selectedCount == K) {
		check();
	}

	else {
		for (int i = index + 1; i < 26; i++) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
	}
	
	visited[index] = false;
	selectedCount--;
}

void check() {
	int result = 0;
	bool flag;

	for (int i = 0; i < N; i++) {
		flag = true;
		for (int j = 0; j < words[i].length(); j++) {
			if (!visited[words[i][j] - 'a']) {
				flag = false;
				break;
			}
		}
	
		if (flag)
			result++;
	}

	if (Max < result)
		Max = result;
}

