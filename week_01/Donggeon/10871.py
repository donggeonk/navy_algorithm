import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int x = input.nextInt();
        String str = "";
        for(int i = 0; i < n; i++) {
            int a = input.nextInt();
            if(a < x) {
                str = str + a + " ";
            }
        }
        
        System.out.println(str);
    }
}
