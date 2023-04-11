#include "FileController.h"


FileController::FileController() {
    inputFac = new TopVFileInputFactory();
}

ModuleData* FileController::import(QFile file) {
    inputFac->fileInput(&file);
}

void FileController::exportUart() {

}
