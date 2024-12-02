package multithreading;

public class MyRunnable implements Runnable {
    @Override
    public void run(){

        for(int i=0;i<11;i++){
            System.out.println("Thread #2 : " + i);
            try {
                Thread.sleep(800);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println("Thread #2 is finished");
    }
}
