#ifndef CONFIGURACONEXAO_H
#define CONFIGURACONEXAO_H

#include <QWidget>

namespace Ui {
   class ConfiguraConexao;
}

class ConfiguraConexao : public QWidget
{
      Q_OBJECT

   public:
      explicit ConfiguraConexao(QWidget *parent = nullptr);
      ~ConfiguraConexao();

   private slots:
      void on_pushButton_clicked();
   private:
      Ui::ConfiguraConexao *ui;
      QString ObtemTipoDriver();
      QStringList tipoBd;
};

#endif // CONFIGURACONEXAO_H
