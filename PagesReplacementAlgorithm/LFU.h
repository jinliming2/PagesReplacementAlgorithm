#pragma once
#include "PageManager.h"
/**
* 最不常用置换算法
*/
class LFU : public PageManager {
public:
    //最不常用置换算法
    LFU();
    //析构函数
    ~LFU();
    //请求页面
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
};
