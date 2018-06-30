import java.util.*;

public class Test {
    public static void main(String[] args)
    {
        System.out.print("hello");
        System.out.print(computeArea(1));

        // ArrayList: dynamically resizing array
        ArrayList<String> myArr = new ArrayList<String>();
        myArr.add("one");
        myArr.add("two");
        System.out.println(myArr.get(0));

        // Vector: synchronized ArrayList
        Vector<String> myVect = new Vector<String>();
        myVect.add("one");
        myVect.add("two");
        System.out.println(myVect.get(0));

        // LinkedList: linked-list
        LinkedList<String> myLinkedList = new LinkedList<String>();
        myLinkedList.add("two");
        myLinkedList.add("one");
        Iterator<String> iter = myLinkedList.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
        }

        // HashMap: hashtable
        HashMap<String, String> map = new HashMap<String, String>();
        map.put("one", "uno");
        map.put("two", "dos");
        System.out.println(map.get("one"));
    }
    // Overloading: two methods have the same name but different type args
    public static double computeArea(int c)
    {
        return 1.1;
    }
    public static double computeArea(char c)
    {
        return 1.1;
    }
}
/*
// Overriding: method shares the same name and function signature as another method in its super class
public abstract class Shape {
    public void printMe()
    {
        System.out.println("I am a shape.");
    }
    public abstract double computeArea();
}

public class Circle extends Shape
 {
     private double rad = 5;
     public void printMe()
     {
         System.out.println("I am a circle");
     }
     public double computeArea()
     {
         return rad * rad * 3.15;
     }
 }

public class Ambiguous extends Shape {
    private double area = 10;
    public double computeArea()
    {
        return area;
    }
}

public class IntroductionOverriding
{
    public static void main(String[] args)
    {
        Shape[] shapes = new Shape[2];
        Circle circle = new Circle();
        Ambiguous ambiguous = new Ambiguous();

        shapes[0] = circle;
        shapes[1] = ambiguous;

        for (Shape s : shapes) {
            s.printMe();
            System.out.println(s.computeArea());
        }
    }
}
*/
