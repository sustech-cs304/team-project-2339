#include "VFile.h"

VFile::VFile(QFile *file) {
    this->data = file;
}

void VFile::Show() {
    std::cout << "This is vFile" << std::endl;
}
