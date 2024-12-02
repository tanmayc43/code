import java.util.Scanner;

class Student {
    private String name;
    private int rollNo;
    private double cgpa;
    public Teacher advisor;
    private String branch;

    public static String collegeCode;

    static {
        collegeCode = "iiitg";
    }

    public Student(String name, int rollNo, double cgpa, Teacher advisor, String branch) {
        this.name = name;
        this.rollNo = rollNo;
        this.cgpa = (cgpa >= 0 && cgpa <= 10) ? cgpa : 0.0;
        this.advisor = advisor;
        this.branch = branch;
    }

    public Student() {
        this.name = "";
        this.rollNo = 0;
        this.cgpa = 0.0;
        this.advisor = null;
        this.branch = "";
    }

    public void updateRecord(String name, double cgpa, String branch, Teacher advisor) {
        this.name = name;
        this.cgpa = (cgpa >= 0 && cgpa <= 10) ? cgpa : this.cgpa;
        this.branch = branch;
        this.advisor = advisor;
    }

    public void getDetails() {
        System.out.println("Name: " + name + ", Roll No: " + rollNo + ", CGPA: " + cgpa + ", Branch: " + branch + ", Advisor: " + (advisor != null ? advisor.name : "None"));
    }

    public Teacher getAdvisor() {
        return this.advisor;
    }

    public void setAdvisor(Teacher advisor) {
        this.advisor = advisor;
    }

    public int getRollNo() {
        return this.rollNo;
    }
}

class Teacher {
    public String name;
    public int empID;

    public Teacher(String name, int empID) {
        this.name = name;
        this.empID = empID;
    }

    public Teacher() {
        this.name = "";
        this.empID = 0;
    }

    public String toString() {
        return "Teacher Name: " + name + ", ID: " + empID;
    }
}

