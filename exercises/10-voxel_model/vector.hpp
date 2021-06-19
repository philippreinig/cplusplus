#pragma once

#include <cstdint>
#include <cstddef>
#include <functional>

namespace Math{

    template<typename T, size_t N>
    class Vector
    {
    public:
        Vector() = default;
        explicit Vector(T _x)
        {
            for(size_t i = 0; i < N; ++i) data[i] = _x;
        }

        Vector(T _x, T _y)
        {
            data[0] = _x;
            for(size_t i = 1; i < N; ++i) data[i] = _y;
        }

        bool operator==(const Vector<T,N>& _oth) const;

        T& operator[](size_t _ind) { return data[_ind]; }
        const T& operator[](size_t _ind) const { return data[_ind]; }
    private:
        T data[N];
    };

    // common types
    typedef Vector<int, 2> IVec2;

    // operators
    template<typename T, size_t N>
    Vector<T,N> operator+(const Vector<T, N>& _lhs, const Vector<T,N>& _rhs);
    template<typename T, size_t N>
    Vector<T,N> operator-(const Vector<T, N>& _lhs, const Vector<T,N>& _rhs);

    template<typename T, size_t N, typename TS>
    Vector<T, N> operator*(const Vector<T,N>& _vec, TS _s);

    template<typename T, size_t N, typename TS>
    Vector<T, N> operator*(TS _s, const Vector<T,N>& _vec);

    // decent hash function for a 2d vector
    template<typename T>
    size_t hashFunc(const Vector<T, 2>& key);


    // ************************************************************ //
    // details

    template<typename T, size_t N>
    inline bool Vector<T,N>::operator==(const Vector<T,N>& _oth) const
    {
        for (size_t i = 0; i < N; ++i)
            if((*this)[i] != _oth[i]) return false;

        return true;
    }

    template<typename T, size_t N>
    inline Vector<T,N> operator+(const Vector<T, N>& _lhs, const Vector<T,N>& _rhs)
    {
        Vector<T,N> v;
        for (size_t i = 0; i < N; ++i)
            v[i] = _lhs[i] + _rhs[i];

        return v;
    }

    template<typename T, size_t N>
    inline Vector<T,N> operator-(const Vector<T, N>& _lhs, const Vector<T,N>& _rhs)
    {
        Vector<T,N> v;
        for (size_t i = 0; i < N; ++i)
            v[i] = _lhs[i] - _rhs[i];

        return v;
    }

    template<typename T, size_t N, typename TS>
    inline Vector<T, N> operator*(const Vector<T,N>& _vec, TS _s)
    {
        Vector<T,N> v;
        for (size_t i = 0; i < N; ++i)
            v[i] = _vec[i] * _s;

        return v;
    }

    template<typename T, size_t N, typename TS>
    inline Vector<T, N> operator*(TS _s, const Vector<T,N>& _vec)
    {
        Vector<T,N> v;
        for (size_t i = 0; i < N; ++i)
            v[i] = _vec[i] * _s;

        return v;
    }

    template<typename T>
    inline size_t hashFunc(const Vector<T, 2>& _key)
    {
        std::hash<T> hashfunc;
        size_t h = 0xbd73a0fb;
        h += hashfunc(_key[0]) * 0xf445f0a9;
        h += hashfunc(_key[1]) * 0x5c23b2e1;
        return h;
    }

}
