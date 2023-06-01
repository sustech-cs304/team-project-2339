
/**
 * @file PreDebugStore.h
 * @brief This file contains the declaration of the PreDebugStore class.
 */

#ifndef PREDEBUGSTORE_H
#define PREDEBUGSTORE_H

#include <memory>
#include <set>

#include "File/AsmFile.h"

/**
 * @brief The PreDebugStore class is responsible for storing the pre-debug information.
 */
class PreDebugStore
{
public:
    /**
     * @brief The asmFile variable stores the pointer to the AsmFile object.
     */
    static std::shared_ptr<AsmFile> asmFile;

    /**
     * @brief The file variable stores the pointer to the QFile object.
     */
    static std::shared_ptr<QFile> file;

    /**
     * @brief The breakPoints variable stores the set of break points.
     */
    static std::set<int> breakPoints;

    friend class PreDebugController;
};

#endif // PREDEBUGSTORE_H


