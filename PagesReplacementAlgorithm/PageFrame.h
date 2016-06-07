#pragma once
#include "Page.h"
/**
 * 页框类
 */
struct PageFrame {
    //页框ID
    int id;
    //对应页面
    Page* page;
};