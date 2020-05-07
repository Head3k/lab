#include <stdio.h>
#include "IntVector.h"

int main()
{

    IntVector *a, *b;
    a = int_vector_new(5);
    for (int i = 0; i < 4; i++)
    {
        a->size++;
        a->arr[i] = i;
    }
    printf("A = ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a->arr[i]);
    }
    b = int_vector_copy(a);
    printf("\nB = ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b->arr[i]);
    }
    int_vector_push_back(b, 5);
    printf("\n%d %zd %zd\n", b->arr[4], int_vector_get_capacity(b), int_vector_get_size(b));
    printf("\nB = ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b->arr[i]);
    }
    int_vector_push_back(b, 5);
    printf("\n%d %zd %zd\n", b->arr[5], int_vector_get_capacity(b), int_vector_get_size(b));
    printf("\nB = ");
    int_vector_set_item(b, 0, 9);
    printf("get item = %d\n", int_vector_get_item(b, 0));
    int_vector_pop_back(b);
    printf("capacity = %zd\nsize = %zd\n", int_vector_get_capacity(b), int_vector_get_size(b));
    int_vector_shrink_to_fit(b);
    printf("capacity = %zd\n", int_vector_get_capacity(b));
    int_vector_resize(b, 20);
    printf("%zd\n", int_vector_get_size(b));
    int_vector_reserve(b, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", b->arr[i]);
    }
    printf("\n%zd\n", int_vector_get_capacity(b));
    int_vector_free(b);
    int_vector_free(a);
    return 0;
}