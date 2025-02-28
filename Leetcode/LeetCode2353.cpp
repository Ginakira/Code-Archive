// LeetCode 2353 设计食物评分系统

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class FoodRatings {
   private:
    using TIS = tuple<int, string>;
    unordered_map<string, TIS> food_to_info_;
    unordered_map<string, set<TIS>> cuisine_to_foods_;

   public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            auto &food = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];
            food_to_info_[food] = {rating, cuisine};
            cuisine_to_foods_[cuisine].emplace(-rating, food);
        }
    }

    void changeRating(string food, int newRating) {
        auto& [rating, cuisine] = food_to_info_[food];
        auto& s = cuisine_to_foods_[cuisine];
        s.erase({-rating, food});
        s.emplace(-newRating, food);
        rating = newRating;
    }

    string highestRated(string cuisine) {
        return get<1>(*cuisine_to_foods_[cuisine].begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */