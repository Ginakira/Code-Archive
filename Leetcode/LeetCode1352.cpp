// LeetCode 1352. Product of the Last K Numbers

class ProductOfNumbers {
 private:
  vector<int> pre_prod_{1};

 public:
  ProductOfNumbers() {}

  void add(int num) {
    if (num == 0) {
      pre_prod_ = {1};
      return;
    }
    pre_prod_.emplace_back(pre_prod_.back() * num);
  }

  int getProduct(int k) {
    int n = pre_prod_.size();
    ;
    if (pre_prod_.size() <= k) {
      return 0;
    }
    return pre_prod_.back() / pre_prod_[n - k - 1];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */