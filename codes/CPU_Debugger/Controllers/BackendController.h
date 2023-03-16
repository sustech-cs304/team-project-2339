#ifndef BACKENDCONTROLLER_H
#define BACKENDCONTROLLER_H

#include "States/State.h"
#include "States/WaitingState.h"

#include <QMap>
#include <QString>
#include <memory>

class BackendController final
{
private:

    std::shared_ptr<State> curState;
    QMap <QString, std::shared_ptr<State>> stateMap;

    BackendController();

public:

    static BackendController& getInstance();

    std::shared_ptr<State> getState();
    void setState(QString);

    void doStateAction();
};

#endif // BACKENDCONTROLLER_H
