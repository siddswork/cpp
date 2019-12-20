//============================================================================
// Name        : Cache.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* prev;
   Node* next;
   int key;
   int value;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

  protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity; tail = NULL; head = NULL;
    }
    /* Get the value (will always be positive) of the key if   *
     * the key exists in the cache, otherwise return -1.       */
    void print()
    {
        cout << "head > ";
        for (Node* i = head; i!= NULL && i != tail; i=i->next)
        {
            if(i) cout << "(" << i->key << "," << i->value << ") ";
        }
        if(tail) cout << "(" << tail->key << "," << tail->value << ") < tail" << endl;
    }
    int get(int key)
    {
        map<int, Node*>::iterator it = mp.find(key);
        if (it == mp.end()) {// not found
            return -1;
        } else // found
        {
            Node* currNode = it->second;
            int retVal = currNode->value;
            //Move the node to head
            if (head != currNode) // only if the node is not already head
            {

                //removing current Node from the list
                Node* prevNode =  currNode->prev;
                Node* nextNode =  currNode->next;
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->prev = prevNode;
                if (currNode == tail)
                {
                    tail = prevNode;
                }
                //adding current node to the front
                currNode->prev = NULL;
                currNode->next = head;
                head->prev = currNode;
                head = currNode;
            }
            print();
            return retVal;
        }
    }
    void set(int key, int value) {
        // When there is no data in cache
        if (tail == NULL && head == NULL) {
            Node* newNode = new Node(key, value);
            head = tail = newNode;
            mp.emplace(key, newNode);
            size++;
        }
        else
        {
            //searching for data in existing cache
            map<int, Node*>::iterator it = mp.find(key);
            if (it != mp.end()) // Data found, leading to no change in cache size
            {
                //updating the value
                it->second->value = value;
                //bring it to the front of the queue
                Node* currNode = it->second;
                if (head != currNode) // only if the node is not already head
                {
                    //removing current Node from the list
                    Node* prevNode =  currNode->prev;
                    Node* nextNode =  currNode->next;
                    if(prevNode) prevNode->next = nextNode;
                    if(nextNode) nextNode->prev = prevNode;
                    if (currNode == tail)
                    {
                        tail = prevNode;
                    }
                    //adding current node to the front
                    currNode->prev = NULL;
                    currNode->next = head;
                    head->prev = currNode;
                    head = currNode;
                }
            }
            else // Data not in cache; need to add it
            {
                if (cp > size) // cache is not full
                {
                    Node* newNode = new Node(NULL, head, key, value);
                    head->prev = newNode;
                    head = newNode;
                    mp.emplace(key, newNode);
                }
                else // cache is full, need to remove node from end
                {
                    //add and then
                    Node* newNode = new Node(NULL, head, key, value);
                    head->prev = newNode;
                    head = newNode;
                    mp.emplace(key, newNode);
                    //remove from list
                    Node* toRemove = tail;
                    tail->prev->next = NULL;
                    tail =  tail->prev;
                    //remove from map
                    it = mp.find(toRemove->key);
                    mp.erase(it);
                }
            }
        }
        print();
    }

    static int size;
protected:

};
int LRUCache::size = 0;

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

/* input:
10 4
set 4 2
set 2 7
get 2
set 1 8
set 5 9
set 6 15
get 4
get 5
set 7 10
set 4
 */
