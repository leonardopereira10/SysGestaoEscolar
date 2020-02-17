#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <QWidget>
#include <typeinfo>
#include <QMessageBox>
using namespace std;
namespace Ui {
   class Autenticacao;
}

class Autenticacao : public QWidget
{
      Q_OBJECT

   public:
      explicit Autenticacao(QWidget *parent = nullptr);
      ~Autenticacao();

   private slots:
      void on_Envia_clicked();

      void on_pushButton_clicked();

   private:
      Ui::Autenticacao *ui;
      QStringList _enum;
};

#endif // AUTENTICACAO_H
