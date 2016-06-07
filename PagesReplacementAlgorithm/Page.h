#pragma once
/**
 * 页面
 */
struct Page {
    //页面号
    int id;
    //访问
    int visit = 0;  //For NRU
    //修改标识
    bool alter = false; //For NRU
};
