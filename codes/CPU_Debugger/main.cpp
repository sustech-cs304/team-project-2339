#include "Controllers/BackendController.h"
int main(){
    BackendController& backendController = BackendController::getInstance();
    backendController.getState()->doAction();
    backendController.setState("Debugging");
    backendController.getState()->doAction();
    backendController.setState("Fuck");
    backendController.getState()->doAction();
}
