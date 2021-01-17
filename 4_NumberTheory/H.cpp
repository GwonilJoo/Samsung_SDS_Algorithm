// 1837 암호제작
/*
강사님 방법
P의 범위가 10^100 ;;
string으로 나타내야 한다. string을 모듈러 연산 해야 함
*/

#include<iostream>
#include<cstring>
using namespace std;

bool *checked;
string P;
int K;

void moduler(int n){
  int x = 0;
  
  for(int i=0;i<P.length();i++){
    x = x * 10 + (P[i]-'0');
    x %= n; 
  }
  
  //cout << P << " % " << n << " = " << x << endl;
  
  if(x == 0){
    cout << "BAD " << n << "\n";
    exit(0);
  } 
}

void prime_num(){
  for(int i=2;i<K;i++){
    if(!checked[i]){
      moduler(i);
      for(int j=i+i;j<K;j+=i){
        checked[j] = true;
      }
    }
  }
}


int main(){
  cin >> P >> K;
  checked = new bool[K];
  prime_num();
  cout << "GOOD\n";
}
