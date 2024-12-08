#include <iostream>
#include <vector>
#include <fstream>

// ��������� ����� ��� ������ � ���������
template <typename T>
class VectorHandler {
private:
    std::vector<T> vec; // ���������� ��������� �������

public:
    // ����������� �� ���������
    VectorHandler() {}

    // ����������� � ���������� ������� �������
    VectorHandler(size_t size) : vec(size) {}

    // ������������� �������� [] ��� ������� � ���������
    T& operator[](size_t index) {
        return vec[index];
    }

    // ��������� �������� (����������� �������)
    const T& operator[](size_t index) const {
        return vec[index];
    }

    // ����� ��� ��������� ������� �������
    size_t Size() const {
        return vec.size();
    }

    // ����� ��� ��������� ������� �������
    void Resize(size_t newSize) {
        vec.resize(newSize);
    }

    // ���� ������� � ����������
    void Input() {
        std::cout << "������� ������ �������: ";
        size_t size;
        std::cin >> size;
        Resize(size);

        std::cout << "������� �������� �������: ";
        for (size_t i = 0; i < size; ++i) {
            std::cin >> vec[i];
        }
    }

    // ����� ������� �� �����
    void Print() const {
        for (const auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    // ���������� ��������� �������� +
    VectorHandler<T> operator+(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("������� �������� �� ��������� ��� �������� ��������.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] + other[i];
        }
        return result;
    }

    // ���������� ��������� ��������� -
    VectorHandler<T> operator-(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("������� �������� �� ��������� ��� �������� ���������.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] - other[i];
        }
        return result;
    }

    // ���������� ��������� ��������� *
    VectorHandler<T> operator*(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("������� �������� �� ��������� ��� �������� ���������.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] * other[i];
        }
        return result;
    }

    // ���������� ��������� ������ <<
    friend std::ostream& operator<<(std::ostream& out, const VectorHandler<T>& v) {
        for (const auto& el : v.vec) {
            out << el << " ";
        }
        return out;
    }

    // ���������� ��������� ����� >>
    friend std::istream& operator>>(std::istream& in, VectorHandler<T>& v) {
        for (auto& el : v.vec) {
            in >> el;
        }
        return in;
    }
};