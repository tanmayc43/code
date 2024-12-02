import java.util.ArrayList;
import java.util.Scanner;

class InvalidUserException extends Exception {
    InvalidUserException(String message) {
        super(message);
    }
}

abstract class User {
    public int userid;
    public String name;
    public String borrowedbook;
    public String booktype;
    public int issuemonthnum;

    User(int userid, String name) {
        this.userid = userid;
        this.name = name;
        this.borrowedbook = "";
        this.booktype = "";
        this.issuemonthnum = 0;
    }

    abstract void issuebook(String title, int issuemonthnum, ArrayList<Book> book);
    abstract void returnbook(String title, int returnmonthnum, ArrayList<Book> book);
    abstract int calcfine(int returnmonthnum, int issuemonthnum);

    @Override
    public String toString() {
        return "UserId: " + userid + ", Name: " + name + ", BorrowedBook: " + borrowedbook
                + ", BookType: " + booktype + ", IssueMonthNum: " + issuemonthnum;
    }
}

class StudentUser extends User {
    public String studentroll;

    StudentUser(int userid, String name, String studentroll) throws InvalidUserException {
        super(userid, name);
        if (userid % 2 == 1) throw new InvalidUserException("STUDENT USER ID SHOULD BE EVEN");
        this.studentroll = studentroll;
    }

    @Override
    void issuebook(String title, int issuemonthnum, ArrayList<Book> book) {
        String x1 = "";
        int gg = -1;
        for (int i = 0; i < book.size(); i++) {
            if (book.get(i).title.equals(title)) {
                x1 = book.get(i).type;
                gg = i;
                break;
            }
        }
        if (x1.equals("")) System.out.println("Book not found");
        else if (book.get(gg).availablecopies <= 0) System.out.println("No copies available");
        else {
            this.booktype = x1;
            this.borrowedbook = title;
            this.issuemonthnum = issuemonthnum;
            book.get(gg).availablecopies = book.get(gg).availablecopies - 1;
        }
    }

    @Override
    void returnbook(String title, int returnmonthnum, ArrayList<Book> book) {
        int fine = this.calcfine(returnmonthnum, this.issuemonthnum);

        this.issuemonthnum = 0;
        this.booktype = "";
        this.borrowedbook = "";

        int gg = -1;
        for (int i = 0; i < book.size(); i++) {
            if (book.get(i).title.equals(title)) {
                gg = i;
                break;
            }
        }
        book.get(gg).availablecopies = book.get(gg).availablecopies + 1;

        System.out.println("The fine is : " + fine);
    }

    @Override
    int calcfine(int returnmonthnum, int issuemonthnum) {
        int gap = returnmonthnum - issuemonthnum;
        if (gap > 3) {
            return gap * 2000;
        }
        return 0;
    }
}

class FacultyUser extends User {
    public String empid;

    FacultyUser(int userid, String name, String empid) {
        super(userid, name);
        try {
            if(userid % 2 == 0)  throw new InvalidUserException("EMPLOYEE USER ID SHOULD BE ODD");

        } catch (InvalidUserException e) {
            e.getMessage();
        }


    }

    @Override
    void issuebook(String title, int issuemonthnum, ArrayList<Book> book) {
        String x1 = "";
        int gg = -1;
        for (int i = 0; i < book.size(); i++) {
            if (book.get(i).title.equals(title)) {
                x1 = book.get(i).type;
                gg = i;
                break;
            }
        }
        if (x1.equals("")) System.out.println("Book not found");
        else if (book.get(gg).availablecopies <= 0) System.out.println("No copies available");
        else {
            this.booktype = x1;
            this.borrowedbook = title;
            this.issuemonthnum = issuemonthnum;
            book.get(gg).availablecopies = book.get(gg).availablecopies - 1;
        }
    }

    @Override
    void returnbook(String title, int returnmonthnum, ArrayList<Book> book) {
        int fine = this.calcfine(returnmonthnum, this.issuemonthnum);
        this.issuemonthnum = 0;
        this.booktype = "";
        this.borrowedbook = "";

        int gg = -1;
        for (int i = 0; i < book.size(); i++) {
            if (book.get(i).title.equals(title)) {
                gg = i;
                break;
            }
        }
        book.get(gg).availablecopies = book.get(gg).availablecopies + 1;
        System.out.println("The fine is  : " + fine);
    }

