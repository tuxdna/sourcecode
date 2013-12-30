#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow: public QMainWindow
{
  Q_OBJECT;
  
 public:
  MainWindow();
  
 protected:
  void closeEvent(QCloseEvent *event);

  private slots:

  void newFile();
  void open();
  void save();
  void saveAs();
  void find();
  void goToCel();
  void sort();
  void about();
  void openRecentFile();
  void updateStatusBar();
  void spreadsheetModified();

 private:
  void createActions();
  void createMenus();
  void createContextMenus();
  void createToolBars();
  void createStatusBar();
  void readSettings();
  void writeSettings();
  bool okToContinue();
  bool loadFile(const QString &fileName);
  bool saveFile(const QString &fileName);
  void setCurrentFile(const QString &fileName);
  void updateRecentFileActions();
  QString strippedName(const QString &fullFileName);

  Spreadsheet *spreadsheet;
  FindDialog *findDailog;
  QLabel *locationLabel;
  QLabel *formulaLabel;
  QStringList recentFiles;
  QString curFile;
  
  enum {MaxRecentFiles = 5};

  QAction *recentFileActions[MaxRecentFiles];
  QAction *separatorAction;
  
  QMenu *fileMenu;
  QMenu *editMenu;
  // ...
  QToolBar *fileToolBar;
  QToolBar *editToolBar;
  QAction *newAction;
  QAction *openAction;
  // ...
  QAction *aboutQtAction;
};


#endif

