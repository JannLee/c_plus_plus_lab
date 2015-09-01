#pragma once


#include <vector>


namespace jannlee
{

template<typename T>
void quickSort(std::vector<T>& numbers);

template<typename T>
void quickSort(std::vector<T>& numbers, const size_t kLeft, const size_t kRight);

template<typename T>
void quickSort(std::vector<T>& numbers)
{
    if (numbers.size())
    {
        quickSort(numbers, 0, numbers.size() - 1);
    }
}

template<typename T>
void quickSort(std::vector<T>& numbers, const size_t kLeft, const size_t kRight)
{
    if (kLeft < kRight)
    {
        T pivot = numbers[kLeft];  // 0¹øÂ° ¿ø¼Ò¸¦ ÇÇº¿À¸·Î ¼±ÅÃ
        size_t left = kLeft;
        size_t right = kRight;

        while (left < right)
        {
            while (pivot <= numbers[right] && left < right)
            {
                right--;
            }

            if (left != right)
            {
                numbers[left] = numbers[right];
            }

            while (numbers[left] <= pivot && left < right)
            {
                left++;
            }

            if (left != right)
            {
                numbers[right] = numbers[left];
                right--;
            }
        }

        numbers[left] = pivot;  // Å½»ö ÈÄ left°¡ ÇÇº¿ °ªÀÌ µÊ

        if (kLeft < left)
        {
            quickSort(numbers, kLeft, left - 1);
        }

        if (left < kRight)
        {
            quickSort(numbers, left + 1, kRight);
        }
    }
}

} // namespace jannlee
