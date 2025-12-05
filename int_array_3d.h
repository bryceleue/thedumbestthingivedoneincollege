#ifndef INTARR3D_H
#define INTARR3D_H

#include <stdexcept>
#include <iostream>

class IntArray3D {
    public:
        IntArray3D(const int slices,const int rows, const int cols);
        IntArray3D(int* init_slice, const int rows, const int cols);
        ~IntArray3D();

        int* Get();
        int Get(const int slice, const int row, const int col);
        void Set(int data, const int slice, const int row, const int col);
        void Set(int* data);

        void Append(int* new_slice);
        void Write(int value, int position);
        void PrintSlices();
        void PrintLast();
        void Size();

    private:
        int* data_;
        int slices_;
        int rows_;
        int cols_;
        int size_;
        int capacity_;
        int FlattenPosition(const int slice, const int row, const int col);
        void Resize();
};

#endif