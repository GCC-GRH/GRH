import java.util.*;
public class input{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter your name");
        String name = sc.next(); // Only takes a single set of token for input. For set of line, we can use nextLine(); object method
        System.out.println(name);
    }

}

// Some scanner class methods for inputs eg are 
// nextInt() : Used for opting integer type inputs into the variable objects
// nextfloat() : Used for taking fractional numbers into the variable objects