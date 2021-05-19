#ifndef node_hpp
#define node_hpp
#include <iostream>
#include <stdio.h>
template<typename TV, typename TK>
struct node
{
    TK key;
    TV data;
    node<TV,TK>* rson;
    node<TV,TK>* lson;
    node<TV,TK>* father;
    unsigned char heigt;
};
template<typename TV, typename TK>
void del(node<TV,TK>* N){
    delete[] N->key;
    delete[] N->data;
}

template<typename TV, typename TK>
class Tree{
    private:
    node<TV,TK>* root;

    public:
    Tree(){
        root = nullptr;
    }
    node<TV,TK>* find(TK key){
        return findnoderec(key, root);
    }
    void insert(TK key,TV vall){
        if(root == nullptr){
        node<TV,TK>* new_node = new node<TK,TV>;
        new_node->father=nullptr;
        new_node->rson =nullptr;
        new_node->lson=nullptr;
        new_node->key=key;
        new_node->data=vall;
        new_node->heigt=0;
        }
        else{
            insertat(key,vall,root);

        }
    }
    void delete_node(TK key){
        node<TV,TK>* now = find(key);
        if(!now){
            throw "Not found Node";
        }
        if(now->lson == nullptr && now->rson == nullptr){
            node<TV,TK>* peretn = now->father;
            while (peretn != nullptr)
            {
                balance(peretn);
                peretn= peretn->father;
            }         
        }
        else if(heigt(now->lson) > heigt(now->rson) || now->rson== nullptr){
            node<TV,TK> * cure = now->lson;
            while (cure->rson != nullptr)
            {
                cure = cure->lson;
            }
            now->data=cure->data;
            now->key=cure->key;
            node<TV,TK>* peretn = cure->father;
            while (peretn != nullptr)
            {
                balance(peretn);
                peretn= peretn->father;
            }           
        }
        else if(heigt(now->rson) > heigt(now->lson) || now->lson == nullptr){
            node<TV,TK> * cure = now->rson;
            while (cure->lson != nullptr)
            {
                cure = cure->rson;
            }
            now->data=cure->data;
            now->key=cure->key;
            node<TV,TK>* peretn = cure->father;
            while (peretn != nullptr)
            {
                balance(peretn);
                peretn= peretn->father;
            }       
        }
        else if(height(now->rson) == height(now->lson)){
            node<TV,TK>* currel = now->lson;
            node<TV,TK>* currer = now->rson;
            while (currel != nullptr)
            {
                currel->rson;
            }
            while (currer != nullptr)
            {
                currer->lson;
            }
            if(std::abc(currer->key - now->key) > std::abc(currel->key - now->key)){
            now->data=curel->data;
            now->key=curel->key;
            node<TV,TK>* peretn = curel->father;
            while (peretn != nullptr)
            {
                balance(peretn);
                peretn= peretn->father;
            }           
            }
            else{
            now->data=curer->data;
            now->key=curer->key;
            node<TV,TK>* peretn = curer->father;
            while (peretn != nullptr)
            {
                balance(peretn);
                peretn= peretn->father;
            }
            }
        }
    }
    protected:
    void balance(node<TV,TK>* now_node){
        if(now_node == nullptr){
            return;
        }
        else if(bfactor(now_node) = 2){
            if(bfactor(now_node->rson) >= 0){
                now_node=small_left_dance(now_node);
            }
            else if(bfactor(now_node->rson) < 0){
                now_node=big_left_dance(now_node);
            }
        }
        else if(bfactor(now_node) = -2){
            if(bfactor(now_node->lson) <= 0){
                now_node=small_right_dance(now_node);
            }
            else if(bfactor(now_node->lson) > 0){
                now_node=big_right_dance(now_node);
            }
        }
    }
    char bfactor(node<TV,TK>* now_node){
        return height(now_node->rson)-height(now_node->lson);
    }
    node<TV,TK>* big_right_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->lson;
        node<TV,TK>* c = b->rson;
        c->father=a->father;
        b->rson = c->lson;
        c->lson->father=b;
        c->lson=b;
        b->father=c;
        a->lson=c->rson;
        c->rson->father=a;
        c->rson=a;
        a->father=c;
        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }
    node<TV,TK>* big_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->rson;
        node<TV,TK>* c = b->lsin;
        c->father=a->father;
        b->lson = c->rson;
        c->rson->father=b;
        c->rson=b;
        b->father=c;
        a->rson=c->lson;
        c->lson->father=a;
        c->lson=a;
        a->father=c;
        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }
    node<TV,TK>* small_right_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->lson;
        b->father=a->father;
        a->lson=b->rson;
        b->rson->father=a;
        b->rson=a;
        a->father=b;
        fix_height(a);
        fix_height(b);
        return b;
    }
    node<TV,TK>* small_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->rson;
        b->father=a->father; 
        a->rson=b->lson;
        b->lson->father=a;
        b->lson=a;
        a->father=b;
        fix_height(a);
        fix_height(b);
        return b;
    }
 /*  int height(node<TK,TV>* now_node){
        if(now_node == nullptr){
            return 0;
        }
        else if(now_node->rson == nullptr && now_node->lson == nullptr){
            return 0;
        }
        else
        return ;
    }*/

    unsigned char height(node<TV,TK>* now_node){
        if(now_node != nullptr)
        return now_node->heigt
        else return 0;
    }

    void fix_height(node<TV,TK>* now_node){
        now_node->heigt = 1 + std::max(height(now_node->lson), height(now_node->lson));
    }
    void insertat(TK key,TV vall,node<TV,TK>* now_node){
        if(now_node->rson == nullptr && key > now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->rson =nullptr;
            new_node->lson=nullptr;
            now_node->rson=new_node;
            new_node->key=key;
            now_node->data=vall;
            new_node->father=now_node;
        }
        else if(now_node->lson == nullptr && key < now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->rson =nullptr;
            new_node->lson=nullptr;
            now_node->lson=new_node;
            new_node->key=key;
            now_node->data=vall;
            new_node->father=now_node
        }   
        else if(key > now_node->key){
            insertat(key, vall,now_node->lson);
            return;
        }
        else if(key < now_node->key){
            insertat(key, vall,now_node->rson);
            return;
        }
        else if(key == now_node->key){
            now_node->vall = vall;
        }
        node<TV,TK>* curr = now_node;
        while ((std::abs(bfactor(curr)) != 2) && curr != nullptr)
        {
            fix_height(curr);
            curr= curr->father;
        }
        balance(curr);
    }
    node<TV,TK>* findnoderec(TK key,node<TV,TK>* now){
        if(key==now->key){
            return now;
        }
        else if (key > now->key)
        {
            if(now->rson == nullptr){
                return nullptr;
            }
            now = now->rson;
            return findnoderec(key, now);
        }
        else if (key < now->key)
        {
            if(now->lson == nullptr){
                return nullptr;
            }
            now = now->lson;
            return findnoderec(key, now);
        }
    }


};
#endif