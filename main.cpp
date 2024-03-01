#include <iostream>
#include <vector> //delete
#include <cstdlib>

void arrayOut(int list[], int listLength){
    for(int i = 0; i < listLength; i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}
void bubbleSort(int list[], int listLength)
{
    while(listLength--)
    {
        bool swapped = false;

        for(int i = 0; i < listLength; i++)
        {
            if(list[i] > list[i + 1])
            {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }

        if(swapped == false)
            break;
    }
}
int partition(int list[], int low,int high) {
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i+1], list[high]);
    return i + 1;
}
int randomPartition(int list[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(list[randomIndex], list[high]);
    return partition(list, low, high);
}
void quickSort(int list[], int low,int high) {
    if (low < high) {
        int pi = randomPartition(list, low, high);

        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}
void heapify(int list[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && list[left] > list[largest]) {
        largest = left;
    }

    if (right < n && list[right] > list[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(list[i], list[largest]);
        heapify(list, n, largest);
    }
}
void heapSort(int list[],int n) {

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(list, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(list[0], list[i]);
        heapify(list, i, 0);
    }
}


int main()
{
    int list[5] = {0,0,0,0,0};
    int n = sizeof(list)/sizeof(int);
    int list1[5] = {0,0,0,0,0};
    int list2[5] = {0,0,0,0,0};
    int list3[5] = {0,0,0,0,0};


    std::cout << "Lenth of array = " << n << std::endl;

    std::cout << "Input every element of array: " << std::endl;
    for(int i = 0; i < n; i++)
        std::cin >> list[i];
    std::cout << std::endl;

    std::copy(std::begin(list), std::end(list), std::begin(list1));
    std::copy(std::begin(list), std::end(list), std::begin(list2));
    std::copy(std::begin(list), std::end(list), std::begin(list3));

    bubbleSort(list1, n);
    quickSort(list2, 0, n - 1);
    heapSort(list3, n);

    std::cout << "Bubble sorted array: " << std::endl;
    arrayOut(list1,n);
    std::cout << "Quick sorted array: " << std::endl;
    arrayOut(list2,n);
    std::cout << "Heap sorted array: " << std::endl;
    arrayOut(list3,n);
}