public class P1 {
    private static Student[] students = new Student[5];
    private static Teacher[] teachers = new Teacher[2];
    private static int studentCount = 0;
    private static int teacherCount = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add Student");
            System.out.println("2. Delete Student");
            System.out.println("3. Add Teacher");
            System.out.println("4. Delete Teacher");
            System.out.println("5. Update Student");
            System.out.println("6. Get Student Details");
            System.out.println("7. Get Advisor Details");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addStudent(sc);
                    break;
                case 2:
                    deleteStudent(sc);
                    break;
                case 3:
                    addTeacher(sc);
                    break;
                case 4:
                    deleteTeacher(sc);
                    break;
                case 5:
                    updateStudent(sc);
                    break;
                case 6:
                    getStudentDetails(sc);
                    break;
                case 7:
                    getAdvisorDetails(sc);
                    break;
                case 8:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice, try again.");
            }
        } while (choice != 8);

        sc.close();
    }

    private static void addStudent(Scanner sc) {
        if (studentCount >= 5) {
            System.out.println("Cannot add more students. Maximum capacity reached.");
            return;
        }
        if (teacherCount == 0) {
            System.out.println("Please add a teacher first.");
            return;
        }

        System.out.print("Enter student name: ");
        String name = sc.next();
        System.out.print("Enter roll number: ");
        int rollNo = sc.nextInt();
        double cgpa;
        do {
            System.out.print("Enter CGPA: ");
            cgpa = sc.nextDouble();
            if (cgpa < 0 || cgpa > 10) {
                System.out.println("Invalid CGPA! Please enter a value between 0 and 10.");
            }
        } while (cgpa < 0 || cgpa > 10);

        System.out.print("Enter branch: ");
        String branch = sc.next();

        System.out.println("Select teacher by ID:");
        for (int i = 0; i < teacherCount; i++) {
            System.out.println((i + 1) + ". " + teachers[i]);
        }
        int teacherChoice = sc.nextInt();
        Teacher advisor = null;
        for (int i = 0; i < teacherCount; i++) {
            if (teachers[i].empID == teacherChoice) {
                advisor = teachers[i];
                break;
            }
        }

        if (advisor == null) {
            System.out.println("Invalid teacher selected.");
            return;
        }

        students[studentCount] = new Student(name, rollNo, cgpa, advisor, branch);
        studentCount++;

        sortStudentsByRollNo();
        System.out.println("Student added successfully.");
    }

    private static void deleteStudent(Scanner sc) {
        if (studentCount == 0) {
            System.out.println("No students to delete.");
            return;
        }

        System.out.print("Enter roll number of student to delete: ");
        int rollNo = sc.nextInt();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                students[studentCount - 1] = null;
                studentCount--;
                System.out.println("Student deleted.");
                return;
            }
        }
        System.out.println("Student with roll number " + rollNo + " not found.");
    }

    private static void addTeacher(Scanner sc) {
        if (teacherCount >= 2) {
            System.out.println("Cannot add more teachers. Maximum capacity reached.");
            return;
        }

        System.out.print("Enter teacher name: ");
        String name = sc.next();
        System.out.print("Enter teacher ID: ");
        int empID = sc.nextInt();

        teachers[teacherCount] = new Teacher(name, empID);
        teacherCount++;
        System.out.println("Teacher added.");
    }

    private static void deleteTeacher(Scanner sc) {
        if (teacherCount == 0) {
            System.out.println("No teachers to delete.");
            return;
        }

        System.out.print("Enter teacher ID to delete: ");
        int empID = sc.nextInt();

        for (int i = 0; i < teacherCount; i++) {
            if (teachers[i].empID == empID) {
                for (int k = 0; k < studentCount; k++) {
                    if (students[k].getAdvisor() != null && students[k].getAdvisor().empID == empID) {
                        students[k].setAdvisor(null);
                    }
                }

                for (int j = i; j < teacherCount - 1; j++) {
                    teachers[j] = teachers[j + 1];
                }
                teachers[teacherCount - 1] = null;
                teacherCount--;
                System.out.println("Teacher deleted.");
                return;
            }
        }
        System.out.println("Teacher with ID " + empID + " not found.");
    }

    private static void updateStudent(Scanner sc) {
        System.out.print("Enter roll number of student to update: ");
        int rollNo = sc.nextInt();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                System.out.print("Enter new name: ");
                String name = sc.next();
                double cgpa;
                do {
                    System.out.print("Enter new CGPA: ");
                    cgpa = sc.nextDouble();
                    if (cgpa < 0 || cgpa > 10) {
                        System.out.println("Invalid CGPA! Please enter a value between 0 and 10.");
                    }
                } while (cgpa < 0 || cgpa > 10);

                System.out.print("Enter new branch: ");
                String branch = sc.next();

                System.out.println("Do you want to change the advisor? (yes/no)");
                String changeAdvisor = sc.next();
                Teacher advisor = students[i].getAdvisor();
                if (changeAdvisor.equalsIgnoreCase("yes")) {
                    System.out.println("Select new advisor by ID:");
                    for (int j = 0; j < teacherCount; j++) {
                        System.out.println((j + 1) + ". " + teachers[j]);
                    }
                    int teacherChoice = sc.nextInt();
                    for (int j = 0; j < teacherCount; j++) {
                        if (teachers[j].empID == teacherChoice) {
                            advisor = teachers[j];
                            break;
                        }
                    }
                }

                students[i].updateRecord(name, cgpa, branch, advisor);
                System.out.println("Student record updated.");
                return;
            }
        }
        System.out.println("Student with roll number " + rollNo + " not found.");
    }

    private static void getStudentDetails(Scanner sc) {
        System.out.print("Enter roll number of student: ");
        int rollNo = sc.nextInt();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                students[i].getDetails();
                return;
            }
        }
        System.out.println("Student with roll number " + rollNo + " not found.");
    }

    private static void getAdvisorDetails(Scanner sc) {
        System.out.print("Enter roll number of student: ");
        int rollNo = sc.nextInt();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                System.out.println(students[i].getAdvisor());
                return;
            }
        }
        System.out.println("Student with roll number " + rollNo + " not found.");
    }

    private static void sortStudentsByRollNo() {
        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = i + 1; j < studentCount; j++) {
                if (students[i].getRollNo() > students[j].getRollNo()) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }
}
