#ifndef UTILITARIOGERALBD_H
#define UTILITARIOGERALBD_H

#include <QSqlDatabase>
#include <QString>



class UtilitarioGeralBD
{
   public:
      UtilitarioGeralBD();
      static QString SubstituiPlaceholder(QString query, QStringList placeHolders, QStringList values);
      static QString MontaInsert(QString table, QStringList field, QStringList values);
      static QSqlDatabase ObtemBancoDadosDoArquivo();
};

#endif // UTILITARIOGERALBD_H
