#ifndef Sequence_hpp
#define Sequence_hpp
#include "List.hpp"
#include "Array.hpp"

template<typename T>
class Sequence{
public:
    virtual Sequence<T>* GetSubsequence(int startIndex,int endIndex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;

    virtual void Append(T item) = 0;
    virtual void Set(int index,T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item,int index) = 0;

    virtual void Print() = 0;
};

template<typename T>
class ArraySequence : public Sequence<T>{
public:
    ArraySequence(): data() {}
    ArraySequence(int size): data(size) {}
    ArraySequence(T* item,int count): data(item, count) {}

    ArraySequence(const ArraySequence<T> &array) : data(array.data){}

    ArraySequence(LinkedList<T>& list){
        T* items;
        items = new T [(list.GetLength())];
        for (int i = 0; i < list.GetLength(); ++i) {
            items[i] = list.Get(i);
        }

        DynamicArray<T>* tmp = new DynamicArray<T>(items,list.GetLength());
        data = *tmp;
    }
    int GetLength() const{
        return data.GetSize();
    }
    T Get(int index) const{
        return data.Get(index);
    }
    T GetFirst() const{
        return data.Get(0);
    }
    T GetLast() const{
        return data.Get(data.GetSize()-1);
    }
    void Set(int index, T item){
        return data.Set(index,item);
    }
    void Append(T item){
        data.Append(item);
    }
    void Prepend(T item){
        data.Prepend(item);
    }
    void InsertAt(T item,int index){
        if(index >= data.GetSize() || index < 0)
            throw "\nInsertAt Message : Index Out Of Range";
        data.Resize(data.GetSize()+1);
        for (int i = data.GetSize()-2; i >= index ; --i) {
            data.Set(i+1,data.Get(i));
        }
        data.Set(index,item);
    }

    void Print(){
        data.Print();
    }

    static int compare(ArraySequence<T> P1, ArraySequence<T> P2){
        if(P1.GetLength() == P2.GetLength()){
            for (int i = 0; i < P1.GetLength(); i++){
                if(!(P1.Get(i) == P2.Get(i))){
                    return 0;
                }
            }
            return 1;
        }
        else return 0;
    }
    ArraySequence<T>* GetSubsequence(int startIndex,int endIndex){
        T* items = new T [(endIndex-startIndex)];
        for (int i = startIndex; i < endIndex; ++i) {
            items[i-startIndex] = data.Get(i);
        }
        ArraySequence<T>* result = new ArraySequence<T>(items,endIndex-startIndex);
        return result;
    }

    ArraySequence<T>* Concat(Sequence<T>* list){
        if(list->GetLength() != 0){
            T* items = new T [(data.GetSize()+list->GetLength())];
            for (int i = 0; i < data.GetSize(); ++i) {
                items[i] = data.Get(i);
            }
            for (int i = 0; i < list->GetLength(); ++i) {
                items[i+data.GetSize()] = list->Get(i);
            }
            ArraySequence<T>* result = new ArraySequence<T>(items,data.GetSize()+list->GetLength());

            return result;
        }else{
            ArraySequence<T>* result = new ArraySequence<T>(*this);
            return result;
        }

    }


private:
    DynamicArray<T> data;
};
template<typename T>
std::ostream & operator << (std::ostream & out, const Sequence<T>& a){
    for(int i = 0; i < a.GetLength();++i){
        out << a.Get(i) << " ";
    }
    return out;
}
template<typename T>
std::istream & operator >> (std::istream & in, ArraySequence<T>& a){
    T q;
    for(int i = 0; i < a.GetLength();i++){
        in >> q;
        a.Set(i,q);
    }
    return in;
}
template<typename T>
class LinkedListSequence : public Sequence<T>{
public:
    LinkedListSequence(){
        LinkedList<T>* tmp = new LinkedList<T>();
        data = *tmp;
    }
    LinkedListSequence(T* items,int count){
        LinkedList<T>* tmp = new LinkedList<T>(items,count);
        data = *tmp;

    }
    LinkedListSequence<T>* Concat(Sequence<T>* list){
        for (int i = 0; i < list->GetLength(); ++i) {
            data.Append(list->Get(i));
        }
        T* items;
        items = new T [(data.GetLength()+list->GetLength())];
        for (int i = 0; i < data.GetLength(); ++i) {
            items[i] = data.Get(i);
        }

        LinkedListSequence<T>* result = new LinkedListSequence<T>(items,data.GetLength());
        return result;
    }

    LinkedListSequence(const LinkedList<T>& list){
        LinkedList<T>* tmp = new LinkedList<T>(list);
        std::cout<< "Constructor by object . . .\n";
        data = *tmp;
    }
    LinkedListSequence<T>* GetSubsequence(int startIndex,int endIndex){
        LinkedList<T>* tmp = data.GetSubLinkedList(startIndex,endIndex);
        T* items;
        items = new T [(endIndex-startIndex)];
        for (int i = 0; i < endIndex-startIndex; ++i) {
            items[i] = tmp->Get(i);
        }

        LinkedListSequence<T>* result = new LinkedListSequence<T>(items,endIndex-startIndex);

        return result;
    }

        static int compare(LinkedListSequence<T> P1, LinkedListSequence<T> P2){
        if(P1.GetLength() == P2.GetLength()){
            for (int i = 0; i < P1.GetLength(); i++){
                if(!(P1.Get(i) == P2.Get(i))){
                    return 0;
                }
            }
            return 1;
        }
        else {return 0;}
    }

    int GetLength() const{
        return data.GetLength();
    }
    T GetFirst() const{
        return data.GetFirst();
    }
    T GetLast() const{
        return data.GetLast();
    }
    T Get(int index) const{
        return data.Get(index);
    }
    void Append(T item){
        data.Append(item);
    }
    void Prepend(T item){
        data.Prepend(item);
    }
    void InsertAt(T item,int index){
        data.InsertAt(item,index);
    }
    void removeAt(int index){
        data.removeAt(index);
    }
    void Print(){
        data.print_from_begin();
    }
    void Set(int index, T data1){
        data.Set(data1, index);
    }

private:
    LinkedList<T> data;
};
#endif