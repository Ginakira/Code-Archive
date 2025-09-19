// LeetCode 3484 设计电子表格

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

class Spreadsheet {
 private:
  vector<array<int, 26>> cells_;

  tuple<int, int> parse_cell(const std::string& cell) {
    return {stoi(cell.substr(1)), cell[0] - 'A'};
  }

  int get_cell(string cell) {
    auto [row, col] = parse_cell(cell);
    return cells_[row][col];
  }

  bool is_number(const string& num) {
    return ranges::all_of(num, [](char c) { return isdigit(c); });
  }

 public:
  Spreadsheet(int rows) { cells_.resize(rows + 1, array<int, 26>{0}); }

  void setCell(string cell, int value) {
    auto [row, col] = parse_cell(cell);
    cells_[row][col] = value;
  }

  void resetCell(string cell) { setCell(cell, 0); }

  int getValue(string formula) {
    int pos = formula.find('+');
    string part_a = formula.substr(1, pos - 1);
    string part_b = formula.substr(pos + 1);
    int a = is_number(part_a) ? stoi(part_a) : get_cell(part_a);
    int b = is_number(part_b) ? stoi(part_b) : get_cell(part_b);
    return a + b;
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */