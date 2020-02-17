#ifndef AUTENTICADOR_H
#define AUTENTICADOR_H

#include <QSql>
#include <QSqlDatabase>
#include <QStringList>

class Autenticador
{
   public:
      Autenticador();
      QByteArray Autentica(QString usuario, QString senha);
      bool CriaUsuario(QString usuario, QString senha, QString newUsuario, QString newSenha, int tipoUser);
   private:
      QSqlDatabase db;
      bool CriaUsuario(QString newUsuario, QString newSenha, int tipoUser);
};

#endif // AUTENTICADOR_H
