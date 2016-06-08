#pragma once
#include "PageManager.h"
/**
 * 改进时钟置换算法（存在内存修改情况）
 */
class CLOCK2 : public PageManager {
public:
    //改进时钟置换算法
    CLOCK2();
    //析构函数
    ~CLOCK2();
    //请求页面
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //时钟指针
    int pointer = 0;
};
