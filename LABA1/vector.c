#include "vector.h"
#include <stdio.h>
vector* create (int size){
    vector* result =(vector*)calloc(1,sizeof(vector));
    result->size = size;
    return result;
}
void del(vector* del){
    if (del->head){
        free(del->head);
    }
    free(del);
}
void push(vector* pu,void* data, int count){
    pu->head=realloc(pu->head,(pu->len+count)*pu->size);
    memcpy(pu->head + (pu->len)*pu->size,data,count*pu->size);
    pu->len+=count;

}