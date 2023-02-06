#include <iostream>

using namespace std;

void a(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==n/2){
                cout << "* ";
            } else if(i == n/2) {
                cout << "* ";
            } else if(i==0 || i==n-1) {
                cout << "* ";
            } else {
                (j==0 || j==n-1)? cout << "* ":cout << "  ";
            }
        }
        cout << '\n';
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i=1;i<n;i+=2){
        a(i);
        cout << '\n';
    }
    
    return 0;
}
