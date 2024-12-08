#include <iostream>
#include <vector>
#include <fstream>

// ����� ��� ���������� �������� � ���������
template <typename T>
class Calculator {
public:
    // �������� ��������
    VectorHandler<T> Add(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 + v2;
    }

    // ��������� ��������
    VectorHandler<T> Subtract(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 - v2;
    }

    // ��������� ��������
    VectorHandler<T> Multiply(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 * v2;
    }
};