//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long int left_pointer=0,right_pointer=n-1,res=0,left_max=0,right_max=0;
        while(left_pointer<=right_pointer)
        {
            if(arr[left_pointer]<=arr[right_pointer])
            {
                if(arr[left_pointer]>=left_max)
                    left_max=arr[left_pointer];
                else
                    res+=left_max-arr[left_pointer];
                
                left_pointer++;
            }
            else
            {
                if(arr[right_pointer]>=right_max)
                    right_max=arr[right_pointer];
                else
                    res+=right_max-arr[right_pointer];
                    
                right_pointer--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends