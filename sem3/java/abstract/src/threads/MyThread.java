package threads;

public class MyThread extends Thread {

    @Override
    public void run(){
        if(this.isDaemon()) System.out.println("daemon is running");
        else System.out.println("The thread is running.");
    }
}
