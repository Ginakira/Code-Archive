// LeetCode 881 救生艇

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.rbegin(), people.rend());
        int count = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                --right;
            }
            ++left;
            ++count;
        }

        return count;
    }
};