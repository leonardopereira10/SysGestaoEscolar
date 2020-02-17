#include "autenticacao.h"
#include "ui_autenticacao.h"
#include "autenticador.h"
#include "configuraconexao.h"
#include "completacaddir.h"
#include "menuprincipal.h"
#include <qmetaobject.h>
#include <list>
#include <iostream>
#include <type_traits>

using namespace std;

Autenticacao::Autenticacao(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::Autenticacao)
{
   ui->setupUi(this);
   _enum <<"Diretoria"<<"Secretaria"<<"Coordenador de Curso"<<"Professor"<<"Aluno";
   ui->TipoUsuario->addItems(_enum);
   ui->Senha->setEchoMode(ui->Senha->Password);
   ui->Senha_2->setEchoMode(ui->Senha_2->Password);
   ui->Senha_3->setEchoMode(ui->Senha_3->Password);
}

Autenticacao::~Autenticacao()
{
   delete ui;
}

void Autenticacao::on_Envia_clicked()
{
   if(ui->EscolheCadastroLogin->tabText(ui->EscolheCadastroLogin->currentIndex()) == "Cadastro") {
      Autenticador auth = Autenticador();
      if(auth.CriaUsuario(ui->Usuario->text(), ui->Senha->text(), ui->Usuario_2->text(), ui->Senha_2->text(), ui->TipoUsuario->currentIndex()))
      {
         this->close();
         QString UsuarioAutenticado = auth.Autentica(ui->Usuario_2->text(), ui->Senha_2->text());
         switch(ui->TipoUsuario->currentIndex())
         {
            case 0:
            {
               CompletaCadDir *dialog = new CompletaCadDir(UsuarioAutenticado);
               dialog->show();
               break;
            }/*
            case 1:
            {
               CompletaCadastro *dialog = new CompletaCadastro(UsuarioAutenticado);
               dialog->show();
               break;
            }
            case 2:
            {
               CompletaCadastro *dialog = new CompletaCadastro(UsuarioAutenticado);
               dialog->show();
               break;
            }
            case 3:
            {
               CompletaCadastro *dialog = new CompletaCadastro(UsuarioAutenticado);
               dialog->show();
               break;
            }
            case 4:
            {
               CompletaCadastro *dialog = new CompletaCadastro(UsuarioAutenticado);
               dialog->show();
               break;
            }*/
         }
      }
   }
   else {
      Autenticador auth = Autenticador();
      QString UsuarioAutenticado = auth.Autentica(ui->Usuario_3->text(), ui->Senha_3->text());
      if (UsuarioAutenticado == "")
      {
         ui->Usuario_3->setText("");
         ui->Senha_3->setText("");
         QMessageBox::warning(this, "Aviso", "Usuario ou senha incorreta");
      }
      else
      {
         this->close();
         MenuPrincipal *dialog = new MenuPrincipal(UsuarioAutenticado);
         dialog->show();
      }
   }
}

void Autenticacao::on_pushButton_clicked()
{
   ConfiguraConexao *dialog = new ConfiguraConexao();
   dialog->show();
}
