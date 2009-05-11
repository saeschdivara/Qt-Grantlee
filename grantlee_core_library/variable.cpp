/*
    Copyright (c) 2009 Stephen Kelly <steveire@gmail.com>
*/

#include "variable.h"

#include <QVariant>
#include <QStringList>
#include <QMetaEnum>

#include "context.h"

#include <QDebug>

using namespace Grantlee;

Variable::Variable()
{

}

Variable::Variable(const QString &var)
{
  m_varString = var.trimmed();
}

bool isNumeric(const QString &str)
{
  bool ret = false;

  QString searchString;

  if ( str.startsWith(".") )
    return true;
    
  if ( str.startsWith("+") || str.startsWith("-") )
  {
    searchString = str.right(str.size() - 1);
  } else {
    searchString = str;
  }

  if (str.isEmpty())
    return false;
  
  QRegExp re("\\d+");


  return re.exactMatch(searchString);  
}

QVariant Variable::resolve(Context *c)
{
  if ((m_varString.startsWith("\"") && m_varString.endsWith("\""))
    || (m_varString.startsWith("'") && m_varString.endsWith("'")))
  {
    int size = m_varString.size();
    return m_varString.mid(1, size - 2);
  }
  QStringList list = m_varString.split(".");
  QString varName = list.takeFirst();
  
  if (varName.isEmpty())
  {
    QVariant v(m_varString);
    return v.toDouble();    
  }

  if (isNumeric(varName))
  {
    QVariant v(m_varString);
    if (list.isEmpty())
    {
      return v.toInt();
    } else {
      return v.toDouble();
    }
  }
  
  QVariant var = c->lookup(varName);
  if (!var.isValid())
    return QVariant();
  foreach (const QString &part, list)
  {
    var = resolvePart(var, part);
    if (!var.isValid())
      return var;
  }
  return var;
}

QVariant Variable::resolvePart( QVariant var, const QString &nextPart )
{
  QVariant returnVar;

//   Should be
// * QVariantMap key lookup
// * Property? (member in django)
// // * method call
// * list index

  if ( QVariant::Map == var.type() )
  {
    QVariantMap map = var.toMap();
    return map.value( nextPart );
  }
  else if ( QMetaType::QObjectStar == var.userType() )
  {
    // Can't be const because of invokeMethod.
    const QObject *obj = var.value<QObject *>();
    const QMetaObject *metaObj = obj->metaObject();

    QMetaProperty mp;
    for (int i = 0; i < metaObj->propertyCount(); ++i)
    {
      // TODO only read-only properties should be allowed here.
      // This might also handle the variant messing I hit before.
      mp = metaObj->property(i);

      if (QString(mp.name()) != nextPart)
        continue;

      return mp.read(obj);

    }
    return QVariant();

//     QMetaMethod mm;
//     for (int i = 0; i < metaObj->methodCount(); ++i)
//     {
//       mm = metaObj->method(i);
//
//       if ( mm.parameterNames().size() > 0 )
//         continue;
//
//       // Remove the '()' from the end of the signature. It is already normalized and takes no args.
//       QString methodName(mm.signature());
//       methodName.chop(2);
//
//       if (methodName != nextPart)
//         continue;
//
//       if (mm.access() != QMetaMethod::Public)
//         continue;
//
//       if (mm.methodType() == QMetaMethod::Signal)
//         continue;
//
//       // TODO: It would be much nicer if methods could return any type that QVariant handles.
// //       qDebug() << "erte" << QVariant::metaObject().className();
// // Works outside of invokeMethod.
//   //   MyClass *myc= new MyClass();
//   //   qDebug() << myc->getSomething();
//   //   QVariant v2 = myc->getSomething();
//   //   qDebug() << v2;
//
//       QString varTypeString("QVariant");
//       if ( mm.typeName() != varTypeString )
//         continue;
//
//
// //       qDebug() << (mm.methodType() == QMetaMethod::Slot) << mm.signature() << methodName <<  mm.parameterNames() << mm.parameterTypes() << mm.typeName();
//
//       metaObj->invokeMethod(obj, qPrintable(methodName),
//                             Qt::DirectConnection,
//                             Q_RETURN_ARG(QVariant, returnVar));
//
// //       qDebug() << returnVar;
// //       if (returnVar.isValid() )
//       return returnVar;
//     }
  } else {
    // List index test

    bool ok = false;
    int listIndex = nextPart.toInt(&ok);
    if (!ok)
      return QVariant();
    if ( QVariant::List == var.type() )
    {
      QVariantList varList = var.toList();
      if (listIndex >= varList.size())
        return QVariant();
      return varList.at(listIndex);
    } else if ( QVariant::StringList == var.type() )
    {
      QStringList strList = var.toStringList();
      return strList.at(listIndex);
    } else if ( QVariant::ByteArray == var.type() )
    {
      QByteArray ba = var.toByteArray();
      return ba.at(listIndex);
    } else if ( QVariant::String == var.type() )
    {
      QString str = var.toString();
      return str.at(listIndex);
    }
  }

  return QVariant();
}