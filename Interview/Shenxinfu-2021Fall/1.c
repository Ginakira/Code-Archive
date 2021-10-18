#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COOK_TABLE_NUM 3
#define CHANGE_TIME 6
#define COOKING_TIME 15

struct CookTool {
    int number;
    int last_use;
};

// 为此订单寻找合适的厨具位置
int find_tool(struct CookTool *tools, int order) {
    int min_last_use = INT_MAX, min_last_use_id = 0;
    for (int i = 0; i < 3; ++i) {
        if (tools[i].number == 0 ||
            tools[i].number == order) {  // 未使用过的或正好和订单号对应
            return i;
        } else if (tools[i].last_use < min_last_use) {
            min_last_use = tools[i].last_use;
            min_last_use_id = i;
        }
    }
    return min_last_use_id;
}

void change_tool_and_cook(struct CookTool *tools, int tool_id, int order,
                          int *time_used) {
    if (tools[tool_id].number != 0 &&
        tools[tool_id].number != order) {  // 槽位已有厨具时，更换厨具耗时
        *time_used += CHANGE_TIME;
    }
    tools[tool_id].number = order;
    *time_used += COOKING_TIME;
    tools[tool_id].last_use = *time_used;
}

// AC
int main() {
    int order;
    int time_used = 0;
    struct CookTool tools[3] = {0};
    memset(tools, 0, sizeof(tools));
    while (scanf("%d", &order) && order != 7) {
        int tool_id = find_tool(tools, order);
        change_tool_and_cook(tools, tool_id, order, &time_used);
    }
    printf("%d\n", time_used);
    return 0;
}