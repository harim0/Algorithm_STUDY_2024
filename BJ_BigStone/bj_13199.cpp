#include<bits/stdc++.h>

using namespace std;

int t,p,m,f,c;
int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        int s = 0;
        int d = 0;
        cin>>p>>m>>f>>c;
        // int chicken = m/p;
        // s+=chicken;
        // while(chicken/f>=1){
        //     chicken*=c;
        //     chicken/=f;
        //     s+=chicken;
        // }
        s = m/p;
        int k = (m/p)*c;
        if (k >= f){
			k -= f;
			s += 1;
			s += k / (f - c);
		} // 얼탱이가 옶다,,
        d=(m/p)+(m/p)*c/f;
        if(s>d) cout<<endl<<s-d<<endl;
        else cout<<0<<endl;
    }
    return 0;
}