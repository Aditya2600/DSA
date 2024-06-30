#include <iostream>
using namespace std;
int main(){
    int arr[] = {-2,-1,0,1,3,5,8,11,12} ;
    int x = 12;
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    int j = n - 1;
    int answer = 0;


    while(j>i){
    if (arr[i] + arr[j] == x){
    answer+=1;
    i++;
    j--;
    }
    else if (arr[i] + arr[j] < x){
        i++;

    }
    else{
        j--;
    }
    }
    cout<<answer;
    
}