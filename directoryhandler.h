#ifndef DIRECTORY_HANDLER_H
#define DIRECTORY_HANDLER_H

#include <fstream>
#include <QString>
#include <QDebug>

#define FILE_PATH(filename) DirectoryHandler::completePath(filename)

class DirectoryHandler {
 public:
    static QString completePath(QString filename);

 private:
    static QString readDirectory();

};

#endif // DIRECTORY_HANDLER_H
