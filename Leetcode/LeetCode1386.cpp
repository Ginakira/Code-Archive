// LeetCode 1386 安排电影院座位

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    ranges::sort(reservedSeats);
    int ans = 0;
    std::bitset<10> mark;
    int pre_row = 1;
    auto calc = [&]() {
      constexpr auto kProfile1Mask = std::bitset<10>{0b0000011110};
      constexpr auto kProfile2Mask = std::bitset<10>{0b0001111000};
      constexpr auto kProfile3Mask = std::bitset<10>{0b0111100000};
      bool profile_1 = (mark & kProfile1Mask).none();
      bool profile_2 = (mark & kProfile2Mask).none();
      bool profile_3 = (mark & kProfile3Mask).none();
      if (profile_1 && profile_3) {
        ans += 2;
      } else if (profile_1 || profile_2 || profile_3) {
        ++ans;
      }
    };

    for (const auto& rs : reservedSeats) {
      int row = rs[0], seat = rs[1];
      if (row != pre_row) {
        calc();
        ans += 2 * (row - pre_row - 1);

        mark.reset();
        pre_row = row;
      }
      mark.set(seat - 1);
    }

    if (!reservedSeats.empty()) {
      calc();
      ans += 2 * (n - pre_row);
    } else {
      ans = 2 * n;
    }

    return ans;
  }
};