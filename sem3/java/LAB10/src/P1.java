class Person {
    int age;

    Person(int age) {
        this.age = age;
    }

    void eat() {
        System.out.println("Person is eating.");
    }

    void sleep() {
        System.out.println("Person is sleeping.");
    }
}


interface Driver {
    int driveCar();
    int driveBike();
}

interface Singer {
    void riyaz();
    int sing();
}

class Employee extends Person implements Driver, Singer {

    Employee(int age) {
        super(age);
    }

    @Override
    public int driveCar() {
        return age < 40 ? 10 : 0;
    }

    @Override
    public int driveBike() {
        return age < 40 ? 5 : 0;
    }

    @Override
    public int sing() {
        return age < 20 ? 15 : 0;
    }

    @Override
    public void riyaz() {
        System.out.println("Employee is doing riyaz");
    }

    public int officeWork() {
        return age < 40 ? 20 : 10;
    }

    public int calculateEIF() {
        return driveCar() + driveBike() + sing() + officeWork();
    }

}

public class P1 {
    public static void main(String[] args) {
        Employee emp = new Employee(25);

        Driver driver = emp;
        System.out.println("Driving car: " + driver.driveCar());
        System.out.println("Driving bike: " + driver.driveBike());

        Singer singer = emp;
        singer.riyaz();
        System.out.println("Singing: " + singer.sing());


    }
}
