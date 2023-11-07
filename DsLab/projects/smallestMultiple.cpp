#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    map<int, int> m;
    m[2]=0;
    m[3]=0;
    for(int i=5;i*i<=n;i+=6){
        if(n%i!=0 && n%(i+2)!=0){
        m[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(const auto& j:m){
        if(i%j.first==0){
            m[j.first]=max(j.second,i/j.first);
        }
        }
    }
    int result=1;
    for(const auto& i:m){
        result*=pow(i.first,i.second);
    }
    return result;
    }
