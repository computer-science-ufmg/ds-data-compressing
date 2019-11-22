#include<cstdlib>

#include"../include/hash.hpp"
#include"../include/linked_list.hpp"
#include"../include/cell.hpp"
#include"../include/hash_pair.hpp"

template<class T>
Hash<T>::Hash(){
    this->lists = (LinkedList<HashPair<T>>**) malloc(this->max_size*sizeof(LinkedList<HashPair<T>>*));
    for(int i = 0; i < this->max_size; i++){
        this->lists[i] = new LinkedList<HashPair<T>>();
    }
    
}

template<class T>
Hash<T>::Hash(int max_size){
    this->max_size = max_size;
    this->lists = (LinkedList<HashPair<T>>**) malloc(this->max_size*sizeof(LinkedList<HashPair<T>>*));
    for(int i = 0; i < this->max_size; i++){
        this->lists[i] = new LinkedList<HashPair<T>>();
    }
    
}

template<class T>
Hash<T>::~Hash(){

}

template<class T>
void Hash<T>::add(const char* key, T* value){
    int numeric_key = 0;
    HashPair<T>* pair = new HashPair<T>(key, value);
    LinkedList<HashPair<T>>* list;

    for(int i = 0; key[i] != '\0'; i++){
        numeric_key += (int)key[i];
    }
    list = this->lists[numeric_key % max_size];
    list->add(pair);
}

template<class T>
T* Hash<T>::get(const char* key){
    int numeric_key = 0;
    HashPair<T>* pair;
    LinkedList<HashPair<T>>* list;
    
    for(int i = 0; key[i] != '\0'; i++){
        numeric_key += (int)key[i];
    }
    list = this->lists[numeric_key % max_size];
    for(Cell<HashPair<T>>* it = list->begin(); it != nullptr; it = it->get_next()){
        pair = it->get_object();
        if(pair->match(key)){
            return pair->value;
        }
    }
    return nullptr;
}

template class Hash<int>;