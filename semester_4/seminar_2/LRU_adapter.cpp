#include <iostream>
#include <set>
#include <pair>

class LRU{
    public:
        LRU(int capacity):Size(capacity){};

        int get(int key){
            auto pl = sup_iter.find(key);
            if (pl == sup_iter.end()){
                std::cout << "There is no such element"<< std::endl;
                return -1
            };
            LRU_list.splice(LRU_list.begin(),LRU_list,it->second);
            return pl->second->second; 
        };

        void put(int key, int value){
            auto pl = sup_iter.find(key);
            if (pl != sup_iter.end()){
                LRU_list.splice(LRU_list.begin(),LRU_list,it->second);
                it->second->second = value;
            } else {
                LRU_list.push_front(make_pair(key,value));
                sup_iter.insert(make_pair(key,LRU_list.begin()));
            };
            if(LRU_list.size() > Size) {
                sup_iter.erase(LRU_list.back().first);
                LRU_list.pop_back();
            };
        };
    private:
        int Size;
        std::list<std::pair<int,int>> LRU_list;
        std::set<int, std::list<std::pair<int, int>>::iterator> sup_iter;
};

/*
Поскольку доступ к элементам list по итератору -> получения элемента за o(1), + перемещение в начало списка за O(1)
Поиск элемента в set тоже o(1)
Итого, все операции за O(1).
*/
