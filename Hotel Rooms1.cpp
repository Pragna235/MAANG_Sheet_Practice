string maxRoomBooked(vector<string> arr, int n) {
    // Write your code here.
    int maxCount=0;
    string ans;

    for(int i=0;i<arr.size();i++){
        if(arr[i][0]=='+'){
            int count=0;
            for(int j=0;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }

            if(maxCount<count){
                maxCount=count;
                ans=arr[i];
            }
            else if(maxCount==count){
                ans=min(ans,arr[i]);
            }
        }

    }
    return ans.substr(1,2);

    
}


