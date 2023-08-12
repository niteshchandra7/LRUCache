#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_
#include "CacheNode.h"
#include<unordered_map>

class LRUCache {
    unsigned int size;
    unsigned int capacity;
    CacheNode* MRUNode;
    CacheNode* LRUNode;
    std::unordered_map<int,CacheNode*>keyNodeMap;

    public:
    LRUCache(unsigned int capacity):capacity(capacity), size(0), MRUNode(nullptr), LRUNode(nullptr){}
    
    unsigned int getCapacity();
    void setCapacity(int capacity);
    
    void setSize(int size);
    unsigned int getSize();

    void setMRUNode(CacheNode* MRUNode);
    CacheNode* getMRUNode();

    void setLRUNode(CacheNode* LRUNode);
    CacheNode* getLRUNode();

    std::unordered_map<int,CacheNode*>& getKeyNodeMap();
    bool contains(int key);
    void setKeyNodeMap(int key, CacheNode* cacheNode);
    CacheNode* getKeyNodeMapValue(int key);
    void deleteKeyFromMap(int key);

    CacheNode* deleteAndUpdateLRUNode();
    CacheNode* deleteCacheNode(CacheNode* currCacheNode);

    void InsertAtMRU(CacheNode* currCacheNode);
    
    int get(int key);
    void set(int key,int value);




};

#endif
