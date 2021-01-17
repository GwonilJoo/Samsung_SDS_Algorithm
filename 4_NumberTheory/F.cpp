// 1644 소수의 연속합

#include<iostream>
#include<vector>
using namespace std;

#define MAX 4000000

bool visit[MAX+1];
vector<int> prime;

void find_prime(){
  for(int i=2;i<=MAX;i++){
    if(!visit[i]){
      prime.push_back(i);
      for(int j=i;j<=MAX;j+=i){
        visit[j] = true;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  find_prime();
  
  int N, ans = 0;
  cin >> N;
  
  for(int i=0;i<prime.size();i++){
    if(prime[i] > N) break;
    
    int sum = 0;
    for(int j=i;j<prime.size();j++){
      sum += prime[j];
      
      if(sum == N){
        ans++; break;
      }
      else if(sum > N) break;
      else continue;
    }
  }
  
  cout << ans << endl;
}
