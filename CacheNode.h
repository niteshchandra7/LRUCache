#ifndef _CACHE_NODE_H_
#define _CACHE_NODE_H_

class CacheNode {
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;
    public:
    CacheNode(int key, int value):key(key),value(value),prev(nullptr),next(nullptr){}
    void setKey(int key);
    int getKey();
    void setValue(int value);
    int getValue();
    void setPrev(CacheNode* prevNode);
    void setNext(CacheNode* nextNode);
    CacheNode* getPrev();
    CacheNode* getNext();
};

#endif