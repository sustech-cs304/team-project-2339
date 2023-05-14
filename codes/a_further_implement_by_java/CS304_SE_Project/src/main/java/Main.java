import Controllers.BackendController;
import Data.DataStore;
import Data.Files.asmFile;
import Data.Files.cFile;
import States.DebuggingState;
import States.FileProcessingState;

import java.io.File;

public class Main {
    public static void main(String[] args) {
        cFile file = new asmFile();
        file.setFile(new File("src/test.asm"));
        DataStore store = DataStore.getInstance();
        BackendController backendController = BackendController.getInstance();

        backendController.doStateAction();

        backendController.setState("FileProcessingState");
        backendController.doStateAction();

        backendController.doStateAction();

        backendController.setState("DebuggingState");
        backendController.doStateAction();

        backendController.doStateAction();

        store.file = file;
        backendController.setState("DebuggingState");
        backendController.doStateAction();
    }
}
