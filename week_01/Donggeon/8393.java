// Big O Notation and Time Complexity
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int ans = (1 + n) * n / 2;
        System.out.println(ans);
    }
}
