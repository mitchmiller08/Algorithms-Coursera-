#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long merge(int*,int*,int,int,int);
long long mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    long long invCount=0LL;
    if(low<high)
    {
        pivot=(low+high)/2;
        invCount = mergesort(a,b,low,pivot);
        invCount += mergesort(a,b,pivot+1,high);
        invCount += merge(a,b,low,pivot,high);
    }
    return invCount;
}
long long merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    long long invCount = 0LL;
    h=low;
    i=low;
    j=pivot+1;
    
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
            invCount = invCount + pivot+1 - h;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
    
    return invCount;
}

int main(){
    
    int i=0;
    long long count=0LL;
    string dummy;
    ifstream myfile("QuickSortArray.txt");
    //int *a = new int[100000];
    int a[100000];

    while(!myfile.eof()){
        
        getline(myfile,dummy);
        a[i] = atoi(dummy.c_str());
        i++;
    
    }
    
    myfile.close();
    //int a[] = { 4, 80, 70, 23, 9, 60, 68, 27, 66, 78, 12, 40, 52, 53, 44, 8, 49, 28, 18, 46, 21, 39, 51, 7, 87, 99, 69, 62, 84, 6, 79, 67, 14, 98, 83, 0, 96, 5, 82, 10, 26, 48, 3, 2, 15, 92, 11, 55, 63, 97, 43, 45, 81, 42, 95, 20, 25, 74, 24, 72, 91, 35, 86, 19, 75, 58, 71, 47, 76, 59, 64, 93, 17, 50, 56, 94, 90, 89, 32, 37, 34, 65, 1, 73, 41, 36, 57, 77, 30, 22, 13, 29, 38, 16, 88, 61, 31, 85, 33, 54 };
    //int a[] = { 9, 12, 3, 1, 6, 8, 2, 5, 14, 13, 11, 7, 10, 4, 0 };
    //int a[] = {1,5,3,2,4};
    int num;
    
    num = sizeof(a)/sizeof(int);
    
    int b[num];
    
    count = mergesort(a,b,0,num-1);
    
    
    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    cout << "There are " << count << " inversions.\n";
    
    //delete[] a;
    
    return 0;
}