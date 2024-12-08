#include <iostream>
#include <vector>
#include <fstream>
#include "Vec_Handler.cpp"
#include "Export.cpp"
#include "Calc.cpp"

// ќсновна€ функци€
int main()
{
    try
    {
        VectorHandler<int> vec1, vec2, result;

        // ¬вод векторов
        std::cout << "¬ведите первый вектор:\n";
        vec1.Input();
        std::cout << "¬ведите второй вектор:\n";
        vec2.Input();

        // —оздание объектов калькул€тора и экспортера
        Calculator<int> calc;
        Exporter<int> exporter;

        // ќпераци€ сложени€
        std::cout << "–езультат сложени€ векторов:\n";
        result = calc.Add(vec1, vec2);
        result.Print();

        // Ёкспорт результата в файл
        exporter.ExportToFile(result, "add_result.txt");

        // ќпераци€ вычитани€
        std::cout << "–езультат вычитани€ векторов:\n";
        result = calc.Subtract(vec1, vec2);
        result.Print();

        // Ёкспорт результата в файл
        exporter.ExportToFile(result, "sub_result.txt");

        // ќпераци€ умножени€
        std::cout << "–езультат умножени€ векторов:\n";
        result = calc.Multiply(vec1, vec2);
        result.Print();

        // Ёкспорт результата в файл
        exporter.ExportToFile(result, "mul_result.txt");
    }
    catch (const std::exception &e)
    {
        std::cerr << "ќшибка1: " << e.what() << std::endl;
    }

    return 0;
}