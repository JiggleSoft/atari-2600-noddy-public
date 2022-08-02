package uk.co.jigglesoft.noddy.sgs;

import java.util.concurrent.*;

public class Main
{
    static boolean die = false;
    public static void main(String[] args)
    {
        final int availableProcessors = Runtime.getRuntime().availableProcessors();
        final int queueCapacity = availableProcessors * 4;
        final BlockingQueue<Integer> bq = new ArrayBlockingQueue<>(queueCapacity);
        final int threadPoolSize = availableProcessors*4 - 1;
        final ExecutorService executor = Executors.newFixedThreadPool(threadPoolSize);
        System.out.println("CPU: " + availableProcessors + "    Queue: " + queueCapacity + "    Threads: " + threadPoolSize);

        for (int i = 0;  i < threadPoolSize;  i++) {
            executor.submit(new Runnable() {
                @Override
                public void run() {
                    while (!die) {
                        int z = 0;
                        try {
                            z = bq.take();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        System.out.println("THREAD(" + Thread.currentThread().getName() + "): " + z);
                        try {
                            Thread.sleep(20);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            });
        }
        final long start = System.currentTimeMillis();
        for (int i = 0;  i < 256000;  i++)
        {
            while (bq.remainingCapacity() == 0)
            {
                Integer z = null;
                //try {
                    z = null;//bq.take();
               // } catch (InterruptedException e) {

                //}
                if (z != null) {
                    System.out.println("MAIN: " + z);
                }
            }
            try {
                bq.put(i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        while (!bq.isEmpty())
            ;
        die = true;
        final long stop = System.currentTimeMillis();
        final long diff = stop - start;
        System.out.println("DIFF=" + diff);
        executor.shutdown();
        try {
            executor.awaitTermination(5000, TimeUnit.MILLISECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
