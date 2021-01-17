// 11653 소인수분해

#include<iostream>
#include<vector>
using namespace std;

#define MAX 10000000

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
  
  int N, idx = 0;
  cin >> N;
  
  while(true){
    if(N == 1 || idx >= prime.size()) break;
    
    if(N%prime[idx] == 0){
      cout << prime[idx] << "\n";
      N/=prime[idx];
    }
    else{
      idx++;
    }
  }
}
