#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>

using namespace std;

template<typename Object>
class ArrayList{
    private:
        Object *items;
        int length;
        int capacity;

        void reserve(int newCapacity){
            Object *tmp = new Object[newCapacity];
            for(int i = 0; i < capacity; i++){
                tmp[i] = items[i];
            }
           delete [] items;
           items = tmp;
           capacity = newCapacity;
        }
    public:
        ArrayList(){
            length = 0;
            capacity = 100;
            items = new Object(capacity);
        }
        int size(){
            return length;
        }
        bool isEmpty(){
            return length == 0;
        }
        void add(const Object& item){
            insert(0,item);
        }
        void insert(int index, const Object& item){
            if(index < 0 || index > length) throw "index out of range";
            if(length == capacity) reserve(2 * capacity);
        }
};

#endif