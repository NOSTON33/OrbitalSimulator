#include <vector>
#include <iostream>

#include <QApplication>
#include <QWidget> 

#include "Vector2.hpp"
#include "Physics.hpp"
#include "Integrator.hpp"
#include "Constants.hpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Orbital Simulator");
    window.resize(900, 700);
    window.show();

    return app.exec();
}