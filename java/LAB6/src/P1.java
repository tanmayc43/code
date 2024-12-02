import java.util.Scanner;

class Person {
    protected String name;
    protected int age;

    public Person() {}

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void getDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Faculty extends Person {
    private int empID;

    public Faculty(String name, int age, int empID) {
        super(name, age);
        this.empID = empID;
    }

    @Override
    public void getDetails() {
        super.getDetails();
        System.out.println("Emp ID: " + empID);
    }

    public int getEmpID() {
        return empID;
    }
}

class Student extends Person {
    private int rollNo;
    private double cgpa;
    private String branch;
    private String collegeID;
    Faculty facultyAdvisor;

    public Student(String name, int age, int rollNo, double cgpa, String branch, String collegeID) {
        super(name, age);
        this.rollNo = rollNo;
        this.cgpa = cgpa;
        this.branch = branch;
        this.collegeID = collegeID;
        this.facultyAdvisor = null;
    }

    public Student(String name, int age, int rollNo, double cgpa, String branch, String collegeID, Faculty facultyAdvisor) {
        this(name, age, rollNo, cgpa, branch, collegeID);
        this.facultyAdvisor = facultyAdvisor;
    }

    @Override
    public void getDetails() {
        super.getDetails();
        System.out.println("Roll No: " + rollNo);
        System.out.println("CGPA: " + cgpa);
        System.out.println("Branch: " + branch);
        System.out.println("College ID: " + collegeID);
        if (facultyAdvisor != null) {
            System.out.println("Advisor: " + facultyAdvisor.name);
        }
    }

    public Faculty getAdvisor() {
        return facultyAdvisor;
    }

    public int getRollNo() {
        return rollNo;
    }
}

public class P1 {
    private static Person[] people = new Person[10];
    private static int currentCount = 0;
    private static int studentCount = 0;
    private static int facultyCount = 0;

    public static void addPerson(Person person) {
        if (currentCount < people.length) {
            people[currentCount++] = person;
            if (person instanceof Student) {
                studentCount++;
            } else if (person instanceof Faculty) {
                facultyCount++;
            }
            System.out.println("Person added successfully.");
        } else {
            System.out.println("Error: Maximum number of people reached.");
        }
    }

