#include "CLOCK2.h"
//构造函数
CLOCK2::CLOCK2() {
}

//析构函数
CLOCK2::~CLOCK2() {
    for(auto frame : frames) {
        delete frame.page;
    }
}

//请求页面
Missing CLOCK2::requireFrame(const int pageId, int & frameId, const bool alter) {
    //页表命中
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            //访问次数
            frame.page->visit = 1;
            //页面修改
            if(alter) {
                frame.page->visit = alter;
            }
            return No;
        }
    }
    //存在空页框
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frame.page->visit = 1;
            //页面修改
            if(alter) {
                frame.page->visit = alter;
            }
            frameId = frame.id;
            return MissingPage;
        }
    }
    //页面置换
    int now = pointer;
    while(true) {
        if(!frames[pointer].page->alter && frames[pointer].page->visit == 0) {
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
        pointer++;
        if(pointer >= TOTAL_PAGE_FRAMES) {
            pointer -= TOTAL_PAGE_FRAMES;
        }
        while((frames[pointer].page->alter || frames[pointer].page->visit == 1) && pointer != now) {
            pointer++;
            if(pointer >= TOTAL_PAGE_FRAMES) {
                pointer -= TOTAL_PAGE_FRAMES;
            }
        }
        if(!frames[pointer].page->alter && frames[pointer].page->visit == 0) {
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
        pointer++;
        if(pointer >= TOTAL_PAGE_FRAMES) {
            pointer -= TOTAL_PAGE_FRAMES;
        }
        while((!frames[pointer].page->alter || frames[pointer].page->visit == 1) && pointer != now) {
            frames[pointer].page->visit = 0;
            pointer++;
            if(pointer >= TOTAL_PAGE_FRAMES) {
                pointer -= TOTAL_PAGE_FRAMES;
            }
        }
        if(frames[pointer].page->alter && frames[pointer].page->visit == 0) {
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
    }
}
