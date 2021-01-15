// 1722 순열의 순서

#include<iostream>
#include<vector>
using namespace std;

long long fact[21];
bool visited[21];
int a[21];

void factorial(){
  fact[0] = 1;
  for(int i=1;i<=20;i++){
    fact[i] = fact[i-1]*i;
  }
}

void query1(int n, long long k){
  for(int i=0;i<n;i++){
    for(int j=1;j<=n;j++){
      if(visited[j]) continue;
      if(fact[n-i-1] < k){
        k -= fact[n-i-1]; // 다음 숫자 범위 내에 k가 들어가는지 확인하기 위해 k에서 factorial을 빼줌.
      }
      else{
        a[i] = j;
        visited[j] = true;
        break;
      }
    }
  }
  
  for(int i=0;i<n;i++){
    cout << a[i] << " ";
  }
  cout << "\n";
}

long long query2(int N){
  long long ans = 1;
  for(int i=N-1;i>=0;i--){
    int x;
    cin >> x;
    
    for(int j=1;j<x;j++){
      if(!visited[j]){
        ans += fact[i];
      }
    }
    visited[x] = true;
  }
  
  return ans;
} 

int main(){
  int N, num;
  long long k;
  cin >> N >> num;
  
  factorial();
  
  if(num==1){
    cin >> k; 
    query1(N,k);
  }
  else{
    cout << query2(N) << "\n";
  }
}
