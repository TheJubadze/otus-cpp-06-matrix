#pragma once

#include <map>

//============================================= KeyValuePair =============================================
template<typename T, int>
class KeyValuePair {
public:
    int &operator[](int);

private:
    std::map<int, T &> m_Map;
};

template<typename T, int defaultValue>
int &KeyValuePair<T, defaultValue>::operator[](int index) {
    return m_Map.contains(index)
           ? m_Map[index]
           : static_cast<int &>(defaultValue);
}
//==========================================================================================

//============================================= Matrix =============================================
template<typename T, int defaultValue>
class Matrix {
public:
    KeyValuePair<T, defaultValue> &operator[](int);

private:
    std::map<int, KeyValuePair<T, defaultValue>> m_Matrix;
    KeyValuePair<T, defaultValue> m_EmptyKeyValuePair = KeyValuePair<T, defaultValue>();
};

template<typename T, int defaultValue>
KeyValuePair<T, defaultValue> &Matrix<T, defaultValue>::operator[](int index) {
    return m_Matrix.contains(index)
           ? m_Matrix[index]
           : m_EmptyKeyValuePair;
}
//==========================================================================================
