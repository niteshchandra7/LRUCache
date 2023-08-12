#include "CacheNode.h"
#include "LRUCache.h"
#include<iostream>
using namespace std;


int main() {
    cout << "Client Started" << endl;
    int capacity = 2;
    LRUCache* lruCache = new LRUCache(2);
    lruCache->set(1,10);
    lruCache->set(5,12);
    cout << lruCache->get(5) << endl;
    cout << lruCache->get(1) << endl;
    cout << lruCache->get(10) << endl;
    lruCache->set(6,14);
    cout << lruCache->get(5) << endl;
    return 0;
}