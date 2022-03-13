// LeetCode 393 UTF-8编码验证

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static const int MASK1 = (1 << 7);
    static const int MASK2 = (1 << 7) + (1 << 6);

    bool is_valid_u8_byte(int byte) { return (byte & MASK2) == MASK1; }

    int get_u8_bytes_num(int start_byte) {
        if ((start_byte & MASK1) == 0) {
            return 1;
        }
        int count = 0;
        int mask = MASK1;
        while ((start_byte & mask) != 0) {
            ++count;
            mask >>= 1;
            if (count > 4) {
                return -1;
            }
        }
        return count >= 2 ? count : -1;
    }

   public:
    bool validUtf8(vector<int>& data) {
        size_t ind = 0, n = data.size();
        while (ind < n) {
            int count = get_u8_bytes_num(data[ind]);
            if (count < 0 || ind + count > n) {
                return false;
            }
            for (int i = 1; i < count; ++i) {
                if (!is_valid_u8_byte(data[ind + i])) {
                    return false;
                }
            }
            ind += count;
        }
        return true;
    }
};
