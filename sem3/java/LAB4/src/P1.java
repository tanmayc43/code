import java.util.Scanner;
public class P1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Account[] accounts = new Account[10];
        int currentAccountIndex = 0;
        while (true) {
            System.out.println("\n--- Banking Application Menu ---");
            System.out.println("1. Create Account");
            System.out.println("2. Update Details");
            System.out.println("3. Get Details");
            System.out.println("4. Deposit");
            System.out.println("5. Withdraw");
            System.out.println("6. Display Total Accounts Created");
            System.out.println("7. Compare Two Accounts");
            System.out.println("8. Exit");
            System.out.print("Choose an option: ");
            int option = sc.nextInt();

            switch (option) {
                case 1:
                    if (currentAccountIndex < accounts.length) {
                        accounts[currentAccountIndex] = new Account();
                        accounts[currentAccountIndex].createAccount();
                        currentAccountIndex+=1;
                    }
                    else System.out.println("Account limit reached.");
                    break;
                case 2:
                    System.out.print("Enter Account Number to Update: ");
                    int updateAccNo = sc.nextInt();
                    boolean foundUpdate = false;
                    for (Account acc : accounts) {
                        if (acc != null && acc.getDetails(updateAccNo) != null) {
                            acc.updateDetails(updateAccNo);
                            foundUpdate = true;
                            break;
                        }
                    }
                    if (!foundUpdate) System.out.println("Account not found.");
                    break;
                case 3:
                    System.out.print("Enter Account Number to Get Details: ");
                    int getAccNo = sc.nextInt();
                    boolean foundGet = false;
                    for (Account acc : accounts) {
                        if (acc != null && acc.getDetails(getAccNo) != null) {
                            System.out.println(acc.getDetails(getAccNo));
                            foundGet = true;
                            break;
                        }
                    }
                    if (!foundGet) System.out.println("Account not found.");
                    break;
                case 4:
                    System.out.print("Enter Account Number to Deposit: ");
                    int depositAccNo = sc.nextInt();
                    System.out.print("Enter Amount to Deposit: ");
                    float depositAmount = sc.nextFloat();
                    boolean foundDeposit = false;
                    for (Account acc : accounts) {
                        if (acc != null && acc.getDetails(depositAccNo) != null) {
                            acc.deposit(depositAccNo, depositAmount);
                            foundDeposit = true;
                            break;
                        }
                    }
                    if (!foundDeposit) System.out.println("Account not found.");
                    break;
                case 5:
                    System.out.print("Enter Account Number to Withdraw: ");
                    int withdrawAccNo = sc.nextInt();
                    System.out.print("Enter Amount to Withdraw: ");
                    float withdrawAmount = sc.nextFloat();
                    boolean foundWithdraw = false;
                    for (Account acc : accounts) {
                        if (acc != null && acc.getDetails(withdrawAccNo) != null) {
                            acc.withdraw(withdrawAccNo, withdrawAmount);
                            foundWithdraw = true;
                            break;
                        }
                    }
                    if (!foundWithdraw) System.out.println("Account not found.");
                    break;
                case 6:
                    System.out.println("Total accounts created: " + Account.totalAccount());
                    break;
                case 7:
                    System.out.print("Enter Account Number 1 to Compare: ");
                    int compareAccNo1 = sc.nextInt();
                    System.out.print("Enter Account Number 2 to Compare: ");
                    int compareAccNo2 = sc.nextInt();
                    Account account1 = null;
                    Account account2 = null;
                    for (Account acc : accounts) {
                        if (acc != null) {
                            if (acc.getDetails(compareAccNo1) != null) account1 = acc;
                            if (acc.getDetails(compareAccNo2) != null) account2 = acc;
                        }
                    }
                    if (account1 != null && account2 != null) Account.compare(account1, account2);
                    else System.out.println("One or both accounts not found.");
                    break;
                case 8:
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid option. Please choose again.");
            }
        }
    }
}

class Account {
    private int accountNumber;
    private String accountType;
    private String serviceBranchIFSC;
    private float minimumBalance;
    private float availableBalance;
    private int customerID;
    private String customerName;
    private static int totalAccountCreated = 0;

