#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

struct Tareas
{
    std::string nombre;
    int prioridad;
};

void agregar_tareas(std::list<Tareas> &l);
void mostrar_tareas(const std::list<Tareas> &l);
void ordenar(std::list<Tareas> &l, std::stack<Tareas> &p, std::queue<Tareas> &c);
void search(const std::list<Tareas> &l, std::string &nombre);
void tareas_urgentes(std::stack<Tareas> &t);
void tareas_livianas(std::queue<Tareas> &t);

int main()
{
    std::list<Tareas> lista_tareas;
    std::stack<Tareas> tareas_prioritarias;
    std::queue<Tareas> tareas_medianas;

    return 0;
}

void agregar_tareas(std::list<Tareas> &l)
{
    Tareas temp;

    std::cin >> temp.nombre;

    do
    {
        std::cin >> temp.prioridad;
    } while (temp.prioridad < 1 || temp.prioridad > 3);

    l.push_back(temp);
}

void mostrar_tareas(const std::list<Tareas> &l)
{
    if (l.empty())
        return;

    for (auto &c : l)
    {
        std::cout << c.nombre << " || " << c.prioridad << "\n";
    }
}

void search(const std::list<Tareas> &l, std::string &nombre)
{
    auto n = std::find_if(l.begin(), l.end(), nombre);

    if (n != l.end())
        std::cout << "Encontrado!";
    else
        return;
}

void ordenar(std::list<Tareas> &l, std::stack<Tareas> &p, std::queue<Tareas> &c)
{
    l.sort([](const Tareas &a, const Tareas &b)
           { return a.prioridad < b.prioridad; });

    for (auto t : l)
    {
        if (t.prioridad == 1)
            p.push(t);
        else if (t.prioridad == 2)
            c.push(t);
        else
            c.push(t);
    }
}

void tareas_urgentes(std::stack<Tareas> &t)
{
    while (!t.empty())
    {
        std::cout << t.top().nombre << " || " << t.top().prioridad << "\n"
                  << "Tareas solventada!\n";
        t.pop();
    }
}

void tareas_livianas(std::queue<Tareas> &t)
{
    while (!t.empty())
    {
        std::cout << t.front().nombre << " || " << t.front().prioridad << "\n"
                  << "Tareas solventada!\n";
        t.pop();
    }
}
