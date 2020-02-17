#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>

namespace Ui {
   class MenuPrincipal;
}

class MenuPrincipal : public QWidget
{
      Q_OBJECT

   public:
      explicit MenuPrincipal(QString idLogado, QWidget *parent = nullptr);
      ~MenuPrincipal();

   private:
      Ui::MenuPrincipal *ui;
      QString id;
};

#endif // MENUPRINCIPAL_H
