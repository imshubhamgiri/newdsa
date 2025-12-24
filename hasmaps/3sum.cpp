// // //     int n = nums.size();
// //         vector<vector<int>>ans;

// //         set<vector<int>> s;
// //         for(int i=0; i<n; i++){
// //             for(int j=i+1; j<n ; j++){
// //                 for(int k=j+1; k<n; k++){
// //                     if(nums[i]+ nums[j]+nums[k]==0){
// //                         vector<int> tres = {nums[i], nums[j],nums[k]};
// //                         sort(tres.begin(), tres.end());
// //                         if(s.find(tres)== s.end()){
// //                             s.insert(tres);
// //                             ans.push_back(tres);
// //                         }
// //                     }
// //                 }
// //             }
// //         }
// //         return ans;
// //     }

//   vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>>uniquenum;
//         for (int i = 0; i < n; i++) {
//             int tar = -nums[i];
//             set<int> y;

//             for (int j = i + 1; j < n; j++) {
//                 int third = tar - nums[j];

//                 if (y.find(third) != y.end()) {
//                     vector<int> trip = {nums[i], nums[j], third};
//                     sort(trip.begin(), trip.end());
//                     uniquenum.insert(trip);
//                 }
//                 y.insert(nums[j]);
//             }
//         }

//         vector<vector<int>> ans(uniquenum.begin(), uniquenum.end());
//         return ans;
//     }