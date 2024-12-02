package interfaces;

public class Mediaplayer implements Media{

    @Override
    public void start() {
        System.out.println("gaana bjao bc");
    }

    @Override
    public void stop() {
        System.out.println("yeh kya bja diya yr");
    }
}
