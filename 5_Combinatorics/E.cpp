// 5568 카드 놓기

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> v;
bool visit[10];
string card[10];

int n, k, ans;

void per(string s, int next, int depth){
  // 1. 체크인
  visit[next] = true;
  s += card[next];
  
  // 2. 목적지 도착?
  if(depth == k){
    v.push_back(s);
  }
  
  // 3. 연결된 곳 순회
  for(int i=0;i<n;i++){
    // 4. 갈 수 있는가?
    if(visit[i]) continue;
    
    // 5. 간다
    per(s, i, depth+1);
  }
     
  // 6. 체크아웃 
  visit[next] = false;
} 

int main(){
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> card[i];
  }

  for(int i=0;i<n;i++){
    per("", i, 1);
  }
  
  sort(v.begin(), v.end());
  
  string tmp = "";
  for(string a : v){
    if(a == tmp) continue;
    
    tmp = a; ans++;
  }
  
  cout << ans << endl;
}