    public static void deletePerson(String name) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i].name.equals(name)) {
                if (people[i] instanceof Student) {
                    studentCount--;
                } else if (people[i] instanceof Faculty) {
                    deleteFaculty(((Faculty) people[i]).getEmpID());
                    facultyCount--;
                }
                people[i] = people[currentCount - 1];
                people[currentCount - 1] = null;
                currentCount--;
                System.out.println("Person deleted successfully.");
                return;
            }
        }
        System.out.println("Error: Person not found.");
    }

    public static void deleteFaculty(int empID) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i] instanceof Faculty) {
                Faculty faculty = (Faculty) people[i];
                if (faculty.getEmpID() == empID) {
                    for (int j = 0; j < currentCount; j++) {
                        if (people[j] instanceof Student) {
                            Student student = (Student) people[j];
                            if (student.getAdvisor() != null && student.getAdvisor().getEmpID() == empID) {
                                student.facultyAdvisor = null;
                                System.out.println("Removed advisor for student: " + student.name);
                            }
                        }
                    }
                    people[i] = people[currentCount - 1];
                    people[currentCount - 1] = null;
                    currentCount--;
                    System.out.println("Faculty deleted successfully.");
                    return;
                }
            }
        }
        System.out.println("Error: Faculty not found.");
    }


    public static void deleteStudent(int rollNo) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i] instanceof Student) {
                Student student = (Student) people[i];
                if (student.getRollNo() == rollNo) {
                    people[i] = people[currentCount - 1];
                    people[currentCount - 1] = null;
                    currentCount--;
                    studentCount--;
                    System.out.println("Student deleted successfully.");
                    return;
                }
            }
        }
        System.out.println("Error: Student not found.");
    }

    public static void getPersonDetails(String name) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i].name.equals(name)) {
                people[i].getDetails();
                return;
            }
        }
        System.out.println("Error: Person not found.");
    }

    public static void getStudentDetails(int rollNo) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i] instanceof Student) {
                Student student = (Student) people[i];
                if (student.getRollNo() == rollNo) {
                    student.getDetails();
                    return;
                }
            }
        }
        System.out.println("Error: Student not found.");
    }

    public static void getAdvisorDetails(int rollNo) {
        for (int i = 0; i < currentCount; i++) {
            if (people[i] instanceof Student) {
                Student student = (Student) people[i];
                if (student.getRollNo() == rollNo && student.getAdvisor() != null) {
                    student.getAdvisor().getDetails();
                    return;
                }
            }
        }
        System.out.println("Error: Student or advisor not found.");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\n--- College System Menu ---");
            System.out.println("1) Add Student");
            System.out.println("2) Delete Student");
            System.out.println("3) Add Faculty");
            System.out.println("4) Delete Faculty");
            System.out.println("5) Add Person");
            System.out.println("6) Delete Person");
            System.out.println("7) Get Student Details");
            System.out.println("8) Get Advisor Details");
            System.out.println("9) Get Person Details");
            System.out.println("10) Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    if (studentCount < 5) {
                        System.out.print("Enter student name: ");
                        String studentName = scanner.nextLine();
                        System.out.print("Enter age: ");
                        int studentAge = scanner.nextInt();
                        System.out.print("Enter roll no: ");
                        int rollNo = scanner.nextInt();
                        System.out.print("Enter CGPA: ");
                        double cgpa = scanner.nextDouble();
                        while(cgpa>10){
                            System.out.println("cgpa cant be more than 10");
                            cgpa = scanner.nextDouble();
                        }
                        scanner.nextLine();
                        System.out.print("Enter branch: ");
                        String branch = scanner.nextLine();
                        System.out.print("Enter college ID: ");
                        String collegeID = scanner.nextLine();

                        System.out.print("Assign faculty advisor? (y/n): ");
                        char assignAdvisor = scanner.nextLine().charAt(0);
                        if (assignAdvisor == 'y') {
                            System.out.print("Enter faculty empID: ");
                            int empID = scanner.nextInt();
                            Faculty advisor = null;
                            for (int i = 0; i < currentCount; i++) {
                                if (people[i] instanceof Faculty) {
                                    Faculty faculty = (Faculty) people[i];
                                    if (faculty.getEmpID() == empID) {
                                        advisor = faculty;
                                        break;
                                    }
                                }
                            }
                            if (advisor != null) {
                                Student studentWithAdvisor = new Student(studentName, studentAge, rollNo, cgpa, branch, collegeID, advisor);
                                addPerson(studentWithAdvisor);
                            } else {
                                System.out.println("Error: Faculty advisor not found.");
                            }
                        } else {
                            Student student = new Student(studentName, studentAge, rollNo, cgpa, branch, collegeID);
                            addPerson(student);
                        }
                    } else {
                        System.out.println("Error: Maximum number of students reached.");
                    }
                    break;

                case 2:
                    System.out.print("Enter student roll no to delete: ");
                    int rollToDelete = scanner.nextInt();
                    deleteStudent(rollToDelete);
                    break;

                case 3:
                    if (facultyCount < 2) {
                        System.out.print("Enter faculty name: ");
                        String facultyName = scanner.nextLine();
                        System.out.print("Enter age: ");
                        int facultyAge = scanner.nextInt();
                        System.out.print("Enter emp ID: ");
                        int facultyEmpID = scanner.nextInt();
                        Faculty faculty = new Faculty(facultyName, facultyAge, facultyEmpID);
                        addPerson(faculty);
                    } else {
                        System.out.println("Error: Maximum number of faculty reached.");
                    }
                    break;

                case 4:
                    System.out.print("Enter faculty empID to delete: ");
                    int empIDToDelete = scanner.nextInt();
                    deleteFaculty(empIDToDelete);
                    break;

                case 5:
                    System.out.print("Enter person name: ");
                    String personName = scanner.nextLine();
                    System.out.print("Enter age: ");
                    int personAge = scanner.nextInt();
                    Person person = new Person(personName, personAge);
                    addPerson(person);
                    break;

                case 6:
                    System.out.print("Enter person name to delete: ");
                    String nameToDelete = scanner.nextLine();
                    deletePerson(nameToDelete);
                    break;

                case 7:
                    System.out.print("Enter student roll no to get details: ");
                    int rollForDetails = scanner.nextInt();
                    getStudentDetails(rollForDetails);
                    break;

                case 8:
                    System.out.print("Enter student roll no to get advisor details: ");
                    int rollForAdvisor = scanner.nextInt();
                    getAdvisorDetails(rollForAdvisor);
                    break;

                case 9:
                    System.out.print("Enter person name to get details: ");
                    String nameForDetails = scanner.nextLine();
                    getPersonDetails(nameForDetails);
                    break;

                case 10:
                    running = false;
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
        scanner.close();
    }
}
