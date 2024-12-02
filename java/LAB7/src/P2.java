class Shape {
    public double getArea() {
        return 0.0;
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }
}

public class P2 {
    public static void main(String[] args) {
        Shape shape = new Shape();
        System.out.println("Area of Shape: " + shape.getArea());

        Rectangle rectangle = new Rectangle(5.0, 3.0);
        System.out.println("Area of Rectangle: " + rectangle.getArea());
    }
}
