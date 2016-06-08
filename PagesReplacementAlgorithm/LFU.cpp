#include "LFU.h"
//构造函数
LFU::LFU() {
}

//析构函数
LFU::~LFU() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//请求页面
inline Missing LFU::requireFrame(const int pageId, int & frameId, const bool alter) {
    //页表命中
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            //访问次数
            frame.page->visit++;
            return No;
        }
    }
    //存在空页框
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frame.page->visit = 1;
            frameId = frame.id;
            return MissingPage;
        }
    }
    //页面置换
    Page* p1 = frames[0].page;
    int min = p1->visit;
    for(auto frame : frames) {
        if(frame.page->visit < min) {
            p1 = frame.page;
            min = frame.page->visit;
        }
    }
    for(auto& frame : frames) {
        if(frame.page->id == p1->id) {
            delete frame.page;
            frame.page = new Page;
            frame.page->id = pageId;
            frame.page->visit = 1;
            frameId = frame.id;
            return MissingPageAndReplace;
        }
    }
    return No;
}
