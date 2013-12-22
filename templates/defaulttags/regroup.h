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

#ifndef REGROUPNODE_H
#define REGROUPNODE_H

#include "lib/node.h"

using namespace Grantlee;


class RegroupNodeFactory : public AbstractNodeFactory
{
  Q_OBJECT
public:
  RegroupNodeFactory();

  Node* getNode( const QString &tagContent, Parser *p ) const;

};

class RegroupNode : public Node
{
  Q_OBJECT
public:
  RegroupNode( FilterExpression target, FilterExpression expression, const QString &varName, QObject *parent = 0 );

  void render( OutputStream *stream, Context *c ) const;

private:
  FilterExpression m_target;
  FilterExpression m_expression;
  QString m_varName;

};

#endif

