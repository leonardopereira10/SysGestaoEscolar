#include "autenticador.h"
#include "utilitariogeralbd.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QSqlDriver>
Autenticador::Autenticador()
{
   db = QSqlDatabase::cloneDatabase(UtilitarioGeralBD::ObtemBancoDadosDoArquivo(), "Autenticador SGE2");
}

QByteArray Autenticador::Autentica(QString usuario, QString senha)
{
   db.open();
   QByteArray id = QCryptographicHash::hash(usuario.toUtf8() + senha.toUtf8(), QCryptographicHash::Md5).toHex();
   QSqlQuery query = QSqlQuery(db);
   query.prepare(UtilitarioGeralBD::SubstituiPlaceholder("SELECT ID FROM AUTENTICACAO WHERE ID = ':id'",QStringList()<<":id",QStringList()<<id));
   query.exec();
   if(query.next() != NULL)
   {
      db.close();
      return id;
   }
   db.close();
   return "";
}

bool Autenticador::CriaUsuario(QString usuario, QString senha, QString newUsuario, QString newSenha, int tipoUser)
{
   QByteArray id = Autentica(usuario, senha);//verifica se pode criar tipoUsuario
   if(id != "")
   {
      return CriaUsuario(newUsuario, newSenha, tipoUser);
   }
   else
      return false;
}

bool Autenticador::CriaUsuario(QString newUsuario, QString newSenha, int tipoUser)
{
   db.open();
   QSqlQuery query(db);
   QString _tipo;
   query.prepare(UtilitarioGeralBD::SubstituiPlaceholder("INSERT INTO autenticacao (ID,USER_NAME,TIPO_USUARIO)VALUES(':id',':user',':tipo')",QStringList()<<":id"<<":user"<<":tipo",QStringList()<<QCryptographicHash::hash(newUsuario.toUtf8() + newSenha.toUtf8(), QCryptographicHash::Md5).toHex()<<newUsuario<<_tipo.number(tipoUser)));
   query.exec();
   db.close();
   qDebug()<<query.lastError().text();
   return query.lastError().text()=="";
}