    @Override
    int calcfine(int returnmonthnum, int issuemonthnum) {
        int gap = returnmonthnum - issuemonthnum;
        if (gap > 5) {
            return gap * 5000;
        }
        return 0;
    }
}

class Book {
    public String title;
    public String type;
    public int availablecopies;

    Book(String title, String type) {
        this.title = title;
        this.type = type;
        this.availablecopies = 5;
    }

    @Override
    public String toString() {
        return "Title: " + title + ", Type: " + type + ", AvailableCopies: " + availablecopies;
    }
}

public class P1{
    public static void main(String[] args) throws InvalidUserException {
        ArrayList<User> users = new ArrayList<>();
        ArrayList<Book> books = new ArrayList<>();

        users.add(new StudentUser(1, "Tanmay", "226"));
        users.add(new StudentUser(4, "Shourya", "227"));
        users.add(new StudentUser(6, "Tanishk", "228"));
        users.add(new StudentUser(8, "Soumil", "229"));
        users.add(new StudentUser(10, "Pratap", "230"));

        users.add(new FacultyUser(1, "Mr. Arijit", "emp1"));
        users.add(new FacultyUser(3, "Mr. Sanjay", "emp2"));
        users.add(new FacultyUser(5, "Mr. Kaustuv", "emp3"));
        users.add(new FacultyUser(7, "Mr. Hari", "emp4"));
        users.add(new FacultyUser(9, "Mr. Gagan", "emp5"));

        books.add(new Book("Computer Organization", "Text"));
        books.add(new Book("Gemba Kaizen", "Non-text"));
        books.add(new Book("Let us C", "Text"));
        books.add(new Book("Operating Systems", "Text"));
        books.add(new Book("The Alchemist", "Non-text"));

        displayRecords(users, books);

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter new faculty details ( name,userid, empId):");
        String newName = scanner.nextLine();
        int newUserId = scanner.nextInt();
        String newEmpId = scanner.next();
        FacultyUser newFaculty = new FacultyUser(newUserId, newName, newEmpId);
        users.add(newFaculty);
        System.out.println("Newly added faculty record:");
        System.out.println(newFaculty);

        System.out.println("Enter user id, book title, and issue month to issue a book:");
        int userId = scanner.nextInt();
        scanner.nextLine();
        String bookTitle = scanner.nextLine();

        int issueMonth = scanner.nextInt();
        issueBook(users, books, userId, bookTitle, issueMonth);

        System.out.println("Enter return month:");
        int returnMonth = scanner.nextInt();
        returnBook(users, books, userId, bookTitle, returnMonth);

        scanner.close();
    }

    static void displayRecords(ArrayList<User> users, ArrayList<Book> books) {
        System.out.println("record of users:");
        users.forEach(System.out::println);
        System.out.println("\nbooks;");
        books.forEach(System.out::println);
    }

    static void issueBook(ArrayList<User> users, ArrayList<Book> books, int userId, String bookTitle, int issueMonth) {
        User user = finduserbyid(users, userId);
        Book book = findbookbytitle(books, bookTitle);
        if (user != null && book != null && book.availablecopies > 0) {
            user.issuebook(bookTitle, issueMonth, books);
            System.out.println("\nAfter issuing, the updated User and Book Records are as follows:");
            displayRecords(users, books);
        } else {
            System.out.println("either user or book not found; or there are no copies available.");
        }
    }

    static void returnBook(ArrayList<User> users, ArrayList<Book> books, int userId, String bookTitle, int returnMonth) {
        User user = finduserbyid(users, userId);
        Book book = findbookbytitle(books, bookTitle);
        if (user != null && book != null) {
            user.returnbook(bookTitle, returnMonth, books);
            System.out.println("\nAfter returning, the updated User and Book Records are as follows:");
            displayRecords(users, books);
        } else {
            System.out.println("either user or book not found");
        }
    }

    static User finduserbyid(ArrayList<User> users, int userId) {
        for (User user : users) {
            if (user.userid == userId) {
                return user;
            }
        }
        return null;
    }

    static Book findbookbytitle(ArrayList<Book> books, String bookTitle) {
        for (Book book : books) {
            if (book.title.equals(bookTitle)) {
                return book;
            }
        }
        return null;
    }



}

