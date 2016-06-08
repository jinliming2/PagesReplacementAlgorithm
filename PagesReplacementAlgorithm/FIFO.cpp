#include "FIFO.h"
//构造函数
FIFO::FIFO() {
}

//析构函数
FIFO::~FIFO() {
}

//请求页面
inline Missing FIFO::requireFrame(const int pageId, int & frameId, const bool alter) {
    //页表命中
    for(auto frame : frames) {
        if(frame.page != nullptr && frame.page->id == pageId) {
            frameId = frame.id;
            return No;
        }
    }
    //存在空页框
    for(auto& frame : frames) {
        if(frame.page == nullptr) {
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.enqueue(*frame.page);
            return MissingPage;
        }
    }
    //页面置换
    Page p1;
    pages.dequeue(p1);
    for(auto& frame : frames) {
        if(frame.page->id == p1.id) {
            delete frame.page;
            frame.page = new Page;
            frame.page->id = pageId;
            frameId = frame.id;
            pages.enqueue(*frame.page);
            return MissingPageAndReplace;
        }
    }
    return No;
}
