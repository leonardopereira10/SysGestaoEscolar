#include "utilitariogeralbd.h"

#include <QStringList>

UtilitarioGeralBD::UtilitarioGeralBD()
{

}

QString UtilitarioGeralBD::SubstituiPlaceholder(QString query, QStringList placeHolders, QStringList values )
{
   int a = values.count();
   if(a == placeHolders.count())
   {
      for(int i = 0; i < a; i++)
      {
         query.replace(placeHolders.value(i),values.value(i));
      }
   }
   else{
      throw "quantidade de valores diferentes";
   }
   return query;
}

QString UtilitarioGeralBD::MontaInsert(QString table, QStringList field,QStringList values)
{
   QString insert = "INSERT INTO " + table + "(";
   while (!field.isEmpty())
   {
      insert += field.takeFirst();
      if(!field.isEmpty())
      {
         insert += ",";
      }
   }
   insert += ") VALUES(";
   while (!values.isEmpty())
   {
      insert += "'" + values.takeFirst()+ "'";
      if(!values.isEmpty())
      {
         insert += ",";
      }
   }
   insert += ");";
   return insert;
}


QSqlDatabase UtilitarioGeralBD::ObtemBancoDadosDoArquivo()
{
   QSqlDatabase db;
   FILE *conn = fopen("StringDeConexao.txt", "r");
   char _char = 'a';
   QString stringAtual;
   QStringList listaconn;
   while(_char != EOF)
   {
      _char = getc(conn);
      if( _char != '+')
      {
         stringAtual.append(_char);
      }
      else
      {
         listaconn.push_back(stringAtual);
         stringAtual = "";
      }
   }
   fclose(conn);
   db = QSqlDatabase::addDatabase(listaconn.value(0));
   db.setHostName(listaconn.value(1));
   db.setPort(listaconn.value(2).toInt());
   db.setDatabaseName(listaconn.value(3));
   db.setUserName(listaconn.value(4));
   db.setPassword(listaconn.value(5));
   return  db;
}
