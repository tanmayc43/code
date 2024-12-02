public class P1 {
    private static int sharedCounter = 0;
    private static final Object counterLock = new Object();

    static class CounterIncrementThread extends Thread {
        public void run() {
            for (int i = 0; i < 5000; i++) {
                synchronized(counterLock) {
                    sharedCounter++;
                    System.out.println("IncrementThread: sharedCounter = " + sharedCounter);
                }
            }
        }
    }

    static class CounterDecrementThread extends Thread {
        public void run() {
            for (int i = 0; i < 3000; i++) {
                synchronized(counterLock) {
                    sharedCounter--;
                    System.out.println("DecrementThread: sharedCounter = " + sharedCounter);
                }
            }
        }
    }

    static class IncrementRunnable implements Runnable {
        public void run() {
            for (int i = 0; i < 5000; i++) {
                synchronized(counterLock) {
                    sharedCounter++;
                    System.out.println("IncrementRunnable: sharedCounter = " + sharedCounter);
                }
            }
        }
    }

    static class DecrementRunnable implements Runnable {
        public void run() {
            for (int i = 0; i < 3000; i++) {
                synchronized(counterLock) {
                    sharedCounter--;
                    System.out.println("DecrementRunnable: sharedCounter = " + sharedCounter);
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Starting Part 1 - Without join()");
        CounterIncrementThread incrementThread = new CounterIncrementThread();
        CounterDecrementThread decrementThread = new CounterDecrementThread();

        incrementThread.start();
        decrementThread.start();

        System.out.println("Shared counter value without join(): " + sharedCounter);

        try {
            incrementThread.join();
            decrementThread.join();
            System.out.println("Shared counter value with join(): " + sharedCounter);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        sharedCounter = 0;

        System.out.println("\nStarting Part 2 - Using Runnable");
        Thread incrementRunnableThread = new Thread(new IncrementRunnable());
        Thread decrementRunnableThread = new Thread(new DecrementRunnable());

        incrementRunnableThread.start();
        decrementRunnableThread.start();

        System.out.println("Shared counter value without join() in Runnable: " + sharedCounter);

        try {
            incrementRunnableThread.join();
            decrementRunnableThread.join();
            System.out.println("Shared counter value with join() in Runnable: " + sharedCounter);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
