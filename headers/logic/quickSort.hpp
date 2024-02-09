#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>
#include "../entities/physical/Pack.hpp"

double calculateArea(const Pack& p);

int partition(packVector& pacchi, int low, int high);

void quickSort(packVector& pacchi, int low, int high);

void swap(Pack*& a, Pack*& b);  // Change the swap function to work with pointers

#endif
