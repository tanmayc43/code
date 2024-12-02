package interfaces;

public class Powerunit implements Engine{
    @Override
    public void start() {
        System.out.println("engine chaalu sahab");
    }

    @Override
    public void stop() {
        System.out.println("bc petrol khtm");
    }

    @Override
    public void accelerate() {
        System.out.println("bhgao mc");
    }
}
