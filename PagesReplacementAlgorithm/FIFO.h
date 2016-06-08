#pragma once
#include "PageManager.h"
#include "Queue.h"
/**
 * 先进先出置换算法
 */
class FIFO : public PageManager {
public:
    //最近最少使用置换算法
    FIFO();
    //析构函数
    ~FIFO();
    //请求页面
    Missing requireFrame(const int pageId, int& frameId, const bool alter = false);
private:
    //页面访问记录
    Queue<Page> pages;
};
