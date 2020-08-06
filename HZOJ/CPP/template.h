/************************************************************
    File Name : template.h
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/06 15:33:18
************************************************************/

#ifndef _TEMPLATE_H
#define _TEMPLATE_H

template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

int func();

#endif