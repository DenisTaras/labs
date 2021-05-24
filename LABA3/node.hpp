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
class Tree{
    private:
    node<TV,TK>* root;

    public:
    unsigned char height_tree(){
        return root->heigt;
    }

    Tree(){
        root = nullptr;
    }

    node<TV,TK>* find(TK key){
        return findnoderec(key, root);
    }

    ~Tree(){
        delete_Tree(root);
    }

    void printTree(){
        printTreerev(root, 1);
    }
    TV Get(TK key){
        node<TV,TK>* a = find(key);
        return a->data;
    }

    void insert(TK key,TV vall){
        if(root == nullptr){
        node<TV,TK>* new_node = new node<TK,TV>;
        new_node->father=nullptr;
        new_node->rson =nullptr;
        new_node->lson=nullptr;
        new_node->key=key;
        new_node->data=vall;
        new_node->heigt=1;
        root = new_node;
        }
        else{
            insertat(key,vall,root);

        }
    }

    void delete_node(TK key){
        node<TV,TK>* now = find(key);
        delete_node_rec(now);
    }

    void map( void (*funk)(TV* element)){
        node<TV,TK>* curr = root;
        node<TV,TK>* prev = nullptr;
        do{
            if((!curr->lson) && (!curr->rson) && (!curr->father)){// если только 1 элемент
                funk(&(curr->data));
                return;
            }
            else if((curr->lson) && (curr->rson != prev) && (curr->lson != prev)){ //down left
                prev = curr;
                curr = curr->lson;
            }
            else if((curr->rson) && (curr->rson != prev) && ((curr->lson == prev) || (!(curr->lson)))){// right down
                prev = curr;
                curr = curr->rson;
            }
            else if ((!curr->lson) && (!curr->rson)){  //last 
                funk(&(curr->data));
                prev = curr;
                curr = curr->father;
            }
            else if((curr->rson == prev) || ((!curr->rson) && (prev == curr->lson))){
                funk(&(curr->data));
                prev = curr;
                curr = curr->father;
            }
        }while(!((curr->father == nullptr) && (curr->rson == prev)));
    }

    Tree<TV,TK> * where(bool(*f)(TV elem)){
    node<TV,TK> * curr = root;
    node<TV,TK> * lastNode = nullptr;
    Tree<TV,TK> * newtree = new Tree();
    while(curr != nullptr){
        if(lastNode == curr->father){
            if(curr->lson){
                lastNode = curr;
                curr = curr->lson;
            } else if (curr->rson){
                lastNode = curr;
                curr = curr->rson;
            } else {
                if(f(curr->data)){
                    newtree->insertat(curr->key, curr->data);
                }
                lastNode = curr;
                curr = curr->father;
            }
        } else if(lastNode == curr->lson){
            if(curr->rson){
                lastNode = curr;
                curr = curr->rson;
            } else {
                if(f(curr->data)){
                    newtree->insertat(curr->key,curr->data);
                }
                lastNode = curr;
                curr = curr->father;
            }
        } else if(lastNode == curr->rson){
            if(f(curr->data)){
                newtree->insertat(curr->key,curr->data);
            }
            lastNode = curr;
            curr = curr->father;
        }
    }
    return newtree;
    }

    void merger( Tree<TV,TK> tree){
        node<TV,TK>* curr = root;
        node<TV,TK>* prev = nullptr;
        do{
            if((!curr->lson) && (!curr->rson) && (!curr->father)){// если только 1 элемент
                tree.insertat(curr);
                return;
            }
            else if((curr->lson) && (curr->rson != prev) && (curr->lson != prev)){ //down left
                prev = curr;
                curr = curr->lson;
            }
            else if((curr->rson) && (curr->rson != prev) && ((curr->lson == prev) || (!(curr->lson)))){// right down
                prev = curr;
                curr = curr->rson;
            }
            else if ((!curr->lson) && (!curr->rson)){  //last 
                tree.insertat(curr);
                prev = curr;
                curr = curr->father;
            }
            else if((curr->rson == prev) || ((!curr->rson) && (prev == curr->lson))){
                tree.insertat(curr);
                prev = curr;
                curr = curr->father;
            }
        }while(!((curr->father == nullptr) && (curr->rson == prev)));
    }

