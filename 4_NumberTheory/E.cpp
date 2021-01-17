// 6588 골드바흐의 추측

#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000000

int N, K;
bool checked[MAX+1];
vector<int> v;

void prime_num(){
  for(int i=2;i<=MAX;i++){
    if(!checked[i]){
      if(i%2 == 1)
        v.push_back(i);
      for(int j=i+i;j<=MAX;j+=i){
        if(!checked[j]){
          checked[j] = true;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  prime_num();
  
  while(true){
    bool flag = false;
    int n;
    cin >> n;
    
    if(n == 0) break;
    
    for(int a : v){
      if(!checked[n-a]){
        cout << n << " = " << a << " + " << n-a << "\n";
        flag = true;
        break;
      }
    }
    
    if(!flag) cout << "Goldbach's conjecture is wrong.\n";
  }
}
