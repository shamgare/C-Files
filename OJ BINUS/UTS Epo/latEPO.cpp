#include <stdio.h>


void merge(long long int a[],int L, int mid, int R){

    int leftArrLen = mid-L+1;
    int rightArrLen = R-mid;

    int left[leftArrLen];
    int right[rightArrLen]; 
    
    for(int i=0; i<leftArrLen; i++){
     left[i]=a[L+i]; 
    }
    for(int i=0; i<rightArrLen; i++){
     right[i]=a[i+mid+1];
    }
    int mainCursor = L, leftCursor=0, rightCursor=0; 
    while(leftCursor<leftArrLen && rightCursor<rightArrLen){
        if(left[leftCursor]<=right[rightCursor]){
         a[mainCursor]=left[leftCursor];
            leftCursor++;
            mainCursor++;
        }
        else{
         a[mainCursor]=right[rightCursor]; 
            rightCursor++;
            mainCursor++;
        }
    }
    while(leftCursor<leftArrLen){
     a[mainCursor]=left[leftCursor];
        leftCursor++;
        mainCursor++;
        
    }

    while(rightCursor<rightArrLen){
     a[mainCursor]=right[rightCursor]; 
        rightCursor++;
        mainCursor++;
    }
}

void sort(long long int a[],int left,int right){
    if(left>=right)return;
    int mid= (right+left)/2;
    sort(a,left, mid);
    sort(a,mid+1, right);
    merge(a,left,mid,right);
}

int main() {
    int n;
    long long int a[1001];
    int q;
    long long int x;
    int count = 0;

    scanf("%d",&n); getchar();
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    sort(a, 0, n - 1);
 
    scanf("%d", &q); getchar();
    
    for (int j = 0; j < q; j++) {
        scanf("%lld", &x);
        int k;
        count = 0;
        for (k = 0; k < n; k++) {
            if (a[k] == x) {
                count++;
                printf("%d\n", k + 1);
                break;
            }
        }
        printf("%d %d\n", k, count);
        if (k == n && count == 0) {
            printf("-1\n");
        }
    } 
    return 0;
}