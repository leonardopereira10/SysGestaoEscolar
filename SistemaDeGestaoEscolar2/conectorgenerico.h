#ifndef CONECTORGENERICO_H
#define CONECTORGENERICO_H

#include <QSqlDatabase>



class ConectorGenerico
{
   private:
      QSqlDatabase db;
      QString _nomeConexao;
   public:
      ConectorGenerico(QString nomeConexao);
      bool ExecutaSql(QString query);
      ~ConectorGenerico();
};

#endif // CONECTORGENERICO_H
