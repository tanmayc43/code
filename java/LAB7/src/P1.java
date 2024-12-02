import java.util.Scanner;

public class P1 {
    public int add() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int a = scanner.nextInt();
        System.out.print("Enter second number: ");
        int b = scanner.nextInt();
        return a + b;
    }

    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b + c;
    }

    public static void main(String[] args) {
        P1 addition = new P1();

        int resultFromUserInput = addition.add();
        System.out.println("Sum from user input: " + resultFromUserInput);

        int sumTwoNumbers = addition.add(5, 10);
        System.out.println("Sum of 5 and 10: " + sumTwoNumbers);

        int sumThreeNumbers = addition.add(1, 2, 3);
        System.out.println("Sum of 1, 2, and 3: " + sumThreeNumbers);
    }
}
