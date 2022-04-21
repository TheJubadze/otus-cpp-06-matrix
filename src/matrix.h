#pragma once

#include <map>

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
    Element<T, defaultValue> &operator[](int);

private:
    std::map<int, Element<T, defaultValue>> m_Map;
    Element<T, defaultValue> m_EmptyElement = Element<T, defaultValue>();
};

template<typename T, T defaultValue>
Element<T, defaultValue> &KeyValuePair<T, defaultValue>::operator[](int index) {
    return m_Map.contains(index)
           ? m_Map[index]
           : m_EmptyElement;
}
//==========================================================================================

//============================================= Matrix =============================================
template<typename T, T defaultValue>
class Matrix {
public:
    KeyValuePair<T, defaultValue> &operator[](int);

private:
    std::map<int, KeyValuePair<T, defaultValue>> m_Matrix;
    KeyValuePair<T, defaultValue> m_EmptyKeyValuePair = KeyValuePair<T, defaultValue>();
};

template<typename T, T defaultValue>
KeyValuePair<T, defaultValue> &Matrix<T, defaultValue>::operator[](int index) {
    return m_Matrix.contains(index)
           ? m_Matrix[index]
           : m_EmptyKeyValuePair;
}
//==========================================================================================
