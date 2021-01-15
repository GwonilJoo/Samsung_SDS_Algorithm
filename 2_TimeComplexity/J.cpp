// 2842 집배원 한상덕

#include<iostream>
using namespace std;

int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};

struct node{
  int y, x, low, high, cnt;
};

int N;
char map[50][50];
int info[50][50];
bool visited[50][50];
node Post;
int K_cnt = 0, ans = 0;

void init();
void show();
void dfs(node cur);

int main(){
  init();
  //show();
  dfs(Post);
  cout << ans << endl;
}

void init(){
  cin >> N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      cin >> map[i][j];
      
      if(map[i][j] == 'P'){
        Post = {i, j, 0, 0, 0};
      }
      else if(map[i][j] == 'K')
        K_cnt++;
    }
    
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin >> info[i][j];
      
  Post.low = info[Post.y][Post.x];
  Post.high = info[Post.y][Post.x];
      
  cout << "K_cnt: " << K_cnt << endl;
}

void show(){
  cout << endl;
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << map[i][j];
      
    cout << endl;
  }
  
  cout << endl;
    
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout << info[i][j] << " ";
  
    cout << endl;
  }
}

void dfs(node cur){
  // 1. 체크인
  visited[cur.y][cur.x] = true;
  
  cout << "befor\n" << endl;
  cout << "cnt: " <<  cur.cnt << endl;
  cout << "low: " << cur.low << endl;
  cout << "high: " << cur.high << endl;
  
  if(map[cur.y][cur.x] == 'K') cur.cnt++;
  if(cur.low > info[cur.y][cur.x]) cur.low = info[cur.y][cur.x];
  if(cur.high < info[cur.y][cur.x]) cur.high = info[cur.y][cur.x];
  
  cout << "\nafter\n";
  cout << "cnt: " <<  cur.cnt << endl;
  cout << "low: " << cur.low << endl;
  cout << "high: " << cur.high << endl;
  cout << endl;
  
  // 2. 목적지 도달햇는가?
  if(cur.cnt == K_cnt){
    if(ans > (cur.high - cur.low))
      ans = cur.high - cur.low;
    return;
  }
  
  // 3. 연결된 곳 순회
  for(int i=0;i<8;i++){
    int ny = dy[i] + cur.y;
    int nx = dx[i] + cur.x;
    
     // 4. 갈 수 있는가?
    if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
      continue;
    
    // 5.간다
    dfs({ny, nx, cur.low, cur.high, cur.cnt});
  }
  
  // 6. 체크아웃
  visited[cur.y][cur.x] = false;
}
