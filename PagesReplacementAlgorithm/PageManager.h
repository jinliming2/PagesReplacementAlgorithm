#pragma once
#include "PageFrame.h"
#include "Missing.h"
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
    virtual Missing requireFrame(const int pageId, int& frameId, const bool alter = false) = 0;
protected:
    //页框
    PageFrame frames[TOTAL_PAGE_FRAMES];
};

//构造函数
inline PageManager::PageManager() {
    int i = 1;
    for(auto& frame : frames) {
        frame.id = i++;
    }
}

//析构函数
inline PageManager::~PageManager() {
}
