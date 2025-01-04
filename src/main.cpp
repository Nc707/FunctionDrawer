// File: /my-cpp-project/my-cpp-project/src/main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "function.h"
#include "var.h"
void generarSVG(const std::vector<std::pair<double, double>>& puntos, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
        return;
    }

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
    file << "<polyline points=\"";
    for (const auto& punto : puntos) {
        file << punto.first << "," << punto.second << " ";
    }
    file << "\"\n style= \"fill:none;stroke:black;stroke-width:3\" />\n";
    file << "</svg>\n";

    file.close();
}

int main() {
    auto x = var();
    x = x * 2 * x + 3;
    Function funcion = Function(x.getArgument());
    std::vector<std::pair<double, double>> puntos = funcion.generatePoints(0, 10, 1);
    for (const auto& punto : puntos) {
        std::cout << "(" << punto.first << ", " << punto.second << ")\n";
    }
    generarSVG(puntos, "output.svg");
    system("pause");
    return 0;
}