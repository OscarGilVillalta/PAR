#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

struct DatosBiblioteca
{
    std::string nombre;
    std::string ubicacion;
};

struct InfoBiblioteca
{
    std::string numero;
    int empleados;
};

struct Apertura
{
    std::string apertura;
};

struct Libro
{
    std::string libro;
    std::string autor;
    int publicacion;
    int numero_paginas;
};

struct Node
{
    DatosBiblioteca datos;
    InfoBiblioteca informacion;
    Apertura apertura;
    std::vector<Libro> libros;
};

void solicitar_informacion(std::list<Node> &lista_bibliotecas);
void imprimir(const std::list<Node> &lista);
void ordenar(std::list<Node> &lista_bibliotecas);
void buscar(const std::list<Node> &lista, std::string nombre);

int main()
{
    std::list<Node> lista_bibliotecas{};
    return 0;
}

void imprimir(const std::list<Node> &lista)
{
    for (auto l : lista)
    {
        // Lista
        for (int i = 0; i < l.libros.size(); ++i)
        {
            // Libros
        }
    }
}

void solicitar_informacion(std::list<Node> &lista_bibliotecas)
{
    Node new_node;
    int cantidad_libros;

    std::cin >> new_node.datos.nombre;
    std::cin >> new_node.datos.ubicacion;
    std::cin >> new_node.informacion.numero;
    std::cin >> new_node.informacion.empleados;
    std::cin >> new_node.apertura.apertura;

    for (int i = 0; i < cantidad_libros; i++)
    {
        Libro l;
        std::cin >> l.libro;
        std::cin >> l.autor;
        std::cin >> l.publicacion;
        std::cin >> l.numero_paginas;

        new_node.libros.push_back(l);
    }

    lista_bibliotecas.push_back(new_node);
}

void ordenar(std::list<Node> &lista_bibliotecas)
{
    lista_bibliotecas.sort([](const Node &a, const Node &b)
                           { return a.informacion.empleados < b.informacion.empleados; });
}

void buscar(const std::list<Node> &lista, std::string nombre)
{
    for (auto l : lista)
    {
        if (l.datos.nombre == nombre)
        {
            return;
        }
    }
}
