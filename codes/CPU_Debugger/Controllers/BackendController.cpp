#include "BackendController.h"
#include "States/State.h"
#include "States/WaitingState.h"
#include "States/DebugginState.h"
#include <iostream>

BackendController::BackendController()
{
    this->stateMap.insert("Waiting", std::make_shared<WaitingState>());
    this->stateMap.insert("Debugging", std::make_shared<DebugginState>());
    curState = this->stateMap.value("Waiting");
}

BackendController& BackendController::getInstance()
{
    static BackendController instance;
    return instance;
}

void BackendController::setState(QString string){
    if (!stateMap.contains(string))
    {
        std::cout << "Please check the state name is right." << std::endl;
        return;
    }
    this->curState = this->stateMap.value(string);
}

std::shared_ptr<State> BackendController::getState()
{
    return this->curState;
}

void BackendController::doStateAction()
{
    this->curState->doAction();
}
