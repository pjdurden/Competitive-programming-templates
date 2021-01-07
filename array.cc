// for an array or string of n elements subarrays-n*(n-1)/2 subsequences-2^n - 1 
//min swaps to sort array using graph
int minSwaps(int arr[], int n) 
{ 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
    sort(arrPos, arrPos + n);  
    vector<bool> vis(n, false); 
    int ans = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 

//pair with sum x
void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
        if (s.find(temp) != s.end()) 
            cout << arr[i] << temp;
        s.insert(arr[i]); 
    } 
}

//binary search
int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2;
    if (key == arr[mid]) 
        return mid; 
    if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
    return binarySearch(arr, low, (mid - 1), key); 
} 

//peak element using binary search
int findPeakUtil(int arr[], int low,int high, int n) 
{ 
    int mid = low + (high - low) / 2; 
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid - 1), n); 
    else
        return findPeakUtil(arr, (mid + 1), high, n); 
} 

//to find array is subset of given array
int binarySearch(int arr[], int low,int high, int x) 
{ 
    if(high >= low) 
    { 
        int mid = (low + high)/2;
        if(( mid == 0 || x > arr[mid-1]) && (arr[mid] == x)) 
            return mid; 
        else if(x > arr[mid]) 
            return binarySearch(arr, (mid + 1), high, x); 
        else
            return binarySearch(arr, low, (mid -1), x); 
    } 
    return -1; 
}  
void exchange(int *a, int *b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int A[], int si, int ei) 
{ 
    int x = A[ei]; 
    int i = (si - 1); 
    int j; 
  
    for (j = si; j <= ei - 1; j++) 
    { 
        if(A[j] <= x) 
        { 
            i++; 
            exchange(&A[i], &A[j]); 
        } 
    } 
    exchange (&A[i + 1], &A[ei]); 
    return (i + 1); 
} 
bool isSubset(int arr1[], int arr2[], 
                        int m, int n) 
{ 
    int i = 0; 
  
    quickSort(arr1, 0, m-1); 
    for (i=0; i<n; i++) 
    { 
        if (binarySearch(arr1, 0, m - 1, 
                        arr2[i]) == -1) 
        return 0; 
    } 
    return 1; 
} 

//longest increasing subsequence
int lis( int arr[], int n )  
{  
    int lis[n]; 
    lis[0] = 1;    
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
    return *max_element(lis, lis+n); 
}  

//size of largest histogram
int largestRectangleArea(vector<int>& heights) {
        
        int curr=0;
        int maxs=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() || heights[st.top()]<heights[i])
                st.push(i);
            else
            {
                int tp=st.top();
                st.pop();
                curr=heights[tp]* ( st.empty() ? i :i-st.top()-1 ) ;
                maxs=max(curr,maxs);
                i--;
            }
        }
        int i=heights.size();
        while(!st.empty())
        {

            int tp=st.top();
            st.pop();
            curr=heights[tp]* ( st.empty()?i:i-st.top()-1) ;
            maxs=max(curr,maxs);            
        }
        return maxs;
    }

