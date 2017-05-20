#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(int* A, int i, int j){
    
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    
}

long long quickSort(int* A, int l, int r){
    
    int i,j;
    int mid = (l+r)/2;
    long long count = r - l - 1;
    
    // Pick pivot based on problem number
    
    int pivot = l;                                          // PROBLEM 1
    // int pivot = r;                                       // PROBLEM 2
    /*if((l >= mid && r <= mid) || (l <= mid && r>=mid)){   // PROBLEM 3
        pivot = mid;
    }
    else if((r >= l && mid <= l) || (r <= l && mid >= l)){
        pivot = l;
    }
    else pivot = r;*/
    
    // Partition Section
    
    i = l+1;
    for(j=l+1;j<=r;j++){
        
        if(A[j] < A[pivot]){
            
            swap(A,j,i);
            i++;
            
        }
        
    }
    swap(A,l,i-1);
    
    // Recursive Section
    
    count += quickSort(A,l,pivot);
    count += quickSort(A,pivot+1,r);
    
    return count;
    
    
}

int main(){
    
    int i=0;
    long long count=0LL;
    string dummy;
    ifstream myfile("QuickSortArray.txt");
    int a[10000];
    
    while(!myfile.eof()){
        
        getline(myfile,dummy);
        a[i] = atoi(dummy.c_str());
        cout << i << " ";
        i++;
    
    }
    
    myfile.close();
    //int a[] = { 4, 80, 70, 23, 9, 60, 68, 27, 66, 78, 12, 40, 52, 53, 44, 8, 49, 28, 18, 46, 21, 39, 51, 7, 87, 99, 69, 62, 84, 6, 79, 67, 14, 98, 83, 0, 96, 5, 82, 10, 26, 48, 3, 2, 15, 92, 11, 55, 63, 97, 43, 45, 81, 42, 95, 20, 25, 74, 24, 72, 91, 35, 86, 19, 75, 58, 71, 47, 76, 59, 64, 93, 17, 50, 56, 94, 90, 89, 32, 37, 34, 65, 1, 73, 41, 36, 57, 77, 30, 22, 13, 29, 38, 16, 88, 61, 31, 85, 33, 54 };
    //int a[] = { 9, 12, 3, 1, 6, 8, 2, 5, 14, 13, 11, 7, 10, 4, 0 };
    //int a[] = {1,5,3,2,4};
    int num = 10000;
    
    
    
    count = quickSort(a,0,num-1);
    
    
    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    cout << "There are " << count << " comparisons.\n";
    
    
    return 0;
}