    protected:
    void delete_node_rec(node<TV,TK>* now){
        if(now == nullptr){
            throw "Key doesn't found";
        }
            if(now->rson == nullptr && now->lson == nullptr){
                if(now->father->rson == now){
                    now->father->rson = nullptr;
                }
                else if(now->father->lson == now){
                    now->father->lson = nullptr;
                }
                node<TV,TK>* parent = now->father;
                delete now;
                fix_height(parent);
                while (parent->father != nullptr)
                {
                    parent = balance(parent);
                    fix_height(parent);
                    parent = parent->father;
                }
                root = balance(root);
                fix_height(root);
                return;
            }
            else{
                if(((now->rson) && (now->lson) && (height(now->rson) < height(now->lson))) || (!now->rson)&&(now->lson)){
                    node<TV,TK>* curr = now->lson;
                    while (curr->rson != nullptr)
                    {
                        curr=curr->rson;
                    }
                    now->key=curr->key;
                    now->data=curr->data;
                    delete_node_rec(curr);
                }
                else if(((now->lson) && (now->rson) && (height(now->lson) < height(now->rson))) || (!now->lson)&&(now->rson)){
                    node<TV,TK>* curr = now->rson;
                    while (curr->lson != nullptr)
                    {
                        curr=curr->lson;
                    }
                    now->key=curr->key;
                    now->data=curr->data;
                    delete_node_rec(curr);
                }
                else if((now->rson)&&(now->lson)&&(height(now->rson)==height(now->lson))){
                    node<TV,TK>* currR = now->rson;
                    while (currR->lson != nullptr)
                    {
                        currR = currR->lson;
                    }
                    node<TV,TK>* currL = now->lson;
                    while (currL->rson != nullptr)
                    {
                        currL = currL->rson;
                    }
                    if((now->key - currL->key) < (currR->key - now->key)){
                        now->key = currL->key;
                        now->data = currL->data;
                        delete_node_rec(currL);
                    }
                    else{
                        now->key = currR->key;
                        now->data = currR->data;
                        delete_node_rec(currR);
                    }
                }
            }
    }

    void printTreerev(node<TV,TK> *top, int level) {
        if (top) {
            printTreerev(top->lson, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "_____";
            std::cout << top->key << "(" << ((top->father)?(top->father->key):-1) << ")" << std::endl;
            printTreerev(top->rson, level + 1);
        } else {
            for (int i = 0; i < level; i++){
                std::cout << "_____";
            }
                    
            std::cout << "nil" << std::endl;
        }
    }

    void delete_Tree(node<TV,TK>* qwe){
        if(qwe == nullptr){
            return;
        }
        if((qwe->lson) && (root->rson)){
            if(qwe->father){
                if(qwe->father->rson == qwe){
                    qwe->father->rson = nullptr;
                }
                else if(qwe->father->lson == qwe){
                    qwe->father->lson == nullptr;
                }
            }
            delete qwe;
        }
        else if(qwe->rson){
            delete_Tree(qwe->lson);
            delete_Tree(qwe);

        }
        else if(qwe->lson){
            delete_Tree(qwe->rson);
            delete_Tree(qwe);
        }
        else{
            delete_Tree(qwe->lson);
            delete_Tree(qwe->rson);
            delete_Tree(qwe);
        }
    }
    
    node<TV,TK>* balance(node<TV,TK>* now_node){
        if(now_node == nullptr){
            return nullptr;
        }
        else if(bfactor(now_node) == 2){
            if(bfactor(now_node->rson) >= 0){
                now_node=small_left_dance(now_node);
            }
            else if(bfactor(now_node->rson) < 0){
                now_node=big_left_dance(now_node);
            }
        }
        else if(bfactor(now_node) == -2){
            if(bfactor(now_node->lson) <= 0){
                now_node=small_right_dance(now_node);
            }
            else if(bfactor(now_node->lson) > 0){
                now_node=big_right_dance(now_node);
            }
        }
        return now_node;
    }

    char bfactor(node<TV,TK>* now_node){
        return height(now_node->rson)-height(now_node->lson);
    }
    
    node<TV,TK>* big_right_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->lson;
        node<TV,TK>* c = b->rson;
        c->father=a->father;
        if(c->father){
            if (c->father->rson == a)
            {
                c->father->rson = c;
            }
            else if(c->father->lson == a){
                c->father->lson = c; 
            } 
        }
        b->rson = c->lson;
        if (c->lson)
        {
            c->lson->father=b;
        }
        c->lson=b;
        b->father=c;
        a->lson=c->rson;
        if(c->rson){
            c->rson->father=a;
        }
        c->rson=a;
        a->father=c;
        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }

