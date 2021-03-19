// LeetCode 1603 设计停车系统
#include <vector>
using namespace std;

class ParkingSystem {
   private:
    enum { BigType = 1, MediumType, SmallType };
    vector<int> data;

   public:
    ParkingSystem(int big, int medium, int small) : data(4) {
        data[BigType] = big;
        data[MediumType] = medium;
        data[SmallType] = small;
    }

    bool addCar(int carType) {
        if (data[carType] == 0) return false;
        data[carType] -= 1;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */