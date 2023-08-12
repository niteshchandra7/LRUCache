#include "CacheNode.h"

void CacheNode::setKey(int key)
{
    this->key = key;
}

int CacheNode::getKey()
{
    return this->key;
}

void CacheNode::setValue(int value)
{
    this->value=value;
}

int CacheNode::getValue()
{
    return this->value;
}

void CacheNode::setPrev(CacheNode *prevNode)
{
    this->prev = prevNode;
}

void CacheNode::setNext(CacheNode *nextNode)
{
    this->next = nextNode;
}

CacheNode *CacheNode::getPrev()
{
    return this->prev;
}

CacheNode *CacheNode::getNext()
{
    return this->next;
}
