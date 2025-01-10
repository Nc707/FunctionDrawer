#include <iostream>
#include <fstream>
#include <vector>
#include "PointsGenerators/2DGenerators/basic2DGenerator.h"
#include "Variables/basicExpressionVariable.h"
void generarSVG(const std::vector<std::tuple<double, double>>& puntos, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
        return;
    }

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
    file << "<polyline points=\"";
    for (const auto& punto : puntos) {
        file << std::get<0>(punto) << "," << std::get<1>(punto) + 10 << " ";
    }
    file << "\"\n style= \"fill:none;stroke:black;stroke-width:0.5\" />\n";
    file << "</svg>\n";

    file.close();
}

int main() {
    ArithmeticPoints::BasicExpressionVariable<double> x = ArithmeticPoints::BasicExpressionVariable<double>();
    x = sin(x)/ cos(x) * 6;
    ArithmeticPoints::PointGeneration::Basic2DGenerator<double> funcion(x.getArgument());
    std::vector<std::tuple<double, double>> puntos = funcion.generatePoints({-10, 1000, 0.1});
    //*
    for (const auto& punto : puntos) {
        std::cout << "(" << std::get<0>(punto) << ", " << std::get<1>(punto) << ")\n";
    }
    //*/
    generarSVG(puntos, "output.svg");
    return 0;
}