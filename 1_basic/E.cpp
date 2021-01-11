// 1103 게임

#include<iostream>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct pos{
  int y, x;
};

int N, M;
int map[50][50], dp[50][50];
bool visited[50][50];

void init(){
  cin >> N >> M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
      char c;
      cin >> c;
      if(c >= '1' && c <= '9') 
        map[i][j] = c-'0';
    }
}

void show(){
  cout << endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++)
      cout << map[i][j];
    cout << endl;
  }
  
  cout << endl;
}

int DFS(int y, int x){
  // 구멍이거나 범위를 벗어난 경우, 0 리턴
  if(y < 0 || y >= N || x < 0 || x >= M || map[y][x] == 0){
    return 0;
  }
  
  // 이미 방문한 곳. 사이클 발생한 것. -1 리턴
  if(visited[y][x] == true){
    cout << -1 << endl;
    exit(0);
  }
  
  // 이 위치에서 최대 갈 수 있는 횟수. dp[y][x] 리턴
  if(dp[y][x] != 0){
    return dp[y][x];
  }
  
  // 체크인
  visited[y][x] = true;
  // 순회
  for(int i=0;i<4;i++){
    // 갈 수 있는가? = 이 위치에서 최대로 갈 수 있는 횟수 업데이트
    dp[y][x] = max(dp[y][x], DFS(y + map[y][x] * dy[i], x + map[y][x] * dx[i]) + 1);
  }
  // 체크아웃
  visited[y][x] = false;
  
  return dp[y][x];
}

int main(){
  init();
  cout << DFS(0, 0) << endl;
}