    node<TV,TK>* big_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->rson;
        node<TV,TK>* c = b->lson;
        c->father=a->father;
       if(c->father){
            if (c->father->rson == a)
            {
                c->father->rson = c;
            }
            else if(c->father->lson == a){
                c->father->lson = c; 
            } 
        }
        b->lson = c->rson;
        if (c->rson){
            c->rson->father=b;
        }
        c->rson=b;
        b->father=c;
        a->rson=c->lson;
        if(c->lson){
            c->lson->father=a;
        }
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
        if(b->father){
            if (b->father->rson == a)
            {
                b->father->rson = b;
            }
            else if(b->father->lson == a){
                b->father->lson = b; 
            } 
        }
        a->lson=b->rson;
        if(b->rson){ 
            b->rson->father=a;
        }
        b->rson=a;
        a->father=b;
        fix_height(a);
        fix_height(b);
        return b;
    }

    node<TV,TK>* small_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->rson;
        b->father=a->father;
        if(b->father){
            if (b->father->rson == a)
            {
                b->father->rson = b;
            }
            else if(b->father->lson == a){
                b->father->lson = b; 
            } 
        } 
        a->rson=b->lson;
        if (b->lson){
            b->lson->father=a;
        }
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
        if(now_node != nullptr){
        return now_node->heigt;
        }
        else return 0;
    }

    void fix_height(node<TV,TK>* now_node){
        now_node->heigt = 1 + std::max(height(now_node->lson), height(now_node->rson));
    }

    void insertat(TK key,TV vall,node<TV,TK>* now_node){
        if(now_node->rson == nullptr && key > now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->rson =nullptr;
            new_node->lson=nullptr;
            now_node->rson=new_node;
            new_node->key=key;
            new_node->data=vall;
            new_node->father=now_node;
            new_node->heigt = 1;
        }
        else if(now_node->lson == nullptr && key < now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->rson =nullptr;
            new_node->lson=nullptr;
            now_node->lson=new_node;
            new_node->key=key;
            new_node->data=vall;
            new_node->father=now_node;
            new_node->heigt = 1;
        }   
        else if(key < now_node->key){
            insertat(key, vall,now_node->lson);
            return;
        }
        else if(key > now_node->key){
            insertat(key, vall,now_node->rson);
            return;
        }
        else if(key == now_node->key){
            now_node->data = vall;
            return;
        }
        node<TV,TK>* curr = now_node;
        while ((curr != nullptr)  && (std::abs(bfactor(curr)) != 2))
        {
            fix_height(curr);
            curr= curr->father;
        }
        if (curr)
        {
            if(curr->father){
                if (curr->father->lson == curr)
                {
                    curr->father->lson = balance(curr);
                }
                else if(curr->father->rson == curr){
                    curr->father->rson = balance(curr);
                }   
            }
            else{
            root = balance(root);
            }
        }
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
            return findnoderec(key, now->rson);
        }
        else if (key < now->key)
        {
            if(now->lson == nullptr){
                return nullptr;
            }
            return findnoderec(key, now->lson);
        }
    }

};
#endif