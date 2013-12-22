/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009,2010 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either version
  2.1 of the Licence, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "util.h"

#include "metaenumvariable_p.h"
#include "metatype.h"

#include <QtCore/QStringList>

QString Grantlee::unescapeStringLiteral( const QString &input )
{
  return input.mid( 1, input.size() - 2 )
         .replace( QLatin1String( "\\\'" ), QChar::fromLatin1( '\'' ) )
         .replace( QLatin1String( "\\\"" ), QChar::fromLatin1( '"' ) )
         .replace( QLatin1String( "\\\\" ), QChar::fromLatin1( '\\' ) );
}

bool Grantlee::variantIsTrue( const QVariant &variant )
{

  if ( !variant.isValid() )
    return false;
  switch ( variant.userType() ) {
  case QVariant::Bool: {
    return variant.toBool();
  }
  case QVariant::Int: {
    return ( variant.toInt() > 0 );
  }
  case QVariant::Double: {
    return ( variant.toDouble() > 0 );
  }
  case QMetaType::QObjectStar: {
    QObject *obj = variant.value<QObject *>();
    if ( !obj )
      return false;

    if ( obj->property( "__true__" ).isValid() ) {
      return obj->property( "__true__" ).toBool();
    }
    return true;
  }
  case QVariant::List: {
    return ( variant.toList().size() > 0 );
  }
  case QVariant::Hash: {
    return ( variant.toHash().size() > 0 );
  }
  }

  return !getSafeString( variant ).get().isEmpty();
}

Grantlee::SafeString Grantlee::markSafe( const Grantlee::SafeString &input )
{
  Grantlee::SafeString sret = input;
  sret.setSafety( Grantlee::SafeString::IsSafe );
  return sret;
}

Grantlee::SafeString Grantlee::markForEscaping( const Grantlee::SafeString &input )
{
  Grantlee::SafeString temp = input;
  if ( input.isSafe() || input.needsEscape() )
    return input;

  temp.setNeedsEscape( true );
  return temp;
}

Grantlee::SafeString Grantlee::getSafeString( const QVariant &input )
{
  if ( input.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
    return input.value<Grantlee::SafeString>();
  } else {
    return input.toString();
  }
}

bool Grantlee::isSafeString( const QVariant &input )
{
  const int type = input.userType();
  return (( type == qMetaTypeId<Grantlee::SafeString>() )
          || type == QVariant::String );
}

static QList<int> getPrimitives()
{
  QList<int> primitives;
  primitives << qMetaTypeId<Grantlee::SafeString>()
             << QVariant::String
             << QVariant::Bool
             << QVariant::Int
             << QVariant::Double
             << QVariant::Date
             << QVariant::Time
             << QVariant::DateTime;
  return primitives;
}

bool Grantlee::supportedOutputType( const QVariant &input )
{
  static const QList<int> primitives = getPrimitives();
  return primitives.contains( input.userType() );
}


bool Grantlee::equals( const QVariant &lhs, const QVariant &rhs )
{

  // TODO: Redesign...

  // QVariant doesn't use operator== to compare its held data, so we do it manually instead for SafeString.
  bool equal = false;
  if ( lhs.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
    if ( rhs.userType() == qMetaTypeId<Grantlee::SafeString>() ) {
      equal = ( lhs.value<Grantlee::SafeString>() == rhs.value<Grantlee::SafeString>() );
    } else if ( rhs.userType() == QVariant::String ) {
      equal = ( lhs.value<Grantlee::SafeString>() == rhs.toString() );
    }
  } else if ( rhs.userType() == qMetaTypeId<Grantlee::SafeString>() && lhs.userType() == QVariant::String ) {
    equal = ( rhs.value<Grantlee::SafeString>() == lhs.toString() );
  } else if ( rhs.userType() == qMetaTypeId<MetaEnumVariable>() ) {
    if ( lhs.userType() == qMetaTypeId<MetaEnumVariable>() ) {
      equal = ( rhs.value<MetaEnumVariable>() == lhs.value<MetaEnumVariable>() );
    } else if ( lhs.type() == QVariant::Int ) {
      equal = ( rhs.value<MetaEnumVariable>() == lhs.toInt() );
    }
  } else if ( lhs.userType() == qMetaTypeId<MetaEnumVariable>() ) {
    if ( rhs.type() == QVariant::Int ) {
      equal = ( lhs.value<MetaEnumVariable>() == rhs.toInt() );
    }
  } else {
    equal = (( lhs == rhs ) && ( lhs.userType() == rhs.userType() ) );
  }
  return equal;
}

Grantlee::SafeString Grantlee::toString( const QVariantList &list )
{
  QString output( QLatin1Char( '[' ) );
  QVariantList::const_iterator it = list.constBegin();
  const QVariantList::const_iterator end = list.constEnd();
  while ( it != end ) {
    const QVariant item = *it;
    if ( isSafeString( item ) ) {
      output += QLatin1Literal( "u\'" )
              + static_cast<QString>( getSafeString( item ).get() )
              + QLatin1Char( '\'' );
    }
    if ( ( item.type() == QVariant::Int )
      || ( item.type() == QVariant::UInt )
      || ( item.type() == QVariant::Double )
      || ( item.type() == QVariant::LongLong )
      || ( item.type() == QVariant::ULongLong )
    ) {
      output += item.toString();
    }
    if ( item.type() == QVariant::List ) {
      output += static_cast<QString>( toString( item.toList() ).get() );
    }
    if ( ( it + 1 ) != end )
      output += QLatin1String( ", " );
    ++it;
  }

  return output.append( QLatin1Char( ']' ) );
}

