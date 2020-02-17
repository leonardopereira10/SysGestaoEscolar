#include "autenticacao.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Autenticacao w;
   w.show();
   return a.exec();
}