    public Account() {
        totalAccountCreated+=1;
    }

    public void setDetails(int accountNumber, String accountType, String serviceBranchIFSC, float minimumBalance, float availableBalance, int customerID, String customerName) {
        this.accountNumber = accountNumber;
        this.accountType = accountType;
        this.serviceBranchIFSC = serviceBranchIFSC;
        this.minimumBalance = minimumBalance;
        this.availableBalance = availableBalance;
        this.customerID = customerID;
        this.customerName = customerName;
    }

    public void createAccount() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Account Number: ");
        this.accountNumber = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Account Type (e.g., Savings, Checking): ");
        this.accountType = sc.nextLine();
        System.out.print("Enter Branch IFSC Code: ");
        this.serviceBranchIFSC = sc.nextLine();
        System.out.print("Enter Minimum Balance: ");
        this.minimumBalance = sc.nextFloat();
        System.out.print("Enter Initial Deposit (Available Balance): ");
        this.availableBalance = sc.nextFloat();
        System.out.print("Enter Customer ID: ");
        this.customerID = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Customer Name: ");
        this.customerName = sc.nextLine();
        System.out.println("Account created successfully!");
    }

    public String getDetails(int accountNo) {
        if (this.accountNumber == accountNo) {
            return "Account Number: " + accountNumber + "\nAccount Type: " + accountType + "\nBranch IFSC: " + serviceBranchIFSC + "\nMinimum Balance: " + minimumBalance + "\nAvailable Balance: " + availableBalance + "\nCustomer ID: " + customerID + "\nCustomer Name: " + customerName;
        }
        else return "Account not found.";
    }

    public void updateDetails(int accountNo) {
        if (this.accountNumber == accountNo) {
            Scanner sc = new Scanner(System.in);
            System.out.println("1. Update Account Type");
            System.out.println("2. Update Branch IFSC");
            System.out.println("3. Update Minimum Balance");
            System.out.println("4. Update Customer ID");
            System.out.println("5. Update Customer Name");
            System.out.print("Choose an option to update: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter new Account Type: ");
                    this.accountType = sc.nextLine();
                    break;
                case 2:
                    System.out.print("Enter new Branch IFSC: ");
                    this.serviceBranchIFSC = sc.nextLine();
                    break;
                case 3:
                    System.out.print("Enter new Minimum Balance: ");
                    this.minimumBalance = sc.nextFloat();
                    break;
                case 4:
                    System.out.print("Enter new Customer ID: ");
                    this.customerID = sc.nextInt();
                    break;
                case 5:
                    System.out.print("Enter new Customer Name: ");
                    this.customerName = sc.nextLine();
                    break;
                default:
                    System.out.println("Invalid option.");
            }
        }
        else System.out.println("Account not found.");
    }

    public float getBalance(int accountNo) {
        if (this.accountNumber == accountNo) {
            return availableBalance;
        }
        else {
            System.out.println("Account not found.");
            return -1;
        }
    }

    public void deposit(int accountNo, float amount) {
        if (this.accountNumber == accountNo) {
            this.availableBalance += amount;
            System.out.println("Amount deposited successfully.");
        }
        else System.out.println("Account not found.");
    }

    public void withdraw(int accountNo, float amount) {
        if (this.accountNumber == accountNo) {
            if (this.availableBalance - amount >= this.minimumBalance) {
                this.availableBalance -= amount;
                System.out.println("Amount withdrawn successfully.");
            } else {
                System.out.println("Insufficient balance.");
            }
        }
        else System.out.println("Account not found.");
    }

    public static int totalAccount() {
        return totalAccountCreated;
    }

    public static void compare(Account account1, Account account2) {
        if (account1.availableBalance > account2.availableBalance)System.out.println("Account 1 has a higher available balance.");
        else if (account1.availableBalance < account2.availableBalance) System.out.println("Account 2 has a higher available balance.");
        else System.out.println("Both accounts have the same available balance.");
    }
}
