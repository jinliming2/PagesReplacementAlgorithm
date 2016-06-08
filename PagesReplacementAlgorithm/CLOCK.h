#pragma once
#include "PageManager.h"
/**
 * 时钟置换算法
 */
class CLOCK : public PageManager {
public:
    //时钟置换算法
    CLOCK();
    //析构函数
    ~CLOCK();
    //请求页面
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //时钟指针
    int pointer = 0;
};
