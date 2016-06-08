#include <iostream>
#include <ctime>
#include "LRU.h"
#include "FIFO.h"
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
    //页框号
    int frame_id;
    //最近最少使用置换算法
    LRU LRUManager;
    //缺页中断计数
    unsigned int missing_page_lru = 0;
    //页面置换计数
    unsigned int page_algorithm_lru = 0;
    //模拟请求
    cout << "******************** LRU ********************" << endl;
    for(auto i : arr) {
        cout << "请求页号：" << i << "\t";
        switch(LRUManager.requireFrame(i, frame_id)) {
        case No:
            cout << "页表命中！页框号：";
            break;
        case MissingPage:
            missing_page_lru++;
            cout << "页表未命中，调入页面至页框号：";
            break;
        case MissingPageAndReplace:
            missing_page_lru++;
            page_algorithm_lru++;
            cout << "页表未命中，页框已满，调入页面并替换页框号：";
            break;
        }
        cout << frame_id << endl;
    }
    cout << "#################### LRU ####################" << endl;
    //先进先出置换算法
    FIFO FIFOManager;
    //缺页中断计数
    unsigned int missing_page_fifo = 0;
    //页面置换计数
    unsigned int page_algorithm_fifo = 0;
    //模拟请求
    cout << "******************** FIFO ********************" << endl;
    for(auto i : arr) {
        cout << "请求页号：" << i << "\t";
        switch(FIFOManager.requireFrame(i, frame_id)) {
        case No:
            cout << "页表命中！页框号：";
            break;
        case MissingPage:
            missing_page_fifo++;
            cout << "页表未命中，调入页面至页框号：";
            break;
        case MissingPageAndReplace:
            missing_page_fifo++;
            page_algorithm_fifo++;
            cout << "页表未命中，页框已满，调入页面并替换页框号：";
            break;
        }
        cout << frame_id << endl;
    }
    cout << "#################### FIFO ####################" << endl;
    //输出结果
    cout << "LRU算法，共计产生页面失效"
        << missing_page_lru
        << "次，其中发生页面置换"
        << page_algorithm_lru
        << "次。"
        << endl;
    cout << "FIFO算法，共计产生页面失效"
        << missing_page_fifo
        << "次，其中发生页面置换"
        << page_algorithm_fifo
        << "次。"
        << endl;
    system("pause");
    return 0;
}
