#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
#pragma once

#include <map>
#include <numeric>

//============================================= Element =============================================
template<typename T, T defaultValue>
class Element {
public:
    explicit Element() : value{defaultValue} {};
    explicit Element(T value) : value{value} {};
    operator T() const { return value; }
    Element &operator=(T right) {
        value = right;
        return *this;
    }

private:
    T value;
};
//==========================================================================================

//============================================= KeyValuePair =============================================
template<typename T, T defaultValue>
class KeyValuePair {
public:
    [[nodiscard]] int size() const;
    Element<T, defaultValue> &operator[](int);

private:
    std::map<int, Element<T, defaultValue>> m_Map;
    Element<T, defaultValue> m_EmptyElement = Element<T, defaultValue>();
};

template<typename T, T defaultValue>
Element<T, defaultValue> &KeyValuePair<T, defaultValue>::operator[](int index) {
    return m_Map[index];
}

template<typename T, T defaultValue>
int KeyValuePair<T, defaultValue>::size() const {
    return std::accumulate(std::begin(m_Map), std::end(m_Map), 0,
                           [](const std::size_t previous,
                              const std::pair<const int, Element<T, defaultValue>> &p) {
                               return previous + (p.second == defaultValue ? 0 : 1);
                           });
}
//==========================================================================================

//============================================= Matrix =============================================
template<typename T, T defaultValue>
class Matrix {
public:
    [[nodiscard]] int size() const;
    KeyValuePair<T, defaultValue> &operator[](int);

private:
    std::map<int, KeyValuePair<T, defaultValue>> m_Matrix;
    KeyValuePair<T, defaultValue> m_EmptyKeyValuePair = KeyValuePair<T, defaultValue>();
};

template<typename T, T defaultValue>
KeyValuePair<T, defaultValue> &Matrix<T, defaultValue>::operator[](int index) {
    return m_Matrix[index];
}
template<typename T, T defaultValue>
int Matrix<T, defaultValue>::size() const {
    return std::accumulate(std::begin(m_Matrix), std::end(m_Matrix), 0,
                           [](const std::size_t previous,
                              const std::pair<const int, KeyValuePair<T, defaultValue>> &p) {
                               return previous + p.second.size();
                           });
}
//==========================================================================================

#pragma clang diagnostic pop