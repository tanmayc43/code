package threads;

public class Main {
    public static void main(String[] args) {
//        System.out.println(Thread.activeCount());
//        System.out.println(Thread.currentThread().getName());
//
//        Thread.currentThread().setName("HOLERA");
//        System.out.println(Thread.currentThread().getName());
//
//        System.out.println(Thread.currentThread().getPriority());
//        // default priority is 5 of the main thread
//        Thread.currentThread().setPriority(1);
//        System.out.println(Thread.currentThread().getPriority());
//
//        System.out.println(Thread.currentThread().isAlive());
//
//        for(int i=5;i>0;i--){
//            System.out.println(i);
//            try {
//                Thread.sleep(5000);
//            } catch (InterruptedException e) {
//                throw new RuntimeException(e);
//            }
//        }
//
//        System.out.println("hogya");

        Thread.currentThread().setPriority(6);
        MyThread thread1 = new MyThread();
        System.out.println(thread1.isAlive());
        thread1.setDaemon(true);
        thread1.start();
        System.out.println(thread1.isAlive());

        // the difference between calling run directly and calling start method

        System.out.println(thread1.getName());
        thread1.setName("second thread");
        System.out.println(thread1.getName());

        thread1.setPriority(9);
        System.out.println(thread1.getPriority()); // inherits the priority of thread that created it

        System.out.println(Thread.activeCount());

        // daemon threads - low priority, runs in bg, garbage collection shit like that
        // user defined threads - JVM terminates itself when all non daemon threads finish their execution

        System.out.println(thread1.isDaemon());
    }
}
