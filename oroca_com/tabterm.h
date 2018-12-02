#ifndef TABTERM_H
#define TABTERM_H

#include <QWidget>

namespace Ui {
  class TabTerm;
}


class Console;

class TabTerm : public QWidget
{
  Q_OBJECT

public:
  explicit TabTerm(QWidget *parent = nullptr);
  ~TabTerm();

private:
  Ui::TabTerm *ui;


  void writeData(const QByteArray &data);
  void readData(void);

  Console *console;

  void refreshPortList();
};

#endif // TABTERM_H
