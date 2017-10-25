/**
 * @file lt_node.cpp
 * @brief 数据结构链路节点
 * @author dekai.wang
 * @version 
 * @date 2017-09-21
 */

namespace lt
{

template<class T>
struct LinkNode
{
    LinkNode() 
        : data(), next(nullptr) {}
    LinkNode(const T &element) 
        : data(element), next(nullptr) {}
    LinkNode(const T &element, LinkNode<T> *next_ptr) 
        : data(element), next(next_ptr) {}
    ~LinkNode() { next = nullptr; }
    T               data;
    LinkNode<T>     *next;
};

};

