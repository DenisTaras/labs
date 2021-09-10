#ifndef List_hpp
#define List_hpp
#include <string.h>
#include <iostream>
template<typename T>
class Node{
public:
    Node* pNext;
    Node* pPrev;
    T data;
    Node(T data = T(),Node* pPrev = nullptr,Node* pNext = nullptr){
        this->data = data;
        this->pPrev = pPrev;
        this->pNext = pNext;
    }
};


template<typename T>
class LinkedList{
public:
    LinkedList();
    LinkedList(T* items,int count);
    LinkedList(const LinkedList<T>& LinkedList );
    ~LinkedList();

    int GetLength() const{return Size;}
    T GetFirst() const;
    T GetLast() const;
    T Get(int index) const;
    void Set(T data, int index);

    LinkedList<T>* GetSubLinkedList(int startIndex,int endIndex);
    LinkedList<T>* Concat(LinkedList<T>* LinkedList);

    void Append(T data);//push_back
    void Prepend(T data);

    void pop_front();
    void pop_back();

    void print_from_end();
    void print_from_begin();

    void InsertAt(T data,int index);
    void removeAt(int index);


    T& operator[] (const int index);

private:
    int Size;
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
LinkedList<T> :: ~LinkedList(){
        while(Size){
        pop_front();
    }
}
template<typename T>
LinkedList<T> :: LinkedList(){
    Size = 0;
    head = nullptr;
}

template<typename T>
LinkedList<T> :: LinkedList(T* items,int count){
    if(items == nullptr){
        Size = 0;
        head = nullptr;
    }
    else{
        Size = 0;
        this->head = nullptr;
        this->tail = nullptr;
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }
}

template<typename T>
LinkedList<T> :: LinkedList(const LinkedList<T>& list){
    Size = 0;
    this->head = nullptr;
    Node<T>* current = list.head;
    for (int i = 0; i < list.GetLength();++i){
        this->Append(current->data);
        current = current->pNext;
    }
}

template<typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list){
    this->tail->pNext = list->head;
    list->head->pPrev = this->tail;
    this->tail = list->tail;
    Size+=list->Size;

    return this;
}

template<typename T>
T LinkedList<T> ::Get(int index) const{
    if(index < 0 || index >= Size)
        throw "\nGet Message : Index Out Of Range\n";

    Node<T>* current;

    if(index < Size/2){
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->pNext;
        }
    }else{
        current = tail;
        for (int i = 0; i < Size-index-1; ++i) {
            current = current->pPrev;
        }
    }
    return current->data;

}
template<typename T>
void LinkedList<T> ::Set(T data,int index){
     if(index < 0 || index >= Size)
        throw "\nGet Message : Index Out Of Range\n";
    Node<T>* current;
    if(index < Size/2){
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->pNext;
        }
    }else{
        current = tail;
        for (int i = 0; i < Size-index-1; ++i) {
            current = current->pPrev;
        }
    }
    current->data=data;
}

template<typename T>
T LinkedList<T> ::GetFirst()  const{
    if(Size == 0)
        throw "\nGetFirst Message : Index Out Of Range\n";
    std::cout<<"\nGetFirst:\n";
    return Get(0);
}

template<typename T>
T LinkedList<T> ::GetLast() const{
    if(Size == 0)
        throw "\nGetLast Message : Index Out Of Range\n";
    std::cout<<"\nGetLast:\n";
    return Get(Size - 1);
}

template<typename T>
LinkedList<T>* LinkedList<T>::GetSubLinkedList(int startIndex,int endIndex){
    if(startIndex < 0 || endIndex < 0 || startIndex >= Size || endIndex >=Size)
        throw "\nGetSubLinkedList Message : Index Out Of Range\n";
    //std::cout<<"\nGetSubLinkedList\n";
    Node<T>* current = this->head;
    for (int i = 0; i <=startIndex; ++i) {
        current = current->pNext;
    }
    T* items;
    items = new T [(endIndex-startIndex)];
    for (int i = 0; i < endIndex-startIndex; ++i) {
        items[i] = current->data;
        current = current->pNext;
    }

    LinkedList<T>* result = new LinkedList<T>(items,endIndex-startIndex);
    return result;

}

