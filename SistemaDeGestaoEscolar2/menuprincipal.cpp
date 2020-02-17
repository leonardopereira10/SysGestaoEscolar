#include "menuprincipal.h"
#include "ui_menuprincipal.h"

MenuPrincipal::MenuPrincipal(QString idLogado,QWidget *parent) :
   QWidget(parent),
   ui(new Ui::MenuPrincipal)
{
   ui->setupUi(this);
   id = idLogado;
}

MenuPrincipal::~MenuPrincipal()
{
   delete ui;
}
