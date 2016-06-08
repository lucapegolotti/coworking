#include "directoryhandler.h"

QString DirectoryHandler::completePath(QString filename) {
    QString path = readDirectory();
    path.append(filename);
    return path;
}

QString DirectoryHandler::readDirectory() {
    std::ifstream file;
    file.open("config.txt");
    if (!file.is_open()){
        qDebug() << "Using default directory";
        return "./";
    }
    std::string dir;
    std::getline(file,dir);
    return QString::fromStdString(dir);
}
