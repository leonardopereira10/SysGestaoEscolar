#ifndef COMPLETACADDIR_H
#define COMPLETACADDIR_H

#include <QWidget>

namespace Ui {
   class CompletaCadDir;
}

class CompletaCadDir : public QWidget
{
      Q_OBJECT

   public:
      explicit CompletaCadDir(QString id, QWidget *parent = nullptr);
      ~CompletaCadDir();

   private slots:
      void on_pushButton_clicked();

   private:
      Ui::CompletaCadDir *ui;
      QString _id;
};

#endif // COMPLETACADDIR_H
