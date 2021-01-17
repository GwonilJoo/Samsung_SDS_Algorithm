// 3020 개똥벌레

/*

H=5라고 가정하자
H = 1 -> bottom 중 1보다 크거나 같은 개수 + top 중 5보다 크거나 같은 개수
H = 2 -> bottom 중 2보다 크거나 같은 개수 + top 중 4보다 크거나 같은 개수
H = 3 -> bottom 중 3보다 크거나 같은 개수 + top 중 3보다 크거나 같은 개수
H = 4 -> bottom 중 4보다 크거나 같은 개수 + top 중 2보다 크거나 같은 개수
H = 5 -> bottom 중 5보다 크거나 같은 개수 + top 중 1보다 크거나 같은 개수

내가 생각한 방식. 이런식으로 구해 나가자!
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> top, bottom;
int N, H;

void init(){
  cin >> N >> H;  
  
  int size;
  for(int i=1;i<=N;i++){
    cin >> size;
    if(i%2) bottom.push_back(size);
    else top.push_back(size); 
  }
  
  sort(bottom.begin(), bottom.end());
  sort(top.begin(), top.end());
}

int lower_bound(vector<int>& v, int target){
  int mid, start, end;
  start = 0; end = v.size()-1;
  
  while(end > start){
    mid = (start+end)/2;
    
    if(v[mid] >= target) end = mid;
    else start = mid+1; 
  }
  
  if(v[end] >= target) return end; // target 보다 크거나 같더라도 end는 항상 size-1 이하이므로, +1을 해준다
  else return end+1;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  init();
  
  int ans=2*1e5, cnt=0;
  for(int i=1;i<=H;i++){
    int result = (top.size() - lower_bound(top, H-i+1)) + (bottom.size() - lower_bound(bottom, i));
    
    //cout << i << "'s resut: " << result << endl;
    if(result < ans){
      ans = result; cnt = 1;
    }
    else if(result == ans) cnt++;
    else continue;
  }
  
  cout << ans << " " << cnt << "\n";
}
