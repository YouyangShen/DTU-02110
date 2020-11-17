#include <iostream> 
#include<algorithm>
  
using namespace std; 
  
/*         n --> No. of elements present in input array.  
    BITree[0..n] --> Array that represents Binary Indexed Tree. 
    arr[0..n-1] --> Input array for which prefix sum is evaluated. */
  
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Iniialize result 
    //cout << "index in sum=" << index << endl;
    // index in BITree[] is 1 more than the index in arr[] 
    //index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    //index = index + 1; 
    //cout << "index=" << index << endl;
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] += 1; 
  
    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 
  
  
// Driver program to test above functions 
int main() 
{ 
    int m,n;
    cin >> n >> m;
    
    int *tree = new int[m];
    int d;
    //cin the value of the tree
    for (int i = 0; cin >> d;i++) {
         tree[i] = d;
    }
    

     int *BITree = new int[n+1]; 
     for (int i=1; i<=n; i++) 
         BITree[i] = 0; 
    //use bst
    int result;
    
    //if(m>1){
    for (int i =0;i<m;i++){
        // cout << "i=" << i << endl;
        updateBIT(BITree,n,tree[i]+1);
        //update first
        result = getSum(BITree,tree[i]);
        
            cout << result << endl;//sum
        
    }
    //}
    // else{
    //     cout << 0 <<endl;
    // } 
    

    return 0; 
    delete tree;
} 