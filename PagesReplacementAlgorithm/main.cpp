#include <iostream>
#include <ctime>
#include "LRU.h"
using namespace std;

#define __LENGTH__ 1000

int main(int argc, char** argv) {
    //页号请求顺序表
    int arr[__LENGTH__];
    srand((unsigned int)time(NULL));
    for(auto& i : arr) {
        //随机页号
        i = rand() % 100;
    }
    //缺页中断计数
    unsigned int missing_page;
    //页面置换计数
    unsigned int page_algorithm;
    //最近最少使用置换算法
    LRU LRUManager;
    missing_page = page_algorithm = 0;
    //页框号
    int frame_id;
    //模拟请求
    for(auto i : arr) {
        cout << "请求页号：" << i << "\t";
        switch(LRUManager.requireFrame(i, frame_id)) {
        case No:
            cout << "页表命中！页框号：";
            break;
        case MissingPage:
            missing_page++;
            cout << "页表未命中，调入页面至页框号：";
            break;
        case MissingPageAndReplace:
            missing_page++;
            page_algorithm++;
            cout << "页表未命中，页框已满，调入页面并替换页框号：";
            break;
        }
        cout << frame_id << endl;
    }
    //输出结果
    cout << "LRU算法，共计产生页面失效"
        << missing_page
        << "次，其中发生页面置换"
        << page_algorithm
        << "次。"
        << endl;
    system("pause");
    return 0;
}
