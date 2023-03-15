package Data;
import Data.Files.cFile;
import Data.Module.ModuleSet;
import Data.Module.Signal;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class DataStore {
    public static final DataStore instance = new DataStore();

    //TODO:change the parameters to Input and Output.
    public cFile file;
    public ModuleSet moduleSet;
    public ArrayList<Signal> signedSignals;

//    private HashMap<String, Objects> inputs;
//    private HashMap<String, Objects> outputs;

    private DataStore(){}
    public static DataStore getInstance(){
        return instance;
    }


}