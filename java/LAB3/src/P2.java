import java.util.Scanner;
class Book {
    int bookid;
    String booktitle;
    int yearofpub;
    String authname;
    String publishername;
    int availablecopies;
    int totalcopies;

    Book() {
        this.bookid = -1;
        this.booktitle = "";
        this.yearofpub = 0;
        this.authname = "";
        this.publishername = "";
        this.availablecopies = 0;
        this.totalcopies = 0;
    }

    void setDetails(int bookid, String booktitle, int yearofpub, String authname, String publishername, int availablecopies, int totalcopies) {
        this.bookid = bookid;
        this.booktitle = booktitle;
        this.yearofpub = yearofpub;
        this.authname = authname;
        this.publishername = publishername;
        this.availablecopies = availablecopies;
        this.totalcopies = totalcopies;
    }

    void issueBook() {
        if (this.availablecopies > 0) {
            this.availablecopies--;
            System.out.println("BOOK ISSUED SUCCESSFULLY");
        } else {
            System.out.println("No copies available");
        }
    }

    void returnBook() {
        if (this.availablecopies < this.totalcopies) {
            this.availablecopies++;
            System.out.println("BOOK RETURNED SUCCESSFULLY");
        } else {
            System.out.println("All copies are already available");
        }
    }

    void getDetails() {
        System.out.println("BOOK ID: " + this.bookid);
        System.out.println("BOOK TITLE: " + this.booktitle);
        System.out.println("YEAR OF PUBLICATION: " + this.yearofpub);
        System.out.println("AUTHOR NAME: " + this.authname);
        System.out.println("PUBLISHER NAME: " + this.publishername);
        System.out.println("AVAILABLE COPIES: " + this.availablecopies);
        System.out.println("TOTAL COPIES: " + this.totalcopies);
    }
}

public class P2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of books:");
        int n = sc.nextInt();
        Book arr[] = new Book[n];

        for (int i = 0; i < n; i++) arr[i] = new Book();
        while (true) {
            System.out.println("ENTER \n 1 TO SET DETAILS \n 2 TO GET DETAILS \n 3 TO ISSUE A BOOK \n 4 TO RETURN A BOOK \n 5 TO TERMINATE THE PROGRAM");
            int option = sc.nextInt();

            if (option == 1) {
                int bookid;
                while (true) {
                    System.out.println("Enter book ID (0 to " + (n - 1) + "): ");
                    bookid = sc.nextInt();
                    boolean idExists = false;

                    for (int i = 0; i < n; i++) {
                        if (arr[i].bookid == bookid) {
                            idExists = true;
                            break;
                        }
                    }

                    if (!idExists) break;
                    else System.out.println("Book ID already exists. Please enter a different book ID.");
                }

                System.out.println("Enter book title: ");
                sc.nextLine();
                String booktitle = sc.nextLine();
                System.out.println("Enter year of publication: ");
                int yearofpub = sc.nextInt();
                System.out.println("Enter author name: ");
                sc.nextLine();
                String authname = sc.nextLine();
                System.out.println("Enter publisher name: ");
                String publishername = sc.nextLine();
                System.out.println("Enter total copies: ");
                int totalcopies = sc.nextInt();
                System.out.println("Enter available copies: ");
                int availablecopies = sc.nextInt();

                for (int i = 0; i < n; i++) {
                    if (arr[i].bookid == -1) {
                        arr[i].setDetails(bookid, booktitle, yearofpub, authname, publishername, availablecopies, totalcopies);
                        break;
                    }
                }
            }
            else if (option == 2) {
                System.out.println("Enter the book ID to get details of: ");
                int i = sc.nextInt();
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (arr[j].bookid == i) {
                        arr[j].getDetails();
                        found = true;
                        break;
                    }
                }
                if (!found) System.out.println("Book ID not found.");
            }
            else if (option == 3) {
                System.out.println("Enter the book ID to issue: ");
                int i = sc.nextInt();
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (arr[j].bookid == i) {
                        arr[j].issueBook();
                        found = true;
                        break;
                    }
                }
                if (!found) System.out.println("Book ID not found.");
            }
            else if (option == 4) {
                System.out.println("Enter the book ID to return: ");
                int i = sc.nextInt();
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (arr[j].bookid == i) {
                        arr[j].returnBook();
                        found = true;
                        break;
                    }
                }
                if (!found) System.out.println("Book ID not found.");
            }
            else if (option == 5) break;
            else System.out.println("Invalid option.");
        }
        sc.close();
    }
}
