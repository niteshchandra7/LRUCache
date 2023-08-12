#include "LRUCache.h"
#include<iostream>

unsigned int LRUCache::getCapacity()
{
    return this->capacity;
}

void LRUCache::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void LRUCache::setSize(int size)
{
    this->size=size;
}

unsigned int LRUCache::getSize()
{
    return this->size;
}

void LRUCache::setMRUNode(CacheNode *MRUNode)
{
    this->MRUNode = MRUNode;
}

CacheNode *LRUCache::getMRUNode()
{
    return this->MRUNode;
}

void LRUCache::setLRUNode(CacheNode *LRUNode)
{
    this->LRUNode = LRUNode;
}

CacheNode *LRUCache::getLRUNode()
{
    return this->LRUNode;
}

std::unordered_map<int, CacheNode*>& LRUCache::getKeyNodeMap()
{
    return (this->keyNodeMap);
}

bool LRUCache::contains(int key)
{
    return (this->keyNodeMap).find(key)!=(this->keyNodeMap).end();
}

void LRUCache::setKeyNodeMap(int key, CacheNode* cacheNode)
{
    (this->keyNodeMap).insert({key,cacheNode});
}

CacheNode *LRUCache::getKeyNodeMapValue(int key)
{
    if (!this->contains(key))return nullptr;
    return (this->keyNodeMap)[key];
}

void LRUCache::deleteKeyFromMap(int key)
{
    if(!this->contains(key))return;
    this->getKeyNodeMap().erase(key);
}

// deletes LRUNode and update LRUNode
CacheNode *LRUCache::deleteAndUpdateLRUNode()
{
    CacheNode* LRUNode = this->getLRUNode();
    if (LRUNode==nullptr)return nullptr;
    CacheNode* prevNode = LRUNode->getPrev();
    if(prevNode)prevNode->setNext(nullptr);
    LRUNode->setPrev(nullptr);
    this->setLRUNode(prevNode);
    return LRUNode;
}

CacheNode *LRUCache::deleteCacheNode(CacheNode *currCacheNode)
{
    CacheNode* prevCacheNode =  currCacheNode->getPrev();
    CacheNode* nextCacheNode = currCacheNode->getNext();
    prevCacheNode->setNext(nextCacheNode);
    nextCacheNode->setPrev(prevCacheNode);
    currCacheNode->setNext(nullptr);
    currCacheNode->setPrev(nullptr);
    return currCacheNode;
}

void LRUCache::InsertAtMRU(CacheNode *currCacheNode)
{
    CacheNode* MRUNode = this->getMRUNode();
    currCacheNode->setNext(MRUNode);
    if(MRUNode)MRUNode->setPrev(currCacheNode);
    else this->setLRUNode(currCacheNode);
    this->setMRUNode(currCacheNode);
}

// Gets the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
int LRUCache::get(int key)
{
    // If key is not found int the cache return -1
    if(!this->contains(key))return -1;
    // If keyNodeMap holds MRUNode then return value
    if(this->getKeyNodeMapValue(key)==this->getMRUNode())return this->getKeyNodeMapValue(key)->getValue();

    CacheNode* MRUNode = nullptr;
    // If keyNodeMap holds LRUNode then delete LRUNode and update LRUNode;
    if(this->getKeyNodeMapValue(key)==this->getLRUNode())MRUNode = this->deleteAndUpdateLRUNode();
    // If keyNodeMap doesn't holds MRUNode or LRUNode then delete the CacheNode from its position.
    else MRUNode = this->deleteCacheNode(this->getKeyNodeMapValue(key));
    // Insert the deletedNode at MRU position and update MRUNode and then return value of MRUNode
    this->InsertAtMRU(MRUNode);
    return this->getMRUNode()->getValue();
}

// Set or insert the value if the key is not already present. When the cache reaches its capacity, 
// It should invalidate the least recently used item before inserting the new item.
void LRUCache::set(int key, int value)
{
    CacheNode* currCacheNode = nullptr;
    if(this->contains(key)){
        get(key);
        return;
    }
    currCacheNode = new CacheNode(key,value);
    this->setKeyNodeMap(key,currCacheNode);
    if(this->getSize()==this->getCapacity()){
        CacheNode* deletedNode = this->deleteAndUpdateLRUNode();
        this->deleteKeyFromMap(deletedNode->getKey());
        delete deletedNode;
        this->InsertAtMRU(currCacheNode);
    }
    else {
        this->InsertAtMRU(currCacheNode);
        this->setSize(this->getSize()+1);
    }
}
