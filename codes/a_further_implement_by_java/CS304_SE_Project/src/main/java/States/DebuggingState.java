package States;
import Controllers.BackendController;
import Controllers.DebuggerController;
import Data.DataStore;
import Data.Files.asmFile;
import Data.Files.cFile;
import utils.FileUtils;

public class DebuggingState implements State{
    @Override
    public void doAction() {
        DataStore store = DataStore.getInstance();
        if(!FileUtils.checkFileType(store, asmFile.class)) {
            System.out.println("Please select a .asm file first!");
            BackendController.getInstance().setState("WaitingState");
            return;
        }
        System.out.println("Enjoy Debugging!");
        BackendController.getInstance().setState("WaitingState");
    }
}
