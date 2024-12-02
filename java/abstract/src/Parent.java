public abstract class Parent{

    int age;

    Parent(int age){
        this.age = age;
    }
    abstract void career(String name);
    abstract void partner(String name, int age);

    static void kimi(){
        System.out.println("nukeeeeeeeeeeeeeeee");
    }

    void normal(int magic){
        System.out.println("The magic number is " + magic + " something");
    }
}