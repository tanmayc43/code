import java.util.Scanner;

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {

        super(message);
    }
}

class InvalidPinException extends Exception {
    public InvalidPinException(String message) {
        super(message);
    }
}

class InvalidRollNumberException extends Exception {
    public InvalidRollNumberException(String message) {
        super(message);
    }
}

class InvalidEmployeeIDException extends Exception {
    public InvalidEmployeeIDException(String message) {
        super(message);
    }
}

class Person {
    String firstName, lastName, pan, addressPin;

    public Person(String firstName, String lastName, String pan, String addressPin) throws InvalidPinException {
        this.firstName = firstName;
        this.lastName = lastName;
        this.pan = pan;
        if (addressPin.length() != 6 || !addressPin.matches("\\d+")) {
            throw new InvalidPinException("PIN code must be exactly 6 digits.");
        }
        this.addressPin = addressPin;
    }
}

class Student extends Person {
    String emailID, rollNumber;

    public Student(String firstName, String lastName, String pan, String addressPin, String emailID, String rollNumber)
            throws InvalidEmailException, InvalidRollNumberException, InvalidPinException {
        super(firstName, lastName, pan, addressPin);
        if (!emailID.contains("@") || !emailID.contains(".")) {
            throw new InvalidEmailException("Email must contain '@' and a domain.");
        }
        String[] emailParts = emailID.split("@"); // imp
        if (emailParts.length != 2) {
            throw new InvalidEmailException("Invalid email format.");
        }
        String localPart = emailParts[0];
        if (!(localPart.contains("!") || localPart.contains("#") || localPart.contains("$") ||
                localPart.contains("%") || localPart.contains("&") || localPart.contains("*"))) {
            throw new InvalidEmailException("Email must contain a special character before '@'.");
        }
        if (!rollNumber.startsWith("stud") || rollNumber.length() != 9) {
            throw new InvalidRollNumberException("Roll number must start with 'stud' followed by 5 digits.");
        }
        this.emailID = emailID;
        this.rollNumber = rollNumber;
    }

    @Override
    public String toString() {
        return "Student [Name: " + firstName + " " + lastName + ", PAN: " + pan + ", PIN: " + addressPin +
                ", Email ID: " + emailID + ", Roll Number: " + rollNumber + "]";
    }
}

class Employee extends Person {
    String emailID, employeeID;

    public Employee(String firstName, String lastName, String pan, String addressPin, String emailID, String employeeID)
            throws InvalidEmailException, InvalidEmployeeIDException, InvalidPinException {
        super(firstName, lastName, pan, addressPin);
        if (!emailID.contains("@") || !emailID.contains(".")) {
            throw new InvalidEmailException("Email must contain '@' and a domain.");
        }
        String[] emailParts = emailID.split("@");
        if (emailParts.length != 2) {
            throw new InvalidEmailException("Invalid email format.");
        }
        String localPart = emailParts[0];
        if (!(localPart.contains("!") || localPart.contains("#") || localPart.contains("$") ||
                localPart.contains("%") || localPart.contains("&") || localPart.contains("*"))) {
            throw new InvalidEmailException("Email must contain a special character before '@'.");
        }
        if (!employeeID.startsWith("emp") || employeeID.length() != 6) {
            throw new InvalidEmployeeIDException("Employee ID must start with 'emp' followed by 3 digits.");
        }
        this.emailID = emailID;
        this.employeeID = employeeID;
    }

    @Override
    public String toString() {
        return "Employee [Name: " + firstName + " " + lastName + ", PAN: " + pan + ", PIN: " + addressPin +
                ", Email ID: " + emailID + ", Employee ID: " + employeeID + "]";
    }
}

public class P1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.println("Enter Student Details:");
            System.out.print("First Name: ");
            String firstName = scanner.next();
            System.out.print("Last Name: ");
            String lastName = scanner.next();
            System.out.print("PAN: ");
            String pan = scanner.next();
            System.out.print("Address PIN: ");
            String addressPin = scanner.next();
            System.out.print("Email ID: ");
            String emailID = scanner.next();
            System.out.print("Roll Number: ");
            String rollNumber = scanner.next();

            Student student = new Student(firstName, lastName, pan, addressPin, emailID, rollNumber);
            System.out.println("Student created successfully.");
            System.out.println(student);

            System.out.println("\nEnter Employee Details:");
            System.out.print("First Name: ");
            firstName = scanner.next();
            System.out.print("Last Name: ");
            lastName = scanner.next();
            System.out.print("PAN: ");
            pan = scanner.next();
            System.out.print("Address PIN: ");
            addressPin = scanner.next();
            System.out.print("Email ID: ");
            emailID = scanner.next();
            System.out.print("Employee ID: ");
            String employeeID = scanner.next();

            Employee employee = new Employee(firstName, lastName, pan, addressPin, emailID, employeeID);
            System.out.println("Employee created successfully.");
            System.out.println(employee);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
