class Faculty {
    String name;
    int empID;


    public Faculty(String name, int empID) {
        this.name = name;
        this.empID = empID;
    }

    public Faculty(Faculty f) {
        this.name = f.name;
        this.empID = f.empID;
    }
    @Override
    public String toString() {
        return "Faculty Name: " + name + ", EmpID: " + empID;
    }
}

class Student {
    String name;
    int rollNo;
    double cgpa;
    Faculty facultyAdvisor;
    String branch;
    String collegeID;

    public Student(String name, int rollNo, double cgpa, Faculty facultyAdvisor, String branch, String collegeID) {
        this.name = name;
        this.rollNo = rollNo;
        this.cgpa = cgpa;
        this.facultyAdvisor = facultyAdvisor;
        this.branch = branch;
        this.collegeID = collegeID;
    }

    public Student(Student s) {
        this.name = s.name;
        this.rollNo = s.rollNo;
        this.cgpa = s.cgpa;
        this.facultyAdvisor = new Faculty(s.facultyAdvisor);
        this.branch = s.branch;
        this.collegeID = s.collegeID;
    }

    public String getStudentDetails() {
        return "Name: " + name + ", RollNo: " + rollNo + ", CGPA: " + cgpa +
                ", Advisor: " + facultyAdvisor.toString() +
                ", Branch: " + branch + ", CollegeID: " + collegeID;
    }

    void changename(String name){
        this.name = name;
    }
}

public class DeepCopy {
    public static void main(String[] args) {
        Faculty advisor = new Faculty(" Dr. Aman", 101);

        Student student1 = new Student("hari", 123, 9.1, advisor, "Computer Science", "iiitg");

        Student student2 = new Student(student1);

        System.out.println("Before modifying faculty:");
        System.out.println(student1.getStudentDetails());
        System.out.println(student2.getStudentDetails());

        advisor.name = " Dr. Gagan";

        System.out.println("\nAfter modifying faculty:");
        System.out.println(student1.getStudentDetails());
        System.out.println(student2.getStudentDetails());
    }
}
