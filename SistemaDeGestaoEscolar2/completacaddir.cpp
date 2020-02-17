#include "completacaddir.h"
#include "ui_completacaddir.h"
#include "conectorgenerico.h"
#include "utilitariogeralbd.h"

CompletaCadDir::CompletaCadDir(QString id, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::CompletaCadDir)
{
   _id =id;
   ui->setupUi(this);
}

CompletaCadDir::~CompletaCadDir()
{
   delete ui;
}

void CompletaCadDir::on_pushButton_clicked()
{
   QStringList values = QStringList()<<_id<<ui->nome->text()<<ui->cpf->text()<<ui->nascimento->text()<<ui->email->text()<<ui->telefone->text()<<ui->endereco->text();
   QStringList fields = QStringList()<<"ID"<<"NOME"<<"CPF"<<"DATA_NASCIMENTO"<<"EMAIL"<<"TELEFONE"<<"ENDERECO";
   ConectorGenerico bd("Cadastro");
   bd.ExecutaSql(UtilitarioGeralBD::MontaInsert("pessoas", fields, values));
   values.clear();
   fields.clear();
   values<<ui->cpf->text()<<ui->formacao->text()<<ui->tipo_formacao->text();
   fields<<"FK_CPF"<<"FORMACAO"<<"TIPO_FORMACAO";
   bd.ExecutaSql(UtilitarioGeralBD::MontaInsert("diretores", fields, values));

   this->close();
}
