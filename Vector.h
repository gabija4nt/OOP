#ifndef VECTOR_H
#define VECTOR_H

#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include <memory>
#include <iterator>
#include <iomanip>
#include <chrono>



template <typename T, typename Allocator = std::allocator<T>>
class Vector {
private:
    T* data_ptr;
    std::size_t data_size;
    std::size_t data_capacity;
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<allocator_type>::pointer;
    using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


    // Constructor
    Vector() : data_ptr(nullptr), data_size(0), data_capacity(0) {}

    // Constructor with initial size
    explicit Vector(std::size_t initialSize) : data_ptr(new T[initialSize]), data_size(initialSize), data_capacity(initialSize) {}

    Vector(std::initializer_list<T> initList)
        : data_ptr(new T[initList.size()]), data_size(initList.size()), data_capacity(initList.size())
    {
        std::copy(initList.begin(), initList.end(), data_ptr);
    }

    template <typename InputIt>
    Vector(InputIt first, InputIt last) {
        size_t size = std::distance(first, last);
        reserve(size);
        std::copy(first, last, data_ptr);
        data_size = size;
    }

    // Copy constructor
    Vector(const Vector& other) : data_ptr(new T[other.data_size]), data_size(other.data_size), data_capacity(other.data_size) {
        for (std::size_t i = 0; i < data_size; ++i) {
            data_ptr[i] = other.data_ptr[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data_ptr;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_ptr;
            data_ptr = new T[other.data_capacity];
            data_size = other.data_size;
            data_capacity = other.data_capacity;
            for (std::size_t i = 0; i < data_size; ++i) {
                data_ptr[i] = other.data_ptr[i];
            }
        }
        return *this;
    }

    bool operator==(const Vector& other) const {
        if (data_size != other.data_size) {
            return false;
        }

        for (std::size_t i = 0; i < data_size; ++i) {
            if (data_ptr[i] != other.data_ptr[i]) {
                return false;
            }
        }

        return true;
    }
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
    bool operator<(const Vector& other) const {
        for (std::size_t i = 0; i < data_size && i < other.data_size; ++i) {
            if (data_ptr[i] < other.data_ptr[i]) {
                return true;
            }
            else if (data_ptr[i] > other.data_ptr[i]) {
                return false;
            }
        }

        return data_size < other.data_size;
    }
    bool operator<=(const Vector& other) const {
        return (*this < other) || (*this == other);
    }
    bool operator>(const Vector& other) const {
        return !(*this <= other);
    }
    bool operator>=(const Vector& other) const {
        return !(*this < other);
    }


    const_iterator operator+(std::size_t n) const {
        return data_ptr + n;
    }

    // Assigns new values to the vector, replacing its current contents
    void assign(std::size_t count, const T& value) {
        clear();
        reserve(count);
        for (std::size_t i = 0; i < count; ++i) {
            data_ptr[i] = value;
        }
        data_size = count;
    }
    void assign(std::initializer_list<T> ilist) {
        delete[] data_ptr;
        data_size = ilist.size();
        data_ptr = new T[data_size];
        std::size_t i = 0;
        for (const auto& elem : ilist) {
            data_ptr[i++] = elem;
        }
    }
    template <class InputIt>
    void assign(InputIt first, InputIt last) {
        delete[] data_ptr;
        data_size = std::distance(first, last);
        data_ptr = new T[data_size];
        std::size_t i = 0;
        for (auto it = first; it != last; ++it) {
            data_ptr[i++] = *it;
        }
    }
    // Returns the allocator associated with the vector
    Allocator get_allocator() const {
        return Allocator();
    }

    reference at(std::size_t index) {
        if (index >= data_size) {
            throw std::out_of_range("Index out of range");
        }
        return data_ptr[index];
    }

    const_reference at(std::size_t index) const {
        if (index >= data_size) {
            throw std::out_of_range("Index out of range");
        }
        return data_ptr[index];
    }

    reference operator[](size_t index) {
        if (index >= data_size) {
            throw std::out_of_range("Index out of range");
        }
        return data_ptr[index];
    }

    const_reference operator[](size_t index) const {
        if (index >= data_size) {
            throw std::out_of_range("Index out of range");
        }
        return data_ptr[index];
    }

    reference front() {
        return data_ptr[0];
    }

    const_reference front() const {
        return data_ptr[0];
    }

    reference back() {
        return data_ptr[data_size - 1];
    }

    const_reference back() const {
        return data_ptr[data_size - 1];
    }

    iterator data() {
        return data_ptr;
    }

    const_iterator data() const {
        return data_ptr;
    }

    iterator begin() {
        return data_ptr;
    }

    const_iterator begin() const {
        return data_ptr;
    }

    const_iterator cbegin() const {
        return data_ptr;
    }

    iterator end() {
        return data_ptr + data_size;
    }

    const_iterator end() const {
        return data_ptr + data_size;
    }

    const_iterator cend() const {
        return data_ptr + data_size;
    }

    typename std::reverse_iterator<T*> rbegin() {
        return typename std::reverse_iterator<T*>(data_ptr + data_size);
    }

    typename std::reverse_iterator<const T*> rbegin() const {
        return typename std::reverse_iterator<const T*>(data_ptr + data_size);
    }

    typename std::reverse_iterator<const T*> crbegin() const {
        return typename std::reverse_iterator<const T*>(data_ptr + data_size);
    }

    typename std::reverse_iterator<T*> rend() {
        return typename std::reverse_iterator<T*>(data_ptr);
    }

    typename std::reverse_iterator<const T*> rend() const {
        return typename std::reverse_iterator<const T*>(data_ptr);
    }

    typename std::reverse_iterator<const T*> crend() const {
        return typename std::reverse_iterator<const T*>(data_ptr);
    }

    bool empty() const {
        return data_size == 0;
    }

    std::size_t size() const {
        return data_size;
    }

    std::size_t max_size() const {
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

    void reserve(std::size_t new_capacity) {
        if (new_capacity > data_capacity) {
            T* new_data = new T[new_capacity];
            for (std::size_t i = 0; i < data_size; ++i) {
                new_data[i] = std::move(data_ptr[i]);
            }

            delete[] data_ptr;
            data_ptr = new_data;
            data_capacity = new_capacity;
        }
    }

    size_type capacity() const noexcept {
        return data_capacity;
    }

    void shrink_to_fit() {
        if (data_size < data_capacity) {
            T* new_data = new T[data_size];
            for (std::size_t i = 0; i < data_size; ++i) {
                new_data[i] = data_ptr[i];
            }
            delete[] data_ptr;
            data_ptr = new_data;
            data_capacity = data_size;
        }
    }

    void clear() {
        delete[] data_ptr;
        data_ptr = nullptr;
        data_size = 0;
        data_capacity = 0;
    }

    iterator insert(iterator position, const T& value) {
        std::size_t index = position - begin();

        if (data_size == data_capacity) {
            reserve(data_capacity == 0 ? 1 : data_capacity * 2);
        }

        // Shift elements to the right to make space for the new element
        for (std::size_t i = data_size; i > index; --i) {
            data_ptr[i] = data_ptr[i - 1];
        }

        // Insert the new element
        data_ptr[index] = value;
        ++data_size;

        return begin() + index;
    }

    template <typename... Args>
    iterator emplace(iterator position, Args&&... args) {
        std::size_t index = position - begin();

        if (data_size == data_capacity) {
            reserve(data_capacity == 0 ? 1 : data_capacity * 2);
        }

        // Shift elements to the right to make space for the new element
        for (std::size_t i = data_size; i > index; --i) {
            data_ptr[i] = data_ptr[i - 1];
        }

        // Construct the new element in-place
        new (&data_ptr[index]) T(std::forward<Args>(args)...);
        ++data_size;

        return begin() + index;
    }

    iterator erase(iterator position) {
        std::size_t index = position - begin();

        if (index >= data_size) {
            return position;
        }

        // Destruct the element at the specified position
        data_ptr[index].~T();

        // Shift elements to the left to fill the gap
        for (std::size_t i = index; i < data_size - 1; ++i) {
            data_ptr[i] = data_ptr[i + 1];
        }

        --data_size;

        return begin() + index;
    }

    iterator erase(iterator first, iterator last) {
        std::size_t start = first - begin();
        std::size_t end = last - begin();

        if (start >= data_size) {
            return last;
        }

        // Destruct the elements within the specified range
        for (std::size_t i = start; i < end; ++i) {
            data_ptr[i].~T();
        }

        // Shift elements to the left to fill the gap
        std::size_t num_elements = end - start;
        for (std::size_t i = start; i < size - num_elements; ++i) {
            data_ptr[i] = data_ptr[i + num_elements];
        }

        data_size -= num_elements;

        return begin() + start;
    }

    void push_back(const T& value) {
        if (data_size == data_capacity)
            reserve(data_capacity == 0 ? 1 : data_capacity * 2);
        data_ptr[data_size++] = value;
    }

    void push_back(T&& value) {
        if (data_size == data_capacity)
            reserve(data_capacity == 0 ? 1 : data_capacity * 2);
        data_ptr[data_size++] = std::move(value);
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (data_size == data_capacity) {
            reserve(data_capacity == 0 ? 1 : data_capacity * 2);
        }

        new (&data_ptr[data_size]) T(std::forward<Args>(args)...);
        ++data_size;
    }

    void pop_back() {
        if (data_size > 0) {
            --data_size;
            data_ptr[data_size].~T();
        }
    }

    void resize(std::size_t count) {
        if (count <= data_size) {
            data_size = count;
        }
        else {
            T* new_data_ptr = new T[count]();
            if (data_ptr) {
                std::copy(data_ptr, data_ptr + data_size, new_data_ptr);
                delete[] data_ptr;
            }
            data_ptr = new_data_ptr;
            data_size = count;
        }
    }

    // Resizes the vector to the specified count and initializes new elements with the specified value
    void resize(size_type count, const value_type& value) {
        if (count <= data_size) {
            data_size = count;
        }
        else {
            if (count > data_capacity) {
                reserve(count);
            }
            std::fill(data_ptr + data_size, data_ptr + count, value);
            data_size = count;
        }
    }


    void swap(Vector& other) {
        std::swap(data_ptr, other.data_ptr);
        std::swap(data_size, other.data_size);
        std::swap(data_capacity, other.data_capacity);
    }

    friend void swap(Vector& lhs, Vector& rhs) noexcept {
        std::swap(lhs.data_ptr, rhs.data_ptr);
        std::swap(lhs.data_size, rhs.data_size);
        std::swap(lhs.data_capacity, rhs.data_capacity);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector<T, Allocator>& vec) {
        os << "{";
        for (std::size_t i = 0; i < vec.data_size; ++i) {
            os << ' ' << vec.data_ptr[i];
        }
        os << " }";
        return os;
    }
    template <typename RandomIt, typename Compare>
    void sort(RandomIt first, RandomIt last, Compare comp);
};

#endif // VECTOR_H

namespace std {
    template<typename iterator>
    iterator next(iterator it, typename Vector<typename iterator::value_type>::difference_type n) {
        std::advance(it, n);
        return it;
    }
}