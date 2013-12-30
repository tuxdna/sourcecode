/****************************************************************************
** MainWindow meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Nov 14 15:48:47 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "mainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainWindow::className() const
{
    return "MainWindow";
}

QMetaObject *MainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainWindow( "MainWindow", &MainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"newLetter", 0, 0 };
    static const QUMethod slot_1 = {"save", 0, 0 };
    static const QUMethod slot_2 = {"print", 0, 0 };
    static const QUMethod slot_3 = {"undo", 0, 0 };
    static const QUMethod slot_4 = {"about", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "customer", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"insertCustomer", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "paragraph", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"addParagraph", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "newLetter()", &slot_0, QMetaData::Private },
	{ "save()", &slot_1, QMetaData::Private },
	{ "print()", &slot_2, QMetaData::Private },
	{ "undo()", &slot_3, QMetaData::Private },
	{ "about()", &slot_4, QMetaData::Private },
	{ "insertCustomer(const QString&)", &slot_5, QMetaData::Private },
	{ "addParagraph(const QString&)", &slot_6, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainWindow", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* MainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainWindow" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool MainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newLetter(); break;
    case 1: save(); break;
    case 2: print(); break;
    case 3: undo(); break;
    case 4: about(); break;
    case 5: insertCustomer((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: addParagraph((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainWindow::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool MainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
