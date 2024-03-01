#include <iostream>

void arrayout(int list[], int listLength){
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

int main()
{
    int list[5] = {0,0,0,0,0};
    int list1[5] = {0,0,0,0,0};
    int list2[5] = {0,0,0,0,0};
    int list3[5] = {0,0,0,0,0};
    int n = sizeof(list)/sizeof(int);

    std::cout << "Lenth of array = " << n << std::endl;

    std::cout << "Input every element of array: " << std::endl;
    for(int i = 0; i < n; i++)
        std::cin >> list[i];
    std::cout << std::endl;


    std::copy(std::begin(list), std::end(list), std::begin(list1));
    std::copy(std::begin(list), std::end(list), std::begin(list2));
    std::copy(std::begin(list), std::end(list), std::begin(list3));


    bubbleSort(list1, n);

    std::cout << "Sorted array: " << std::endl;
    arrayout(list1,n);
    arrayout(list2,n);
    arrayout(list3,n);
}


/*
 * массив случайных 10 чисел
 * дублируем на 3
 * каждый сортируем
 * каждый выводим
 *
 * Пузырьковая сортировка (Bubble sort);
 * Быстрая сортировка (Quick sort);
 * Сортировка кучей (Heap sort).
 */