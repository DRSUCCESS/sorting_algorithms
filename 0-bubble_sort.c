#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending
 *               order using the bubble sort algorithm.
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No return
 */
 void bubble_sort(int *array, size_t size)
 {
     size_t i, j, temp;

     if (size < 2)
         return;

     for (i = 0; i <= size - 1; i++)
     {
         for (j = 0; j <= size - 2; j++)
         {
             if (array[j] > array[j + 1])
             {
                 temp = array[j];
                 array[j] = array[j + 1];
                 array[j + 1] = temp;
                 print_array(array, size);
             }
         }
     }
 }
