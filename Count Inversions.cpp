//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int countInv(long long int arr[],long long int l,long long int h)
    {
        long long res=0;
        if(l<h)
        {
            long long int m=l+(h-l)/2;
            res+=countInv(arr,l,m);
            res+=countInv(arr,m+1,h);
            res+=countAndMerge(arr,l,m,h);
        }
        return res;
    }
    long long int countAndMerge(long long int arr[],long long int l,long long int m,long long int h)
    {
        long long int n1=m-l+1,n2=h-m;
        long long int left[n1],right[n2];
        for(long long int i=0;i<n1;i++)
            left[i]=arr[l+i];
        for(long long int i=0;i<n2;i++)
            right[i]=arr[m+1+i];
        long long int res=0,k=l,i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(left[i]<=right[j])
            {
                arr[k]=left[i];
                i++;
            }
            else
            {
                arr[k]=right[j];
                j++;
                res=res+(n1-i);
            }
            k++;
        }
        while(i<n1)
        {
            arr[k]=left[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k]=right[j];
            j++;
            k++;
        }
        return res;
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return countInv(arr,0,N-1);
        // Your Code Here
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
