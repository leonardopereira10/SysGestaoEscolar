#include "configuraconexao.h"
#include "ui_configuraconexao.h"
#include <QMessageBox>
#include <QtSql>
ConfiguraConexao::ConfiguraConexao(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::ConfiguraConexao)
{
   ui->setupUi(this);
   ui->comboBox->addItems(QStringList()<<"IBM DB2"<<"Borland InterBase Driver"<<"MySQL Driver"<<"Oracle Call Interface Driver"<<"ODBC Driver (includes Microsoft SQL Server)"<<"PostgreSQL Driver"<<"SQLite version 3 or above"<<"SQLite version 2"<<"Sybase Adaptive Server");
}

ConfiguraConexao::~ConfiguraConexao()
{
   delete ui;
}

void ConfiguraConexao::on_pushButton_clicked()
{
   QSqlDatabase bd = QSqlDatabase::addDatabase(ObtemTipoDriver(), "TesteDeConexao");
   bd.setHostName(ui->endereco->text());
   bd.setPort(ui->porrrrta->text().toInt());
   bd.setDatabaseName(ui->database_name->text());
   bd.setUserName(ui->usuario->text());
   bd.setPassword(ui->senha->text());
   bd.open();
   if(bd.isOpen())
   {
      QMessageBox::information(this, "Conexão", "Conexão com o banco " + ui->database_name->text() + " bem sucedida");
      QString StringDeConexao;// =
      StringDeConexao += ObtemTipoDriver() + "+";
      StringDeConexao += ui->endereco->text() + "+";
      StringDeConexao += ui->porrrrta->text() + "+";
      StringDeConexao += ui->database_name->text() + "+";
      StringDeConexao += ui->usuario->text() + "+";
      StringDeConexao += ui->senha->text() + "+";
      remove("StringDeConexao.txt");
      FILE *file = fopen("StringDeConexao.txt", "w");
      fprintf(file, StringDeConexao.toUtf8());
      fclose(file);
      bd.close();
      this->close();
   }
   else
   {
      QMessageBox::critical(this, "Conexão", "Erro em conexão com o banco: " + ui->database_name->text() + "\n\tVerificar dados inseridos!!");
      bd.close();
   }
}

QString ConfiguraConexao::ObtemTipoDriver()
{
   switch(ui->comboBox->currentIndex())
   {
      case 0:
         return "QDB2";
      case 1:
         return "QIBASE";
      case 2:
         return "QMYSQL";
      case 3:
         return "QOCI";
      case 4:
         return "QODBC";
      case 5:
         return "QPSQL";
      case 6:
         return "QSQLITE";
      case 7:
         return "QSQLITE2";
      case 8:
         return "QTDS";
      default:
         return "";
   }
}
