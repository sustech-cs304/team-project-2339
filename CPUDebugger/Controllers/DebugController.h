
#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H

#include <QtCore>
#include <memory>

#include "File/AsmFile.h"
#include "Stores/DebugStore.h"
#include "uart/comm.h"
#include "Controllers/PreDebugController.h"
#include "Stores/PreDebugStore.h"
#include "model/CPUSignal.h"

/**
 * @brief The DebugController class provides functions to control the debugging process.
 */
class DebugController
{
public:
    /**
     * @brief Resumes the execution of the program.
     * @return The response from the CPU.
     */
    static std::optional<QByteArray> resume();

    /**
     * @brief Executes a single instruction.
     * @return The response from the CPU.
     */
    static std::optional<QByteArray> step();

    /**
     * @brief Pauses the execution of the program.
     * @return 1.
     */
    static int pause();

    /**
     * @brief Attempts to automatically connect to the CPU.
     * @return True if the connection was successful, false otherwise.
     */
    static int detect();

    /**
     * @brief Returns the binary representation of the assembled program.
     * @return The binary representation of the assembled program.
     */
    static QByteArray getBin();

    /**
     * @brief Sends the assembled program to the CPU for execution.
     * @return The response from the CPU.
     */
    static std::optional<QByteArray> sendPrograme();

    /**
     * @brief Compiles the assembly file.
     * @return 0.
     */
    static int compileAsm();

    friend class PreDebugController;

private:
    enum FileType
    {
        Asm,
        Bin
    };

    /**
     * @brief Checks if the DebugStore is initialized.
     * @throws std::invalid_argument if the DebugStore is not initialized.
     */
    static void checkStore();

    /**
     * @brief Initializes the DebugStore with the given AsmFile.
     * @param asmFilePtr The AsmFile to initialize the DebugStore with.
     */
    static void initialize(std::shared_ptr<AsmFile> asmFilePtr);

    /**
     * @brief Clears the DebugStore.
     */
    static void clear();

    /**
     * @brief Extracts the program counter from the CPU response.
     * @param cpuResponse The response from the CPU.
     * @return The program counter.
     */
    inline static int extractPC(QByteArray& cpuResponse);

    /**
     * @brief Sets the program counter based on the given file type and PC.
     * @param fileType The type of file (Asm or Bin).
     * @param PC The program counter.
     * @return 0.
     */
    inline static int setPC(FileType fileType, int PC);
};

#endif // DEBUGCONTROLLER_H


