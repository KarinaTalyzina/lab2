#include <iostream>
#include <vector>
#include <fstream>
#include "Vec_Handler.cpp"
#include "Export.cpp"
#include "Calc.cpp"

// �������� �������
int main()
{
    try
    {
        VectorHandler<int> vec1, vec2, result;

        // ���� ��������
        std::cout << "������� ������ ������:\n";
        vec1.Input();
        std::cout << "������� ������ ������:\n";
        vec2.Input();

        // �������� �������� ������������ � ����������
        Calculator<int> calc;
        Exporter<int> exporter;

        // �������� ��������
        std::cout << "��������� �������� ��������:\n";
        result = calc.Add(vec1, vec2);
        result.Print();

        // ������� ���������� � ����
        exporter.ExportToFile(result, "add_result.txt");

        // �������� ���������
        std::cout << "��������� ��������� ��������:\n";
        result = calc.Subtract(vec1, vec2);
        result.Print();

        // ������� ���������� � ����
        exporter.ExportToFile(result, "sub_result.txt");

        // �������� ���������
        std::cout << "��������� ��������� ��������:\n";
        result = calc.Multiply(vec1, vec2);
        result.Print();

        // ������� ���������� � ����
        exporter.ExportToFile(result, "mul_result.txt");
    }
    catch (const std::exception &e)
    {
        std::cerr << "������1: " << e.what() << std::endl;
    }

    return 0;
}