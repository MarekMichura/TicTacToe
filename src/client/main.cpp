#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include <string>

void QTHelloWorld(){
  QTextStream qtin(stdin);
  QTextStream qtout(stdout);

  qtout << "Hello, whats your name?\n";
  qtout.flush();
  QString name = qtin.readLine();
  qtout << "Hello " << name << "\n";
  qtout.flush();
}

int main() {
  QTHelloWorld();
  return 0;
}
