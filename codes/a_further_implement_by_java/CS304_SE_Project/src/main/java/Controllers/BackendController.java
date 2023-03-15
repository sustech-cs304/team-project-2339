package Controllers;

import States.DebuggingState;
import States.FileProcessingState;
import States.State;
import States.WaitingState;

import java.util.ArrayList;
import java.util.HashMap;

public class BackendController {
    private static final BackendController instance = new BackendController();

    State cur_state;
    HashMap<String, State> stateMap = new HashMap<>(){{
        put("WaitingState", new WaitingState());
        put("FileProcessingState", new FileProcessingState());
        put("DebuggingState", new DebuggingState());
    }};


    private BackendController() {
        cur_state = null;
    }

    public static BackendController getInstance() {
        return instance;
    }

    public void setState(String state) {
        cur_state = stateMap.get(state);
    }

    public void setState(State state) {
        cur_state = state;
    }

    public void doStateAction() {
        if (cur_state == null) {
            cur_state = new WaitingState();
        }
        cur_state.doAction();
    }
}
