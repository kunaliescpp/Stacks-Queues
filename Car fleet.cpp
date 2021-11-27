/*
Problem Link: https://leetcode.com/problems/car-fleet/

Car Fleet

There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the 
speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

Example 1:
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation: 
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.

Example 2:
Input: target = 10, position = [3], speed = [3]
Output: 1
 

Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106
*/

class Solution {
public:
//A fleet car is the name given to a vehicle which belongs to a group of two or more cars which together form the commercial transportation
// for a business.
    
//A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. |till end|
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        
        priority_queue< vector<double> >pq;
       for(int i = 0; i < pos.size(); i++){
           
           double time = (double)(target - pos[i])/ speed[i];                     // time can be in decimals, that's why we are taking double
           pq.push ({(double) pos[i], (double) speed[i], time});
       }
        
       if(pq.size() == 0) return 0;               // for No car
        
       int fleet = 0;
       while(true){ 
           
            if(pq.size() == 1){                                     // for 1 car
              fleet++; break;
            }
      
           auto ahead = pq.top(); pq.pop();                          // jo destination ke pass he vo phle aaegi
           auto behind = pq.top(); pq.pop();        
    
           if(ahead[2] >= behind[2]){                               // ahead vali car dest ke pass hone ke baad bhi late destination par pahoch rhi he, 
            pq.push(ahead);                                         // to piche vali car usse takra jaegi. Ab dono car dheere hi pahochegi ahead car vali speed me
           }                                        
    
           else {
             fleet++;                                             // ahead vali car dest ke pass he or jaldi bhi destination par pahoch rhi he, to 
             pq.push(behind);                                     // dest. akele hi paar kar jaegi
          }
       }
    return fleet;
    }
};


