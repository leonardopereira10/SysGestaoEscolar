#include "conectorgenerico.h"
#include "utilitariogeralbd.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

ConectorGenerico::ConectorGenerico(QString nomeConexao)
{
   _nomeConexao = nomeConexao;
   db = QSqlDatabase::cloneDatabase(UtilitarioGeralBD::ObtemBancoDadosDoArquivo(), _nomeConexao);
   db.open();
}

bool ConectorGenerico::ExecutaSql(QString query)
{
   QSqlQuery _query(db);
   _query.exec(query);
   qDebug()<<_query.lastError().text();
   qDebug()<<_query.lastQuery();
   return true;
}

ConectorGenerico::~ConectorGenerico()
{
   db.close();
}
