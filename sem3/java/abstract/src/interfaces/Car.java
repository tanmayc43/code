package interfaces;

public class Car implements Engine, Brake, Media{

    int a = 21;

    @Override
    public void brake() {
        System.out.println("I break like a retard");
    }

    @Override
    public void start() {
        System.out.println("gaddi chalu sahab");
    }

    @Override
    public void stop() {
        System.out.println("oh bc patrol khtm");
    }

    @Override
    public void accelerate() {
        System.out.println("bhagao bc");
    }

}

