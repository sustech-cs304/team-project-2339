package States;

import Controllers.BackendController;

public class FileProcessingState implements State{
    @Override
    public void doAction() {
        System.out.println("File is being processed");
        System.out.println("File is processed!");
        BackendController.getInstance().setState("WaitingState");
    }
}
