#include "Controllers/BackendController.h"
#include "Lib_Comm/comm.h"
int main(){
    BackendController& backendController = BackendController::getInstance();
    backendController.getState()->doAction();
    backendController.setState("Debugging");
    backendController.getState()->doAction();
    backendController.setState("Fuck");
    backendController.getState()->doAction();
    test_serial_ports();
}
