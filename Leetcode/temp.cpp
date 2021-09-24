// 如果对C++不熟悉可改写C语言版本的试题
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void encode(const vector<pair<int, int>>& inBuffer,
            vector<uint8_t>& outBuffer) {
    // todo:
    if (inBuffer.empty()) {
        return;
    }

    map<pair<int, int>, uint8_t> dir_to_type;
    dir_to_type.insert({{-1, 1}, 0});
    dir_to_type.insert({{0, 1}, 1});
    dir_to_type.insert({{1, 1}, 2});
    dir_to_type.insert({{1, 0}, 3});
    dir_to_type.insert({{1, -1}, 4});
    dir_to_type.insert({{0, -1}, 5});
    dir_to_type.insert({{-1, -1}, 6});
    dir_to_type.insert({{-1, 0}, 7});

    // 起点
    union int_to_uint8 {
        int num;
        uint8_t to_bits[4];
    } u_start_x, u_start_y;

    // auto [start_x, start_y] = inBuffer[0];
    int start_x = inBuffer[0].first;
    int start_y = inBuffer[0].second;
    u_start_x.num = start_x;
    u_start_y.num = start_y;
    for (int i = 0; i < 4; ++i) {
        outBuffer.push_back(u_start_x.to_bits[i]);
    }
    for (int i = 0; i < 4; ++i) {
        outBuffer.push_back(u_start_y.to_bits[i]);
    }

    // 路径
    int n = inBuffer.size();
    int last_x = start_x, last_y = start_y;
    const uint8_t DOUBLE_DATA = 0b10000000;
    uint8_t cur = 0b01000000;
    for (int i = 1; i < n; ++i) {
        // auto [x, y] = inBuffer[i];
        int x = inBuffer[i].first, y = inBuffer[i].second;
        int dx = x - last_x, dy = y - last_y;
        last_x = x, last_y = y;
        pair<int, int> dir_pair{dx, dy};
        uint8_t dir = dir_to_type[dir_pair];
        if (i % 2 == 0) {
            cur |= (dir << 3);
            cur |= DOUBLE_DATA;
            outBuffer.push_back(cur);
            cur = 0b01000000;
        } else {
            cur |= dir;
        }
    }
    if (cur != 0b01000000) {
        outBuffer.push_back(cur);
    }
}

void decode(const vector<uint8_t>& inBuffer,
            vector<pair<int, int>>& outBuffer) {
    // todo:
    if (inBuffer.empty() || inBuffer.size() < 8) {
        return;
    }

    map<uint8_t, pair<int, int>> type_to_dir;
    type_to_dir.insert({0, {-1, 1}});
    type_to_dir.insert({1, {0, 1}});
    type_to_dir.insert({2, {1, 1}});
    type_to_dir.insert({3, {1, 0}});
    type_to_dir.insert({4, {1, -1}});
    type_to_dir.insert({5, {0, -1}});
    type_to_dir.insert({6, {-1, -1}});
    type_to_dir.insert({7, {-1, 0}});

    // 起点
    union int_to_uint8 {
        int num;
        uint8_t to_bits[4];
    } u_start_x, u_start_y;

    for (int i = 0; i < 4; ++i) {
        u_start_x.to_bits[i] = inBuffer[i];
    }
    for (int i = 4; i < 8; ++i) {
        u_start_y.to_bits[i - 4] = inBuffer[i];
    }
    int start_x = u_start_x.num, start_y = u_start_y.num;
    outBuffer.emplace_back(start_x, start_y);

    // 路径
    int n = inBuffer.size();
    int last_x = start_x, last_y = start_y;
    const uint8_t DOUBLE_DATA = 0b10000000;

    for (int i = 8; i < n; ++i) {
        uint8_t cur = inBuffer[i];
        {
            int dir_type = (int)(cur & 0b00000111);
            // auto [dx, dy] = type_to_dir[dir_type];
            int dx = type_to_dir[dir_type].first,
                dy = type_to_dir[dir_type].second;
            int nx = last_x + dx, ny = last_y + dy;
            outBuffer.emplace_back(nx, ny);
            last_x = nx, last_y = ny;
        }

        if (cur & DOUBLE_DATA) {
            uint8_t cur = inBuffer[i];
            int dir_type = (int)((cur & 0b00111000) >> 3);
            // auto [dx, dy] = type_to_dir[dir_type];
            int dx = type_to_dir[dir_type].first,
                dy = type_to_dir[dir_type].second;
            int nx = last_x + dx, ny = last_y + dy;
            outBuffer.emplace_back(nx, ny);
            last_x = nx, last_y = ny;
        }
    }
}

int main() {
    // cout << sizeof(uint8_t) << endl; //1字节
    // system("pause");
    vector<pair<int, int>> bData;
    vector<uint8_t> zipData;
    bData.push_back(make_pair(10019, 1124));
    bData.push_back(make_pair(10019, 1123));
    bData.push_back(make_pair(10019, 1122));
    bData.push_back(make_pair(10018, 1123));
    bData.push_back(make_pair(10018, 1122));
    bData.push_back(make_pair(10018, 1121));

    //输出原始路径
    cout << "bData src:" << endl;
    for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end();
         it++) {
        cout << it->first << "," << it->second << endl;
    }
    // cout << sizeof(bData) << endl;//24
    // cout << sizeof(pair<int, int> ) << endl;//8
    ////压缩数据
    encode(bData, zipData);
    std::cout << zipData.size() << std::endl;
    ////解压数据
    bData.clear();
    decode(zipData, bData);

    ////输出解压出来的路径
    cout << "bData dest:" << endl;
    for (vector<pair<int, int>>::iterator it = bData.begin(); it != bData.end();
         it++) {
        cout << it->first << "," << it->second << endl;
    }
    getchar();
    return 0;
}