template<typename T>
void LinkedList<T> ::print_from_end(){
    std::cout << std::endl;
    Node<T>* tmp = this->tail;
    if(Size == 1)
        std::cout << tail->data << " ";
    else{
        while(tmp != nullptr){
            std::cout << tmp->data <<" ";
            tmp = tmp->pPrev;
        }
    }
}

template<typename T>
void LinkedList<T> ::print_from_begin(){
    if(head != nullptr){
        std::cout << std::endl;
        Node<T>* tmp = this->head;
        if(Size == 1)
            std::cout << head->data << " ";
        else{
            while(tmp != nullptr){
                std::cout << tmp->data <<" ";
                tmp = tmp->pNext;
            }
        }
    }
}


template<typename T>
void LinkedList<T> :: Append(T data){
    if(head == nullptr){
        head = new Node<T>(data);
        this->tail = head;

    }else{
        Node<T>* current = this->head;
        Node<T>* tmp;
        while(current->pNext != nullptr){
            tmp = current;
            current = current->pNext;
            current->pPrev = tmp;
        }

        this->tail = new Node<T>(data,current,current->pNext);
        current->pNext = tail;
    }
    Size++;
}

template<typename T>
void LinkedList<T> ::Prepend(T data) {
    if(head == nullptr){
        head = new Node<T>(data);
        this->tail = head;
    }
    else{
        Node<T>* one_more = new Node<T>(data,head->pPrev,head);
        head->pPrev = one_more;
        this->head = one_more;
        Node<T>* current = head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        this->tail = current;
    }
    Size++;
}

template<typename T>
void LinkedList<T> ::pop_front() {
    if(Size == 1){
        delete [] tail;
        Size--;
    }
    else{
        Node<T>* tmp = head;
        head = head->pNext;
        head->pPrev = nullptr;
        delete [] tmp;
        Size--;
    }

}

template<typename T>
void LinkedList<T> ::pop_back(){
    Node<T>* tmp = tail;
    tail = tail->pPrev;
    tail->pNext = nullptr;
    delete [] tmp;
    Size--;
}

template<typename T>
void LinkedList<T> ::InsertAt(T data, int index) {
    if(index < 0 || index >= Size)
        throw "\nInsertAt Message : Index Out Of Range\n";
    Node<T>* previous;
    Node<T>* new_elem;
    Node<T>* tmp;
    std::cout << "\nInsertAt data = " << data << " index = " << index << "\n";
    if(index <= Size/2){
        if(index == 0)
            Prepend(data);
        previous = head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
    }
    else{

        previous = tail;
        for (int i = 0; i < Size - index; ++i) {
            previous = previous->pPrev;
        }
    }
    tmp = previous->pNext;
    new_elem = new Node<T>(data,previous,previous->pNext);
    previous->pNext = new_elem;
    tmp->pPrev = new_elem;

    Size++;
}

template<typename T>
void LinkedList<T>::removeAt(int index) {
    if(index < 0 || index >= Size)
        throw "removeAt Message : Index Out Of Range\n";
    std::cout << "\nremoveAt index = " << index << "\n";
    if(index == 0)
        pop_front();
    else{
        if(index == Size - 1)
            pop_back();
        else{
            Node<T>* previous;
            Node<T>* toDelete;
            if(index <= Size/2){
                previous = head;
                for (int i = 0; i < index - 1; ++i) {
                    previous = previous->pNext;
                }
            }
            else{
                previous = tail;
                for (int i = 0; i < Size - index; ++i) {
                    previous = previous->pPrev;
                }
            }

            toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            toDelete->pNext->pPrev = previous;

            delete[] toDelete;
        }
        Size--;
    }
}



template<typename T>
T& LinkedList<T> :: operator[](const int index){
    int counter;
    Node<T>* current;
    if(index <= Size/2){
        counter = 0;
        current = this->head;
        while(current != nullptr){
            if(counter == index){
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
    else{
        counter = Size - 1;
        current = this->tail;
        while(current != nullptr){
            if(counter == index){
                return current->data;
            }
            current = current->pPrev;
            counter--;
        }
    }
}
#endif