#include <iostream>
using namespace std;

int findMax(int arr[], int n){ // function to get the Max element
    int max=arr[0],cnt=0;
    for(int i=1;i<n;i++)
	{
        if(arr[i]>max)
            max=arr[i];
    }
    while(max>0)
	{
        cnt++;
        max=max/10;
    }
   
    return cnt;
}

void bucketSort(int arr[],int *bucket[],int n) // Bucket Sort function
{
    static int i,j[10],k,l,d=1;
    int max;
    max=findMax(arr,n);
  
    for(int x=0; x<max; x++){
        for(i=0;i<10;i++)
            j[i]=0;
        for(i=0;i<n;i++){
            k=(arr[i]/d)%10;
            bucket[k][j[k]]=arr[i];
            j[k]++;
        }
     
        l=0;
        for(i=0;i<10;i++){
            for(k=0;k<j[i];k++){
                arr[l]=bucket[i][k];
                l++;
            }
        }
        d*=10;
    }
}

int main()
 {
    int n,*arr,i;
    int *bucket[10];
    std::cout << "Number of elements: "; // Input the number of elements
    std::cin>> n;
    arr=new int[n+1];
    for(i=0;i<10;i++)
        bucket[i]=new int[n];
    
	std::cout <<"Enter elements: "; // Input the array of elements
    for(i=0;i<n;i++)
        cin>> arr[i];
    bucketSort(arr,bucket,n); // Call bucket sort function
   
    std::cout <<"\nSorted array: ";
    for(i=0;i<n;i++)
        cout<< arr[i]<< " ";
    
	return 0;
}
