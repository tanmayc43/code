package multithreading;

public class Main {
    public static void main(String[] args) {

//                MyThread thread1 = new MyThread();
//
//                MyRunnable runnable1 = new MyRunnable();
//                Thread thread2 = new Thread(runnable1);

//        //        thread1.setDaemon(true);
//        //        thread2.setDaemon(true);
//
//                thread1.start();
//        //        try {
//        //            thread1.join(3000); // calling thread will wait until this thread dies or the specified milliseconds
//        //        } catch (InterruptedException e) {
//        //            throw new RuntimeException(e);
//        //        }
//                thread2.start();
//                System.out.println();
//                System.out.println(1/0);
        int i=8;
        try{
            System.out.println(i/0);
        }
        finally {
            System.out.println("bsag");
        }


        System.out.println("sangsangiasn");



    }
}
