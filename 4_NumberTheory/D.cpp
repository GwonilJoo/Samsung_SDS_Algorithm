// 2960 에라토스테네스의 체

#include<iostream>
using namespace std;

int N, K;
int *checked;

void prime_num(){
  int cnt = 1;
  for(int i=2;i<=N;i++){
    if(!checked[i]){
      checked[i] = cnt++;
      //cout << i << ": " << checked[i] << endl;
      for(int j=i+i;j<=N;j+=i){
        if(!checked[j]){
          checked[j] = cnt++;
          //cout << j << ": " << checked[j] << endl;
        }
      }
    }
  }
}

int main(){
  cin >> N >> K;
  checked = new int[N+1];
  prime_num();
  
  for(int i=2;i<=N;i++){
    if(checked[i] == K){
      cout << i << "\n";
      break;
    }
  }
}
