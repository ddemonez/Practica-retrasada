// Practica retrasada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>/// libresias
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    string nit, nombre, empresa;
    double ingresoM, ingresoA;
    double isrA, ssA, impuestosTotA;
    double marginal, medio, netoM;
    double ssEmpleadoA, ssEmpresaA;
    double empAportes = 0.1267; // 12.67% SS empresa (aprox basado en reporte)
    double empEmpleado = 0.0483; // 4.83% SS empleado

    // Entrada
    cout << "Ingrese NIT: "; getline(cin, nit);
    cout << "Ingrese nombre completo: "; getline(cin, nombre);
    cout << "Ingrese nombre de empresa: "; getline(cin, empresa);
    cout << "Ingrese ingreso bruto mensual (Q): "; cin >> ingresoM;

    ingresoA = ingresoM * 12.0;
    marginal = 11.5;
    isrA = ingresoA * 0.05462;
    ssA = ingresoA * empEmpleado;
    ssEmpresaA = ingresoA * empAportes;
    impuestosTotA = isrA + ssA + ssEmpresaA;

    // Medios y neto
    medio = ((isrA + ssA) / ingresoA) * 100.0; // tasa media empleado
    netoM = ingresoM - (isrA / 12.0 + ssA / 12.0);
    double empleadoA = isrA + ssA;
    double totalA = impuestosTotA;
    double tasaReal = (totalA / ingresoA) * 100.0;

    // Salida en consola
    cout << fixed << setprecision(2) << "\n--- Reporte Mensual ---\n";
    cout << "Ingreso bruto mensual: Q" << ingresoM << "\n";
    cout << "Pago neto mensual: Q" << netoM << "\n";
    cout << "Impuestos empleado (mensual): Q" << (empleadoA / 12.0) << "\n";
    cout << "Impuestos empresa (mensual): Q" << (ssEmpresaA / 12.0) << "\n";
    cout << "Total impuestos mensuales: Q" << (totalA / 12.0) << "\n";
    cout << "Tipo impositivo marginal: " << marginal << "%\n";
    cout << "Tipo impositivo medio empleado: " << medio << "%\n";
    cout << "Tasa impositiva real (incluye aportes empresa): " << tasaReal << "%\n";

    // Guardar reporte.txt
    ofstream out("reporte.txt");
    out << fixed << setprecision(2)
        << "REPORTE MENSUAL DE INGRESOS E IMPUESTOS\n"
        << "NIT: " << nit << "\n"
        << "Nombre: " << nombre << "\n"
        << "Empresa: " << empresa << "\n"
        << "Ingreso bruto mensual: Q" << ingresoM << "\n"
        << "Pago neto mensual: Q" << netoM << "\n"
        << "Impuestos empleado (mensual): Q" << (empleadoA / 12.0) << "\n"
        << "Impuestos empresa (mensual): Q" << (ssEmpresaA / 12.0) << "\n"
        << "Total impuestos mensuales: Q" << (totalA / 12.0) << "\n"
        << "Tipo impositivo marginal: " << marginal << "%\n"
        << "Tipo impositivo medio empleado: " << medio << "%\n"
        << "Tasa real total: " << tasaReal << "%\n";
    out.close();

    cout << "\nReporte guardado en 'reporte.txt'. Puedes convertirlo a PDF.\n";
    return 0;
}
