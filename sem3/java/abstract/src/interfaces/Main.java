package interfaces;

public class Main {
    public static void main(String[] args) {
//        Engine car1 = new Car();
//        // jo access kr skte hain vo from left side and what version of that is decided from the right
//        //car1.a;
//        car1.start();
//        car1.accelerate();
//        car1.stop();
//
//        Media carmedia = new Car();
//        carmedia.start();
//        carmedia.stop();

        Gaadi gaadi1 = new Gaadi();

        gaadi1.start();
        gaadi1.startMusic();
        gaadi1.stopMusic();
        gaadi1.accelerate();
        gaadi1.stop();
    }
}
