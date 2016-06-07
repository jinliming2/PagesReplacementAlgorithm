#pragma once
#include "PageManager.h"
#include "Stack.h"
/**
 * 最近最少使用置换算法
 */
class LRU : public PageManager {
public:
    //最近最少使用置换算法
    LRU();
    //析构函数
    ~LRU();
    //请求页面
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //页面访问记录
    Stack<Page> pages;
    //将访问的页面移至栈顶
    void moveToTop(const int pageId);
};
