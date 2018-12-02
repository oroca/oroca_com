#include "tabterm.h"
#include "ui_tabterm.h"
#include "console.h"
#include <QSerialPort.h>
#include <QSerialPortInfo.h>



TabTerm::TabTerm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TabTerm)
{
  ui->setupUi(this);


  console = new Console;
  console->setEnabled(false);
  QVBoxLayout *console_layout  =new QVBoxLayout();
  console_layout->addWidget(console);
  ui->verticalLayout->addWidget(console);
  connect(console, &Console::getData, this, &TabTerm::writeData);


  refreshPortList();
}

TabTerm::~TabTerm()
{
  delete ui;
}

void TabTerm::writeData(const QByteArray &data)
{
    //serial->write(data);
}

void TabTerm::readData()
{
    QByteArray data = "a";//serial->readAll();
    console->putData(data);
}

void TabTerm::refreshPortList()
{
  ui->comboBox_PortList->clear();
  foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
  {
    QString port_name;

    port_name = serialPortInfo.portName();
    //port_name += serialPortInfo.description();

    ui->comboBox_PortList->addItem(port_name);
  }
}

