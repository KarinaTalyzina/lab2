#include <iostream>
#include <vector>
#include <fstream>

// ����� ��� �������� ������ � ����
template <typename T>
class Exporter {
public:
    // ����� ��� ������ ������� � ����
    void ExportToFile(const VectorHandler<T>& vec, const std::string& filename) {
        std::ofstream outfile(filename);
        if (!outfile) {
            std::cerr << "�� ������� ������� ���� ��� ������!\n";
            return;
        }
        outfile << "��������� �������:\n";
        outfile << vec << "\n";
        outfile.close();
        std::cout << "���������� ��������� � ���� " << filename << "\n";
    }
};