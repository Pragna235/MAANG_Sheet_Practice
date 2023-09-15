#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

string maxRoomBooked(vector<string> arr, int n) {
    // Write your code here.
    int maxCount=0;
    string ans;

    unordered_map<string,int> room_counts;


    for(int i=0;i<arr.size();i++){
        if(arr[i][0]=='+'){

            string roomType=arr[i].substr(1);

            room_counts[roomType]++;
            

            if(room_counts[roomType]>maxCount){
                maxCount=room_counts[roomType];
                ans=roomType;
            }
            else if(maxCount==room_counts[roomType]){
                ans=min(ans,roomType);
            }
        }

    }
    return ans;

    
}


