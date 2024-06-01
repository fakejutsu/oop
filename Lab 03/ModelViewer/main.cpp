#include "mainwindow.h"

#include <QApplication>
#include "matrixbase.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto m = MatrixBase<double, 4, 4>::IdentityMatrix();

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << (*m)[i][j] << ' ';
        }
        std::cout << '\n';
    }

    MainWindow w;
    w.show();
    return a.exec();
}
