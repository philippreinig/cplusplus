#pragma once

#include <cstdint>

/* Implement a generic mathematical Vector.
 * todo: * add template parameters
 *       * implement the required operators
 *       * test all functions
 *       * keep it const correct
 */
namespace Math{

    // The vector should have both a generic numeric type(T) and a number of dimensions(N).
    // The data can be stored in an array of type T and size N.
    template<typename T, int n>
    class Vector
    {

    public:
        Vector() = default;

        T& operator[](int i) const
        {
            return this->data[i];
        }

        T& operator[](int i)
        {
            return this->data[i];
        }

        Vector<T, n> operator-(){
            Vector<T, size> temp_vec; 
            for(int i = 0; i < n; i++){
                temp_vec[i] = - this->data[i];
            }
            return temp_vec;
        }

        Vector<T, n> operator+(Vector<T, n>& other)
        {
            Vector<T, size> temp_vec; 
            for(int i = 0; i < n; i++){
                temp_vec[i] = this->data[i] + other[i];
            }
            return temp_vec;
        }

        Vector<T, n> operator-(Vector<T, n>& other)
        {
            Vector<T, size> temp_vec; 
            for(int i = 0; i < n; i++){
                temp_vec[i] = this->data[i] - other[i];
            }
            return temp_vec;
        }

        Vector<T, n> operator*(int x)
        {
            Vector<T, size> temp_vec; 
            for(int i = 0; i < n; i++){
                temp_vec[i] = this->data[i] * x;
            }
            return temp_vec;
        }

        friend Vector<T, n> operator*(T x, Vector<T, n>& v)
        {   
            Vector<T, size> temp_vec; 
            for(int i = 0; i < n; i++){
                temp_vec[i] = v[i] * x;
            }
            return temp_vec;
        }
    private:
        T data[n] {0};
        static const int size = n;
    };
}
