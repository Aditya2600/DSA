#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input,int target){
    int lo = 0;
    int hi = input.size() - 1;

    while (lo <= hi){
   int mid = (lo + hi)/2;
    if(input[mid]==target) return mid;
   else if (input[mid]<target){
   lo = mid + 1 ;
   }else if (input[mid>target]){
    hi = mid - 1;
   }
   

}
return -1;
}

;
return 0;
}


