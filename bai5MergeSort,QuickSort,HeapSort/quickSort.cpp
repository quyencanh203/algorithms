#include<bits/stdc++.h>
template <typename T>
unsigned int partition(T &array, unsigned int lo, unsigned int hi)
{
    auto i = lo;
    auto j = hi + 1;
    auto v = array[lo];
    while (true)
    {
        while (array[++i] < v)
            if (i == hi) break;
        while (v < array[--j])
            if (j == lo) break;
        if (i >= j) break;
        std::swap(array[i], array[j]);
    }
    std::swap(array[lo], array[j]);
    return j;
}

// template <typename T>
// void shuffle(T &array)
// {
//     for (auto i = 0; i < sizeof(array); ++i)
//     {
//         auto r = i + rand() % (sizeof(array) - i);
//         std::swap(array[i], array[r]);
//     }
// }

template <typename T>
void quick_sort(T &array, unsigned int lo, unsigned int hi)
{
    if (hi <= lo) return;
    auto j = partition(array, lo, hi);
    quick_sort(array, lo, j - 1);
    quick_sort(array, j + 1, hi);
}

template <typename T>
void quick_sort(T &array)
{
    //shuffle(array);
    quick_sort(array, 0, sizeof(array) - 1);
}

int main()
{
    int array[] = {23,6,44,22,8,5,11,40,34,18};
    quick_sort(array);
    // for(int x : array)
    // {
    //     std::cout<<x<<" ";
    // };
    for(int i = 0; i < sizeof(array); i++)
    {
        std::cout<<array[i]<<" ";
    }
}