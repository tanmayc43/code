import java.util.Scanner;

public class P1
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number of test cases: ");
        int n = sc.nextInt();

        int[] testcases = new int[n];
        System.out.println("enter the number of elements in each test case: ");
        for (int i = 0; i < n; i++) testcases[i] = sc.nextInt();

        int[] evengg = new int[n];
        int[] oddgg = new int [n];
        int oddt = 0, event = 0;
        for (int i = 0; i < n; i++) {
            int oddCnt = 0;
            int evenCnt = 0;
            System.out.println("Enter elements for test case " + (i + 1) + ":");

            for (int j = 0; j < testcases[i]; j++) {
                int num = sc.nextInt();
                if (num % 2 == 0) {
                    evenCnt++;
                    event++;
                } else {
                    oddCnt++;
                    oddt++;
                }
            }
            oddgg[i]=oddCnt;
            evengg[i]=evenCnt;
        }


        for(int i=0;i<n;i++)System.out.println("Test Case " + (i + 1) + ": Odd Count = " + oddgg[i] + ", Even Count = " + evengg[i]);
        System.out.println("Overall Odd Count: " + oddt);
        System.out.println("Overall Even Count: " + event);

        sc.close();
    }
}