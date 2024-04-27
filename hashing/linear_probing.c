#include<stdio.h>
#define SIZE 10

int hash(int key){
    return key % SIZE;
}

int probe(int H[], int key){
    int ind = hash(key);
    int i = 0;

    while(H[(ind+i)%SIZE] != 0){
        i++;
    }

    return (ind+i)%SIZE;
}

void insert(int H[], int key){
    int ind = hash(key);

    // Check if the index is occupied or not
    if(H[ind] != 0)
        // Collision occurs, so find next free space using linear probing
        ind = probe(H, key);

    H[ind] = key; // insert the element
}

int search(int H[], int key){
    int ind = hash(key);
    int i = 0;

    while(H[(ind+i)%SIZE] != key){
        if(H[(ind+i)%SIZE] == 0)
            return -1;
        i++;
    }

    return (ind+i)%SIZE;
}

int main(){
    int HT[10] = {0}, key, ind;
    
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);

    key = 35;
    ind = search(HT, key);
    printf("%d is found at index %d in the hashtable.\n", key, ind);

    return 0;
}