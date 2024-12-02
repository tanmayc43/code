import java.util.Scanner;

public class P2 {
    public static void sort(Employee[] employees, int[] eifValues) {
        for (int i = 0; i < eifValues.length - 1; i++) {
            for (int j = 0; j < eifValues.length - 1 - i; j++) {
                if (eifValues[j] > eifValues[j + 1]) {
                    int tempEIF = eifValues[j];
                    eifValues[j] = eifValues[j + 1];
                    eifValues[j + 1] = tempEIF;

                    Employee tempEmp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = tempEmp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Employee[] employees = new Employee[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter age of Employee " + (i + 1) + ": ");
            int age = scanner.nextInt();
            employees[i] = new Employee(age);
        }
        int[] eifValues = new int[5];
        for (int i = 0; i < employees.length; i++) {
            eifValues[i] = employees[i].calculateEIF();
        }

        sort(employees, eifValues);
        System.out.println("\nEmployees sorted by EIF values:");
        for (int i = 0; i < employees.length; i++) {
            System.out.println("Employee age: " + employees[i].age + ", EIF: " + eifValues[i]);
        }
        scanner.close();
    }
}