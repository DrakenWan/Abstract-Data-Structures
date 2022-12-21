#include<iostream>

using namespace std;

int main() {
    const char *s = "assent";
    int c=0;
    for(auto *i = s; *i!=0; i++) {
        c++;
        cout<<endl<<c;
        cout<<*i; 
    }
    return 0;
}