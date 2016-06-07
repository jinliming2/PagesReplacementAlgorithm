#pragma once
#include "PageFrame.h"
#define TOTAL_PAGE_FRAMES 20
/**
 * 页面管理
 */
class PageManager {
public:
    //页框类
    PageManager();
    //析构函数
    ~PageManager();
    //请求页面
    virtual bool requireFrame(const int pageId, int& frameId) = 0;
protected:
    //页框
    PageFrame frames[TOTAL_PAGE_FRAMES];
};

//构造函数
inline PageManager::PageManager() {
    for(auto& frame : frames) {
        frame.page = nullptr;
    }
}

//析构函数
inline PageManager::~PageManager() {
}
