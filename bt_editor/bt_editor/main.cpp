#include <iostream>
#include <QApplication>
#include <node_editor/NodeStyle>
#include <node_editor/FlowViewStyle>
#include <node_editor/ConnectionStyle>

#include "ControlNodeModel.hpp"
#include "mainwindow.h"
#include "ActionNodeModel.hpp"
#include "RootNodeModel.hpp"
#include "NodeFactory.hpp"

#include <node_editor/DataModelRegistry>

using QtNodes::DataModelRegistry;
using QtNodes::FlowViewStyle;
using QtNodes::NodeStyle;
using QtNodes::ConnectionStyle;

int
main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  // Access the command-line arguments from within the event loop
  QStringList arguments = app.arguments();
  arguments.pop_front();
  QString args;
  // Process or use the arguments as needed
  for (const QString &arg : arguments) {
      args.append(" ");
      args.append(arg);
  }

  MainWindow win(0, args);
  win.show();

  return app.exec();
}
