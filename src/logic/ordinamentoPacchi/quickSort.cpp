#include <vector>
#include "../../../headers/entities/physical/Pack.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/quickSort.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/ordinamentoPacchi.hpp"

double calculateArea(const Pack& p) {
    return p.getDims().num1 * p.getDims().num2;
}

int partition(packVector& pacchi, int low, int high) {
    double pivot = calculateArea(*pacchi[low]);  // Dereference the pointer
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (calculateArea(*pacchi[i]) > pivot);
        do {
            j--;
        } while (calculateArea(*pacchi[j]) < pivot);
        if (i >= j) {
            return j;
        }
        swap(pacchi[i], pacchi[j]);
    }
}

void quickSort(packVector& pacchi, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}

void swap(Pack*& a, Pack*& b) {
    Pack* c = a;
    a = b;
    b = c;
}
