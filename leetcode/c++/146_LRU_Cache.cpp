/******************************************************************************
https://leetcode.com/problems/lru-cache/

2.17.2021
*******************************************************************************/

class LRUCache {
private:
    struct Node{
        int val;
        int key;
        Node* prev;
        Node* next;
        Node() : val(0), key(0), prev(nullptr), next(nullptr) {}
        Node(int key_, int val_) : key(key_), val(val_), prev(nullptr), next(nullptr) {}
    };
    
        Node* head = new Node;
        Node* tail = new Node;
        unordered_map<int, Node*> mp;
        int cap;

    void update(Node* node){
        remove(node);
        add_front(node);
    }
    
    void remove(Node* node){
         if (node == tail || node == head){
            return;
        }
        
        Node* previous = node -> prev;
        Node* next = node -> next;
        previous -> next = next;
        next -> prev = previous;
    }
    
    void popBack(){
        if (tail -> prev == head){
            return;
        }
        Node* to_delete = tail -> prev;
        remove(tail -> prev);
        mp.erase(to_delete -> key);
       delete to_delete;
    }
    
    void add_front(Node* node){
       node -> next = head -> next;
        head -> next -> prev = node;
        
        head -> next = node;
        node -> prev = head;
    }

public:
    LRUCache(int capacity) : cap(capacity){
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        auto found_itr = mp.find(key);
        if (found_itr == mp.end()){
            return -1;
        }
        
        update(mp[key]);
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        auto found_itr = mp.find(key);
        if (found_itr != mp.end()){
            found_itr-> second -> val = value;
            update(mp[key]);
        }else{
            Node* newNode = new Node(key, value);
            add_front(newNode);
            mp[key] = head -> next;
            if (mp.size() > cap){
                popBack();
            }
        }
    }
};

/*
class LRUCache {
private:
    size_t capacity_;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> tracker;
    
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto found_itr = tracker.find(key);
        if (found_itr == tracker.end()){
            return -1;
        }
            cache.push_front({found_itr -> second-> first, found_itr -> second-> second});
            found_itr -> second = cache.begin();
            cache.pop_back();
            return cache.begin() -> second;
        }
        
    void put(int key, int value) {
        auto found_itr = tracker.find(key);
        if (found_itr == tracker.end()){
            if (tracker.size() >= capacity_){
                
                tracker.erase(cache.back().first);
                cache.pop_back();
            }
            
            cache.push_front({key, value});
            tracker[key] = cache.begin();
        }else{
            found_itr -> second -> second = value;
            cache.splice(cache.begin(), cache, found_itr-> second);
        }
    }
};
*/

/*
class LRUCache {
private:
    size_t capacity_;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> tracker;
    
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto found_itr = tracker.find(key);
        if (found_itr == tracker.end()){
            return -1;
        }
            cache.splice(cache.begin(), cache, found_itr-> second);
            return cache.begin() -> second;
        }
        
    void put(int key, int value) {
        auto found_itr = tracker.find(key);
        if (found_itr == tracker.end()){
            if (tracker.size() >= capacity_){
                
                tracker.erase(cache.back().first);
                cache.pop_back();
            }
            
            cache.push_front({key, value});
            tracker[key] = cache.begin();
        }else{
            found_itr -> second -> second = value;
            cache.splice(cache.begin(), cache, found_itr-> second);
        }
    }
};

*/