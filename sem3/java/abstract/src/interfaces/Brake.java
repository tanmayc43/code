package interfaces;

public interface Brake {
    // static interface methods should have a body
    // call via the interface name
    void brake();
    void start();
}

//nested interface possible
// nested one can be declared public private or protected
// standard is public or default only