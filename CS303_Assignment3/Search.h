// File: Search.h
#pragma once

#include <vector>

// recursive linear search: last occurrence in vec[0..lastIndex]
template<typename T>
int linear_search(const std::vector<T>& vec,
    const T& target,
    int lastIndex);
