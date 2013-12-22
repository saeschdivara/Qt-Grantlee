/********************************************************************************
 ** The MIT License (MIT)
 **
 ** Copyright (c) 2013 Sascha Ludwig Häusler
 **
 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:
 **
 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *********************************************************************************/

#include <QCoreApplication>
#include <QDebug>

#include <lib/engine.h>

using namespace Grantlee;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Engine *engine = new Engine();

    FileSystemTemplateLoader::Ptr loader = FileSystemTemplateLoader::Ptr( new FileSystemTemplateLoader() );
    loader->setTemplateDirs( QStringList() << "/home/saskyrardisaskyr/Documents/grantlee/examples/build-SimpleTemplateRendering-Desktop_Qt_5_2_0_GCC_64bit-Debug/templates" );
    engine->addTemplateLoader( loader );

    engine->addPluginPath( "/home/saskyrardisaskyr/Documents/grantlee/examples/build-SimpleTemplateRendering-Desktop_Qt_5_2_0_GCC_64bit-Debug/" );

    Template template1 = engine->loadByName( "index.html" );
    if (template1->error()) {
            qDebug() << template1->errorString();
        }

    return a.exec();
}
