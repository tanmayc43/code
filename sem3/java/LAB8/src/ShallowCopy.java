class Fac {
    String name;
    int empID;

    public Fac(String name, int empID) {
        this.name = name;
        this.empID = empID;
    }

    @Override
    public String toString() {
        return "Faculty Name: " + name + ", EmpID: " + empID;
    }
}

class Stud {
    String name;
    int rollNo;
    double cgpa;
    Fac facultyAdvisor;
    String branch;
    String collegeID;


    public Stud(String name, int rollNo, double cgpa, Fac facultyAdvisor, String branch, String collegeID) {
        this.name = name;
        this.rollNo = rollNo;
        this.cgpa = cgpa;
        this.facultyAdvisor = facultyAdvisor;
        this.branch = branch;
        this.collegeID = collegeID;
    }


    public Stud(Stud s) {
        this.name = s.name;
        this.rollNo = s.rollNo;
        this.cgpa = s.cgpa;
        this.facultyAdvisor = s.facultyAdvisor;
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

public class ShallowCopy {
    public static void main(String[] args) {
        Fac advisor = new Fac("Dr. Aman", 101);
        Stud student1 = new Stud("hari", 123, 9.1, advisor, "Computer Science", "iiitg");

        Stud student2 = new Stud(student1);

        System.out.println("Before modifying faculty:");
        System.out.println(student1.getStudentDetails());
        System.out.println(student2.getStudentDetails());

        advisor.name = "Dr. Gagan";
        student1.changename("newname");
        System.out.println("\nAfter modifying faculty:");
        System.out.println(student1.getStudentDetails());
        System.out.println(student2.getStudentDetails());
    }
}
