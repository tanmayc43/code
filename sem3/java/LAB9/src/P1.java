import java.util.*;

class Student {
    String name;
    int roll;
    String birthyear;

    Student(String name, int roll, String birthyear) {
        this.name = name;
        this.roll = roll;
        this.birthyear = birthyear;
    }

    String getFirstName() {
        return name.split(" ")[0];
    }

    String getTitle() {
        return name.split(" ")[1];
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Roll: " + roll + ", Birthyear: " + birthyear;
    }
}

class FirstNameComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return s1.getFirstName().compareTo(s2.getFirstName());
    }
}

class TitleComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return s1.getTitle().compareTo(s2.getTitle());
    }
}

class RollNumberDescendingComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return Integer.compare(s2.roll, s1.roll);
    }
}

class BirthYearComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return s1.birthyear.compareTo(s2.birthyear);
    }
}

public class P1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Student> students = new ArrayList<>();

        System.out.println("Enter the number of students: ");
        int gg = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Enter details for " + gg + " students:");
        for (int i = 0; i < gg; i++) {
            System.out.print("Enter name (FirstName Title): ");
            String name = scanner.nextLine();
            System.out.print("Enter roll number: ");
            int roll = scanner.nextInt();
            System.out.print("Enter birth year: ");
            String birthyear = scanner.next();
            scanner.nextLine();

            students.add(new Student(name, roll, birthyear));
        }

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Sort by First Name");
            System.out.println("2. Sort by Title");
            System.out.println("3. Sort by Roll Number (Descending)");
            System.out.println("4. Sort by Birth year (Ascending)");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Collections.sort(students, new FirstNameComparator());
                    System.out.println("\nSorted by First Name:");
                    students.forEach(System.out::println);
                    break;
                case 2:
                    Collections.sort(students, new TitleComparator());
                    System.out.println("\nSorted by Title:");
                    students.forEach(System.out::println);
                    break;
                case 3:
                    Collections.sort(students, new RollNumberDescendingComparator());
                    System.out.println("\nSorted by Roll Number (Descending):");
                    students.forEach(System.out::println);
                    break;
                case 4:
                    Collections.sort(students, new BirthYearComparator());
                    System.out.println("\nSorted by Birth year (Ascending):");
                    students.forEach(System.out::println);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
