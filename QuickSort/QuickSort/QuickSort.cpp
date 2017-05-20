#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void swap(vector<int>& A, int i, int j){
    
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    
}

long long quickSort(vector<int>& A, int l, int r){
    
    int i,j;
    int mid = (l+r)/2;
    long long count = r - l ;
    if(r - l < 2){
		//cout << "FLAG" << endl;
		
		if(A[r] < A[l]){
			swap(A,r,l);
			//count+=r-l-1;
			return count;
		}
        else return count;
        //return count;

	}

	int pivot = l;
	//swap(A,l,r);
    if((A[l] >= A[mid] && A[mid] >= A[r]) || (A[l] <= A[mid] && A[mid] <=A[r])){
		swap(A,l,mid);
		//pivot = mid;
    }
    else if((A[r] >= A[l] && A[mid] <= A[l]) || (A[r] <= A[l] && A[mid] >= A[l])){
		//pivot = l;
    }
    else swap(A,l,r);
    
    // Partition Section
    
    i = l+1;
    for(j=l+1;j<=r;j++){
        
        if(A[j] < A[l]){
            
			swap(A,j,i);
            i++;
            
        }
        
    }
    swap(A,l,i-1);
    
    // Recursive Section
    if(l<i-2)	count += quickSort(A,l,i-2);
    if(i<r)		count += quickSort(A,i,r);
    
    return count;
    
    
}

int main(){
    
    int i=0;
    long long count=0LL;
	int num = 10000;
    string dummy;
    ifstream myfile("QuickSortArray.txt");
    vector<int> a(num);
    
    while(!myfile.eof()){
        
        getline(myfile,dummy);
        a.at(i) = atoi(dummy.c_str());
        //cout << a.at(i) << endl;
        i++;
    
    }
    
    myfile.close();
	//static const int aa[10] = { 3,9,8,4,6,10,2,5,7,1 };
    //vector<int> a (aa, aa+ sizeof(aa) / sizeof(aa[0]));
    
    count = quickSort(a,0,num-1);
    
    
    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    cout << "There are " << count << " comparisons.\n";
	getchar();

    return 0;
}