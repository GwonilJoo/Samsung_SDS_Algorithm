// 2824 최대공약수
// 내가 품 캬캬

#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

int n, m;
ll a[1000], b[1000], ans = 1;
bool flag;

ll gcd(ll a, ll b){
  while(b!=0){
    ll r = a%b;
    a = b;
    b = r;
  }
  
  return a;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%lld", &a[i]);
  }
  
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    scanf("%lld", &b[i]);
  }
  
  for(int i=0;i<n;i++){
    if(a[i] == 1) continue;
    
    for(int j=0;j<m;j++){
      if(b[j] == 1) continue;
    
      ll gcd_ij = gcd(a[i], b[j]);
      
      if(gcd_ij != 1){
        ans *= gcd_ij;
        if(ans >= (ll)1e9) flag = true;
        ans %= (ll)1e9;
        a[i] /= gcd_ij;
        b[j] /= gcd_ij;
        
        if(a[i] == 1) break;
      }
    }
  }
  
  flag ? printf("%09lld\n", ans) : printf("%lld\n", ans);
}
