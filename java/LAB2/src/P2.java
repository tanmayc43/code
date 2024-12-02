import java.util.Scanner;

public class P2 {
    public static void main(String[] args) {
        Student a1 = new Student();
        Student a2 = new Student();
        System.out.println("Enter the details of the first student: ");
        a1.set();
        System.out.println("Enter the details of the second student: ");
        a2.set();

        a1.print_stud_details();
        a2.print_stud_details();

        if(a1.branch_change()){
            System.out.println("Branch Changed Successfully");
        }
        else{
            System.out.println("Branch not changed");
        }
        if(a2.branch_change()){
            System.out.println("Branch Changed Successfully");
        }
        else{
            System.out.println("Branch not changed");
        }

        a1.print_stud_details();
        a2.print_stud_details();




    }
}

class Student{
    int roll_number;
    String name;
    String branch;
    float CGPA;

    boolean branch_change(){
        if(this.branch.equals("CSE")){
            return false;
        }
        else{
            if(this.CGPA>9){
                this.branch = "CSE";
                return true;
            }
            else{
                return false;
            }
        }
    }

    void set(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of the student: ");
        this.name = sc.nextLine();
        System.out.println("Enter the roll number of the student: ");
        this.roll_number = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the branch of the student: ");
        this.branch = sc.nextLine();
        System.out.println("Enter the CGPA of the student: ");
        this.CGPA = sc.nextFloat();
    }

    void print_stud_details(){
        System.out.println("The details of the student are as follows: ");
        System.out.println(this.name);
        System.out.println(this.roll_number);
        System.out.println(this.branch);
        System.out.println(this.CGPA);
    }

}