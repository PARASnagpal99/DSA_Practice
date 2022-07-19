class Solution {
public:
void merge(vector<int> &count ,vector<pair<int,int>>&v , int left , int mid , int right ){
    int i = left ;
    int j = mid + 1 ;
    int k = 0 ;
    
    vector<pair<int,int>>temp(right-left+1);
    
    while(i<=mid && j<=right){
        if(v[i].first <= v[j].first){
            temp[k++] = v[j++];
        }else{
            count[v[i].second] += (right-j+1) ;
            temp[k++] = v[i++] ;
        }
    }
    
    
    while(i <= mid){
        temp[k++] = v[i++] ;
    }
    
    while(j <= right){
        temp[k++] = v[j++] ;
    }
    
    for(int i=left ; i<=right ; ++i){
        v[i] = temp[i-left] ;
    }
}





void mergeSort(vector<int> &count , vector<pair<int,int>>& v , int left , int right){
    if(left >= right) return ;
    
    int mid = left + (right - left)/2 ;
    
    mergeSort(count,v,left,mid);
    mergeSort(count,v,mid+1,right);
    merge(count,v,left,mid,right);
    
}

    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>nums(n) ;
	    
	    for(int i=0 ; i<n ; ++i){
	        nums[i] = make_pair(arr[i],i) ;
	    }
	    
	    vector<int> res(n) ;
	    
	    mergeSort(res,nums,0,n-1);
	    
	    
	    return res ;
	    
    }
};