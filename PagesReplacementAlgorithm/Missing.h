#pragma once
/**
 * 缺页
 */
enum Missing {
    //页表命中，不缺页
    No,
    //缺页中断
    MissingPage,
    //缺页中断，并发生页面置换
    MissingPageAndReplace
};
