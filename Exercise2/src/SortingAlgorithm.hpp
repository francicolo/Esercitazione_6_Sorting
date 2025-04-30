#pragma once

#include <iostream>
#include <vector>
//#include <concepts>
//#include <utility>

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};


///Bubble sort        
template<Sortable T>

void BubbleSort(std::vector<T>& v){
    const unsigned int n = v.size();
    for(unsigned int i = 0; i <= n-2; i++){
        for(unsigned int j = i+1; j <= n-1; j++){
            if(v[j] < v[i]){
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }       
}

///Heap sort

template<Sortable T>
void HeapSort(std::vector<T>& v) {

    unsigned int n = v.size();
    bool disordinato = true;

    //Enqueue: costruire l'heap dal vettore v
    for (unsigned int i = 0; i < n; i++) {
        unsigned int j = i;
        disordinato = true;
        // aggiungo l'elemento all'heap
        while(j > 0 && disordinato){
            unsigned int padre = (j - 1) / 2;
            if (v[j] > v[padre]) { // se figlio > padre
                std::swap(v[j], v[padre]); // li scambio
                j = padre;
            } 
            else {
                disordinato = false;
            }
        }
    }
    //Dequeue: riordinare v per priorità decrescente
    for (unsigned int i = n; i > 1; i--) {
        std::swap(v[0], v[i-1]);
        unsigned int j = 0;
        
        while (2 * j + 1 < i - 1){
            unsigned int figlio_sx = 2 * j + 1;
            unsigned int figlio_dx = 2 * j + 2;
            unsigned int maggiore = j;

            if (figlio_sx < i - 1 && v[figlio_sx] > v[maggiore])
                maggiore = figlio_sx;
            if (figlio_dx < i - 1 && v[figlio_dx] > v[maggiore])
                maggiore = figlio_dx;

            if (maggiore != j){
                std::swap(v[j], v[maggiore]);
                j = maggiore;
            }
            else {
                break;
            }
        }
    }
    }
}


