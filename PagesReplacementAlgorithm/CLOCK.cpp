#include "CLOCK.h"
//构造函数
CLOCK::CLOCK() {
}

//析构函数
CLOCK::~CLOCK() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//请求页面
inline Missing CLOCK::requireFrame(const int pageId, int & frameId, const bool alter) {
    //页表命中
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            //访问次数
            frame.page->visit = 1;
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
    while(frames[pointer].page->visit == 1) {
        frames[pointer++].page->visit = 0;
        if(pointer >= TOTAL_PAGE_FRAMES) {
            pointer -= TOTAL_PAGE_FRAMES;
        }
    }
    delete frames[pointer].page;
    frames[pointer].page = new Page;
    frames[pointer].page->id = pageId;
    frames[pointer].page->visit = 1;
    frameId = frames[pointer++].id;
    if(pointer >= TOTAL_PAGE_FRAMES) {
        pointer -= TOTAL_PAGE_FRAMES;
    }
    return MissingPageAndReplace;
}
