#include<bits/stdc++.h>
using namespace std;

long long euclid_gcd(long long a,long long b,long long *x, long long *y ){
	if(a==0){
		*x=0;*y=1;
		return b;
	}
	else{
		long long x1,y1;
		long long g=euclid_gcd(b%a,a,&x1,&y1);
		*x=y1-(b/a)*x1;
		*y=x1;
			return g;
	}

}
long long modinv(long long fact,long long p){
	long long x,y;
	long long gcd=euclid_gcd(fact,p,&x,&y);
	if(gcd!=1){
		return 0;
	}
	else{
		long long res=(x%p +p)%p;
		return res;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,p,fact=1;
		bool flag=false;
		cin>>n>>p;
		//cout<<n<<" "<<p<<endl;
		if(n>=p){
			cout<<0<<endl;
		}
		else{
		int d=abs(p-n-1);
		for(int i=2;i<=d;i++){
			fact=((fact%p)*(i%p));
		}
		long long ans=modinv(fact,p);
		if(d%2==0)ans=(p-ans)%p;
		cout<<ans<<endl;
	}	
}
}
