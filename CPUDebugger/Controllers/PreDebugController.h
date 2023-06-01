
/**
 * @file PreDebugController.h
 * @brief This file contains the declaration of the PreDebugController class.
 */

#ifndef PREDEBUGCONTROLLER_H
#define PREDEBUGCONTROLLER_H

#include <QtCore>
#include <memory>
#include <set>

#include "Stores/PreDebugStore.h"
#include "Controllers/DebugController.h"

/**
 * @brief The PreDebugController class is responsible for handling the pre-debugging process.
 */
class PreDebugController
{
public:
    /**
     * @brief Uploads the file at the given file path.
     * @param filePath The path of the file to upload.
     * @return A shared pointer to the uploaded file.
     * @throws std::invalid_argument if the file path is invalid.
     */
    static std::shared_ptr<QFile> uploadFile(QString filePath);

    /**
     * @brief Sets a breakpoint at the given line index.
     * @param lineIdx The index of the line to set the breakpoint at.
     */
    static void setBreakPoint(int lineIdx);

    /**
     * @brief Gets the assembly file.
     * @return A shared pointer to the assembly file.
     */
    static std::shared_ptr<AsmFile> getAsm();

    /**
     * @brief Gets the uploaded file.
     * @return A shared pointer to the uploaded file.
     */
    static std::shared_ptr<QFile> getFile();

    /**
     * @brief Clears the pre-debugging process.
     */
    static void clear();

private:
    /**
     * @brief Converts the assembly file to binary.
     * @param file A shared pointer to the assembly file.
     */
    static void asmToBin(std::shared_ptr<QFile> file);
};

#endif // PREDEBUGCONTROLLER_H


