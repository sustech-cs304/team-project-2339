package States;

public class WaitingState implements State{
    @Override
    public void doAction() {
        System.out.println("Waiting...");
    }
}
