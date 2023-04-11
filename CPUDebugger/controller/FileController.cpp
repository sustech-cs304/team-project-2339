#include "FileController.h"


FileController::FileController() {
    inputFac = new TopVFileInputFactory();
}

void FileController::import(QFile file) {
    inputFac->fileInput(&file);
}

void FileController::exportUart() {

}
