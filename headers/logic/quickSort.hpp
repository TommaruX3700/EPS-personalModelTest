#ifndef QSP_H
#define QSP_H

#include <vector>
#include <algorithm>  // Per std::max
#include "../entities/physical/Pack.hpp"

using namespace std;

double calculateArea(const Pack& p) {
    return p.getDims().X * p.getDims().Y;
}

int partition(vector<Pack>& pacchi, int low, int high) {
    double pivot = calculateArea(pacchi[low]);
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (calculateArea(pacchi[i]) > pivot);
        do {
            j--;
        } while (calculateArea(pacchi[j]) < pivot);
        if (i >= j) {
            return j;
        }
        swap(pacchi[i], pacchi[j]);
    }
}

void quickSort(vector<Pack>& pacchi, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}

void swap(Pack& a, Pack& b) {
    Pack c = a;
    a = b;
    b = c;
}

#endif
