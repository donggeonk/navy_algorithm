import java.util.Scanner;

/*
O(n)
- in a loop, add next int to the sum
- drop the sum when it goes below 0
- compare the sum with the max and update it

(Brute force -> O(n^2))
*/

public class Main{
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int sum = 0;
        int max = -1000;
        
        for(int i = 0; i < n; i++){
            int a = input.nextInt();
            sum = (sum <= 0) ? a : sum+a;
            if(sum > max){
                max = sum;
            }
        }
        
        System.out.println(max);
    }
}
