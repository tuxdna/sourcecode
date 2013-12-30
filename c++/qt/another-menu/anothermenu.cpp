#include "anothermenu.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QTextStream>
#include <QToolBar>
#include <QIcon>
#include <QAction>

AnotherMenu::AnotherMenu(QWidget *parent)
  : QMainWindow(parent)
{
  QTextStream out(stdout);
  QString icons_basepath = "/usr/share/icons/gnome/16x16/actions/";
  icons_basepath = "/usr/share/icons/gnome/48x48/actions/";
  QString new_image = icons_basepath+"document-new.png";
  QString open_image = icons_basepath+"document-open.png";
  QString quit_image = icons_basepath+"application-exit.png";

  // new_image = "new.png";
  // open_image = "open.png";
  // quit_image = "quit.png";

  out << "Listing file locations:" << endl
      << new_image << endl
      << open_image << endl
      << quit_image << endl
      << endl;

  QPixmap newpix(new_image);
  QPixmap openpix(open_image);
  QPixmap quitpix(quit_image);

  // out << "Listing pix objects:" << endl;
  // out << newpix << endl
  //     << openpix << endl
  //     << quitpix << endl
  //     << endl;

  QAction *newa = new QAction(newpix, "&New", this);
  QAction *open = new QAction(openpix, "&Open", this);
  QAction *quit = new QAction(quitpix, "&Quit", this);
  quit->setShortcut(tr("CTRL+Q"));

  viewst = new QAction("&View Statusbar", this);
  viewst->setCheckable(true);
  viewst->setChecked(true);

  QMenu *file =  menuBar()->addMenu("&File");
  file->addAction(newa);
  file->addAction(open);
  file->addAction(viewst);
  file->addSeparator();
  file->addAction(quit);

  statusBar();
  connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
  connect(viewst, SIGNAL(triggered()), this, SLOT(toggleStatusbar()));


  QToolBar *toolbar = addToolBar("main toolbar");
  toolbar->addAction(QIcon(newpix), "New File");
  toolbar->addAction(QIcon(openpix), "Open File");
  toolbar->addSeparator();
  QAction *toolbar_quit = toolbar->addAction(QIcon(quitpix), "Quit File");
  connect(toolbar_quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void AnotherMenu::toggleStatusbar() {
  if(viewst->isChecked()){
    statusBar()->show();
  }else{
    statusBar()->hide();
  }
}
