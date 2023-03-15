package Controllers;

import Data.DataStore;

public class DebuggerController {
    DataStore dataStore = DataStore.getInstance();
    private static final DebuggerController instance = new DebuggerController();
    private DebuggerController() {}
    public static DebuggerController getInstance() {
        return instance;
    }

}
